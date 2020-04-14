/*
    ExceptionsDemo.cpp

    Demonstration of order of catch'es for a try

    Values to try on command line:

    * Success: 10
    * domain_error: -1
    * length_error: 101
    * invalid_argument: 50
*/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

int f(int n) {
    if (n < 0)
        throw std::domain_error("Negative value");
        
    return n + 1;
}

int g(int n) {
    // limited length of result
    if (n > 100)
        throw std::length_error("Over 100");

    return f(n) * 2;
}

int h(int n) {
    if (n == 50)
        throw std::invalid_argument("50 is not allowed");

    return g(n) / 2;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <size>\n";
        return 1;
    }

    try {
        int n = std::stoi(argv[1]);
        auto result = h(n);

    } catch (std::domain_error& e) {
        std::cerr << "Domain Error: " << e.what() << '\n';
        return 1;
    } catch (std::length_error& e) {
        std::cerr << "Length Error: " << e.what() << '\n';
        return 1;
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid Argument: " << e.what() << '\n';
        return 1;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Error: " << '\n';
        return 1;
    }
    
    return 0;
}
