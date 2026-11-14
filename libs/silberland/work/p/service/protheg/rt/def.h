
#define RT "/p/service/protheg/rt/"
#define OBJ RT "obj/"
#define RTM RT "master/"
#define STD RT "std/"
#define SOUL RT "soul/"

#define MAGIERNAME "protheg"

#define RACETOOLID "\nPROtheG_Racetool"

#ifndef DB
#define DB(x) if(find_player(MAGIERNAME)) \
                tell_object(find_player(MAGIERNAME),(x))
#endif

#define FM(x, y, z) (x->QueryProp(P_GENDER)==FEMALE ? y : z)

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

#define MOST "/d/wueste/protheg/most/"
#define CLOSURE(x) #'x
