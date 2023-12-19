#include <iostream>
#include <exception>
#include <string>


class MyException : public std::exception {
protected:
    std::string errorMsg; // Сообщение об ошибке

public:
    MyException(const std::string& message) : errorMsg(message) {}

 
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};


class MathException : public MyException {
public:
    MathException(const std::string& message) : MyException(message) {}
};


class MemoryException : public MyException {
public:
    MemoryException(const std::string& message) : MyException(message) {}
};

class FileException : public MyException {
public:
    FileException(const std::string& message) : MyException(message) {}
};

int main() 
{
    setlocale(LC_ALL, "");
    try {
        throw MathException("Ошибка математической операции");
    }
    catch (const MyException& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    try {
        throw MemoryException("Ошибка нехватки памяти");
    }
    catch (const MyException& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    try {
        throw FileException("Ошибка работы с файлом");
    }
    catch (const MyException& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    return 0;
}
