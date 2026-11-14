#define BOGENQUEST    "Der Wettkampf der Bogenschuetzen"
#define BOGENQUESTLOG "/log/quests/bogen"
#define BOGENQUESTID  "\nbogenschuetzenquest"
#define BOGENQUEST_DIR "/d/dschungel/feyaria/dorf/"

#define QUEST_HOLZ    "\nbogenquest_holz"
#define QUEST_PFEIL   "\nbogenquest_pfeil"
#define QUEST_SPITZE  "\nbogenquest_pfeilspitze"
#define QUEST_WFEDER  "\nbogenquest_feder_weiss"
#define QUEST_SFEDER  "\nbogenquest_feder_schwarz"
#define QUEST_BOGEN   "\nbogenquest_bogen"
#define QUEST_LIANE   "\nbogenquest_liane"
#define QUEST_STOCK   "\nbogenquest_stock"
#define QUEST_STAHL   "\nbogenquest_zwergenstahl"
#define QUEST_FUTTER  "\nbogenquest_futter"

#define BQ_ZETTEL_BEKOMMEN  0x001
#define BQ_STOCK            0x002
#define BQ_LIANE            0x004
#define BQ_BOGENBAUEN       0x008
#define BQ_ZWERGENSTAHL     0x010
#define BQ_PFEILSPITZE      0x020
#define BQ_HOLZ             0x040
#define BQ_WFEDER           0x080
#define BQ_FUTTER           0x100
#define BQ_SFEDER           0x200
#define BQ_PFEILBASTELN     0x400
#define BQ_GEUEBT           0x800
#define BQ_ALLE_TEILE       0xFFF

#define QUESTSTRING ([0x001:"Zettel bekommen", 0x002:"Stock gefunden", \
    0x004:"Liane abgeschnitten", 0x008:"Bogen gebaut", \
    0x010:"Zwergenstahl bekommen", 0x020: "Pfeilspitze geschmiedet", \
    0x040:"Pfeilschaft bekommen", 0x080:"weisse Feder gefunden",\
    0x100:"Futter eingesammelt", 0x200:"schwarze Feder bekommen", \
    0x400: "Pfeil gebastelt", 0x800: "Bogenschiessen geuebt", \
    0xFFF: "Fertig!!!!!"])
