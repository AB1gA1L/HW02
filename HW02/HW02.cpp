#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
    virtual ~Animal() {}
    virtual void makesound() = 0;
};

class Dog : public Animal {
public:
    void makesound() override {
        cout << "멍멍" << endl;
    }
};

class Cat : public Animal {
public:
    void makesound() override {
        cout << "냥냥" << endl;
    }
};

class Cow : public Animal {
public:
    void makesound() override {
        cout << "음메" << endl;
    }
};

class Zoo {
public:
    Animal* animals[10];
    int animalCount = 0;

    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount] = animal;
            animalCount++;
        }
        else {
            cout << "동물이 너무 많습니다!" << endl;
            delete animal; // 메모리 누수 방지
        }
    }

    void performActions() {
        for (int i = 0; i < animalCount; i++) {
            animals[i]->makesound();
        }
    }

    ~Zoo() {
        for (int i = 0; i < animalCount; i++) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int randInt = rand() % 3;
    if (randInt == 0) {
        return new Dog();
    }
    else if (randInt == 1) {
        return new Cat();
    }
    else {
        return new Cow();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int SIZE = 3;
    Animal* animals[SIZE] = {
        new Dog(),
        new Cat(),
        new Cow()
    };

    Zoo myZoo;
    for (int i = 0; i < 5; i++) {
        myZoo.addAnimal(createRandomAnimal());
    }

    cout << "랜덤동물" << endl;
    myZoo.performActions();

    cout << "동물울음" << endl;
    for (int i = 0; i < SIZE; i++) {
        animals[i]->makesound();
    }

    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }

    return 0;
}
