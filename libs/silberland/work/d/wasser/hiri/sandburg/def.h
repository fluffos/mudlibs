//#define MAGIERNAME "hiri"
//#include "../def.h"
#define MAGIERNAME "hiri"
#define GEBIET "sandburg"

#include "../def.h"



#ifndef NPC
#define NPC  "/players/"  MAGIERNAME "/" GEBIET "/npc/"
#endif

#ifndef OBJ
#define OBJ   "/players/" MAGIERNAME "/" GEBIET "/obj/"
#endif

#ifndef ROOM
#define ROOM  "/players/" MAGIERNAME "/" GEBIET "/room/"
#endif

#ifndef LOG
#define LOG   "/players/" MAGIERNAME "/" GEBIET "/log/"
#endif

#ifndef SAVEDIR
#define SAVEDIR  "/players/" MAGIERNAME "/" GEBIET "/save/"
#endif

#ifndef ARMOUR
#define ARMOUR  "/players/" MAGIERNAME "/" GEBIET "/armour/"
#endif

#ifndef WEAPON
#define WEAPON  "/players/" MAGIERNAME "/" GEBIET "/weapon/"
#endif

#ifndef DB
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),(x))
#endif

#ifndef HOME
#define HOME "/players/" MAGIERNAME "/"
#endif

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




