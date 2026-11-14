// /obj/tools/astral.h   Definitionsdatei zum Astralschwert
// 15-12-98   Ezo

#include <defines.h>

// Makros

#define ESC "
#define STRICHE     "--------------------------------------------------"\
                    "---------------------------\n"
#define OTHER_VERBS  ({"showhelp","showroom","createroom"})
#define SHOW_VERBS   ({"showdetail","shownight","showread","showsmell",\
                       "showsound","showspecial","showcommand","showfood",\
                       "showdrink","showexit","showitem"})
#define ADD_VERBS    ({"adddetail","addnight","addread","addsmell",\
                       "addsound","addspecial","addcommand","addfood",\
                       "adddrink","addexit","additem"})
#define REMOVE_VERBS ({"removedetail","removenight","removeread",\
                       "removesmell","removesound","removespecial",\
                       "removecommand","removefood","removedrink",\
                       "removeexit","removeitem"})
#define EDIT_VERBS   ({"editlong","editnightlong","editshort","edittemp",\
                       "editroom","editterrain","editlight","editday"})
#define VALID_VERBS  OTHER_VERBS+SHOW_VERBS+ADD_VERBS+REMOVE_VERBS+EDIT_VERBS
#define KEYS         ({"P_INT_LONG","P_INT_NIGHTLONG","P_INT_SHORT",\
                       "P_TEMPERATURE","P_INDOORS","P_TERRAIN",\
                       "P_LIGHT","P_ISDAY_OVERRIDE","AddDetail","AddDetail",\
                       "AddReadDetail","AddSmell","AddSound",\
                       "AddSpecialDetail","AddCmd","AddFood","AddDrink",\
                       "AddExit","AddItem","Raum"})
#define TYPES        ({"Langbeschreibung","Nachtlangbeschreibung",\
                       "Kurzbeschreibung","Temperatur","Raumzustand",\
                       "Terraintyp","Lichtlevel","Tagzustand",\
                       "Detail","Detail","ReadDetail","Smell","Sound",\
                       "SpecialDetail","Command","Essen","Drink",\
                       "Exit","Item","Raum"})
#define TERRAIN_TYPES_IN ({"Höhle","Verlies","Gebäude","Bergwerk",\
                         "unter Wasser","Gewölbe"})
#define TERRAIN_TYPES_OUT ({"Arktis","Lehm","Wüste","Wald","Dschungel",\
                         "Hügel","Berg","Ebene","Straße","Fels",\
                         "Sumpf","Stadt","Tundra","Wasser"})
#define TERRAIN_TYPES TERRAIN_TYPES_IN+TERRAIN_TYPES_OUT
#define TERRAIN_TYPES_IN_ORG ({"CAVE","DUNGEON","HOUSE","MINE",\
                        "UNDERWATER","VAULT"})
#define TERRAIN_TYPES_OUT_ORG ({"ARCTIC","CLAY","DESERT","FOREST",\
                        "JUNGLE","HILL","MOUNTAIN","PLAIN","ROAD","ROCK",\
                        "SWAMP,"TOWN","TUNDRA","WATER"})
#define TERRAIN_TYPES_ORIGINAL ({"CAVE","DUNGEON","HOUSE","MINE",\
                        "UNDERWATER","VAULT","ARCTIC","CLAY","DESERT",\
                        "FOREST","JUNGLE","HILL","MOUNTAIN","PLAIN","ROAD",\
                        "ROCK","SWAMP","TOWN","TUNDRA","WATER"})
#define INDOOR_TYPES  ({"freier Himmel","geschlossener Raum",\
                        "Raum mit Ausblick","unter Wasser"})
#define INDOOR_TYPES_ORIGINAL ({"OUTDOORS","CLOSED","OPEN","UNDERWATER"})
#define DAY_TYPES     ({"normale Tagzustände","immer Nacht","immer Tag"})
#define SHORT_EXITS   ({"n","no","o","so","s","sw","w","nw","u","ob"})
#define LONG_EXITS    ({"norden","nordosten","osten","südosten","süden",\
                        "südwesten","westen","nordwesten","unten","oben"})

#define ANZAHL(x,y)     sizeof(mkmapping(m_values(\
                          (mappingp(x->QueryProp(y))?x->QueryProp(y):([])))))
#define WTE(x)          tell_object(find_player("ezo"),to_string(x))
#define BS(x)           break_string("\n"+x, 78)
#define TP              this_player()
#define TPN             TP->name()
#define TO              this_object()
#define TPP		TP->QueryPronoun()
#define TPPP		TP->QueryPossPronoun()
#define TI		this_interactive()
#define ENV(x)		environment(x)
#define INV(x)		all_inventory(x)
#define SUID		seteuid(getuid(this_object()))

// Prototypen

void nixda();
int astralcommands(string str);
void showhilfe();
void showroom();
varargs void createroom(string str,mixed *extra);
void show(int key);
void add1(int key);
varargs void add2(string str,string datei,int *zeilennummern,int key,string extra);
void remove1(int key);
void remove2(string str,string datei,int *zeilennummern,int key);
void edit1(int key);
void edit2(string str,string datei,int *zeilennummern,int key);
string liste(string *arr);
void savefile(string str,string datei,string savefile,int key,string text);
int *createfind(string datei);
int *dateiinfo(string datei,string *zeilen,int key);
