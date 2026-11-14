#include <properties.h>  // Fast alle Properties
#include <language.h>    // MALE, FEMALE
#include <moving.h>      // Konstanten fuer move  
#include <combat.h>      // Schadenstypen und alles fuer den Kampf 
#include <wizlevels.h>   // Magierstufen
#include <new_skills.h>  // fuer Spells

#include <defines.h>		 // definiert in /sys
// ME, PL, RPL, CAP, QPP, IS_CLONE, IS_BLUE, MAX 

#include <moredef.h>		 // definiert in /sys
// TELL, CAP, UPPER, LOWER, TO, TP, TPN, TPP, TPPP, CAP_TPN, TI, 
// PO, BS, ENV, MENV, SUID, CLONEME, CLONEOB, CLONE, WLOG, AddProp

#define TRUE   1
#define FALSE  0

#define ES     0
#define ER     1
#define SIE    2
#define ID     "userid"

#define PlayerAlign  this_player()->QueryProp(P_ALIGN)
#define PlayerGender this_player()->QueryProp(P_GENDER)

/*
#define HOME(x)    "/players/charon"+x
#define ROOM(x)    HOME("room/")+x
#define OBJ(x)     HOME("obj/")+x
#define WEAPON(x)  HOME("weapon/")+x
#define NPC(x)     HOME("npc/")+x
#define WEG(x)     ROOM("weg/")+x
#define LOGFILE    "charon.log"
*/

#define MAGIERNAME "charon"
#define QUESTERZ   "muaddib"
                    
#define DBM(x) if(find_player(QUESTERZ))   tell_object(find_player(QUESTERZ),x);

#ifndef DB
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),x);
#endif 
