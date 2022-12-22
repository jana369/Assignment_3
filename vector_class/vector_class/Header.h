
#include<iostream>
#include<string>
#include<iterator>
#include <iomanip>
#include <stdexcept>
using namespace std;
template<class T>
class AJVector {
private:
    int size, capacity;
    T *data;
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
    T &operator[](int index) {
        if (index < 0 || index >= size) {
            //Error("getAt: index out of range");
        }
        if (index < size)
            return data[index];
    }

    //modifying operators
    void push_back(T new_item) {//to add a new data
        if (size < capacity) {
            data[size++] = new_item;
        } else {
            capacity *= 2;
            T *new_vector = new T[capacity * 2];
            for (int i = 0; i < size; i++) {
                new_vector[i] = data[i];
            }
            delete[] data;
            data = new_vector;
            new_vector = nullptr;
            delete new_vector;
            data[size++] = new_item;
        }
    }

    int Size() const {
        return size;
    }

    T pop_back() {

        data[size - 1] = 0;

    }

    void clear() {
        size = 0;
        data = 0;
    }
    //void insert(iterator , T);
    ////iterators

    int begin() {
        int *ptr = &data[0];
        return *ptr;

    }

    int end() {
        int *ptr = &data[size - 1];
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

    void resize(int num) const {
        T* new_vector = new T*{capacity};
        for (int i = 0; i < size; i++) {
            new_vector[i] = data[i];
        }
        delete[] data;
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
