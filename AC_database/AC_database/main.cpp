#include "List.h"

int main() {
	int size = 0;
	bool isPlay = true;
	string input;
	List targets;
	cout << "Make a list of targets" << endl << "Enter number of targets" << endl;
	cin >> size;
	targets = { size };
	cout << endl << "Now enter target names (you can remove names by typing remove instead of an name or type print to print your list or type q to quit)" << endl;
	while (isPlay) {
		if (input == "q") {
			isPlay = false;
		}
		else if (input == "remove") {
			cout << "Enter the name you want to remove" << endl;
			cin >> input;
			targets.remove(input);
		}
		else if (input == "print")
		{
			cout << endl;
			targets.print();
		}
		else {
			cin >> input;
		}
		targets = { input };
		
	}

	return 0;
}