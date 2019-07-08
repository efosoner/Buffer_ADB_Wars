#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {

	string input;
	unsigned int numberOfBuffers;

	cin >> input;
	cin >> numberOfBuffers;

	unordered_map<string, int> repetitionsMap;

	string *BufferTable = new string[numberOfBuffers];

	for (unsigned int i = 0; i < numberOfBuffers; i++) {
		cin >> BufferTable[i];
	}

	for (int i = 0; i < input.size(); i++) {
		for (int j = 1; j < 5 && i + j - 1 < input.size(); j++) {
			string key = input.substr(i, j);

			unordered_map<string, int>::iterator it = repetitionsMap.find(key);
			if (it == repetitionsMap.end()) {
				repetitionsMap[key] = 1;
			}
			else {
				it->second++;
			}
		}
	}

	for (int i = 0; i < numberOfBuffers; i++)
	{
		unordered_map<string, int>::iterator it = repetitionsMap.find(BufferTable[i]);
		if (it == repetitionsMap.end()) {
			cout << 0 << '\n';
		}
		else {
			cout << it->second << '\n';
		}
	}
	system("pause");
}