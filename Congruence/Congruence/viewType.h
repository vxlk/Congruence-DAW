#pragma once

#include "congFileHandler.h"

//extern bool isDebug = false;

#ifdef _DEBUG
extern bool isDebug = true;
#include <iostream>
#endif

namespace View {

	class commandLine {
		typedef std::vector<std::string> CommandList;
	private:

		fileHandler fileIO;
		std::string currentPathOfTerminal;

		const CommandList commandList{
			"openVST"
		};

		void getCommand(const std::string& command) const noexcept;
		bool checkCommand(const std::string& command) const noexcept;
		bool processCommand(const std::string& command) noexcept;

	public:

		commandLine() : currentPathOfTerminal(fileIO.getPath("Congruence")) {}

		static const enum ErrorType {
			ErrorTypeNone = 1,
			ErrorTypeTooFewArgs
		};

		//this is assuming using a terminal for now ... i'll have to change this later when I make my own terminal
		inline const ErrorType& mainloop(const bool& cont) noexcept {
			if (isDebug) {
				//using io in command line
				std::cout << fileIO.getPath(currentPathOfTerminal);
			}

			return ErrorTypeTooFewArgs;
		};
	};

	class gui {

	public:
		bool mainloop(const bool& cont); //call juce code
	};
}