/*
  files.h
*/

#define DEBUG(x,y) if (find_player("creative")) tell_object(find_player("creative"), "|**"+x+"**| "+y+"\n")

#define PATH "/d/wasser/creative/schmuggler/"
#define STD(x) PATH+"std/"+x
#define ROOM(x) PATH+"room/"+x
#define OBJ(x) PATH+"obj/"+x
#define NPC(x) PATH+"npc/"+x
#define LOG(x) PATH+"log/"+x
#define WEAPON(x) PATH+"weapon/"+x
#define ARMOUR(x) PATH+"armour/"+x

#define STARTROOM ROOM("d1_1")

#define CAP capitalize
#define TO this_object()
#define TP this_player()
#define PO previous_object()
#define TPN TP->QueryProp(P_NAME)
#define TI this_interactive()
#define BS(x) break_string(x, 78)
#define TIPO (this_interactive() || previous_object())
#define ENV environment

#define GHOSTWRITERS ({ "creative", "kia" })

#define SCHMUGGLER_WARE_WERT 25
#define SCHMUGGLER_QUESTOB "\nschmuggler_ob"
#define SCHMUGGLER_MILCH "\nschmuggler_milchkaennchen"
#define SCHMUGGLER_BRIEF "\nschmuggler_brief"
#define SCHMUGGLER_BUCH "\nschmuggler_buch"
#define SCHMUGGLER_ELIXIER "\nschmuggler_elixier"
#define SCHMUGGLER_MURMELBEUTEL "\nschmuggler_murmelbeutel"
#define SCHMUGGLER_MURMEL "\nschmuggler_murmel"

#define SCHMUGGLER_WARE ({ \
    OBJ("buch"), \
    OBJ("elixier"), \
    OBJ("kaennchen"), \
    })
#define SCHMUGGLER_WARE_ABNEHMER ({ \
    "/d/ebene/Midas/npc/albin", \
    "/d/kristallwald/sargola/dorf/npc/aerendil", \
    "/d/wasser/stahldorn/quest/questnpc" \
    })
#define SCHMUGGLER_GEMS ({ \
    OBJ("saphir"), \
    OBJ("smaragd"), \
    OBJ("tigerauge"), \
    OBJ("rubin") \
    })
#define SCHMUGGLER_GEM_ROOMS ({ \
    ROOM("d1_1"), \
    ROOM("b3_2"), \
    ROOM("c7_2"), \
    ROOM("f4_1"), \
    })
#define MIDAS_LAGER "/d/ebene/Midas/room/lagerraum"
#define DERLIM_LAGER "/d/huegelland/raballion/hobbits/room/store"
#define ELESSAR_LAGER "/d/kristallwald/sargola/dorf/room/lagerrau"

// Queststatus

#define SCHMUGGLER_WARE_VERKAUFT 0x1
#define SCHMUGGLER_BRIEF_ERHALTEN 0x2
#define SCHMUGGLER_BOOT_BEKOMMEN 0x4
#define SCHMUGGLER_RUDER_ERHALTEN 0x8
#define SCHMUGGLER_MURMEL_GESPIELT 0x16

