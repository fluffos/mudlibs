// diverse Compilerpruefungen einschalten
#pragma strong_types
//Magiername angeben
#define MAGIERNAME "delgo"
//uebergeordnete Definitionen laden
#include "../def.h"
//die anschlusspfade laden
#include "./anschluss.h"
//die DeBugReports
#define DBR(x) if (find_player("delgo")) tell_object(find_player("delgo"),(""+x+"\n"))
//Der laecherliche Rest, der in den uebergeordnetetn nicht geladen wurde
#include <language.h>    
#include "/sys/room/description.h"



