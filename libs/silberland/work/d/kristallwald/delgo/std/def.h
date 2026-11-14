// diverse Compilerpruefungen einschalten
#pragma strong_types

//Name des Gebietes angeben
#define GEBIET "std"

//ergaenzende Defines
#define STD_NPCS "/d/" REGION "/" MAGIERNAME "/" GEBIET "/std_npcs/"

//uebegeordnete Definitionen laden
#include "../def.h"

//die DeBugReports
#define DBD(x) if (find_player("delgo")) tell_object(find_player("delgo"),(""+x+"\n"))