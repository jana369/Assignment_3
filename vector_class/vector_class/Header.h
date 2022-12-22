
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
private:
 	size_t size=0, capacity=0;
	T* data=nullptr;
public:
    //constructors and big 4
    AJVector(int capac)//creates a vector of size 0 and capacity == capac
    {
        this->size = 0;
        this->capacity = capac;
        data = new T[capacity];
    };

    AJVector(int n, T *item) {//creates a vecor of array elements of size n
        this->size = n;
        this->capacity = n;
        data = new T[capacity];
        for (int i = 0; i < n; i++) {
            data[i] = item[i];
        }
    };

    AJVector(const AJVector &other) : capacity(other.capacity) {//copy constructor
        cout << "copy constructor";
        this->size = other.size;
        data = new T[capacity + 1];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~AJVector() {//to delete the dynamic storage
        delete[] data;
    }

    T &operator=(const AJVector &) {//copy assignment

    }

    T &operator=(const AJVector &&) {//move assignment

    }

    //access operations
    T& operator[](int index) {
			if(index<0||index>=size)
			throw out_of_range("exception_handling");

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
    }

    T pop_back() {

        data[size - 1] = 0;
        size--;
    }

    void clear() {
        size = 0;
        data = 0;
    }
    //void insert(iterator , T);
    ////iterators
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
    
     T begin() {
        T *ptr = &data[0];
        return *ptr;

    }

    T end() {
        T *ptr = &data[size - 1];
        return *ptr;
    }

    ////comparison operators
    bool operator==(const AJVector<T> &other) {
        if (other.size == size) {
            return true;
        } else
            return false;
    }

    bool operator<(const AJVector<T> &other) {
        if (size < other.size) {
            return true;
        } else {
            return false;
        }
    }

    ////capacity operations
    int pCapacity() const {
        return capacity;

    }

        void resize(int num){
        T* new_vector = new T{num};
        for (int i = 0; i < size; i++) {
            new_vector[i] = data[i];
        }
        delete[] data;
        capacity = num;
        data = new T{num};
        data = new_vector;
        new_vector = nullptr;
        delete new_vector;
    }


    bool empty() {
        if (size == 0) {
            return true;
        } else
            return false;
    }

    //friends
    friend ostream &operator<<(ostream &stream, const AJVector<T> &other) {
        for (int i = 0; i < other.size; i++) {
            cout << other.data[i];
        }
        return stream;
    }
};

int main(){
    AJVector<int>vec{5};
    vec.push_back(20);
    vec.push_back(56);
    vec.push_back(23);
    cout << vec[0] << endl;
    cout << vec.pCapacity() << " " << vec.Size() << endl;
    cout << vec.begin() << endl;
    cout << vec.end() << endl;
    vec.clear();
    cout << vec[2];
}
