/* brooch.c
// This object is what provides the ability to breathe underwater.
// All underwater rooms in this area will query the player to
// make sure they have it, and damage them appropriately if they
// do not :)
// It is armor type brooch only so it can be worn, not to provide protection.
*/

#include <mudlib.h>
#include "../ww.h"
#include "/u/d/dragoon/include/format.h"

inherit ARMOR ;

void create() {
    set("id", ({ "brooch", "silver brooch", "tarnished silver brooch", "#BROOCH#" })) ;
    set("short", "tarnished silver brooch") ;
    set("long", format(
	"A small silver brooch very tarnished with age. "
	"It is shaped into the ancient trident symbol of the mer-folk. "
	"A magical energy seems to radiate from it. "
	"It might be able to aid you underwater. "
      )) ;
    set("value", 0) ;
    set("mass", 0) ;
    set("bulk", 0) ;
    set("type", "brooch") ;
    set("armor", 0) ;
}

/* EOF */

