#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <mutex>

namespace Scroll
{
	/**
	 * @brief		Prints to the screen and ends print command with a newline and an ostreamflush
	 * @warning		Thread Unsafe
	 */
#define PRINTLN(x) std::cout << x << std::endl

	 /**
	  * @brief		Prints to the screen and ends print command with an ostream flush
	  * @warning		Thread Unsafe
	  */
#define PRINT(x) std::cout << x << std::flush

	struct LogFile
	{
		std::string filePath;
		std::fstream * fileStream;

		LogFile(const std::string & filePath)
			: filePath(filePath), fileStream(new std::fstream())
		{
		}

		~LogFile()
		{
			delete fileStream;
		}

		void open()
		{
			fileStream->open(filePath, std::ios::ate);
		}

		void close()
		{
			fileStream->close();
		}
	};

	/**
	 * @class		Scroller
	 *
	 * @brief		The main record keeping class.
	 * @warning		Thread safe
	 */
	class Scroller
	{
	private:
		std::mutex m_CoutMutex;
		std::vector<std::mutex> m_StreamMutexes;
		std::vector<LogFile *> m_LogFiles;

	public:
		Scroller()
		{
		}

		~Scroller()
		{
			for(auto & item : m_StreamMutexes)
			{
				item.unlock();
			}
		}

		void print(const std::string & x)
		{
			m_CoutMutex.try_lock();

			PRINT(x);

			m_CoutMutex.unlock();
		}

		void printToFileStream(LogFile * file, std::string & data)
		{
			file->fileStream->clear();
			*(file->fileStream) << data;
			file->fileStream->flush();
		}

		void

	protected:

	};
}
