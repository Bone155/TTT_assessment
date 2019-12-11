#include "List.h"

int main() {
	int size = 0;
	bool isPlay = true;
	string input;
	List creed;
	cout << "Make a list of targets" << endl << "Enter number of targets" << endl;
	cin >> size;
	creed = { size };
	cout << endl << "Now enter target names (you can remove names by typing remove instead of an name or type print to print your list or type q to quit)" << endl;
	while (isPlay) {
		if (input == "q") {
			isPlay = false;
		}
		else if (input == "remove") {
			cout << "Enter the name you want to remove" << endl;
			cin >> input;
			creed.remove(input);
		}
		else if (input == "print")
		{
			cout << endl;
			creed.print();
		}
		else {
			cin >> input;
		}
		creed = { input };
		
		
	}


	return 0;
}