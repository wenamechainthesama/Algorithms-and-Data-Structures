#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::exception;
using std::string;

class MyException : public exception {

    private:

        int _statusCode;
        string _errorDescription;

    public:

        MyException() {
            _errorDescription = "Something went wrong";
        }

        MyException(std::string error_description) {
            _errorDescription = error_description;
        }

        MyException(std::string error_description, int statusCode) : MyException(error_description) {
            statusCode != 0 ? _statusCode = 1 : _statusCode = statusCode;
        }

        std::string what() {
            return _errorDescription;
        }

        int code() {
            return _statusCode;
        }

        friend ostream& operator<<(ostream &out, const MyException &exception);
};

ostream& operator<<(ostream &out, const MyException &exception) {
    out << exception._errorDescription;
    return out;
}

void foo(int value) {
    if (value < 0) {
        // We can also use exception() but it hasn't got overload for string
        throw std::runtime_error("Value is less than 0");
        // Instead of using runtime_error we can use logic_error
    } else if (value == 0) {
        throw "Value equals to 0";
    } else if (value == 1) {
        throw MyException("Hi", 1);
    }

    cout << "Variable == " << value << endl;
}

int main() {
    try {
        foo(1);
    } catch (MyException exception) {
        cout << exception << endl;
        cout << exception.what() << endl;
        cout << exception.code() << endl;
    } catch (...) {
        cout << "Smth went wrong" << endl;
    }
}