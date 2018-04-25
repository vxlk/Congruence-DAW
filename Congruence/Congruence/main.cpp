#include "module.h"
#include "viewType.h"

int main() {

	using commandLine = View::commandLine;
	using gui		  = View::gui;

	commandLine isCommandLine;
	gui			isGui;
	int		canContinue = 1;
	bool		commandLineMode = true;

	//OPEN config
	//if isCommandLine == 1
	if (commandLineMode) {
		while (canContinue == isCommandLine.ErrorTypeNone) {
			canContinue = isCommandLine.mainloop(canContinue);
		};

	}
	int x;
	std::cin >> x;
	return 0;
}