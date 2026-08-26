/* File: armour.c 
**  Purpose: You figure it out, duh...
**  Date: July 30th, 1997
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
**    8 Oct 97 Cyanide added the init/remove thing to clean up the mud!
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
void create() {
    set("short", "a bright red Santa suit");
    set("long", wrap("A bright red Santa suit, white trimming and "+
	"all. You feel kinda stupid wearing it.") );
    set("id", ({ "newbie_equipment", "suit", "santa suit", "armour" }) );
    set_armor_type("leather");
    set("size", -1);
    set("value", 0);
}

void init() {
    object env = environment(this_object());

    if (env && !living(env))
	call_out("remove", 1);
}

void remove() {
    object env = environment(this_object());

    if (env) tell_room(env,
	  "The newbie item crumbles to dust and blows away.\n");
    ::remove();
}
