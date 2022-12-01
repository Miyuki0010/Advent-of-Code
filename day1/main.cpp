#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> v;
    fstream input("data.txt", ios_base::in);

    if (!input.is_open()) {
        cout << "File not open \n";
        return 1;
    }

    string temp;
    int number{0};

    while (getline(input, temp)) {
        if (temp == "") {
            v.push_back(number);
            number = 0;
            continue;
        }
        number += atoi(temp.data());
    }
    v.push_back(number);

    input.close();

    sort(v.begin(), v.end(), greater<int>());

    long num = v[0] + v[1] + v[2];

    cout << "Most calories carried by an elf: " << v[0] << '\n';
    cout << "Total calories of top 3 elves: " << num << '\n';
}