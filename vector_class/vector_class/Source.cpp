#include"Header.h"

int main() {

	AJVector<int> v(5) ;
	int arr[3] = { 1,2,3 };
	AJVector<int> v1(3,arr);

	//check the size and operator[] ,too.
	//cout << v1.Size();
	//for (int i = 0; i < v1.Size(); i++) {
	//	cout << v1[i] << endl;
	//}


	v.push_back(50);
	v.push_back(60);
	v.push_back(70);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(90);
	cout << v.Size()<<endl;

	/* erase at specific iterator */
    //v.erase(v.begin()+2);
	//cout << v.Size() << endl;
	//for (int i = 0; i < v.Size(); i++) {
	//cout << v[i] << endl;
    //}

	/* erase between two iterators */
	//v.erase(v.begin() + 2 , v.begin() + 3);
	//cout << v.Size() << endl;
	//for (int i = 0; i < v.Size(); i++) {
	//	cout << v[i] << endl;
	//}

	/* insert at specific point */
	v.insert(v.begin()+3,66);
	for (int i = 0; i < v.Size(); i++) {
		cout << v[i] << endl;
	}


	//check the operator []
	/*cout<<v1[-1]<<endl;*/
	
	return 0;
}
