#include <iostream>

/*--------------------------------------------------------------------------------*/

struct NumberValidator {
    std::istream* stream;

    NumberValidator(std::istream& _stream) {
        stream = &_stream;
    };

    void ValidaInteger(size_t& val) {
        while (true) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Valor inválido" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> val;
            }
            if (!std::cin.fail()) {
                break;
            }
        }
    }

    void ValidaFloat(double& val) {
        while (true) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Valor inválido" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> val;
            }
            if (!std::cin.fail()) {
                break;
            }
        }
    }
};

/*--------------------------------------------------------------------------------*/
