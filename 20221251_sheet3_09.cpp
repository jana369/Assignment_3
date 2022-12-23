#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;
template<typename T>
class set {
private:
	vector<T> sett;
public:
	bool is_Exist(T item) {
		for (int i = 0; i < sett.size() ; i++) {
			if (sett[i] == item) {
				return false;
			}
		}
		return true;
	}
	void insert(T item) {
		if (is_Exist(item)) {
			sett.push_back(item);
		}
	}
	void erase(T item) {
		if (!is_Exist(item)) {
			for (int i = 0; i < sett.size(); i++) {
				if (sett[i] == item) {
					sett.erase(sett.begin() + i);
				}
			}
		}
	}
	int count() {
		return sett.size();
	}
	T* array() {
		T arr[sett.size()];
		for (int i = 0; i < sett.size(); i++) {
			arr[i] = sett[i];
		}
		return arr;
	}
	bool operator==(const set& other) {
		if (sett.size() == other.sett.size()) {
			for (int i = 0; i < sett.size(); i++) {
				
				if (sett[i] == other.sett[i]) {
					return true;
				}
			}
		}
		return false;
	}
	bool operator!=(const set& other) {
		if (sett.size() == other.sett.size()) {
			for (int i = 0; i < sett.size(); i++) {
				if (sett[i] != other.sett[i]) {
					return true;
				}
			}
		}
		return false;
	}
	

};
int main() {
	//set<int> s1;
	//set<int> s2;
	//cout<<s1.count()<<endl;
	//s1.insert(50);
	//s1.insert(50);
	//s2.insert(50);
	//s1.insert(50); 
	//cout << s1.count() << endl;
	//s1.erase(60);
	//s2.insert(80);
	//cout << s2.count() << endl<<endl;
	//if (s1 == s2) {
	//	cout << "same" << endl;
	//}
	//else {
	//	cout << "diff" << endl;
	//}
	vector<int>v1;
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	v1.push_back(50);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	return 0;
}
//int num1 = 2, num2 = 3;
//istream_iterator<int> inputInt{ cin };
//num1 = *inputInt;
//num2 = *inputInt;
//ostream_iterator<int> outputInt{ cout };
//outputInt = 5 ;
