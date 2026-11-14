//fisch defines usw fuer quest


#define KOBJ "/d/dschungel/dante/fisch/kannibalen/obj/"
#define KARMOUR "/d/dschungel/dante/fisch/kannibalen/armour/"
#define KWEAPON "/d/dschungel/dante/fisch/kannibalen/weapon/"
#define KROOM "/d/dschungel/dante/fisch/kannibalen/room/"
#define KNPC "/d/dschungel/dante/fisch/kannibalen/npc/"

#define NPC_WEG "/d/dschungel/dante/weg/npc/"
#define WEAPON_WEG "/d/dschungel/dante/weg/weapon/"
#define ARMOUR_WEG "/d/dschungel/dante/weg/armour/"
#define OBJ_WEG "/d/dschungel/dante/weg/obj/"


#define NOLIST if(!present("DANTE_FISCH_LISTE_VIER", TP))  { write(BS("Irgendwie funktioniert das hier nicht. Du musst sicher zuerst andere Aufgaben erfuellen!")); return 1; }

#include "/players/dante/myowndefine.h"
