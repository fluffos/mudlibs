/*
** FILE:    cyberware.c
** PURPOSE: The inheritable cyberware object.
** CREDITS:
**  22 Jun 1999  Cyanide created this file.
*/

// Includes
#include <move.h>
#include <daemons.h>

// Defines
#define STANDARD    0
#define ALPHA       1
#define BETA        2
#define DELTA       3

// Prototypes
void std_deactivate();
int query_essence();
int activate( object );
int deactivate( object );

inherit OBJECT;

/*******************************************************************/
// FUNCTION:    int std_activate( object )
// PURPOSE:     Does all the math for when cyberware is activated.
// RECEIVES:    
//      object player    The user who is using this item. This MUST
//                       also be the object's environment().
// PASSES:      
//      0   Fail
//      1   Success

int std_activate ( object player ) {
    int essence, essence_cost;

    if (query("activated")) return 0;

    if (!player || player != environment()) return 0;

    if (!activate(player)) return 0;

    essence = player->query("essence");
    essence -= query_essence();

    // No player may have an essence of 0 or less.
    if (essence - essence_cost <= 0) return 0;

    player->set("essence", essence);

    set("activated", 1);
    return 1;
}


/*******************************************************************/
// FUNCTION:    void std_deactivate( void )
// PURPOSE:     Does all the math for when cyberware is deactivated
// RECEIVES:    
//      void
// PASSES:      
//      void

void std_deactivate () {
    object owner = environment( this_object() );

    if (!owner) return;
    if (!query("activated")) return;

    deactivate( owner );

    owner->add("essence", query_essence() );

    return;
}


/*******************************************************************/
// Cyberware has its own move function which gracefully deactivates
// the ware if it is SOMEHOW moved. This works the same way armor 
// does.

int move (mixed dest) {
    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if (query("activated")) {
	    std_deactivate();
	}
    }
    return ::move(dest) ;
}


/*******************************************************************/
// Similarly, cyberware has its own remove function, to deactivate
// the cyberware if it is dested or in some other way destructed.

int remove() {
    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if (query("activated")) {
	    std_deactivate();
	}
    }
    return ::remove() ;
}


/*******************************************************************/

void create() {
    // This shows that this is cyberware.
    // It also is used as a flag to help ensure the standard create()
    // function is called, and not totally overridden.
    set("cyberware", 1);    

    // This is the quality of the cyberware.
    set("quality", STANDARD);

    // Make sure this thing doesn't go very far once on the player.
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_clean", 1);
    set("prevent_sell", 1);
}


/*******************************************************************/
// FUNCTION:    int activate() and int deactivate
// PURPOSE:     These are called when the ware is activated or
//              deactivated.
// RECEIVES:    
//      object owner    The owner.
// PASSES:      
//      0   Failed (blocks activate, but deactivate ignores this)
//      1   Success

int activate( object owner ) { return 1; }
int deactivate( object owner ) { return 1; }


/*******************************************************************/

int query_auto_load() { return 1; }


/*******************************************************************/

int query_cyberware() { return query("cyberware"); }


/*******************************************************************/

int query_essence() {
    int e = query("essence");

    switch((int)query("quality")) {
    case ALPHA :    e = (e*4)/5; break;     // -20% Essence
    case BETA :     e = (e*3)/5; break;     // -40% Essence
    case DELTA :    e = e/2; break;         // -50% Essence
    }

    return e;
}

/**[ EOF ]**********************************************************/
