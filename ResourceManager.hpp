#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager()
    { // Konstruktor domy�lny
        dane = new Resource;
    }

    ResourceManager(const ResourceManager& rm)
    { // Konstruktor kopiuj�cy
        dane = new Resource{*rm.dane};
    }

    ResourceManager(ResourceManager&& rm)
    { // Konstruktor przenosz�cy
        dane    = rm.dane;
        rm.dane = nullptr;
    }

    ResourceManager& operator=(const ResourceManager& rm)
    { // kopiujacy przypisania

        if (&rm != this) {
            delete dane;
            dane = new Resource{*rm.dane};
        }
        return *this;
    }

    ResourceManager& operator=(ResourceManager&& rm)
    { // przenosz�cy przypisania

        if (&rm != this) {
            delete dane;
            dane    = rm.dane;
            rm.dane = nullptr;
        }
        return *this;
    }

    ~ResourceManager()
    { // destruktor
        delete dane;
    }

    double get()
    { // funkcja zwracaj�ca get
        return dane->get();
    }

private:
    Resource* dane; // klasa
};