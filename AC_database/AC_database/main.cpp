#include "List.h"

int main() {
	int size = 0;
	bool isPlay = true;
	int numTarg = 0;
	string input;
	List targets;
	cout << "Make a list of targets" << endl << "Enter number of targets" << endl;
	cin >> size;
	targets.size = size;
	cout << endl << "Now enter target names (you can remove names by typing remove instead of an name or type print to print your list or type quit to exit)" << endl;
	while (true) {
		
		while(isPlay) {
			cin >> input;
			if (input == "quit") {
				isPlay = false;
			}
			else if (input == "remove") {
				cout << "Enter the name you want to remove" << endl;
				cin >> input;
				targets.remove(input);
					numTarg--;
			}
			else if (input == "print")
			{
				cout << endl;
				targets.print();
			}
			else {
				cin >> input;
				targets = { input };
				numTarg++;
			}

			if () {

			}

		}
		break;
	}
	system("pause");
	return 0;
}