
/*
    RAIIDataMembers.cpp

    Demonstration to show why use RAII for all data members
*/

#include <iostream>
#include <exception>

class ClassException : public std::exception {};

class Class {
public:
    Class(int size) {
        std::cerr << __FUNCTION__ << '\n';
        data = new int[size];
        // ...
        if (size > 100)
            throw ClassException();
    }

    ~Class() {
        std::cerr << __FUNCTION__ << '\n';
        delete [] data;
    }

private:
    int* data;
};

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <size>\n";
        return 1;
    }

    int size = std::atoi(argv[1]);

    try {
        Class oop(size);

    } catch (std::exception& e) {
        std::cerr << "Exception" << '\n';
    }

    return 0;
}
