#include "Objects.h"

namespace CppStudy
{
    void UpdatePersonName(Person &person, const std::string &newName)
    {
        person.name = newName;
    }

    std::string Animal::getType()
    {
        return type;
    }
    int Animal::getAge()
    {
        return age;
    }
    AnimalType Animal::getAnimalType()
    {
        if (type == "Dog")
            return DOG;
        else if (type == "Cat")
            return CAT;
        else if (type == "Bird")
            return BIRD;
        else
            throw std::invalid_argument("Unknown animal type");
    }

    std::string Planet::getName()
    {
        return name;
    }
    double Planet::getMass()
    {
        return mass;
    }
}
