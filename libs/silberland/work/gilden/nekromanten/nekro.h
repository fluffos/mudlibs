#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <moving.h>
#include <combat.h>
#include <wizlevels.h>
#include <new_skills.h>
#include "./nekro_properties.h"

// Gildennamen
#define GUILDNAME "nekromanten"

// Versionscheck des Items
#define LAST_GUILDITEM_UPDATE "20120320"

// Verzeichnisse festlegen
#ifndef GUILD_DIR
#define GUILD_DIR "/gilden/"
#endif
#define SPELL_DIR "/spellbooks/"
#define NEK_DIR GUILD_DIR+"nekromanten/"
#define NEKROMANTEN NEK_DIR
#define NPC NEKROMANTEN "npc/"
#define ARMOUR NEKROMANTEN "armour/"
#define WEAPON NEKROMANTEN "weapon/"
#define OBJ NEKROMANTEN "obj/"
#define LOG NEKROMANTEN "log/"
#define MEMBERLOG NEKROMANTEN "members_log/"
#define ROOM NEKROMANTEN "room/"
#define LIBS NEKROMANTEN "libs/"
#define BACKUP NEKROMANTEN "backup/"
#define SEQ NEKROMANTEN "seq/"
#define NHIST_LOG LOG "nhist.log"
#define NHIST_ALL_LOG LOG "nhist_all.log"

// Gilde
#define GUILD_ROOM GUILD_DIR+"nekromanten"
#define NEKRO_ISLAND_DIR "/d/unterwelt/nekromanten/"
#define NEKRO_ISLAND_ARMOUR NEKRO_ISLAND_DIR+"armour/"
#define NEKRO_ISLAND_LOG NEKRO_ISLAND_DIR+"log/"
#define NEKRO_ISLAND_WEAPON NEKRO_ISLAND_DIR+"weapon/"
#define NEKRO_ISLAND_NPC NEKRO_ISLAND_DIR+"npc/"
#define NEKRO_ISLAND_OBJ NEKRO_ISLAND_DIR+"obj/"
#define NEKRO_ROOMS NEKRO_ISLAND_DIR+"room/yaq_monoq/"
#define NEKRO_OUTSIDE_ROOMS NEKRO_ISLAND_DIR+"room/outside/"

// Spellbook
#define GUILD_SPELLBOOK SPELL_DIR+"nekro_spells"
#define NEKRO_SPELLS GUILD_SPELLBOOK
// Master festlegen
#define PMASTER "/gilden/paladine/master/paladinmaster"
#define PNPCMASTER "/gilden/paladine/master/npcmaster"
#define NEKROMASTER NEKROMANTEN+"master/nekromaster"
#define NMASTER NEKROMASTER
#define GUILD_MASTER NEKROMASTER
#define NNPCMASTER NEKROMANTEN+"master/npcmaster"
#define SAVEMASTER "/gilden/obj/savefilemaster"
#define ABILMASTER NEKROMANTEN+"master/abilmaster"
#define TASKMASTER NEKROMANTEN+"master/taskmaster"
#define CEREMONYMASTER NEKROMANTEN+"master/sequencer"
#define SEQUENCER CEREMONYMASTER
#define RES_CHECKER "/gilden/obj/restriction_checker"

#define NEKRO_CONNECTROOM_UWELT "/d/unterwelt/basics/central/room/00-22+07"
#define NEKRO_CONNECTROOM_ZINSEL "/d/wasser/dante/zinsel/room/treppe3"
#define NEKRO_ZINSEL_CONNECTROOM NEKRO_ROOM "e1"
#define NEKRO_UWELT_CONNECTROOM NEKRO_OUTSIDE_ROOM "gang"

// Eigene Properties
// --> ausgelagert in nekro_properties.h

#define NEKROMANTEN_SECURE "secure_prop"

#ifndef SI_MAX_DAMAGE
#define SI_MAX_DAMAGE "si_max_damage"
#endif

#define MASTER_MAGES ({"angrox","feyaria","stahldorn","archon"})

// Listen und Logs
#define KILL_LOG LOG+"npc.kills"
#define ABILLIST NEKROMANTEN+"members/abillist"
#define TOPLIST NEKROMANTEN+"members/toplist"
#define REALTOPLIST LOG+"toplist.read"
#define KILLERLIST NEKROMANTEN+"master/killerlist"
#define MEMBERLIST NEKROMANTEN+"members/members"
#define BLOODPOOL NEKROMANTEN+"members/bloodpool"
#define MEMBERBACKUP NEKROMANTEN+"backup/member_backup"
#define SACRIFICE_LIST NEKROMANTEN+"members/sacrificed_paladins"
#define NEKROMANTEN_SUSPICIOUS_LOG LOG+"suspicious.log"

// GuildNPC Definition
#define GUILDNPC_LONGNAME "Xarfai"
#define GUILDNPC_NAME "Xarfai"
#define GUILDNPC_ID "Xarfai"

// GUILDITEM + TASKITEM
// -> ausgelagert in nekro_properties.h

// Anforderungen
// -------------


#define XP_PER_LEVEL\
  ({200000,500000,1000000,1500000,2500000,5000000,15000000})

#define BLOOD_PER_LEVEL\
  ({1000,2500,3500,5000,10000,20000,40000})

#define LXP_PER_LEVEL\
  ({50000,200000,400000,1000000,2000000,4000000,5000000})

#define KILLS_PER_INNERCIRCLE\
  ({40,80,100,175,300,400,600})
// von > auf  
//  1  2  3   4   5   6   7  

// Maximaler Bloodpool
#define MAX_BLOODPOOL 3500
#define BLOODCOST 50

// Security
#define UID_ALLOWED\
  ({"GUILD.nekromanten", "GUILD.nekro_spells"})+MASTER_MAGES


// Spellbook:
#define CANNIBAL_COST 5
#define EXTRA_DTS ({ DT_MAGIC, DT_FIRE, DT_SOUND, DT_TERROR, DT_COLD, DT_MIND  })
#define NEKRO_DTS ({ DT_UNHOLY, DT_ACID, DT_POISON })
#define NOT_NEKRO_DTS ({ DT_HOLY, DT_LIGHT, DT_AIR })

// wieviel Prozent XP man von den Untoten bekommt
#define XP_RATIO 75

// Faktor den die Spells mehr Seelen aus dem Bloodpool brauchen
#define BLOODUSE_FACTOR 0.8 // angepasst am 24.11.2023 Gwenshara: es gibt sehr wenig aktive Nekromanten

// Aufaddierter Bonus pro geopferter Seele  
#define BLOODBONUS 2 // angepasst am 24.11.2023 Gwenshara: es gibt sehr wenig aktive Nekromanten

// Diverse Defines
#define BSA(x, y) break_string(x, 78, y)
#define DB(x) if (find_player("gwenshara")) \
   tell_object(find_player("gwenshara"),("NEKRODEBUG: "+x+"\n"))
#define tell_angrox(x) if(find_player("angrox") && find_player("angrox")->QueryProp("nekro_debug")) tell_object(find_player("angrox"), x)
#define ta(x) tell_angrox(x)
#define tell_feyaria(x) if(find_player("feyaria") && find_player("feyaria")->QueryProp("nekro_debug")) tell_object(find_player("feyaria"), x)
#define tell_stahldorn(x) if(find_player("stahldorn") && find_player("stahldorn")->QueryProp("nekro_debug")) tell_object(find_player("stahldorn"), x)
#define write_secure_log(x) write_file(LOG+"secure", ctime()+": "+x)
#define write_nekro_log(x,y) write_file(LOG+x, ctime()+": "+y)
#define write_error_log(x)  write_file(LOG+"nekro.error", ctime()+": "+x)
#define MAX_KILLS 40 /*Paladinkills zum suehnen*/

// Abstossende Adjektive, kann man vielleicht woanders auch brauchen...
#define DIFAM_ADJ ({"widerlich","ekelhaft","abstossend","verflucht",\
                    "jaemmerlich"})
#define NEKRO_NAMES ({"Xrofax", "Drantos", "Lutrof", "Peladix", "Nortux",\
    "Sechzar","Tzturr", "Werxtaar", "Tlugflam", "Torulax", "Trazzuu",\
    "Fetruq","Terftur","Orzshruf", "Adizorath", "Terf'tal", "Raniur",\
    "Chamar", "Crifon", "Cheldves", "Tethrd", "Zirdqhat",\
    "Tlugat", "R'zzroi", "He'zthur", "Tttralt", "Serrtr'Thur", "Grox'Traak",\
    "Ron'tak'ja", "Ter'fur'na", "Zzetronach"\
});

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
#define NEKROMASKCOMMANDS ([\
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
    



// Hier machma auch mal ein comment :)
// Filename Task Allowds, die duerfen was aendern.
#define FN_TASK_ALLOWED ({\
    "/d/ebene/Midas/room/glockenturm",\
                          })


#define BSC(x) break_string(x, caster->QueryProp(P_SCREENWIDTH))

// Prototyping fuers spellbook
//void do_spellbook_damage(int dam, object pl, string killer, mixed kill_msg);
//varargs int UseBlood(int value);
