#include "/d/dschungel/def.h"
#include "/d/dschungel/charon/charon_def.h"

#define FALLANASSITEMPEL(x)    ("/d/dschungel/charon/tempel/"+x)
#define FT_ROOM(x)            FALLANASSITEMPEL("room/"+x)
#define FT_NPC(x)             FALLANASSITEMPEL("npc/"+x)
#define FT_OBJ(x)             FALLANASSITEMPEL("obj/"+x)
#define FT_WEAPON(x)          FALLANASSITEMPEL("weapon/"+x)

#define FT_TEMPEL_SCHLOSS     FT_OBJ("tempelschloss.txt")
/* #define FT_TRAP_2_ITEM        FT_OBJ("ft_trap_2_item")*/

/* Entschaerfung fuer die Fallen */
#define FT_TRAP_2_DISABLED    0x01
#define FT_TRAP_4_DISABLED    0x02
#define FT_TRAP_5_DISABLED    0x04
#define FT_TRAP_8_DISABLED    0x08

/* Defines, die Mehrspielermodus ermoeglichen */
#define FT_UNT_DSCHUNGEL      0x10

#define FT_QUESTITEM          present("\nft_questitem", TP)
#define FT_STONE(x)           deep_present(x, TP)
#define FT_TRAP(x)            deep_present(x, TP)

#define FT_BRECHEISEN         deep_present("\nft_brecheisen", TP)

#define NOT_PLAYING_QUEST    "Du solltest die Quest vielleicht erst einmal" \
                             " beginnen, bevor Du hier so frisch und frei"  \
                             " alles genauer betrachtest, ohne vorsichtig"  \
                             " sein."