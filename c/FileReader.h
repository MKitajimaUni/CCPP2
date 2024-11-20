//
// Created by Mitsuhiro Kitajima on 24/10/25.
//
#ifndef FILEREADER_H
#define FILEREADER_H

typedef struct {
    char vorname[20];
    char nachname[20];
    char geschlecht;
    unsigned int geburtsjahr;
    unsigned int todesjahr;
    char vaterVorname[20];
    char vaterNachname[20];
    unsigned int vaterGeburtsjahr;
    char mutterVorname[20];
    char mutterNachname[20];
    unsigned int mutterGeburtsjahr;
} Person;

typedef struct {
    char typ;
    unsigned int jahrDerStandesaenderung;
    char gatteVorname[20];
    char gatteNachname[20];
    unsigned int gatteGeburtsjahr;
    char gattinVorname[20];
    char gattinNachname[20];
    unsigned int gattinGeburtsjahr;
}Stand;

Person *readAndStorePerson();
Stand *readAndStoreStand();
unsigned int getPersonenLength();
unsigned int getStandLength();

#endif //FILEREADER_H
