/*
 Rev 1.0 19.11.2003 Archon: erstellt
*/

#ifndef __D_NEKRO_H__
#define __D_NEKRO_H__


#define GEBIET "nekromanten"

#ifndef NPC
#define NPC "/d/unterwelt/" GEBIET "/npc/"
#endif

#ifndef OBJ
#define OBJ  "/d/unterwelt/" GEBIET "/obj/"
#endif

#ifndef ROOM
#define ROOM "/d/unterwelt/" GEBIET "/room/"
#endif

#ifndef LOG
#define LOG  "/d/unterwelt/" GEBIET "/log/"
#endif

#ifndef SAVEDIR
#define SAVEDIR "/d/unterwelt/" GEBIET "/save/"
#endif

#ifndef ARMOUR
#define ARMOUR "/d/unterwelt/" GEBIET "/armour/"
#endif

#ifndef WEAPON
#define WEAPON "/d/unterwelt/" GEBIET "/weapon/"
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

#include <properties.h> // Fast alle Properties
#include <moving.h>   // Konstanten fuer move 
#include <combat.h>   // Schadenstypen und alles fuer den Kampf 
#include <wizlevels.h>  // Magierstufen
#include <new_skills.h> // fuer Spells
#include <class.h>    // Klassen
#include <mnpc.h>    // Moving Npcs

#include <verben.h>
#include <guard.h>


#include "/players/archon/standard/standard.h"


#endif
