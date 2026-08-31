#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                
void create() {
    ::create();                                                                    
    set_name("Lava Dagger");
    set("id", ({ "dagger" }) );
    set("short", "%^RESET%^%^ORANGE%^L%^RED%^a%^ORANGE%^v%^RED%^a %^ORANGE%^D%^RED%^a%^ORANGE%^gg%^RED%^e%^ORANGE%^r%^RESET%^");
    set("long", "%^BOLD%^%^ORANGE%^This dagger was made in the depths of hell.  The blade seems to be made from molten rock.%^RESET%^" );
    set_type("dagger");
    set_weight(40);
    set_curr_value("gold", 200);
    set_wc(12);
    set_type("knife");
    set_decay_rate(200);
    set("skill level", 200);
}
int query_auto_load() {
    if (this_player()->query_level() >= 45)
	return 1;
}
