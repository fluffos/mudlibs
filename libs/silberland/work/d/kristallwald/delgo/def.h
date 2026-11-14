// diverse Compilerpruefungen einschalten
#pragma strong_types
//Magiername angeben
#define MAGIERNAME "delgo"

#ifndef DOC
#define DOC  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/doc/"
#endif

// Npc-Master ansprechen
#define NPC_MASTER "/d/" REGION "/" MAGIERNAME "/std/master/master"
#define REGISTER_ME NPC_MASTER->RegisterNpc(TO)

//uebergeordnete Definitionen laden
#include "../def.h"
//die anschlusspfade laden
#include "./anschluss.h"
//die DeBugReports
#define DBR(x) if (find_player("delgo")) tell_object(find_player("delgo"),(""+x+"\n"))
//Der Rest, der in den uebergeordnetetn nicht geladen wurde
#include <language.h>  
#include <ansi.h>  
#include "/sys/room/description.h"



