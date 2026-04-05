#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>

class RentalException : public std::runtime_error {
public:
    RentalException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidIndexException : public RentalException {
public:
    InvalidIndexException() : RentalException("Invalid index selected.") {}
};

class VehicleNotAvailableException : public RentalException {
public:
    VehicleNotAvailableException() : RentalException("Vehicle is not available for rent.") {}
};

class AlreadyReturnedException : public RentalException {
public:
    AlreadyReturnedException() : RentalException("This vehicle was already returned.") {}
};

class FileException : public RentalException {
public:
    FileException(const std::string& filename)
        : RentalException("Cannot open file: " + filename) {}
};

class WrongPasswordException : public RentalException {
public:
    WrongPasswordException() : RentalException("Wrong password!") {}
};

#endif
