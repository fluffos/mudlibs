#define WMASTER ZONE "master/master"
#define SMASTER ZONE "master/save_master"
#define DMASTER ZONE "master/death_master"
#define LMASTER ZONE "master/list_master"
#define UMASTER ZONE "master/unique_master"
#define IMASTER ZONE "master/item_master"
#define WPMASTER "/d/ebene/wraz/metzelorgie/master/weapon_master"
#define TPU getuid(this_player())
#define DEATHLIST ZONE "list/toppfadsterbeliste.read"
#define KILLLIST ZONE "list/toppfadkillliste.read"

// Heldenpunkte fuer /npc/ahtawqa.c und /weapon/sterbewaffe.c
#define STUFE1 6835
#define STUFE2 15254
#define STUFE3 25622
#define STUFE4 38392
#define STUFE5 54120
#define STUFE6 73491
#define STUFE7 97349
#define STUFE8 126732
#define STUFE9 162922
#define STUFE10 207493
#define STUFE11 262389
#define HELDENPUNKTE 330000

// Default Lebensdauer der Sterbeobjekte
// WLT: weapon life time, 90 Tage
#define WLT 7776000
// FLT: focus life time, 45 Tage
#define FLT 3888000

// Schwellwerte fuer Uniques/Rares
#define UNIQUE_XP_MIN 500
#define RARE_XP_MIN 20