#include <iostream>
using namespace std;

class String {
    
    private:

        char *_str;
        int _size;

        void assignString(const char *str) {
            _size = strlen(str);
            this->_str = new char[_size + 1];  // Add 1 because of `\0` 
            for (int i = 0; i < _size; i++) {
                this->_str[i] = str[i];
            }

            this->_str[_size] = '\0';
        }

    public:

        // Default Constructor
        String() {
            _str = nullptr;
            _size = 0;
        }

        // Non-empty (Custom) Constructor
        String(const char *str) {
            assignString(str);
        }

        // Copy Constructor
        String(const String &otherInstance) {
            
            /* 
            Check if `str` was initialized and clear
            If so -> clear up memory 
            */

            if (_str != nullptr) {
                delete [] _str;
            }

            assignString(otherInstance._str);
        }

        // Move Constructor
        String(String &&otherInstance) {

            _size = otherInstance._size;
            _str = otherInstance._str;
            otherInstance._str = nullptr;
        }

        // Destructor
        ~String() {
            if (_str == nullptr) {
                delete[] _str;
            }
        }

        // Assignment operator overload
        String& operator=(const String &otherInstance) {
            
            /* 
            Check if `str` was initialized and clear
            If so -> clear up memory 
            */

            if (_str != nullptr) {
                delete [] _str;
            }

            assignString(otherInstance._str);

            return *this;
        }

        // Equality operator overload
        bool operator==(const String &otherInstance) {
            if (_size != otherInstance._size) {
                return false;
            }
            
            for (int i = 0; i < strlen(otherInstance._str); i++) {
                if (_str[i] != otherInstance._str[i]) {
                    return false;
                }
            }

            return true;
        }

        // Non-equality operator overload
        bool operator!=(const String &otherInstance) {
            return !operator==(otherInstance);
        }

        // Concatenation operator overload
        String operator+(const String &otherInstance) {
            String newString;
            int selfLength = strlen(this->_str);
            int otherLength = strlen(otherInstance._str);
            newString._size = selfLength + otherLength;
            newString._str = new char[newString._size + 1];
            
            int i = 0;
            for (; i < selfLength; i++) {
                newString._str[i] = this->_str[i];
            }

            for (int j = 0; j < otherLength; i++, j++) {
                newString._str[i] = otherInstance._str[j];
            }

            newString._str[newString._size] = '\0';

            return newString;
        }

        // Index operator overload
        char& operator[](int index) {
            return this->_str[index];
        }

        // smth << overload
        friend std::ostream& operator<<(std::ostream &out, const String &str);

        inline int strlen(const char *str) {

            /*
            const char * is a pointer to a const char,
            while char * const is a constant pointer to
            a char
            */

            int length = 0;
            while (*str != '\0') {
                length++;
                str++;
            }

            return length;
        }

        // Get length of string
        int length() {
            return _size;
        }
};

ostream& operator<<(ostream &out, const String &str) { 
    for (int i = 0; i < str._size; i++) {
        std::cout << str._str[i];
    }
    
    return out;
}

int main() {
    String str = "Hello, World!";
    cout << str;
}

/*
Todo:
Overload * operator
What is move constructor?

Todo after:
Code my array class
*/

