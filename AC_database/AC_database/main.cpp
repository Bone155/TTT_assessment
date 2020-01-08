#include "List.h"

int main() {
	int lines;
	fstream file;
	string input;
	List targets;
	cout << "Make a list of targets" << endl;
	cout << "Write, print, remove, or quit" << endl;
	while(true) {
		cin >> input;
		cout << endl;
		if (input == "Quit" || input == "quit") {
			break;
		}
		else if (input == "Remove" || input == "remove") {
			targets.clear();
			cout << endl;
		}
		else if (input == "Print" || input == "print")
		{
			targets.print();
			cout << endl;
		}
		else if (input == "Write" || input == "write") {
			cout << "Enter # of names" << endl;
			file.open("HitList.txt", ios::out | ios::app);
			if (!file.is_open())
			{
				std::cerr << "File not found." << endl;
			}
			file.clear();
			cin >> lines;
			cout << endl;
			for (int i = -1; i < lines; i++) {
				std::getline(cin, input);
				file << input << endl;
			}
			cout << endl;
			file.flush();
			file.close();
		}
		else if (cin.fail()) {
			cout << "invalid input" << endl;
			cin.clear();
		}

	}
	
	system("pause");
	return 0;
}