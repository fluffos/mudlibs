/*
** bardengilde.h
** by Andyl@Silberland
** Last updated: 2002-08-15
*/

#include <defines.h>
#include <moredef.h>
#include "/p/std/barden/instrument.h"
#include "barden_skills.h"
#include "barden_extern.h"

// FOR LD
//#include "ldmud.h"

#define B_SPELLS(x) "/spellbook"
#define BARDEN(x) "/gilden/bardengilde/"+(x)
#define ROOM(x) BARDEN("room/")+(x)
#define NPC(x) BARDEN("npc/")+(x)
#define ARMOUR(x) BARDEN("armour/")+(x)
#define INSTRUMENT(x) BARDEN("instrument/")+(x)
#define WEAPON(x) BARDEN("weapon/")+(x)
#define OBJ(x) BARDEN("obj/")+(x)
#define LOG(x) BARDEN("log/")+(x)
#define MEMBER_LOG(x) BARDEN("member_log/")+(x)
#define BINFO(x) BARDEN("info/")+(x)
#define LIBS(x) BARDEN("libs/")+(x)

#define SEQ(x) BARDEN("seq/")+(x)
#define LEVELSEQ(x) "/gilden/bardengilde/seq/level/" + x
#define SPELLSEQ(x) SEQ("spells/")+(x)
#define TASKSEQ(x) SEQ("tasks/")+(x)

#define SEQUENCEMASTER BARDEN("master/sequencemaster")
#define TEMPEL ROOM("tempel")
#define SAVEMASTER "/gilden/obj/savefilemaster"
#define TASKMASTER BARDEN("master/taskmaster")
#define ABILMASTER BARDEN("master/abilmaster")
#define ABILLIST BARDEN("members/abillist")
#define MEMBERLIST BARDEN("members/members")
#define TOPLIST BARDEN("members/toplist")
#define REALTOPLIST LOG("barden_toplist.read")
#define ALESTRATOPLIST LOG("barden_alestra_toplist.read")
#define TIRENATOPLIST LOG("barden_tirena_toplist.read")
#define SARRIANTOPLIST LOG("barden_sarrian_toplist.read")
#define KORRIAXTOPLIST LOG("barden_korriax_toplist.read")
#define MEMBERBACKUP BARDEN("backup/member_backup")
#define BARD_SUSPICIOUS_LOG LOG("suspicious.log")
#define BACKUP(x) BARDEN("backup/")+x

#define BSA(x, y) break_string(x, 78, y)
#define tell_andyl(x) tell_object(find_player("andyl"), x)
#define TA(x) tell_object(find_player("andyl"), x)
#define TW(x) if(find_player("wraz"))tell_object(find_player("wraz"),x)
#define write_secure_log(x) write_file(LOG("secure"), dtime(time())+": "+x)
#define bard_log_file(x, y) log_file("gilden/bardengilde/"+x, y)

// MUSS ERST NOCH RICHTIG GESETZT WERDEN

#define XP_PER_LEVEL\
({10000, 25000, 50000, 100000, 200000, 300000, 500000, 750000,\
 1000000, 1250000, 1700000, 2200000, 2800000, 3500000, 5500000})

#define UID_ALLOWED\
  ({"GUILD.bardengilde", "GUILD.barden_spells", "andyl"})

#define FN_TASK_ALLOWED\
  ({"/d/ebene/andyl/scharlatan/room/fakegilde",\
   "/d/gebirge/angrox/npc/skelett",\
   "/d/gebirge/angrox/npc/zombie",\
   "/d/gebirge/angrox/npc/skelett1",\
   "/d/gebirge/angrox/npc/balrog",\
   "/d/dschungel/feyaria/tijara/npc/ketzer",\
   "/d/ebene/Park/npc/landstreicher",\
   "/d/ebene/lamuerte/burg/npc/bettler",\
   "/d/dschungel/dante/weg/npc/bettler",\
   "/d/unterwelt/amazora/dimension/npc/az",\
   "/d/unterwelt/amazora/dimension/npc/cthuga",\
   "/d/unterwelt/amazora/dimension/npc/cthulhu",\
   "/d/unterwelt/amazora/dimension/npc/glaaki",\
   "/d/unterwelt/amazora/dimension/npc/hastur",\
   "/d/unterwelt/amazora/dimension/npc/nya",\
   "/d/unterwelt/amazora/dimension/npc/sho",\
   "/d/unterwelt/amazora/dimension/npc/shubb",\
   "/d/unterwelt/amazora/dimension/npc/shudde",\
   "/d/unterwelt/amazora/dimension/npc/tsa",\
   "/d/unterwelt/amazora/dimension/npc/wendigo",\
   "/d/unterwelt/amazora/dimension/npc/yibb",\
   "/d/unterwelt/amazora/dimension/npc/yog",\
   "/d/unterwelt/zordan/dhrkion/master/dhrkion",\
   "/d/ebene/Midas/npc/nachtkaempfer",\
   "/d/huegelland/feyaria/weg/npc/hirte",\
   "/d/ebene/lamuerte/burg/npc/dieb",\
   "/d/unterwelt/stahldorn/dammnis/npc/hoellenfuerst",\
   "/d/ebene/zordan/ogerhoehle/npc/mensch",\
   "/d/gebirge/monimor/npc/schatten",\
   "/d/gebirge/monimor/npc/seelendieb",\
   "/d/unterwelt/connect/central/npc/sichel",\
   "/d/wasser/stahldorn/knarkh/npc/f_bestie",\
   "/d/wasser/stahldorn/knarkh/npc/h_bestie",\
   "/d/wasser/stahldorn/knarkh/npc/r_bestie",\
   "/d/wasser/stahldorn/knarkh/npc/k_bestie"})

// Spell Info: Spellname mit richtiger Gross-Klein-Schreibung
#define SI_CAP_NAME "capital_name"
// Spell Info: Skills, die zum Zaubern verwendet werden
#define SI_CAST_SKILL "cast_skill"
// Spell Info: Benoetigte Instrumentenstufe
#define SI_INSTRUMENT_LEVEL "instrument_level"

#define BARD_UPKEEP_EFFECT "\nbard_upkeep_effect"
#define BARD_GROUP_INSTRUMENT ([BARD_GROUP_ALESTRA: IT_STRING, BARD_GROUP_TIRENA: IT_WIND, BARD_GROUP_KORRIAX: IT_DRUM, BARD_GROUP_SARRIAN: IT_GLASS])

#define TALENT_ALLEGRO                   0
#define TALENT_ERMUTIGENDE_WORTE         1
#define TALENT_STAKKATO                  2
#define TALENT_FASZINIERENDE_VORSTELLUNG 3
#define TALENT_CRESCENDO                 4
#define TALENT_TAMBOURMAJOR              5
#define TALENT_ANGENEHME_STIMME          6
#define TALENT_FLINKE_FINGER             7
#define TALENT_BANNSAENGER               8
#define TALENT_ALTE_GESCHICHTEN          9
#define TALENT_ELFISCHE_MELODIE          10
#define TALENT_FORTE_FORTISSIMO          11
#define TALENT_LANDSTREICHER             12
#define TALENT_KANON                     13
#define TALENT_HEILER                    14
#define TALENT_AGITATOR                  15
#define TALENT_KREISCHENDES_ECHO         16
#define MAX_TALENT_NR                    17

#define TALENT_ID_TO_STRING ({"Allegro", "Ermutigende Worte", "Stakkato", "Faszinierende Vorstellung", \
                              "Crescendo", "Tambourmajor", "Angenehme Stimme", "Flinke Finger", "Bannsaenger", \
                              "Alte Geschichten", "Elfische Melodie", "Forte, Fortissimo!", "Landstreicher", "Kanon", \
                              "Heiler", "Agitator", "Kreischendes Echo"})

#define HERO_ANGARA   "angara"
#define HERO_ARCON    "arcon"
#define HERO_FLAMMARA "flammara"
#define HERO_GRIMM    "grimm"
#define HERO_KHARTAK  "khartak"
#define HERO_MIRA     "mira"
#define HERO_NOGI     "nogi"
#define HERO_RYNOXA   "rynoxa"
#define HERO_SCHLAIN  "schlain"
#define HERO_ZAFIRA   "zafira"
#define HERO_XULGSCH  "xulgsch"
#define HERO_FRAGGIN  "fraggin"

#define SK_HEROISM(x) "Heldentum_"+x

#define ALLOWED_HERO_PATHS ({HERO_ANGARA, HERO_ARCON, HERO_FLAMMARA, HERO_GRIMM, HERO_KHARTAK, HERO_NOGI, HERO_RYNOXA, HERO_XULGSCH, HERO_FRAGGIN, HERO_ZAFIRA})

#define SPELLS_PER_LEVEL ({ \
  ({"Musizieren", "Singen", "Schrei des Verderbens|flammara", "Das gelueftete Geheimnis"}),\
  ({"Ode an die Sterne", "Der Dinge wahrer Hintergrund"}),\
  ({"Lied der Zauber", "@@GRP3@@"}),\
  ({"Ein Ton in der Stille", "@@GRP4@@|nogi"}),\
  ({"Lied der Winde", "Das geborstene Schwert"}),\
  ({"Aller Welten Freund", "@@GRP6@@"}),\
  ({"Der Besuch des Raben", "Die Strasse gleitet fort"}),\
  ({"Lorica der Musen|angara", "@@GRP8@@|arcon"}),\
  ({"Abendstille ueberall", "Klarster Lebenssaft da quillt"}),\
  ({"Sei hier Gast", "Band der Freundschaft|rynoxa"}),\
  ({"Tanz der Saebel|khartak", "Ruf der Helden|grimm"}),\
  ({"@@GRP12@@|xulgsch"}),\
  ({"Sieben Schritte"}),\
  ({"Lass den Wind dich tragen"})\
})

#define GROUP_SPECIFIC_SPELLS ([ \
  "GRP3": ([BARD_GROUP_ALESTRA: "Flamme bin ich", BARD_GROUP_KORRIAX: "Des Todes drei Trommelschlaege", BARD_GROUP_TIRENA: "Windlied der Sylphen", BARD_GROUP_SARRIAN: "Das Lied vom Sturmvogel"]),\
  "GRP4": ([BARD_GROUP_ALESTRA: "Ballade vom Drachentoeter", BARD_GROUP_TIRENA: "Schildsang der Walkueren", BARD_GROUP_KORRIAX: "zwergisches Ahnenlied", BARD_GROUP_SARRIAN: "Stolze Mauer am Fluss"]),\
  "GRP6": ([BARD_GROUP_TIRENA: "Der Sommer", BARD_GROUP_ALESTRA: "Der Fruehling", BARD_GROUP_KORRIAX: "Der Winter", BARD_GROUP_SARRIAN: "Der Herbst"]),\
  "GRP8": ([BARD_GROUP_TIRENA: "Vana-o isil ar Elena", BARD_GROUP_ALESTRA: "Haette ich ein Herz", BARD_GROUP_KORRIAX: "Toetet das Biest", BARD_GROUP_SARRIAN: "Wiegenlied des Leids"]),\
  "GRP12": ([BARD_GROUP_TIRENA: "Beschwoerung der Sonne", BARD_GROUP_ALESTRA: "Hinter dem Sternenwall", BARD_GROUP_KORRIAX: "Also sprach Qexyypbmizox", BARD_GROUP_SARRIAN: "Das Geheimnis der Insel"]),\
])

#define HERO_SPECIFIC_SPELLS ([\
  HERO_ARCON: "Der Goettin erster Krieger",\
  HERO_FLAMMARA: "Wort des Feuers",\
  HERO_NOGI: "Kriegslied der Zwerge",\
  HERO_ANGARA: "Schuetzendes Herz des Berges",\
  HERO_RYNOXA: "Hymne der Hoffnung",\
  HERO_GRIMM: "Der letzte der Riesen",\
  HERO_KHARTAK: "Sturm der Klingen",\
  HERO_XULGSCH: "Fest der Schatten",\
])

#define TEST_PRINT(who, x) if(who->QueryProp(P_TESTPLAYER) || IS_LEARNER(who)) tell_object(who, x);

#define CLOSURE(x) #'x
