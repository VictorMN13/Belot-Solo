#pragma once

template<class T, typename U>
class Istoric {
    T first;
    U second;
    public:
    Istoric(T first, U second) : first(first), second(second) {}
    T getFirst();
    U getSecond();
    void setFirst(T first);
    void setSecond(U second);
    void addSecond(U second);
    ~Istoric() = default;

    // initializare ca <Player, int> cate puncte a acumulat playerul in runda resprectiva
    // si <Runda, int> penutru a retine id ul playerului care a castigat runda
};

template<class T, typename U>
T Istoric<T, U>::getFirst() {
    return first;
}

template<class T, typename U>
U Istoric<T, U>::getSecond() {
    return second;
}

template<class T, typename U>
void Istoric<T, U>::setFirst(T first) {
    this->first = first;
}

template<class T, typename U>
void Istoric<T, U>::setSecond(U second) {
    this->second = second;
}

template<class T, typename U>
void Istoric<T, U>::addSecond(U second) {
    this->second += second;
}