#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



int main(){
	int contained {0};
	int overlapping {0};
	vector<int> id;
	string line;
	fstream file("input.txt");

	if(file.is_open()) {
		while(getline(file, line)) {
			id.push_back(stoi(line.substr(0, line.find("-"))));
			id.push_back(stoi(line.substr(line.find("-") + 1, line.find(","))));
			id.push_back(stoi(line.substr(line.find(",") + 1, line.find_last_of("-"))));
			id.push_back(stoi(line.substr(line.find_last_of("-") + 1)));
			if((id[0] <= id[2] && id[1] >= id[3]) || (id[2] <= id[0] && id[3] >= id[1])) {
				contained++;
			}
			if(!((id[0] < id[2] && id[1] < id[2]) || (id[2] < id[0] && id[3] < id[0]))) {
				overlapping++;
			}
			id.clear();
		}
		cout << "fully contained: " << contained << endl;
		cout << "overlap: " << overlapping << endl;
		file.close();
	}
	else{
		cout << "unable to open file " << '\n';
	}
	return 0;
}
