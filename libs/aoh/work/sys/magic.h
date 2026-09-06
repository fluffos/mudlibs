// All defines for magic should be here in this file 
#ifndef __MAGIC_H__
#define __MAGIC_H__
#include "combat.h"

// ------------------------------------------------------------
// internal paths and file names for magic things / livings

#define SP_MAIN     "/p/magic/"            // The root directory
#define SP_MOD(x)   SP_MAIN "spells/"+(x)  // The spell modules
#define SP_INI(x)   SP_MAIN "spells/"+(x)  // The config files
#define SP_STD(x)   SP_MAIN "std/" x       // The std stuff

#define P_ISCASTING "IsCasting"            // A living is casting a spell

// ------------------------------------------------------------
// Flags for the spell function calls
// Values of OnFailCasting
#define SP_FAIL     1    // A spell fails due to lack of knowledge
#define SP_BACKFIRE 2    // A spell fails due to resistance of enemy
// Values of CleanUp
#define SP_SUCCESS  1    // Cleanup after successful casting
#define SP_FAILURE  2    // Cleanup after failure in casting

// ------------------------------------------------------------
// pathnames to standard magic stuff (public)
#define SPELL  SP_STD("spell")   // The std-spell object
// -------- STILL NF STUFF ------------------------------------

// standard magic handling objects
#define M_POTION            "/p/magic/std/magic_potion"
#define M_AMULET            "/p/magic/obj/t_amulet"
#define M_RESISTANCE        "/p/magic/std/resistance"
#define M_AIRPORT           "/p/magic/std/stdairport"
#define CASTER              "/obj/caster"
#define INVISARMOUR         "/p/magic/std/invisarmour"
#define MAGICARMOUR         "/p/magic/std/magicarmour"
#define MAGICPROTECTION     "/p/magic/std/magic_defence"
#define STD_TELEPORT        "/p/magic/std/std_teleport"
#define SPELLMONSTER        "/obj/monster/spellmonster" 
#define MAGIC_SCROLL        "/obj/scroll"

// Standard NPCS ... inherit these to give you an easy to use magenpc
#define NPC_DRUID           "/p/magic/std/druidnpc"
#define NPC_SORCERER        "/p/magic/std/sorcerernpc"
#define NPC_WITCH           "/p/magic/std/witchnpc"


// usually this files are only of interest for the magic depertement
#define MAGIC_CARPET        "/p/magic/std/carpet"  // inherit but do not clone
#define GL_SPELLMASTER      "/obj/spellmaster"
#define SPELLBOOK           MAGIC_OBJ_DIR+"spellbook"
#define INCREASER           "sfbincreaser"
#define DEFENDER            "sfbdefender"
#define SCROLL_REMOVER       MAGIC_OBJ_DIR+"scrollremover"
#define MAGENPC             "/d/woodland/common/magicnpc/magenpc"

// should actually go to woodland/sys I think
#define MAGIC_DIR           "/d/woodland/common/"
#define MAGIC_OBJ_DIR       MAGIC_DIR + "magicobj/"
#define MAGIC_NPC_DIR       MAGIC_DIR + "magicnpc/"
#define MAGIC_SCROLL_DIR    MAGIC_DIR + "scrolls/"

// what kind of standard potions do you have
#define POTION_HEALING     1   // restore HP 
#define POTION_MAGIC       2   // restore SP
#define POTION_POISON      3   // poison player
#define POTION_HEALPOISON  4   // heal posion
#define POTION_VIGOR       5   // restore EP
#define POTION_SATIATE     6   // add food
#define POTION_INTOXICATE  7   // add alcohol
#define POTION_SLEEPING    8   // let player fall asleep

// values for the official carpet networks
#define NETWORK_LLP  0   // large network throughout whole NF
#define NETWORK_SMALL  1   // a smaller restricted network throughout whole NF
#define NETWORK_HLP    2   // connects some HLP locations like ellil
#define NETWORK_WOODLAND  3   // connects some Woodland locations for cheap price


// values for teleport forbid property */
#define TPORT_NO   0		// No teleport allowed
#define TPORT_IN   1		// Only telport in allowed
#define TPORT_OUT  2		// Only teleport out allowed
#define TPORT_BOTH (TPORT_IN | TPORT_OUT) // default

// Minimal Teleportkosten in Spellpoints
#define TELEPORT_COST  50

// Defines for the STD_TELEPORT
#define TP_NO_SP       1        // Caster has not enough SP
#define TP_NO_LEVEL    2        // Level of caster is to low
#define TP_IS_WIZ      3        // Target is a wizard
#define TP_NO_AMULET   4        // Target has no teleport amulet
#define TP_AMULET_OFF  5        // Amulet of Target is switched off
#define TP_IS_FIGHTING 6        // Target is fighting
#define TP_OK          7        // everything is fine

// rules the use of the P_MAGIC Property - outdated

#define MAGIC_NO      0x0000    // No Magic

#define MAGIC_LOW     0x0001    // Low magic < Lvl 8
#define MAGIC_MED     0x0002    // Lvl 8 <= Medium magic <= Lvl 16
#define MAGIC_HI      0x0003    // Lvl 16 < High Magic

#define MAGIC_WEAPON  0x0004    // Any sort of attacking
#define MAGIC_ARMOUR  0x0008    // Any sort of shielding
#define MAGIC_LIGHT   0x0010    // A magic lightsource
#define MAGIC_MOVE    0x0020    // IF magic moves things
#define MAGIC_DUR     0x0040    // for spells with duration
#define MAGIC_CREATE  0x0080    // for magic creating any items

// Spell types

#define ST_ALL        0			// All kind of spells 

#define ST_DAMAGE     DT_MAGIC          // First attack spell
#define ST_FIRE       DT_FIRE           // fire spells of any kind
#define ST_COLD       DT_COLD        	// spells which produce coldness
#define ST_WATER      DT_WATER       	// water damage (hot water)
#define ST_GAS        DT_GAS         	// poison gas 
#define ST_POISON     DT_POISON        	// poison .... 
#define ST_ZAP        DT_ZAP         	// Destruct one/more LIVING(s)
#define ST_ELECTRO    DT_ELECTRO      	// Electrical damage          
#define ST_ACID       DT_ACID      	// splash of acid damage          
#define ST_PSYCHO     DT_PSYCHO      	// Mind damages

#define ST_OTHER      (32)              // All other non attack spelltypes
#define ST_KNOW       (ST_OTHER +  2)	// Increases knowledge
#define ST_PROTECT    (ST_OTHER +  3)	// protects you from something
#define ST_HEAL       (ST_OTHER + 4)	// healing spells
#define ST_CREATE     (ST_OTHER + 5)	// you can create something with them
#define ST_SUMMON     (ST_OTHER + 6)	// you can summon something
#define ST_TELEPORT   (ST_OTHER + 7)	// teleport spells
#define ST_INFLUENCE  (ST_OTHER + 8)	// mind influence spells
#define ST_CHARM      ST_INFLUENCE      // charm is influence
#define ST_LIGHT      (ST_OTHER + 9)	// cast light spells
#define ST_CHANGE     (ST_OTHER + 10)	// change items/objects/livings/props
#define ST_DARK       (ST_OTHER + 11)	// dark (evil) spells
#define ST_DESTRUCT   (ST_OTHER + 12)   // destruct a THING
#define ST_FUN        (ST_OTHER + 13)   // FUN Spells

/* flag values for the success function (>0: Success, <0: fail */
#define CAST_FAIL_MSG -1      /* failed in castfun, cast will write message */
#define CAST_FAIL_NOMSG -2    /* failed in castfun, no message */
#define CAST_CHECK_FAIL -3    /* failed in Checkfailfunktions */
#define CAST_ALLOW_FAIL -4    /* failed in allowance checks */
#define CAST_SUCCESS 1        /* cast successful */
#define CAST_REPULSE 2        /* cast successful but repulsed */

/* Magic formulas */
#define MAGIC_WISDOM(x,y) (35*x+315-4*y) // x = caster->WIS, y=SPELL->failchance

#endif // __MAGIC_H__
