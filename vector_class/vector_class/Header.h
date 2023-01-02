#include<iostream>
#include<string>
#include<iterator>
#include <iomanip>
#include <stdexcept>
using namespace std;
template<class iterators>
class vector_iterator {
public:
	using valueType   = typename iterators::valueType;
	using pointerType = valueType*;
	using ReferenceType = valueType&;
	vector_iterator(pointerType ptr)
		:m_ptr(ptr) {};
	vector_iterator& operator++() {//prefix operator
		m_ptr++;
		return *this;
	};
	vector_iterator operator++(int n) {
		vector_iterator iterator = *this;
		++(*this);
		return iterator;
	};
	vector_iterator operator+(int n) {
		//vector_iterator iterator = *this;
		for (int i = 0; i < n; i++) {
			++m_ptr;
		}
		return *this;
	};
	size_t operator+(const vector_iterator& other) {
		return m_ptr + other.m_ptr;
	};
	vector_iterator& operator--() {//prefix operator
		m_ptr--;
		return *this;
	};
	vector_iterator operator--(int n) {
		vector_iterator iterator = *this;
		--(*this);
		return iterator;
	};
	vector_iterator operator-(int n) {
		vector_iterator iterator = *this;
		for (int i = 0; i < n; i++) {
			--(*this);
		}
		return iterator;
	};
	size_t operator-(const vector_iterator& other) {
		return m_ptr-other.m_ptr;
	};
	ReferenceType operator[](int index) {
		return *(m_ptr + index);
	};
	pointerType operator-> () {//the current position of the iterator
		return m_ptr;
	};
	ReferenceType operator* () {
		return *m_ptr;
	};
	bool operator==(const vector_iterator& other)const {
		return m_ptr == other.m_ptr;
	};
	bool operator<(const vector_iterator& other)const {
		return m_ptr <  other.m_ptr;
	};
	bool operator<(const int n)const {
		return n < m_ptr;
	};
	bool operator>(const vector_iterator& other)const {
		return m_ptr > other.m_ptr;
	};
	bool operator>=(const vector_iterator& other)const {
		return m_ptr >= other.m_ptr;
	};
	bool operator!=(const vector_iterator& other)const {
		return !(*this == other.m_ptr);
	};
private:
	pointerType m_ptr;
};
template<class T>
class AJVector {
public :
	using valueType = T;
	using iterator = vector_iterator<AJVector<T>>;

private:
	size_t size=0, capacity=0;
	T* data=nullptr;
public:
	//constructors and big 4
	AJVector(size_t capac)//creates a vector of size 0 and capacity == capac
	{
		this->size = 0;
		this->capacity = capac;
		data = new T[capacity];
	};

	AJVector(size_t n , T* item) {//creates a vecor of array elements of size n
		this->size = n;
		this->capacity = n;
		data = new T[capacity];
		for (int i = 0; i < n; i++) {
			data[i] = item[i];
		}
	};

	AJVector(const AJVector& other) :capacity(other.capacity) {//copy constructor
		cout << "copy constructor";
		this->size = other.size;
		data = new T[capacity + 1];
		for (int i = 0; i < size ; i++)
		{
			data[i] = other.data[i];
		}
	};
	
	~AJVector() {//to delete the dynamic storage
		delete[] data;
	};
	T& operator=(const AJVector& other) {//copy assignment
		if (data != &other.data) {
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[(other.size) + 1];
			for (int i = 0; i < size + 1; i++) {
				data[i] = other.data[i];
			}
		}
		return data;
	};

	T& operator=(const AJVector&& other) {//move assignment
		if (data != &other.data) {
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[(other.size)+1];
			for (int i = 0; i < size+1; i++) {
				data[i] = other.data[i];
			}
			other.data = nullptr;
			other.size = 0;
			other.capacity = 2;
		}
		return *data;
	};
	//access operations
	T& operator[](size_t index) {
		if(index<0 && index>=size){
			try {
					throw throwError();
			}
			catch (AJVector::throwError) {
				cout << "Exception handling: the index is out_of_range";
			}
		}
			return data[index];
	};
	//modifying operators
	size_t push_back(T new_item) {//to add a new data
		if (size < capacity) {
			data[size++] = new_item;
			return size;
		}
		else {
			capacity *= 2;
			T* new_vector = new T[capacity*2];
			for (int i = 0; i < size; i++) {
				new_vector[i] = data[i];
			}
			delete[] data;
			data = new_vector;
			new_vector = nullptr;
			delete[] new_vector;
			data[size++] = new_item;
			return size;
		}
	};

	size_t Size() const {
		return size;
	};
	T pop_back() {
		size--;
		return data[size];
	};
	void clear() {
		delete[] data;
		capacity = 2;
		size = 0;
		data = new T[capacity];
	};
	iterator begin() {
		return iterator(data);
	}
	iterator end() {
		return iterator(data + size);
	}
	void erase(iterator it) {
		try {
			if ((it > begin() || it == begin()) && it < end())
			{
				T* new_one;
				new_one = new T[size - 1];
				for (int i = 0; i < size-1 ; i++) {
					if (i < it - begin()) { new_one[i] = data[i]; }
					else if(i >= it - begin()){ new_one[i] = data[i + 1]; }	
				}
				data = new_one;
				new_one = nullptr;
				size--;
				capacity--;
			}
			else {
				throw throwError();
			}
		}
		catch (AJVector::throwError) {
			cout << "Exception Handling: access_denied"<<endl;
		}
	};
	void erase(iterator it1, iterator it2) {
		try {
			if (((it1 > begin() || it1 == begin()) && it1 < end()) && ((it2 > begin() || it2 == begin()) && it2 < end()) && (it2>it1))
			{
				T* new_one;
				size_t s = size - (it2 - it1);
				new_one = new T[(s)];
				for (int i = 0; i < s ; i++) {
					if (i < (it1 - begin())) {
					new_one[i] = data[i];
					}
					else if (i >= (it1 - begin())) {
					new_one[i] = data[i+(it2-it1)];
					}
				}
				while (it2-it1)
				{
					size--;
					capacity--;
					it1++;
				}
				data = new_one;
				new_one = nullptr;
			}
			else {
				throw throwError();
			}
		}
		catch (AJVector::throwError) {
			cout << "Exception Handling: access_denied" << endl;
		}
	};

	

	void insert(iterator it, T item) {
		try {
			if ((it > begin() || it == begin()) && it < end())
			{
				T* new_one;
				new_one = new T[size + 1];
				for (size_t i = 0; i < (it-begin()); i++) {
					new_one[i] = data[i]; 
				}
				new_one[it - begin()] = item;
				for (size_t i = it-begin()+1 ; i < size+1; i++) {
					new_one[i] = data[i-1] ;
				}
				size++;
				data = new_one;
				new_one = nullptr;
			}
			else {
				throw throwError();
			}
		}
		catch (AJVector::throwError) {
			cout << "Exception Handling: access_denied" << endl;
		}
	};
	 	
	//iterators
	////comparison operators
	bool operator==(const AJVector<T>& other) {
		if (other.size == size) {
			return true;
		}
		else
			return false;
	}

	bool operator<(const AJVector<T>& other) {
		if (size < other.size) {
			return true;
		}
		else {
			return false;
		}
	}

	////capacity operations
	size_t pCapacity() const {
		return capacity;
	}

	void resize(int num) const {
		T* new_vector = new T* { capacity };
		for (int i = 0; i < size; i++) {
			new_vector[i] = data[i];
		}
		delete[] data;
		data = new_vector;
		new_vector = nullptr;
		delete[] new_vector;
	}

	bool empty() {
		if (size == 0) {
			return true;
		}
		else
			return false;
	}

	bool is_empty() {
		return size == 0;
	};

	//friends
	friend ostream& operator << (ostream& ,const AJVector<T>&);
	class throwError {};
};
template<class T>
ostream& operator<< (ostream& stream,const AJVector<T>& other) {
	for (int i = 0; i < other.size; i++) {
		cout << other.data[i];
	}
	return stream;
};
