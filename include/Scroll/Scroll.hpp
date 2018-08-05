#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <mutex>

namespace Scroll
{
	/**
	 * @brief	Prints to the screen and ends print command with a newline and an ostreamflush
	 * @warning	Thread Unsafe
	 */
#define PRINT(x) std::cout << x << std::endl

	 /**
	  * @brief	Prints to the screen and ends print command with an ostream flush
	  * @warning	Thread Unsafe
	  */
#define PRINTLN(x) std::cout << x << std::flush

	  /**
		  * @class	Scroll
		  *
		  * @brief	The main record keeping class.
		  * @warning	Thread safe
		  */
	class Scroll
	{
	private:
		std::mutex m_CoutMutex;
		std::vector<std::mutex> m_StreamMutexes;

	public:
		Scroll()
		{
		}

		~Scroll()
		{
			for(auto & item : m_StreamMutexes)
			{
				item.unlock();
			}
		}

		void print(std::string x, class Scroll)
		{
			m_CoutMutex.try_lock();

			PRINT(x);

			m_CoutMutex.unlock();
		}

		void printToFileStream(std::ostream & stream, std::string data)
		{
			stream << data;
			stream.flush();
		}

	protected:

	};
}
