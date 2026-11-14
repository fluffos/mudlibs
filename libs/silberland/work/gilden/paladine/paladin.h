#include <defines.h>
#include <moredef.h>
#include "paladin_extern.h"

#define SPELLS(x) "/spellbook"
#define PALADINSPELLBOOK SPELLS("pal_spells")
#define PALADIN(x) "/gilden/paladine/"+x
#define NPC(x) PALADIN("npc/"+x)
#define WAYD "/p/daemon/wayd/wayd"
#define ARMOUR(x) PALADIN("armour/"+x)
#define WEAPON(x) PALADIN("weapon/"+x)
#define OBJ(x) PALADIN("obj/"+x)
#define LOG(x) PALADIN("log/"+x)
#define MEMBERLOG(x) PALADIN("members_log/"+x)
#define ROOM(x) PALADIN("room/"+x)
#define ANSCHLUSSWEG "/d/gebirge/impulz/paladinweg/room/weg_1"
#define LIBS(x) PALADIN("libs/"+x)
#define BACKUP(x) PALADIN("backup/"+x)
#define SONG(x) PALADIN("seq/song/"+x)

#define PAL_WAFFENSEGEN "pal_waffensegen"
#define PAL_RUESTUNGSSEGEN "pal_ruestungssegen"
#define PAL_PRAYROOM "pal_prayroom"

#define NPCMASTER PALADIN("master/npcmaster")
#define PALADINMASTER PALADIN("master/paladinmaster")
#define GUILD_MASTER PALADINMASTER
#define TALENTMASTER "/gilden/paladine/master/talentmaster"

#define SAVEMASTER "/gilden/obj/savefilemaster"
#define ABILMASTER PALADIN("master/abilmaster")
#define TASKMASTER PALADIN("master/taskmaster")
#define CEREMONYMASTER PALADIN("master/sequencer")
#define SEQUENCER CEREMONYMASTER
#define RES_CHECKER "/gilden/obj/restriction_checker"

#define ABILLIST PALADIN("members/abillist")
#define TOPLIST PALADIN("members/toplist")
#define REALTOPLIST LOG("toplist.read")
#define KILLERLIST PALADIN("master/killerlist")
#define MEMBERLIST PALADIN("members/members")
#define LVL16LIST PALADIN("members/lvl16quest")
#define MEMBERBACKUP PALADIN("backup/member_backup")
#define PALADIN_SUSPICIOUS_LOG LOG("suspicious.log")
#define GUILDNPC_LONGNAME "Ayla von Schattengrund"
#define GUILDNPC_NAME "Ayla"
#define PALADIN_SECURE "secure_prop"
#define PHIST_LOG LOG("phist.log")
#define PHIST_ALL_LOG LOG("phist_all.log")
#define GUILDNAME "paladine"


#define ISPALADIN "\npaladinnpc"
#define GUILDNPC_ID "\nAyla"
#define WAPPENROCK "\npaladinwappenrock"
#define PALADINITEM "\npaladinitem"
#define PALADINTASK "\npaladintaskitem"
#define PALADINREVIVED "\npaladinrevived"
#define TASKITEM PALADINTASK
#define GUILDITEM_ID WAPPENROCK
#define AMARYLLION "\namaryllion"
#define PALADIN_STANDARTE "\npaladinstandarte\n"
#define PALADIN_MASSENHEILUNG "Massenheilu\ng"
#define LAST_GUILDITEM_UPDATE "2005/05/05"

#define DUSTY_AVATAR "\blunzngroestl"


#define MAX_KILLS 40 

#define MAX_OPFER 10

#define PHIST_LEN 40

#define BSA(x, y) break_string(x, 78, y)
#define tell_angrox(x) if(find_player("angrox")) tell_object(find_player("angrox"), x)
#define tell_zordan(x) if(find_player("feyaria")) tell_object(find_player("feyaria"), x)
#define write_secure_log(x) write_file(LOG("secure"), ctime()+": "+x)
#define write_paladin_log(x,y) write_file(LOG(x), ctime()+": "+y)
#define write_error_log(x)  write_file(LOG("paladine.error"), ctime()+": "+x)

#define MONEY_PER_LEVEL\
  ({10000, 20000, 30000, 40000, 50000, 75000, 100000, 125000,\
        200000, 300000, 400000, 500000, 750000, 1000000, 15000000})
#define XP_PER_LEVEL\
  ({10000, 25000, 50000, 100000, 150000, 250000, 300000, 350000,\
	400000, 450000, 500000, 1000000, 2000000, 3500000, 5000000})
#define UID_ALLOWED\
  ({"GUILD.paladine", "GUILD.pal_spells", "zordan", "angrox"})

#define KETZER_AMULETT "/d/dschungel/feyaria/tijara/armour/amulett"
#define NACHTKAEMPFER_SCHWERT "/d/ebene/obj/waffe/mithrilschwert"
#define DIEB_DOLCH ({"/d/ebene/lamuerte/burg/obj/dolch",\
                     "/d/ebene/lamuerte/burg/obj/dolch_normal"})
  
#define FN_TASK_ALLOWED\
  ({"/d/gebirge/angrox/npc/ghoul",\
   "/d/gebirge/angrox/npc/skelett",\
   "/d/gebirge/angrox/npc/zombie",\
   "/d/gebirge/angrox/npc/skelett1",\
   "/d/gebirge/angrox/npc/balrog",\
   "/d/dschungel/feyaria/tijara/npc/ketzer",\
   "/d/ebene/Park/npc/landstreicher",\
   "/d/ebene/lamuerte/burg/npc/bettler",\
   "/d/dschungel/dante/weg/npc/bettler",\
   "/d/unterwelt/clementine/dimension/npc/az",\
   "/d/unterwelt/clementine/dimension/npc/cthuga",\
   "/d/unterwelt/clementine/dimension/npc/cthulhu",\
   "/d/unterwelt/clementine/dimension/npc/glaaki",\
   "/d/unterwelt/clementine/dimension/npc/hastur",\
   "/d/unterwelt/clementine/dimension/npc/nya",\
   "/d/unterwelt/clementine/dimension/npc/sho",\
   "/d/unterwelt/clementine/dimension/npc/shubb",\
   "/d/unterwelt/clementine/dimension/npc/shudde",\
   "/d/unterwelt/clementine/dimension/npc/tsa",\
   "/d/unterwelt/clementine/dimension/npc/wendigo",\
   "/d/unterwelt/clementine/dimension/npc/yibb",\
   "/d/unterwelt/clementine/dimension/npc/yog",\
   "/d/unterwelt/zordan/dhrkion/master/dhrkion",\
   "/d/ebene/Midas/npc/kanal/nachtkaempfer",\
   "/d/huegelland/feyaria/weg/npc/hirte",\
   "/d/ebene/lamuerte/burg/npc/dieb",\
   "/d/unterwelt/stahldorn/dammnis/npc/hoellenfuerst",\
   "/d/ebene/zordan/ogerhoehle/npc/mensch",\
   "/d/gebirge/monimor/npc/schatten",\
   "/d/gebirge/monimor/npc/seelendieb",\
   "/d/unterwelt/basics/central/npc/sichel",\
   "/d/unterwelt/basics/central/npc/skelett",\
   "/d/wasser/stahldorn/knarkh/npc/f_bestie",\
   "/d/wasser/stahldorn/knarkh/npc/h_bestie",\
   "/d/wasser/stahldorn/knarkh/npc/r_bestie",\
   "/d/wasser/stahldorn/knarkh/npc/k_bestie"})
  
// Wer darf der Gilde nicht beitreten
#define NOT_ALLOWED_MEMBER (["maquis": "Exzessives Skripten"])

// Spezielle Titel
#define PALADIN_EXTRA_TITLE ([\
    "sennah": ({"Ritter der Goettin ", "Ritter der Goettin ", "Ritterin der Goettin "})\
    ])

#define MAGICSTONES_FOR_RESURRECT 3


// DO NOT REMOVE THIS LINE

