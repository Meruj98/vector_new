#include <iostream>
#include <vector>


template<typename T>
class vector2 {

private:
    int _size = 0;
    int _capacity = sizeof(T);
    T *buffer = new T[_capacity];
public:
    vector2() {

    }

    vector2(int size) {
        _capacity = size;
    }

    void push_back(const T &elem) {
        if (_size == _capacity) {
            _capacity *= 2;
            T *tmp = new T[_capacity];
            for (int ix = 0; ix < _size; ++ix) {
                tmp[ix] = buffer[ix];
            }
            delete[] buffer;
            buffer = tmp;
        }
        buffer[_size] = elem;
        ++_size;
    }

    T at(int i) {
        if (i <= _capacity) {
            return buffer[i];
        }
    }

    int size() {
        return _size;
    }

    int capacity() {
        return _capacity;
    }

    T operator[](int index) {
        return buffer[index];
    };


};

int main() {

    std::vector<int> vector;
    auto a = vector.begin();
    vector2<int> vector2(4);
    for (int i = 0; i < 20; ++i) {
        vector2.push_back(i);
    }

    ::vector2<char> charVector;
    charVector.push_back('a');
    charVector.push_back('a');
    charVector.push_back('a');
    charVector.push_back('a');
    charVector.push_back('a');
    charVector.push_back('a');
    charVector.push_back('a');
    charVector.push_back('a');


    for (int i = 0; i < vector2.size(); ++i) {
        std::cout << vector2[i] << std::endl;
    }
//    for (int i = 0; i < charVector.size(); ++i) {
//        std::cout << charVector[i];
//    }
    std::cout << std::endl;
    std::cout << "Capacity:" << vector2.capacity();
    return 0;
}
