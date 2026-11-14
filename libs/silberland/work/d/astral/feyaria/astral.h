#ifndef __ASTRAL_H
#define __ASTRAL_H

#undef DB

#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),(x)); else if (find_player("wumanzu")) tell_object(find_player("wumanzu"), (x))

#include <ansi.h>

#define GRAVEYARD "/d/astral/feyaria/astral/room/friedhof"
#define NEXUS "/d/astral/feyaria/astral/room/nexus"
#define STDROOM "/d/astral/feyaria/std/room"
#define STDNPC "/d/astral/feyaria/std/npc"

#define ENTER_MECHANUS "/d/astral/feyaria/mechanus/room/eingang"
#define ENTER_DJINNISTAN "/d/astral/feyaria/djinnistan/room/luftkneipe"
#define ENTER_INFERNO "/d/astral/feyaria/inferno/room/feuerkneipe"
#define ENTER_AQUATIKA "/d/astral/feyaria/aquatika/room/wasserkneipe"
#define ENTER_FROSTANIA "/d/astral/feyaria/frostania/room/eiskneipe"
#define ENTER_DRACONIA "/d/astral/feyaria/draconia/room/8x12y"
#define ENTER_ELYSIA "/d/astral/feyaria/elysia/room/eingang"
#define ENTER_ABGRUND "/d/astral/feyaria/abgrund/room/abgrund:1:0:0"
#define ENTER_TIME "/d/astral/feyaria/eternia/room/eingang"

#define MECHANUS_ASTRAL "/d/astral/feyaria/astral/room/astral53"

#define GROUPSIZE 8
#define GROUPSIZE2 10 

#define P_ASTRAL_RARE_NPC "astral_rare_npc"
#define P_ASTRAL_DIE_ZONE "astral_die_zone"

#define MECHANUSMASTER "/d/astral/feyaria/mechanus/master/mechanusmaster"

#define MONEY_FACTOR 100

#define WSALBE "/d/astral/feyaria/frostania/obj/wsalbe"
#define WSALBE_CHANCE (123 - PO->QueryProp(P_LEVEL))

#define RSALBE "/d/astral/feyaria/frostania/obj/rsalbe"
#define RSALBE_CHANCE (66 - PO->QueryProp(P_LEVEL)/2)

#define SALBE "/d/astral/feyaria/draconia/obj/salbe"
#define SALBENOBJ "/d/astral/feyaria/draconia/obj/salbenobj"

#define MAGIC_WANDS \
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/revive")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Wiederbelebung) von " + PO->name(WEM));\
}\
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/heal")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Heilung) von " + PO->name(WEM));\
}\
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/damage")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Schaden) von " + PO->name(WEM));\
}\
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/restoration")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Restoration) von " + PO->name(WEM));\
}\
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/regen")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Regeneration) von " + PO->name(WEM));\
}\
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/teleport")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Teleport) von " + PO->name(WEM));\
}\
else if (!random(234 - 2 * PO->QueryProp(P_LEVEL)))\
{\
  clone_object("/d/astral/feyaria/draconia/obj/ident")->move(PO, 2); \
  WLOG(LOG "wands", "findet einen Zauberstab (Identifizierung) von " + PO->name(WEM));\
}

#define PUREMAGIC "/d/astral/feyaria/elysia/obj/mi_maker"
#define PUREMAGIC_CHANCE 1
#define ESSENZ "/d/astral/feyaria/elysia/obj/essenz"
#define RGA "/d/dschungel/feyaria/sumpf/armour/race_guild_armour"
#define RGA_CHANCE 1

#define BOSS_LOOT \
    if (!random(PUREMAGIC_CHANCE))\
    {\
      CLONE(PUREMAGIC, PO );\
    }\
    if (!random(RGA_CHANCE))\
    {\
      CLONE(RGA, PO );\
    }\
    CLONE(ESSENZ, PO );\
    CLONE(WSALBE, PO );\
    CLONE(RSALBE, PO );\
    CLONE(SALBE, PO );

#define CLONELOG(x,y) {clone_object(x)->move(y,2); \
  WLOG(LOG "items", "findet " + explode(x, "/")[<1] + " von " + y->name(WEM));}

#define GEMARRAY ({"diamant","rubin","saphir", "smaragd",\
    "okatarin", "zirkon", "aquamarin", "opal", "jadeit", "amethyst",\
    "tigerauge", "opal", "topas", "granat", "onyx", "bernstein",\
    "lapislazuli", "turmalin", "bergkristall", "peridot"})

#ifndef GEMMASTER
#define GEMMASTER "/obj/gemmaster"
#endif

#ifndef PEARLMASTER
#define PEARLMASTER "/obj/pearlmaster"
#endif

#define ASTRALMASTER "/d/astral/feyaria/astral/master/astralmaster"

#define FLAG_LUXIANA 1
#define FLAG_PRIMUS 2
#define FLAG_KALIF 4
#define FLAG_PADISHA 8
#define FLAG_SULTAN 16
#define FLAG_KHAN 32
#define FLAG_VULAK 64
#define FLAG_DEMON 128
#define FLAG_ELYSIA 256
#define FLAG_TIME 511
#define FLAG_ZERBUXORUK 512

#define ITEMD_DFC "/p/daemon/itemd/functions/defendfunc"
#define ITEMD_HFC "/p/daemon/itemd/functions/hitfunc"
#define ITEMD_AFC "/p/daemon/itemd/functions/attr_mod"

#define P_ZONE "zone"
#define P_SUBDOMAIN "subdomain"

#define ALLOWED_ZONES ({"astral", "mechanus", "djinnistan", "frostania", \
    "inferno", "aquatika", "elysia", "draconia", "abgrund", "eternia"})

#define CORRUPTOR "/d/astral/feyaria/astral/npc/corruptor"

#define ALLOWED_UIDS ({"d.astral.feyaria", "feyaria", "d.dschungel.feyaria", "aaliyah",\
                       "GUILD.zechpreller"})

#ifndef AddGenderDetail
#define AddGenderDetail(x, y, z)  \
  AddDetail( x, lambda(0,({#'sprintf,"%s",\
        ({#'?,({#'==, ({#'call_other, ({#'this_player}), \
                       "QueryProp", P_GENDER}), FEMALE}),\
                  break_string(y), break_string(z) })})));
#endif 

#define GELD(x, y) \
  {\
    object money;\
    money = clone_object("/obj/money");\
    money->AddAmount(x);\
    money->move(y, 2);\
  }


#endif
