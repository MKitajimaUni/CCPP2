//
// Created by Mitsuhiro Kitajima on 24/10/25.
//
#ifndef COUSINS_H
#define COUSINS_H
#include <string.h>

#include "FileReader.h"

typedef struct {
    char vorname[20];
    char nachname[20];
    unsigned int geburtsjahr;
} Geschwister;

void sortByGeburtsjahr(int length, Geschwister *geschwisterList);
void sortByName(int length, Geschwister *geschwisterList);
void printGeschwisterList(Geschwister *allGeschwisterList);
Geschwister *mittelgeschwisterOf(int n, const Person *personList);
Geschwister *getAllMittelGeschwister(void);
#endif //COUSINS_H
