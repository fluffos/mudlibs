#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <moving.h>
#include <combat.h>
#include <wizlevels.h>
#include <new_skills.h>
#include "./dk_properties.h"
#include "./nekro_properties.h"
#include "/gilden/paladine/paladin_extern.h"

// Gildennamen
#define GUILDNAME "todesritter"

// Versionscheck des Items
#define LAST_GUILDITEM_UPDATE "20022004"

// Verzeichnisse festlegen
#ifndef GUILD_DIR
#define GUILD_DIR "/gilden/"
#endif
#define SPELL_DIR "/spellbooks/"
#define DK_DIR GUILD_DIR+"todesritter/"
#define TODESRITTER DK_DIR
#define NPC TODESRITTER "npc/"
#define ARMOUR TODESRITTER "armour/"
#define WEAPON TODESRITTER "weapon/"
#define OBJ TODESRITTER "obj/"
#define LOG TODESRITTER "log/"
#define MEMBERLOG TODESRITTER "members_log/"
#define ROOM TODESRITTER "room/"
#define LIBS TODESRITTER "libs/"
#define BACKUP TODESRITTER "backup/"
#define SEQ TODESRITTER "seq/"
#define NHIST_LOG LOG "nhist.log"
#define NHIST_ALL_LOG LOG "nhist_all.log"

// Gilde
#define GUILD_ROOM GUILD_DIR+"todesritter"
#define DK_ISLAND_DIR "/d/unterwelt/todesritter/"
#define DK_ISLAND_ARMOUR DKRO_ISLAND_DIR+"armour/"
#define DK_ISLAND_LOG DKRO_ISLAND_DIR+"log/"
#define DK_ISLAND_WEAPON DKRO_ISLAND_DIR+"weapon/"
#define DK_ISLAND_NPC DKRO_ISLAND_DIR+"npc/"
#define DK_ISLAND_OBJ DKRO_ISLAND_DIR+"obj/"
#define DK_ROOMS DKRO_ISLAND_DIR+"room/yaq_monoq/"
#define DK_OUTSIDE_ROOMS DKRO_ISLAND_DIR+"room/outside/"

// Spellbook
#define GUILD_SPELLBOOK SPELL_DIR+"dk_spells"
#define DK_SPELLS GUILD_SPELLBOOK
// Master festlegen
#define PMASTER "/gilden/paladine/master/paladinmaster"
#define PNPCMASTER "/gilden/paladine/master/npcmaster"
#define DKMASTER "/gilden/nekromanten/master/nekromaster"
#define NMASTER DKMASTER
#define GUILD_MASTER DKMASTER
#define NNPCMASTER TODESRITTER+"master/npcmaster"
#define SAVEMASTER "/gilden/obj/savefilemaster"
#define ABILMASTER TODESRITTER+"master/abilmaster"
#define TASKMASTER TODESRITTER+"master/taskmaster"
#define CEREMONYMASTER TODESRITTER+"master/sequencer"
#define SEQUENCER CEREMONYMASTER
#define RES_CHECKER "/gilden/obj/restriction_checker"

#define DK_CONNECTROOM_UWELT "/d/unterwelt/basics/central/room/00-22+07"
#define DK_CONNECTROOM_ZINSEL "/d/wasser/dante/zinsel/room/treppe3"
#define DK_ZINSEL_CONNECTROOM DKRO_ROOM "e1"
#define DK_UWELT_CONNECTROOM DKRO_OUTSIDE_ROOM "gang"

// Eigene Properties
// --> ausgelagert in dk_properties.h

#define TODESRITTER_SECURE "secure_prop"

#ifndef SI_MAX_DAMAGE
#define SI_MAX_DAMAGE "si_max_damage"
#endif

#define MASTER_MAGES ({"angrox","feyaria","stahldorn","archon"})

// Listen und Logs
#define KILL_LOG LOG+"npc.kills"
#define ABILLIST TODESRITTER+"members/abillist"
#define TOPLIST TODESRITTER+"members/toplist"
#define REALTOPLIST LOG+"toplist.read"
#define KILLERLIST TODESRITTER+"master/killerlist"
#define MEMBERLIST TODESRITTER+"members/members"
#define BLOODPOOL TODESRITTER+"members/bloodpool"
#define MEMBERBACKUP TODESRITTER+"backup/member_backup"
#define SACRIFICE_LIST TODESRITTER+"members/sacrificed_paladins"
#define TODESRITTER_SUSPICIOUS_LOG LOG+"suspicious.log"

// GuildNPC Definition
#define GUILDNPC_LONGNAME "Helme Haffax"
#define GUILDNPC_NAME "Helme Haffax"
#define GUILDNPC_ID "todessritter_gildenchef"

// GUILDITEM + TASKITEM
// -> ausgelagert in dk_properties.h

// Anforderungen
// -------------


#define XP_PER_LEVEL\
  ({200000,500000,1000000,1500000,2500000,5000000,15000000})

#define BLOOD_PER_LEVEL\
  ({1000,2500,3500,5000,10000,20000,40000})

#define LXP_PER_LEVEL\
  ({100000,400000,800000,2000000,4000000,6000000,7000000})

#define KILLS_PER_INNERCIRCLE\
  ({40,80,100,175,300,400,600})
// von > auf  
//  1  2  3   4   5   6   7  

// Maximaler Bloodpool
#define MAX_BLOODPOOL 3500
#define BLOODCOST 200

// Security
#define UID_ALLOWED\
  ({"GUILD.todesritter", "GUILD.dk_spells"})+MASTER_MAGES


// Spellbook:
#define CANNIBAL_COST 5
#define EXTRA_DTS ({ DT_MAGIC, DT_FIRE, DT_SOUND, DT_TERROR, DT_COLD, DT_MIND  })
#define DK_DTS ({ DT_UNHOLY, DT_ACID, DT_POISON })
#define NOT_DK_DTS ({ DT_HOLY, DT_LIGHT, DT_AIR })

// wieviel Prozent XP man von den Untoten bekommt
#define XP_RATIO 66

// Faktor den die Spells mehr Seelen aus dem Bloodpool brauchen
#define BLOODUSE_FACTOR 1

// Aufaddierter Bonus pro geopferter Seele  
#define BLOODBONUS 1  

// Diverse Defines
#define BSA(x, y) break_string(x, 78, y)
#define DB(x) if (find_player("stahldorn")) \
   tell_object(find_player("stahldorn"),("Debug sagt: "+x+"\n"))
#define tell_angrox(x) if(find_player("angrox") && find_player("angrox")->QueryProp("dk_debug")) tell_object(find_player("angrox"), x)
#define ta(x) tell_angrox(x)
#define tell_feyaria(x) if(find_player("feyaria") && find_player("feyaria")->QueryProp("dk_debug")) tell_object(find_player("feyaria"), x)
#define tell_stahldorn(x) if(find_player("stahldorn") && find_player("stahldorn")->QueryProp("dk_debug")) tell_object(find_player("stahldorn"), x)
#define write_secure_log(x) write_file(LOG+"secure", ctime()+": "+x)
#define write_dk_log(x,y) write_file(LOG+x, ctime()+": "+y)
#define write_error_log(x)  write_file(LOG+"dk.error", ctime()+": "+x)
#define MAX_KILLS 40 /*Paladinkills zum suehnen*/

// Abstossende Adjektive, kann man vielleicht woanders auch brauchen...
#define DIFAM_ADJ ({"widerlich","ekelhaft","abstossend","verflucht",\
                    "jaemmerlich"})

// Gildenpresays fuer nkreische
#define GUILDLVLPRESAYS ([\
    1: ({"Leichenschaender", "Leichenschaender","Leichenschaenderin"}),\
    2: ({"Dunkler", "Dunkler", "Dunkle"}),\
    3: ({"Verfluchter", "Verfluchter","Verfluchte"}),\
    4: ({"Verdammter", "Verdammter","Verdammte"}),\
    5: ({"Nekromant", "Nekromant", "Nekromantin"}),\
    6: ({"Seelenhaescher", "Seelenhaescher", "Seelenhaescherin"}),\
    7: ({"Untoter", "Untoter","Untote"}),\
    ])

// Maskencommandos und welche erlaubt sind:
#define DKMASKCOMMANDS ([\
    "seelenschlag":1,\
    "nkreische"   :1,\
    "nkreisch"    :1,\
    "nwer"        :1,\
    "nreport"     :1,\
    "ntrete"      :1,\
    "ntritt"      :1,\
    "nhist"       :1,\
    "nstatus"     :1,\
    "nfarben"     :1,\
    "opfer"       :1,\
    "opfere"      :1,\
    "info"        :1,\
    "ninfo"       :1,\
    "nitel"       :1,\
    "nemote"      :1,\
    "nhilfe"      :1,\
    ])

#define SKILLPOINT_TIME 60
#define SKILLPOINT_COST 100
    



#define BSC(x) break_string(x, caster->QueryProp(P_SCREENWIDTH))

// Prototyping fuers spellbook
//void do_spellbook_damage(int dam, object pl, string killer, mixed kill_msg);
//varargs int UseBlood(int value);
