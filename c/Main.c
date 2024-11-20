//
// Created by Mitsuhiro Kitajima on 24/10/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "FileReader.h"
#include "Cousins.h"

int main() {

    Geschwister *allGeschwisterList = getAllMittelGeschwister();
    printGeschwisterList(allGeschwisterList);
    return 0;
}