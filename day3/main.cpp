#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> readFile();
unordered_map<char, int> getLetterMap();

int main() {
	vector<string> data = readFile();

	int half {0};
	string firstHalf, secondHalf;

	vector<char> prio;

	for (auto& str : data) {
		half = str.length() / 2;
		firstHalf = str.substr(0, half);
		secondHalf = str.substr(firstHalf.length(), half);

		bool found {false};

		for (int i = 0; i < half; i++) {
			if(found) {
				break;
			}

			for (int j = 0; j < half; j++) {
				if(firstHalf[i] == secondHalf[j]) {
					prio.push_back(firstHalf[i]);
					found = true;
					break;
				}
			}
		}
	}
	unordered_map<char, int> letterMap = getLetterMap();
	int sum {0};
	for (auto& i : prio) {
		sum += letterMap[i];
	}
	cout << "sum: " << sum << '\n';

	//Part 2
	sum = 0;
	for (int i = 0; i < data.size(); i += 3) {
		set<char> first, second, third;
		for(auto& curr_Char : data[i]) {
			first.insert(curr_Char);
		}
		for(auto& curr_Char : data[i + 1]) {
			second.insert(curr_Char);
		}
		for(auto& curr_Char : data[i + 2]) {
			third.insert(curr_Char);
		}

		set<char> common;
		set_intersection(first.begin(), first.end(), second.begin(), second.end(),
				inserter(common, common.begin()));
		
		set<char> common2;
		set_intersection(common.begin(), common.end(), third.begin(), third.end(),
				inserter(common2, common2.begin()));

		sum += letterMap[*(common2.begin())];	// leaves just the priority
	}

	cout << sum << "\n";
	return 0;
}

vector<string> readFile() {

	fstream input("input.txt", ios_base::in);

    if (!input.is_open()) {
        cout << "Error with file \n";
        exit(1);
    }

    string temp;
    vector<string> v;

    while (!input.eof()) {
        if (getline(input, temp)) {
            v.push_back(temp);
            }
	}

	input.close();
	return v;
}

unordered_map<char, int> getLetterMap(){
	unordered_map<char, int> letterMap;
	int count = 1;
	for (char letter = 'a'; letter <= 'z'; letter++) {
		letterMap.insert( {letter, count} );
		count++;
	}

	for (char letter = 'A'; letter <= 'Z'; letter++) {
		letterMap.insert( {letter, count} );
		count++;
	}

	return letterMap;
}
