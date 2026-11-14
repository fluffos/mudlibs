// SilberLand MUDlib
//
// gilden/itemd/itemd_secure.h
//
// $Date$
/* $Revision$
 * $Log$
*/


#define OWNER ({"feyaria", "angrox", "wraz"})
#define ITEMD_RESTORE_ALLOWED ({"/d/ebene/creative/feldlager/npc/bodenstab"})
//#define BASIC_MIN_CHANCE 130
//#define BASIC_MAX_CHANCE 50 
#define BASIC_MIN_CHANCE 350 
#define BASIC_MAX_CHANCE 120 
#define PROBABILITY_DIVISOR 3.0 // Wahrsch. = Anzahl der Items / Divisor
#define PROBABILITIES ({5000,3.1,8500,1.8,9500,0.8,9933,0.30,10000}) // Wahrsch.

// Fuer zusaetzliche Items nach gewisser Anzahl ident. Items ohne magic items 
#define EXTRA_COUNT_MULTIPLIER 2
#define EXTRA_MAX_COUNT 300

// hoehere Chancen
//#define ITEMD_UNIQUE_CHANCE 100000
//#define ITEMD_SET_CHANCE 50000 
//#define ITEMD_RARE_CHANCE 4000
#define ITEMD_SOCKETED_CHANCE 400
#define ITEMD_RUNE_CHANCE 200
//#define ITEMD_TALISMAN_CHANCE 266


// niedrige Chancen
#define ITEMD_UNIQUE_CHANCE 300000
#define ITEMD_SET_CHANCE 90000
#define ITEMD_RARE_CHANCE 10666
//#define ITEMD_SOCKETED_CHANCE 700
//#define ITEMD_RUNE_CHANCE 600
#define ITEMD_TALISMAN_CHANCE 400



// Wahrscheinlichkeit das ein Zeichen eingraviert ist
#define SIGN_PROB 15

// Zeit in Minuten die man nach dem Fund eines Magic Items keine
// weiteren finden kann
#define BASE_TIME 2 
//#define RARE_TIME 30
#define RARE_TIME 0
#define SET_TIME 50
#define UNIQUE_TIME 200


// Anzahl der maximalen Items
// Normale Magic Items
#define LOW_MAX    75
#define MED_MAX   125
#define HIGH_MAX  100 
#define VHIGH_MAX  60
#define GODLY_MAX  20
// Extra Items
#define SET_MAX   125
#define SOC_MAX    75 
#define RAR_MAX    35
#define UNIQUE_MAX 10
// Runen
//#define RUNE_MAX  400

// Persoenliches Magic Item Limit - Punktesystem
#define P_MIV          "mi_value"
#define MIV_LOW        1
#define MIV_MED        3
#define MIV_HIGH       5
#define MIV_VHIGH      8
#define MIV_GODLY     15
#define MIV_RWORD3     7 // Ab hier: Sockel-Items, Runenwort 3
#define MIV_RWORD2     6 // Runenwort 2
#define MIV_RWORD      5 // Runenwort 1
#define MIV_NO_RWORD   3 // Runen, aber kein Wort
#define MIV_NO_RUNE    2 // Keine Runen (zB Edelsteine)

// Runenalter (in Sekunden)
//#define RUNE_MAX_AGE 22118400 // == 256 Tage
#define RUNE_MAX_AGE_LOW    31622400 // ==  366 Tage
#define RUNE_MAX_AGE_MED    31622400 // ==  366 Tage
#define RUNE_MAX_AGE_HIGH   31622400 // ==  366 Tage
#define RUNE_MAX_AGE_VHIGH  31622400 // ==  366 Tage
#define RUNE_MAX_AGE_GODLY  44236800 // ==  512 Tage

// Maximalwerte
#define MAX_WC_FIX 75
#define MAX_WC_FIX2 50
#define MAX_WEAPON_CLASS1 200
#define MAX_CALCULATE_WC 155
#define SET_COUNTER 25 

// SK_LUCK Skillwerte
#define LUCK_LEARN_DIFF -10000
#define LUCK_USE_DIFF 500


// Spieler und IPs, die keine Magic Items finden duerfen
#define ITEMD_CANT_FIND_ITEMS ({})
#define ITEMD_IPNET_CANT_FIND_ITEMS ({})

// #define ITEMD_CANT_FIND_UNIQUE ({"karpfen"})
#define ITEMD_CANT_FIND_UNIQUE ({})
#define ITEMD_IPNET_CANT_FIND_UNIQUE ({})

#define ITEMD_CANT_FIND_SET ({})
#define ITEMD_IPNET_CANT_FIND_SET ({})

// #define ITEMD_CANT_FIND_RARE ({"karpfen"})
#define ITEMD_CANT_FIND_RARE ({})
#define ITEMD_IPNET_CANT_FIND_RARE ({})

#define ITEMD_CANT_FIND_SOCKET ({})
#define ITEMD_IPNET_CANT_FIND_SOCKET ({})

#define ITEMD_CANT_FIND_MAGIC ({})
#define ITEMD_IPNET_CANT_FIND_MAGIC ({})

// Wer darf externe Rare erzeugen
#define ALLOW_RARES_FROM_EXTERNAL ({\
        "/d/ebene/creative/ivory_tiger/obj/imbue",\
        })

// Wer darf externe Sets clonen
#define ALLOW_SETS_FROM_EXTERNAL ({\
        "/d/astral/lamuerte/brunnen/frags/fragmaster",\
        })

// Wer darf magic Items direkt setzen
#define ALLOW_SETMAGIC_FROM_EXTERNAL ({\
        "/p/std/skills/sewing_tanning/naehkaestchen",\
        "/d/astral/feyaria/elysia/obj/mi_maker",\
        })

// Items die nicht zerstoert werden, wenn sie kein living env haben
#define NOREMOVE ({\
    "/gilden/paladine/weapon/standarte",\
    })

//#define DISABLE_UNIQUE_ITEMS 1 
//#define DISABLE_SET_ITEMS 1 
//#define DISABLE_RARE_ITEMS 1 
//#define DISABLE_SOCKET_ITEMS 1 
//#define DISABLE_MAGIC_ITEMS 1
//#define ENABLE_FULL_DEBUG 1

#define CAIN_COST 3000
