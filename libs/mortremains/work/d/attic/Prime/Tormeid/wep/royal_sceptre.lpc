// Chronos and Ilzarion balanced this weapon together. :)
#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("short", "Sceptre of Tormeid") ;
    set("hit_func", "ilzarion's shitty code") ;
    set("long", @ENDLONG
The legendary Sceptre of Tormeid is said to contain the actual life
force of the most powerful wizard ever to live.  He decided that
existing within such a weapon would be more useful than simply
rotting in a tomb somewhere, so he imbued this with his own life.
The sceptre has since changed hands many times, and has often
been the deciding factor in many historical battles, most notably
the battles in which the Lords of Tormeid fought the skaven 
invasion in the great Underworld Wars.
ENDLONG
    );
    set("id", ({ "sceptre", "sceptre of tormeid" }) ) ;
    set("dest_at_sell", 1);
    set("name", "Sceptre of Tormeid") ;
    set("value",26500) ;
    set_weapon_type("mace") ;
    set_bonus(4);
    set_material_type("metal/gold") ;
    set("size", 6) ;
    set_verbs(({
      "swing at",
      "attack",
    }) );
   set("damage", ({ 6, 16 }) ) ;
}

varargs int hit_func(object victim, int damage) {
    if (random(20)) return damage;
    if (!environment()) return damage ;
    if (!victim) victim=environment()->query_current_attacker() ;
    if (!random(20)) {
	message("combat", 
	  wrap("A massive gout of green flames pours forth from the sceptre, burning "+
	    victim->query("cap_name")+" severely!"), environment(environment()),
	  ({ victim }) ) ;
	message("combat", wrap(
	    "A massive gout of green flames pours forth from the sceptre, burning you severely!"),
	  victim ) ;
	victim->receive_damage(30 + random(30), "fire") ;
	return damage ;
    }
    message("combat", wrap(
	"The Sceptre of Tormeid glows brightly with power, and a loud hum fills the air."), environment(environment()), ({ environment() }) ) ;
    message("combat", wrap("The Sceptre of Tormeid glows brightly and seems to guide your attack!"), environment()) ;
    return damage + random(15) + 10 ;
}



