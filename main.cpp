#include <iostream>
#include <vector>


template<typename T>
class vector2 {

private:
    int _size = 0;
    int _capacity = 4;
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
        if (i < _capacity) {
            return buffer[i];
        } else {
            std::cout << "Out of range" << std::endl;
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

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;  // or also value_type*
        using reference = T &;  // or also value_type&
        iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }

        pointer operator->() { return m_ptr; }

        // Prefix increment
        iterator &operator++() {
            m_ptr++;
            return *this;
        }

        // Postfix increment
        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }


        friend bool operator==(const iterator &a, const iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const iterator &a, const iterator &b) { return a.m_ptr != b.m_ptr; };

        friend bool operator<(const iterator &a, const iterator &b) { return a.m_ptr < b.m_ptr; }

    private:
        pointer m_ptr;
    };

    iterator begin() {
        return iterator(&buffer[0]);
    }

    iterator end() {
        return iterator(&buffer[_size + 1]);
    }
};

int main() {

    std::vector<int> vector;
    ::vector2<int> vector2(4);
    for (int i = 2; i < 20; ++i) {
        vector2.push_back(i);
    }

    ::vector2<char> charVector;
    for (int i = 0; i < 8; ++i) {
        charVector.push_back('a');
    }


    for (int i = 0; i < vector2.size(); ++i) {
        std::cout << vector2[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Capacity:" << vector2.capacity();


    auto end = vector2.end();
    for (auto it = vector2.begin(); it != end; ++it) {
        const auto i = *it;
        std::cout << "With iterators:" << i << std::endl;
    }

    auto charEnd = charVector.end();
    for (auto it = charVector.begin(); it != charEnd; ++it) {
        const auto i = *it;
        std::cout << "With iterators char:" << i << std::endl;
    }

    for (auto it = charVector.begin(); it < charVector.end(); ++it) {
        const auto value = *it;
        std::cout << "With overloaded operator:" << value << std::endl;
    }
    return 0;
}
