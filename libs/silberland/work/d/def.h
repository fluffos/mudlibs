// File in dem die Anschluesse zwischen den Regionen definert sind
#include "./anschluss.h"

// REGION, MAGIERNAME und GEBIET muessen eine Etage tiefer definiert werden

#ifndef ZONE 
#define ZONE  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/" 
#endif

#ifndef NPC
#define NPC  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/npc/"
#endif

#ifndef OBJ
#define OBJ   "/d/" REGION "/" MAGIERNAME "/" GEBIET "/obj/"
#endif

#ifndef ROOM
#define ROOM  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/room/"
#endif

#ifndef LOG
#define LOG   "/d/" REGION "/" MAGIERNAME "/" GEBIET "/log/"
#endif

#ifndef SAVEDIR
#define SAVEDIR  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/save/"
#endif

#ifndef ARMOUR
#define ARMOUR  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/armour/"
#endif

#ifndef WEAPON
#define WEAPON  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/weapon/"
#endif

#ifndef DB
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),(x))
#endif

//#ifndef HOME
//#define HOME "/players/" MAGIERNAME "/"
//#endif

#include <defines.h>
// ME, PL, RPL, CAP, QPP, IS_CLONE, IS_BLUE, MAX 

#include <moredef.h>
// TELL, CAP, UPPER, LOWER, TO, TP, TPN, TPP, TPPP, CAP_TPN, TI, 
// PO, BS, ENV, MENV, SUID, CLONEME, CLONEOB, CLONE, WLOG, AddProp

#include <properties.h>  // Fast alle Properties
#include <moving.h>      // Konstanten fuer move  
#include <combat.h>      // Schadenstypen und alles fuer den Kampf 
#include <wizlevels.h>   // Magierstufen
#include <new_skills.h>  // fuer Spells
#include <class.h>       // Klassen
#include <mnpc.h>        // Moving Npcs

#include <verben.h>
#include <guard.h>

