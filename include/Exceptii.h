#pragma once
#include <exception>

class AtuInvalidException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Atu invalid selectat.";
    }
};

class PasInterzisException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Esti dealer, nu poti da pass";
    }
};

class InputExceptionAtu : public std::exception {
public:
    const char* what() const noexcept override {
        return "Raspuns invalid, introdu 1 pentru da, 0 pentru nu";
    }
};

class InputExceptionJoaca : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Nu exista aceasta carte";
    }
};

class AtuFreeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Nu poti juca atuul acum, deoarece atu-ul nu este liber si ai alternative.";
    }
};

class CuloareInvalidException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Trebuia sa joci o carte din culoarea ceruta sau atu daca nu ai, dar nu ai respectat regula.";
    }
};

