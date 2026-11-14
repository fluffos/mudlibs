#include <defines.h>
#include <moredef.h>
#include <material.h>
#include "druiden_extern.h"

#define GUILDNAME "druidenzirkel"
#define DRUIDENMAGIER ({ "angrox", "iwo" })
#define DRUIDENPAPAS ({ "angrox", "iwo" })
#define D_SPELLS(x) "/spellbooks"
#define DRUIDENSPELLS "/spellbooks/druiden_spells"
#define DRUIDEN(x) ("/gilden/druidenzirkel/"+x)
#define NPC(x) DRUIDEN("npc/"+x)
#define ARMOUR(x) DRUIDEN("armour/"+x)
#define WEAPON(x) DRUIDEN("weapon/"+x)
#define OBJ(x) DRUIDEN("obj/"+x)
#define LOG(x) DRUIDEN("log/"+x)
#define LIB(x) DRUIDEN("lib/"+x)
#define ELEMENT_LOG(x) LOG("element/"+x)
#define MEMBER_LOG(x) DRUIDEN("member_log/"+x)

#define DROOM(x) ("/d/huegelland/angrox/druidenzirkel/room/"+x)


#define RES_CHECKER "/gilden/obj/restriction_checker"
#define DRUIDENMASTER DRUIDEN("master/druidenmaster")
#define GUILD_MASTER DRUIDENMASTER
#define SAVEMASTER "/gilden/obj/savefilemaster"
#define ABILMASTER DRUIDEN("master/abilmaster")
#define ABILLIST DRUIDEN("members/abillist")
#define MEMBERLIST DRUIDEN("members/members")
#define TOPLIST DRUIDEN("members/toplist")
#define LEGENDARY DRUIDEN("members/legendary")
#define REALTOPLIST LOG("toplist.read")
#define MEMBERBACKUP DRUIDEN("backup/member_backup")
#define DRUID_SUSPICIOUS_LOG LOG("suspicious.log")
#define DHIST_LOG LOG("dhist.log")

#define DRUIDENAMULETT "\ndruidenamulett"
#define ELEMENTARHANDSCHUHE "\nelementarhandschuhe"
#define TASKITEM "\netask"
#define DRUIDENELEMENTAR "\nd_elementar"
#define SCHUTZHUELLE "\nschutzhuelle"
#define MORE_SERVICE "\nallow_more_services_for_druids"
#define DRUIDEN_DOT "\ndruiden_damage_over_time"
#define DRUIDEN_SPELL_ENHANCE "\ndruiden_spell_enhance"
#define DRUIDEN_ARROW_ENHANCE "\ndruiden_arrow_enhance"
#define DRUIDEN_RESIST_MOD "\ndruiden_resist_mod"
#define DRUIDEN_FOCUS "\ndruiden_focus"

#define ELEMENTAL_SPHERE "\nelement_sphere"

#define SI_SPELLNAME "spellname"
#define LATEST_AMULET_VERSION "31082004"

//#define ELEMENTAL_CASTER "e_caster"
/* aus Sicherheit: */
#define ELEMENT_CASTER "e_caster1"
#define ELEMENT_DEFENDS "e_defends1"
#define ELEMENTAL_ENEMY "e_enemy"
#define E_REMOVE_MSG "e_rem_msg"
#define ELEMENTAL_DEFENDS "e_defends"
#define ELEMENT_SECURE "secure_prop"
#define E_TIME "etime"
#define E_HANDS "ehands"
#define E_AGGRESSIVE "e_aggr"


#define BSA(x, y) break_string(x, 78, y)
#define tell_angrox(x) if(find_player("angrox")) tell_object(find_player("angrox"), x)
#define ta(x) tell_angrox(x)
#define write_secure_log(x) write_file(LOG("secure"), dtime(time())+": "+x)

//#define PARTYMASTER DRUIDEN("master/partymaster.lpc")
//#define PARTYLIST DRUIDEN("party/partymembers")
//#define PARTY_LEADER "party_leader"
//#define PARTY_MEMBER "party_member"
//

#define DHIST_LEN 40

#define DRUID_ENHANCEMENT 1.10
#define XP_PER_LEVEL\
({10000, 25000, 50000, 100000, 200000, 300000, 500000, 750000,\
 1000000, 1250000, 1700000, 2200000, 2800000, 3500000, 5500000})
  
#define XP_LVL1    10000
#define XP_LVL2    25000
#define XP_LVL3    50000
#define XP_LVL4   100000                   
#define XP_LVL5   200000 
#define XP_LVL6   300000
#define XP_LVL7   500000
#define XP_LVL8   750000
#define XP_LVL9  1000000 
#define XP_LVL10 1250000
#define XP_LVL11 1700000
#define XP_LVL12 2200000
#define XP_LVL13 2800000
#define XP_LVL14 3500000 
#define XP_LVL15 5500000 

#define FORBIDDEN_METAL MATERIALDB->GetGroupMembers(MATGROUP_METAL)-({MAT_GOLD})

// Edelsteinart fuer stufe 16
#define P_LEVEL_SIXTEEN_GEM "level16_gem"


/* Die Domains der Elemente */
#define D_ERZ ({"gebirge"})
#define D_FEUER ({"wueste"})
#define D_LUFT ({"ebene", "huegelland", "luft"})
#define D_WASSER ({"wasser"})
#define D_HUMUS ({"dschungel", "kristallwald"})
#define D_EIS ({"polar", "unterwelt"})
#define D_GEIST ({})

/* Die Terrain Types der Elemente */
#define TT_ERZ ({TT_CAVE, TT_MOUNTAIN})
#define TT_FEUER ({TT_DESERT})
#define TT_LUFT ({TT_PLAIN, TT_ROAD, TT_HILL, TT_AIR})
#define TT_HUMUS ({TT_SWAMP, TT_JUNGLE, TT_FOREST})
#define TT_WASSER ({TT_UNDERWATER, TT_WATER})
#define TT_EIS ({TT_ARCTIC})
#define TT_GEIST ({})
#define TT_UNDEF ({TT_OTHER, TT_TOWN, TT_HOUSE})

/* Rassen und deren elementare Vorlieben */
#define E_DWARF ({ ({ERZ, FEUER}), ({LUFT, WASSER}) })
#define E_ELF ({ ({HUMUS, LUFT}), ({EIS, ERZ}) })
#define E_HUMAN ({ ({EIS, LUFT}), ({HUMUS, ERZ}) })
#define E_HOBBIT ({ ({HUMUS, FEUER}), ({EIS, WASSER}) })
#define E_DARKELF ({ ({EIS, ERZ}), ({HUMUS, LUFT}) })
#define E_FAIRY ({ ({HUMUS, WASSER}), ({EIS, FEUER}) })
#define E_OGRE ({ ({WASSER, ERZ}), ({FEUER, LUFT}) })
#define E_DEFAULT ({ ({ERZ, HUMUS}), ({LUFT, EIS}) })
#define E_GAFFO ({ ({EIS, FEUER}), ({HUMUS, WASSER})})

// Verknuepfungen
#define ELEMENT2TERRAIN\
     ([FEUER: TT_FEUER,\
       WASSER:TT_WASSER,\
       HUMUS: TT_HUMUS,\
       EIS: TT_EIS,\
       LUFT: TT_LUFT,\
       ERZ: TT_ERZ,\
       GEIST: TT_GEIST,\
       "default": ({})])

#define ELEMENT2DOMAINS\
     ([FEUER: D_FEUER,\
       WASSER:D_WASSER,\
       HUMUS: D_HUMUS,\
       EIS: D_EIS,\
       LUFT: D_LUFT,\
       ERZ: D_ERZ,\
       GEIST: D_GEIST,\
       "default": ({})])
       
// COLORS
#define ELEMENT_COLORS\
      ([WASSER: ANSI_BLUE,\
        FEUER:  ANSI_RED,\
        HUMUS:  ANSI_GREEN,\
        LUFT:   ANSI_CYAN,\
        ERZ:    ANSI_YELLOW,\
        EIS:    ANSI_PURPLE,\
        GEIST:  ANSI_WHITE,\
      ])

// Elemente und ihre Schaeden
#define ELEMENT_DAMAGE\
     ([FEUER: DT_FIRE,\
       WASSER:DT_WATER,\
       HUMUS: DT_POISON,\
       EIS: DT_COLD,\
       LUFT: DT_AIR,\
       ERZ: DT_BLUDGEON,\
       GEIST:DT_MAGIC\
      ]) 

#define COMPLEMENT_ELEMENTS\
     ([FEUER: WASSER,\
       WASSER: FEUER,\
       HUMUS: EIS,\
       EIS: HUMUS,\
       LUFT: ERZ,\
       ERZ: LUFT,\
       GEIST: GEIST,\
       "default":"default"])

/* Erlaubte Ziele des Luftelementars */
#define LUFT_ZIELE\
  (["midas":({"/d/ebene/Midas/room/room_c5"}),\
    "kyranda":({"/d/ebene/lamuerte/burg/weg/13x9y"}),\
    "feenschloss":({"/d/ebene/ronja/feenquest/room/turm19"}),\
    \
    "felonia":({"/d/gebirge/dusty/weg/m24"}),\
    "trollager":({"/d/gebirge/speedy/trollager/room/t6"}),\
    "arwenock":({"/d/gebirge/iwo/arwenock/room/room_C-03"}),\
    "sturmfels":({"/gilden/paladine/room/w_weg_a1"}),\
    \
    "elessar":({"/d/kristallwald/sargola/dorf/room/1_0514"}),\
    "roch adan":({"/d/kristallwald/chivas/zentauren/room/zen12"}),\
    \
    "derlim":({"/d/huegelland/raballion/hobbits/room/hauptstrasse2"}),\
    "druidenzirkel":({"/gilden/druidenzirkel"}),\
    \
    "fischerdorf":({"/d/wasser/woody/fischerdorf/room/hinterhof"}),\
    "knarkh":({"/d/wasser/stahldorn/knarkh/room/dorf_d5"}),\
    "zombieinsel":({"/d/wasser/dante/zinsel/room/isle_01"}),\
    "mauritius":({"/d/wasser/lupus/mauritius/room/strand03"}),\
    \
    "tijara":({"/d/dschungel/feyaria/tijara/room/wohn_f5"}),\
    "felseninsel":({"/d/dschungel/feyaria/felseninsel/room/hochflaeche"}),\
    "dschungelelfendorf":({"/d/dschungel/feyaria/dorf/room/dorf-013"}),\
    \
    "smoersky":({"/d/polar/lamuerte/dorf/rooms/festland_3"}),\
    "yiqanuc":({"/d/polar/thor/xandim/room/westtor"}),\
    \
    "quaul":({"/d/wueste/protheg/kraterrand/room/krater_4_1_0"}),\
    "arrakeen":({"/d/wueste/protheg/arrakeen/room/ara_3_0_0"}),\
    "echsendorf":({"/d/wueste/gwenshara/echsendorf/room/ttges_1"}),\
    "avir":({"/d/kristallwald/delgo/avir/room/e1-a3-haengebruecke"}),\
    "hypros":({"/d/wasser/rait/hypros/room/room10"}),\
])

/* Erlaubte Ziele des Erzelementars */
#define ERZ_TRANSPORT\
([\
    "midas":({"/d/ebene/Midas/room/room_c5"}),\
    "dhrkion":({"/d/unterwelt/zordan/dhrkion/room/weg-b5"}),\
    "bergwerk":({"/d/gebirge/angrox/room/ebene1/bergwerk_r7"}),\
    "steinstadt":({"/d/gebirge/angrox/4elem/room/stadt/stadt_f8"}),\
])
 
// Eissorten
#define EIS_SORTEN ({\
    "/d/ebene/ronja/feenquest/obj/solero",\
    "/d/ebene/ronja/feenquest/obj/paiper",\
    "/d/polar/thor/xandim/obj/calippo",\
    "/d/polar/thor/xandim/obj/twinni",\
    "/d/polar/thor/xandim/obj/nogger",\
    "/d/polar/thor/xandim/obj/jolly",\
    "/d/polar/thor/xandim/obj/tschisi",\
    })
    
  
// Behandlen!
#define MIN_BEHANDLE 15
#define MAX_BEHANDLE 35

// prozent der XP die man vom Elementar bekommt, wenn es sich aufloest.
#define XP_RATIO 50

#define ELEMENTAL_NAMES ([\
        LUFT: ({"Wirbelwind", "Topas", "Sturm", "Gewitter", "Orkan", \
                "Windhose", "Himmelblau", "Tornado", "Donner",\
                "Donnerhall", "Wirbelsturm", "Himmel", "Wolke"}),\
        ERZ: ({"Granit", "Marmor", "Gipfelstuermer", "Diamant", "Bergkristall",\
               "Opal", "Fels", "Eisenhart", "Erdbeben", "Amboss"}),\
        FEUER: ({"Vulkan", "Lava", "Feuersbrunst", "Rubin", "Flammenmeer", \
                 "Inferno", "Gluthitze", "Magma", "Hitze", "Glut", "Hitze", \
                 "Feuerrot", "Glutrot", "Mittagshitze"}),\
        WASSER: ({"Flutwelle", "Meeresbrandung", "Aquamarin", "Regentropfen", \
                  "Immernass", "Wasserblau", "Sturmflut", "Stromschnelle",\
                  "Ozean", "Ueberschwemmung", "Morgentau"}),\
        EIS: ({"Lawine", "Gletscher", "Eiszapfen", "Saphir", "Neuschnee", \
               "Raureif", "Eiseskaelte", "Frost", "Schneegestoeber", \
               "Schneeflocke", "Eiskristall"}),\
        HUMUS: ({"Flora", "Blumenfreund", "Lebensspender", "Smaragd", \
                 "Dornenranke", "Dornenwall", "Rosendorn", "Blumenwiese",\
                 "Baumwurzel", "Dickicht", "Liane", "Urwald", "Bluetenwirbel"}),\
        ])

/* Kosten fuer die Elementarbefehle */
// Werte sind jetzt im elementar definiert
/* LUFT */  
//#define LUFT_FLIEGEN 100
//#define LUFT_BRINGEN 30
//#define LUFT_MUEDIGKEIT 50  

// #define DISABLE_LUFT_MAGIE 1
// #define DISABLE_LUFT_FLIEGEN 1
// #define DISABLE_LUFT_BRINGEN 1
//#define DISABLE_LUFT_MUEDIGKEIT 1
  
/* ERZ */  
//#define ERZ_EDELSTEIN 60
//#define ERZ_MATERIE 80
//#define ERZ_REPARIEREN 40 
//#define ERZ_SCHUTZ 40
  
// #define DISABLE_ERZ_EDELSTEIN 1
// #define DISABLE_ERZ_MATERIE 1
// #define DISABLE_ERZ_EPARIEREN 1
// #define DISABLE_ERZ_SCHUTZ 1

/* EIS */  
//#define EIS_SCHUTZ 30
//#define EIS_TEMP 30
//#define EIS_SCHUTZHUELLE 30  
//#define EIS_DUNKELHEIT 100
//#define EIS_FRIEREN 80  
//#define EIS_EIS 50  

// #define DISABLE_EIS_SCHUTZ 1
// #define DISABLE_EIS_TEMP 1
// #define DISABLE_EIS_SCHUTZHUELLE 1
//#define DISABLE_EIS_DUNKELHEIT 1
// #define DISABLE_EIS_FRIEREN 1
// #define DISABLE_EIS_EIS 1
  
/* FEUER */  
//#define FEUER_LICHT 10
//#define FEUER_SCHUTZ 30
//#define FEUER_TEMP 30
//#define FEUER_ENTHAARE 5
//#define FEUER_SCHUTZHUELLE 30  

//#define DISABLE_FEUER_LICHT 1
// #define DISABLE_FEUER_SCHUTZ 1
// #define DISABLE_FEUER_TEMP 1
// #define DISABLE_FEUER_ENTHAARE 1
// #define DISABLE_FEUER_SCHUTZHUELLE 1

/* WASSER */  
//#define WASSER_ATMEN 50
//#define WASSER_DURST 30
//#define WASSER_BESCHLEUNIGEN 100  
//#define WASSER_TRINKEN 100
//#define WASSER_PERLEN 60

// #define DISABLE_WASSER_ATMEN 1
// #define DISABLE_WASSER_DURST 1
// #define DISABLE_WASSER_BESCHLEUNIGEN 1
//#define DISABLE_WASSER_TRINKEN 1
//#define DISABLE_WASSER_PERLEN 1

/* HUMUS */  
//#define HUMUS_ENTGIFTEN 100 
//#define HUMUS_HUNGER 30 
//#define HUMUS_ESSEN 100 
//#define HUMUS_AURA  170
//#define HUMUS_LEBEN 50  

//#define DISABLE_HUMUS_ENTGIFTEN 1
//#define DISABLE_HUMUS_HUNGER 1
//#define DISABLE_HUMUS_ESSEN 1
// #define DISABLE_HUMUS_AURA 1
//#define DISABLE_HUMUS_LEBEN 1

// Spell Enhance 
//#define ENHANCE_SPELL_COST 100
// #define DISABLE_ENHANCE_SPELLS 1  

// Well feature
#define DISABLE_WELL_SERVICE_FEATURE 1
#define HUMUS_AURA_OBJ_ID "\nhumusaura\n"  

// Astralring lernt nix
#define ASTRALRING_USAGE_TIME "astralring_usage_time"

// diverse defines fuer die Elementare
#define SPECIAL_HEAT_PROTECTION "feyaria/inferno/room"
#define SPECIAL_COLD_PROTECTION "feyaria/frostania/room"
#define SPECIAL_WATERBREATH "feyaria/aquatika/room"
#define SPECIAL_WINGS "feyaria/djinnistan/room/"

#define NAMED_DRUIDE_ELEMENTAR "\nnamed_druide_elementar"
#define WATERBREATH_OBJ "/d/dschungel/feyaria/kueste/obj/waterbreath"
#define WATERBREATH "\nwaterbreath"
#define WINGS_OBJ "/d/astral/feyaria/djinnistan/obj/wings"
#define WINGS "\nwings"

#define DRUID_ID_ELEMENTAL_BOOST(x) "\ndruid_elemental_booster_"+x
#define P_DRUID_ELEMENTAL_BOOST "druid_elemental_boost_bonus"

void tdm(string str) 
{
  string *y;
  int c;

  for (c = 0; c < sizeof(DRUIDENMAGIER); c++) 
  {
    if(find_player(DRUIDENMAGIER[c]))
	tell_object(find_player(DRUIDENMAGIER[c]), BSA(str, "DRUIDENZIRKEL: "));
  }
}
