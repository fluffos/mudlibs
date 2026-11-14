/** func.h
 ** Headerdatei fuer Funktionen und Makros */

// ---------- Makros
// Fuer Details, die Dunkelelfen oder Zwerge anders sehen als andere Rassen
#define AddDetail_DSpc( k, x, y) \
        AddDetail( (k), ([ 0 : x, "dunkelelf" : y ]) )
#define AddDetail_DZSpc( k, x, y) \
        AddDetail( (k), ([ 0 : x, "dunkelelf" : y, "zwerg" : y ]) )
#define AddSound_DSpc( k, x, y) \
        AddSound( (k), ([ 0 : x, "dunkelelf" : y ]) )


// Kennungen fuer die einzelnen Schreine im Tempelgelaende
#define SCHREIN_RISS    1
#define SCHREIN_SPINNE  2
#define SCHREIN_BECKEN  3
#define SCHREIN_TAFEL   4

// Funktionsdeklaration fuer den Gesinnungsmster
int gesMas_aendere_gesinnung( object player, object room, int schrein);

        
// Damit der xemacs weniger Aerger bekommt
#define CLOSURE( x) #'x

