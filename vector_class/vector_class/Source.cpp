#include"Header.h"
#include<vector>

int main() {

	/*vector<int> vect(10, 10);
	cout << vect.size()<<endl;
	cout << vect.capacity() << endl;*/
	AJVector<int> v(5) ;
	int arr[3] = { 1,2,3 };
	AJVector<int> v1(3,arr);
	cout << v1.Size();
	for (int i = 0; i < v.Size(); i++) {
		cout << v1[i] << endl;
	}
	return 0;
}






//int num1 = 2, num2 = 3;
//istream_iterator<int> inputInt{ cin };
//num1 = *inputInt;
//num2 = *inputInt;
//ostream_iterator<int> outputInt{ cout };
//outputInt = 5 ;