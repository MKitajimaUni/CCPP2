//
// Created by Mitsuhiro Kitajima on 24/10/25.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Cousins.h"
#include "FileReader.h"

//get all cousins and stepbrother/sisters of n-th row
Geschwister *mittelgeschwisterOf(const int n, const Person *personList) {
    unsigned int pLength = getPersonenLength();
    Geschwister *geschwisterList = malloc(pLength * sizeof(Geschwister));
    if (geschwisterList == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int count = 0; //number of cousins

    if (personList[n].vaterVorname[0] == '-') { // return null if there's no information about parents
        free(geschwisterList);
        return NULL;
    }

    for (int i = 0; i < pLength; i++) {
        if ((strcmp(personList[n].vaterVorname, personList[i].vaterVorname) == 0 &&
             strcmp(personList[n].vaterNachname, personList[i].vaterNachname) == 0) ||
            (strcmp(personList[n].mutterVorname, personList[i].mutterVorname) == 0 &&
             strcmp(personList[n].mutterNachname, personList[i].mutterNachname) == 0)) {
            for (int j = 0; j < 20; j++) {
                geschwisterList[count].vorname[j] = personList[i].vorname[j];
                geschwisterList[count].nachname[j] = personList[i].nachname[j];
            }
            geschwisterList[count].geburtsjahr = personList[i].geburtsjahr;

            count++;
        }
    }

    if (count > 2) {
        sortByGeburtsjahr(count, geschwisterList);
        Geschwister *fixedGeschwisterList = malloc((count - 2) * sizeof(Geschwister));
        if (fixedGeschwisterList == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        for (int i = 1; i < count - 1; i++)
            *(fixedGeschwisterList + (i - 1)) = *(geschwisterList + i);

        free(geschwisterList);
        return fixedGeschwisterList;
    }

    free(geschwisterList);
    return NULL;
}

Geschwister *getAllMittelGeschwister() {
    int count = 0; // length of allGeschwisterList
    unsigned int length = getPersonenLength();
    Geschwister *allGeschwisterList = malloc(length * sizeof(Geschwister));
    if (allGeschwisterList == NULL) {
        printf("Memory allocation failed\n"); exit(1);
    }

    Person *personPtr = readAndStorePerson();
    if (personPtr == NULL) {
        printf("Memory allocation failed\n"); exit(1);
    }

    for (int i = 0; i < length; i++) {
        Geschwister *geschwisterPtr = mittelgeschwisterOf(i, personPtr);

        if (geschwisterPtr != NULL) {
            int isSame = 0;
            for (int j = 0; allGeschwisterList[j].vorname[0] != '\0'; j++) {
                if (strcmp(geschwisterPtr->vorname, (allGeschwisterList + j)->vorname) == 0 &&
                    strcmp(geschwisterPtr->nachname, (allGeschwisterList + j)->nachname) == 0 &&
                    geschwisterPtr->geburtsjahr == (allGeschwisterList + j)->geburtsjahr) {
                    isSame = 1;
                    break;
                }
            }

            if (isSame == 0) {
                for (int k = 0; (geschwisterPtr + k)->geburtsjahr != 0; k++) {
                    *(allGeschwisterList + count) = *(geschwisterPtr + k);
                    count++;
                }
            }
            free(geschwisterPtr);
        }
    }

    sortByName(count, allGeschwisterList);

    free(personPtr);
    return allGeschwisterList;
}

int compareInt(const void *a, const void *b) {
   return *(unsigned int *)a - *(unsigned int *)b;
}

int compareName(const void *a, const void *b) {
    Geschwister *gesA = (Geschwister *)a;
    Geschwister *gesB = (Geschwister *)b;
    return strcmp(gesA->vorname, gesB->vorname);
}

// sort by the year of birth
void sortByGeburtsjahr(const int length, Geschwister *geschwisterList) {
    qsort(geschwisterList, length, sizeof(Geschwister), compareInt);
}

// sort by the alphabetical order of first name
void sortByName(const int length, Geschwister *geschwisterList) {
    qsort(geschwisterList, length, sizeof(Geschwister), compareName);
}

void printGeschwisterList(Geschwister *allGeschwisterList) {
    for (int i =0; (allGeschwisterList + i)->vorname[0] != '\0'; i++) {
        printf("%s %s %d %d\n",
            allGeschwisterList[i].vorname,
            allGeschwisterList[i].nachname,
            allGeschwisterList[i].geburtsjahr,
            i);
    }
}
