#pragma strong_types

// Hochzeit
#define KLEIDUNG "\ndelfenhochzeitskleidung" 
#define TRAUSCHEIN "\ntrauschein"
#define HZM ROOM "hzm"
#define GESINNUNG ROOM "gm"
#define LLOTH "/gilden/spinnenkrieger/master/lloth"

// Fuer Details, die Dunkelelfen oder Zwerge anders sehen als andere Rassen
#define AddDetail_DSpc( k, x, y) \
        AddDetail( (k), ([ 0 : x, "dunkelelf" : y ]) )
#define AddDetail_DZSpc( k, x, y) \
        AddDetail( (k), ([ 0 : x, "dunkelelf" : y, "zwerg" : y ]) )
#define AddDetail_D_ZSpc( k, x, y, z) \
        AddDetail( (k), ([ 0 : x, "dunkelelf" : y, "zwerg" : z ]) )
#define AddSound_DSpc( k, x, y) \
        AddSound( (k), ([ 0 : x, "dunkelelf" : y ]) )

#define IS_DROW(x) (x->QueryProp(P_RACE)=="Dunkelelf")
#define IS_DWARF(x) (x->QueryProp(P_RACE)=="Zwerg")

// Kennungen fuer die einzelnen Schreine im Tempelgelaende
#define SCHREIN_RISS    1
#define SCHREIN_SPINNE  2
#define SCHREIN_BECKEN  3
#define SCHREIN_TAFEL   4

// Funktionsdeklaration fuer den Gesinnungsmster
//int gesMas_aendere_gesinnung( object player, object room, int schrein);
