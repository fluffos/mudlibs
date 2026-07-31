#include "animal.h"

mapping animal_info = ([
    "name" : "Ст",
    "id" : "sheep",
    "time" : 5400,
    "meat" : 5,
    "meat_name" : "yangrou",
]);

void create()
{
    create_animal(animal_info);
}