#pragma once
#include <string>
#include <stdexcept>

#ifndef OBJECTS_H
#define OBJECTS_H

namespace CppStudy
{
    struct Person
    {
        std::string name;
        int age;
    };

    // Update structs data sample
    void UpdatePersonName(Person &person, const std::string &newName);

    enum AnimalType
    {
        DOG,
        CAT,
        BIRD
    };

    class Animal
    {
    public:
        Animal(const std::string &type, int age) : type(type), age(age) {}
        std::string getType();
        int getAge();
        AnimalType getAnimalType();

    private:
        std::string type;
        int age;
    };

    class Planet
    {
    public:
        Planet(const std::string &name, double mass) : name(name), mass(mass) {}

        std::string getName();
        double getMass();

    private:
        std::string name;
        double mass;
    };

    class Earth : public Planet
    {
    public:
        Earth() : Planet("Earth", 5.972e24) {}
    };
}

#endif // OBJECTS_H
