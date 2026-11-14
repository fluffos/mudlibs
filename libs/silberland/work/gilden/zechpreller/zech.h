#define MAX_GUILD_LEVEL 10
#include "zechpreller_extern.h"

#define SPELLS(x) "/spellbook"
#define ZECHSPELLBOOK SPELLS("zech_spells")
#define ZECH(x) "/gilden/zechpreller/"+x
#define NPC(x) ZECH("npc/")+x
#define OBJ(x) ZECH("obj/")+x
#define LOG(x) ZECH("log/")+x
#define SLOG(x) ZECH("statistics/")+x
#define ROOM(x) ZECH("room/")+x
#define WEAPON(x) ZECH("weapon/")+x
#define LIBS(x) ZECH("libs/")+x
#define ZECHMASTER ZECH("master/zechmaster.lpc")
#define RES_CHECKER "/gilden/obj/restriction_checker"
#define MEMBERLIST ZECH("members/members")
#define MEMBERBACKUP ZECH("backup/members_backup")
#define TOPLIST ZECH("members/toplist")
#define REALTOPLIST LOG("toplist.read")
#define GILDENOBJFILE OBJ("z_17erschluessel");
#define SAVEMASTER "/gilden/obj/savefilemaster"
#define RES_CHECKTER "/gilden/obj/restriction_checker"
#define LVL_XP ({50000, 100000, 200000, 500000, 1000000, 2000000, \
                  4000000, 6000000, 8000000, 10000000})
#define tell_angrox(x) if(find_player("angrox")) tell_object(find_player("angrox"), x)
#define BSA(x, y) break_string(x, 78, y)
#define ZHIST_LOG "/gilden/zechpreller/log/zhist.log"
#define QUESTMASTER "/gilden/zechpreller/master/questmaster"

// Ein Gegenstand darf maximal einen Bonus von 50% geben
#define MAX_EQUIP_BONUS 50

// Alle Gegenstaende zusammen duerfen nicht mehr als 100% Bonus ausmachen
#define TOTAL_EQUIP_BONUS 70

// Max. Spellcostred.
#define MAX_SPELLCOST_BONUS 60

// Erbdefines
#define EPIC_ITEM "\nzechpreller_epic_item"
#define ERBMASTER "/gilden/zechpreller/master/erbmaster"
#define ERBE_ZECHUS "zechprellererbe_zechus"
#define ERBE_LANESTRA "zechprellererbe_lanestra"
#define ERBE_ARTANOK "zechprellererbe_artanok"
#define ERBE_TARXES "zechprellererbe_tarxes"
#define EPIC(x)     ZECH("epos/")+x
#define ZECHUS_NPC  ({"/d/ebene/Midas/npc/albin",\
		      "/d/ebene/Midas/npc/kanal/nachtkaempfer", \
		      "/d/unterwelt/basics/central/npc/sichel", \
		      "/d/unterwelt/zordan/dhrkion/npc/odania", \
		      "/d/unterwelt/zordan/dhrkion/npc/mystixfis",\
		      "/d/ebene/lamuerte/burg/npc/berzerker",\
		      "/d/ebene/lamuerte/drachen/kyranda_drache"})
#define LANESTRA_NPC ({"/d/kristallwald/protheg/elessar/npc/turambar", \
		       "/d/kristallwald/sargola/lichtung/npc/d", \
		       "/d/kristallwald/protheg/av/npc/woki", \
		       "/d/polar/thor/xandim/npc/yrmalaru", \
		       "/d/polar/lamuerte/eishoehle/npc/yeti", \
		       "/d/polar/lamuerte/eishoehle/npc/ice_dragon"})
#define ARTANOK_NPC  ({"/d/huegelland/raballion/hobbits/npc/oberbuettel", \
		       "/d/huegelland/raballion/hobbits/npc/molkine", \
		       "/d/wasser/stahldorn/knarkh/npc/k_bestie", \
		       "/d/wasser/stahldorn/knarkh/npc/r_bestie",\
		       "/d/wasser/dante/zinsel/npc/saeuredrache",\
	               "/d/dschungel/feyaria/tijara/npc/shagraz",\
	               "/d/dschungel/feyaria/tijara/npc/elsurion"})
#define TARXES_NPC   ({"/d/dschungel/feyaria/sumpf/npc/sumpfdrache", \
		       "/d/ebene/zordan/ogerhoehle/npc/grimow",\
		       "/d/ebene/Midas/npc/offizier", \
		       "/d/gebirge/angrox/npc/balrog", \
		       "/d/gebirge/angrox/npc/bergwerk_drache",\
		       "/d/huegelland/feyaria/weg/npc/steinriese",\
		       "/d/huegelland/feyaria/weg/npc/riesenadler"})

// interne Properties
#define P_TMP_ZECHPRELLER_WINEGHOST "intern_zechpreller_weingeist"

#define pDebug(who, what) if(who->QueryProp(P_TESTPLAYER)) tell_object(who, ANSI_BOLD+ANSI_YELLOW+what+ANSI_NORMAL)

// Statistische Informationen
#define INFORM_STAT ({"gwenshara"})
