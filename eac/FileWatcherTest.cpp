// FileWatcherTest.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include "IFileWatcherListener.h"
#include "CFileSystemWatcher.h"
#include "print.h"

using namespace std;
class FileWatcherListener : public IFileWatcherListener
{
	// Inherited via IFileWatcherListener
	virtual void OnFileChange(const std::wstring & path) override
	{
		print::set_error("We have detected a file change. \n\n");
	}

	// Inherited via IFileWatcherListener
	virtual void OnFileAdded(const std::wstring & path) override
	{
		print::set_ok("We have detected a file added to directory. \n\n");
	}

	// Inherited via IFileWatcherListener
	virtual void OnFileRemoved(const std::wstring & path) override
	{
		print::set_ok("We have detected a file removed. \n\n");
	}

	// Inherited via IFileWatcherListener
	virtual void OnFileRenamed(const std::wstring & path) override
	{
		print::set_error("We have detected a file renamed. \n\n");
	}

};

int main()
{
	
	/*!
	 * Creates watcher by passing the watch directory
	 * 
	 */
	CFileSystemWatcher watcher(L"C:\\Program Files (x86)\\EasyAntiCheat");
	/*!
	 *
	 * Creates Linstener
	 */
	IFileWatcherListener* listener = new FileWatcherListener();
	
	//passes the listener to watcher
	watcher.AddFileChangeListener(listener);
	int choice;
	do
	{
		print::set_error("Easy Anti Cheat File Watcher \n\n");

		print::set_ok("[1] Start  \n\n");

		print::set_error("[2] Stop \n\n");

		Sleep(400);
		system("CLS");


		cin >> choice;

		switch (choice)
		{
		case 1:
		  {
			system("cls");
			if (!watcher.Running())
				watcher.Start();
			else
				print::set_error("Already Started \n\n");

		  }
			break;
		case 2:		
			watcher.Stop();
			break;		
		case 3: 
			exit(0);
			break;
		default:
			cout << "\nInvalid choice";
		}
	   } while (choice != 3);
	
	   
	   delete listener;

    return 0;
}

