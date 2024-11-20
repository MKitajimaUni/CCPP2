//
// Created by Mitsuhiro Kitajima on 24/10/25.
//

#include "FileReader.h"
#include <stdio.h>
#include <stdlib.h>

Person *readAndStorePerson() {
    // open two files in read only mode.
    // using absolute path of local computer. should be fixed in another environment
    char *pFileName = "/Users/kitajimamitsuhiro/Desktop/codes/3.semester/Programmierensprache/CCPP2/c/personen.dat";
    FILE *personenFile = fopen(pFileName, "r");

    if (personenFile == NULL) {
        printf("Error open file\n");
    }

    // make a buffer to store the string from each row
    char buffer[200];

    // reserve a memory space for the list of person and stand
    Person *personList = malloc(sizeof(Person) * getPersonenLength());

    //store the information of each person.
    //each data is separated with space ' '.
    int index = 0;
    while (fgets(buffer, 200, personenFile)) {
        sscanf(buffer, "%100s %100s %c %100d %100d %100s %100s %100d %100s %100s %100d",
               personList[index].vorname,
               personList[index].nachname,
               &personList[index].geschlecht,
               &personList[index].geburtsjahr,
               &personList[index].todesjahr,
               personList[index].vaterVorname,
               personList[index].vaterNachname,
               &personList[index].vaterGeburtsjahr,
               personList[index].mutterVorname,
               personList[index].mutterNachname,
               &personList[index].mutterGeburtsjahr);
        index++;
    }

    fclose(personenFile);

    return personList;
}

unsigned int getPersonenLength() {
    char *pFileName = "/Users/kitajimamitsuhiro/Desktop/codes/3.semester/Programmierensprache/CCPP2/c/personen.dat";
    FILE *personenFile = fopen(pFileName, "r");

    if (personenFile == NULL) {
        printf("Error open file\n");
    }

    // get the number of lines
    char buffer[200];
    int pLineCount = 0;
    while (fgets(buffer, 200, personenFile))
        pLineCount++;

    fclose(personenFile);
    return pLineCount;
}

unsigned int getStandLength() {
    char *sFileName = "/Users/kitajimamitsuhiro/Desktop/codes/3.semester/Programmierensprache/CCPP2/c/stand.txt";
    FILE *standFile = fopen(sFileName, "r");

    if (standFile == NULL) {
        printf("Error open file\n");
    }

    char buffer[200];
    int pLineCount = 0;
    int sLineCount = 0;
    while (fgets(buffer, 200, standFile))
        sLineCount++;

    fclose(standFile);
    return sLineCount;
}
