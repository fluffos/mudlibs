// HEADER fuer die Bardengilde fuer externe Verwendung

#define BARDENMASTER "/gilden/bardengilde/master/bardenmaster"
#define TALENTMASTER "/gilden/bardengilde/master/talentmaster"

#define GUILDNPC_LONGNAME "Artyrian, der Meisterbarde"
#define GUILDNPC_NAME "Artyrian"
#define GUILDNPC_ID "\nartyrian"
#define BARDENBROSCHE "\nbardenbrosche"
#define BARDENITEM "\nbardenitem"
#define BARDENTASK "\nbardentaskitem"
#define GUILD_ALLOWED_OBJ BARDENITEM+"_schreiben"
#define SK_SINGING "Singen"
#define SK_MUSIC "Musizieren"

#define P_BARDEN_SPELLCOST "barden_spellcost"
#define P_BARDEN_BONUS "barden_bonus"
#define P_BARD_DISPLAY_COLOR "bard_display_color"
#define P_BARD_INSPIRATION "bard_inspiration"
#define P_BARD_LAST_INSPIRED "bard_last_inspired"
#define P_BARD_INSPIRATION_LEVEL "bard_inspiration_level"
#define P_BARD_TMP_NEXT_SPELL_IS_MAX_SUCCESS "bard_tmp_next_spell_is_max_success"
#define P_BARD_GROUP "bard_group"

#define BARD_GROUP_KORRIAX "korriax"
#define BARD_GROUP_ALESTRA "alestra"
#define BARD_GROUP_TIRENA "tirena"
#define BARD_GROUP_SARRIAN "sarrian"

#define BARD_ID_GS7_STROPHE_1 "\nbard_gs7_strophe1"
#define BARD_ID_GS7_STROPHE_2 "\nbard_gs7_strophe2"
#define BARD_ID_GS7_STROPHE_3 "\nbard_gs7_strophe3"
#define BARD_ID_GS7_BRIEF "\nbard_gs7_brief"
#define BARD_ID_GS8_BRILLE "\nbard_gs8_item_tirena"
#define BARD_ID_GS8_KERZE "\nbard_gs8_item_alestra"
#define BARD_ID_GS8_TASK "\nbard_gs8_item_sarrian"
#define BARD_ID_GS10_TASK "\nbard_gs10_task"
#define BARD_ID_GS10_TASK_FRIEND "\nbard_gs10_task_friend"

#define BARD_GROUP(pl) "/gilden/bardengilde/master/bardenmaster"->GetBardGroup(pl)

#define TRAVEL_GOALS\
  (["midas":"/d/ebene/Midas/room/room_c5",\
    "kyranda":"/d/ebene/lamuerte/burg/weg/13x9y",\
    "feenschloss":"/d/ebene/ronja/feenquest/room/turm19",\
    \
    "felonia":"/d/gebirge/dusty/weg/m24",\
    "trollager":"/d/gebirge/speedy/trollager/room/t6",\
    "arwenock":"/d/gebirge/iwo/arwenock/room/room_C-03",\
    "sturmfels":"/gilden/paladine/room/w_weg_a1",\
    \
    "elessar":"/d/kristallwald/sargola/dorf/room/1_0514",\
    "zentaurenstadt":"/d/kristallwald/chivas/zentauren/room/zen12",\
    "bardengilde":"/gilden/bardengilde",\
    "ardhmir":"/d/kristallwald/chivas/zwergenfeste/room/zwfe18",\
    \
    "derlim":"/d/huegelland/raballion/hobbits/room/hauptstrasse2",\
    "druidenzirkel":"/gilden/druidenzirkel",\
    "holzfaellerlager":"/d/huegelland/zordan/holzfaeller/room/room-d2",\
    \
    "fischerdorf":"/d/wasser/woody/fischerdorf/room/hinterhof",\
    "knarkh":"/d/wasser/stahldorn/knarkh/room/dorf_d5",\
    "zombieinsel":"/d/wasser/dante/zinsel/room/isle_01",\
    "mauritius":"/d/wasser/lupus/mauritius/room/strand03",\
    \
    "tijara":"/d/dschungel/feyaria/tijara/room/wohn_f5",\
    "felseninsel":"/d/dschungel/feyaria/felseninsel/room/hochflaeche",\
    "dschungelelfendorf":"/d/dschungel/feyaria/dorf/room/dorf-013",\
    \
    "smoersky":"/d/polar/lamuerte/dorf/rooms/festland_3",\
    "yiqanuc":"/d/polar/thor/xandim/room/westtor",\
    \
    "quaul":"/d/wueste/protheg/kraterrand/room/krater_4_1_0",\
    "arrakeen":"/d/wueste/protheg/arrakeen/room/ara_3_0_0",\
    "echsendorf":"/d/wueste/gwenshara/echsendorf/room/ttges_1",\
    "avir":"/d/kristallwald/delgo/avir/room/e1-a3-haengebruecke",\
    "hypros":"/d/wasser/rait/hypros/room/room10",\
    \
    "dhrkion":"/d/unterwelt/zordan/dhrkion/room/weg-b5",\
    "bergwerk":"/d/gebirge/angrox/room/ebene1/bergwerk_r7",\
    "steinstadt":"/d/gebirge/angrox/4elem/room/stadt/stadt_f8",\
    "sternenwald":"/d/unterwelt/ronja/sternenwald/room/eingang",\
    \
    "nexus": "/d/astral/feyaria/astral/room/nexus",\
    "yaq'monoq": "/d/unterwelt/nekromanten/room/yaq_monoq/isteg",\
    "erg": "/d/wueste/arthoas/erg/room/aragh/raum44",\
])