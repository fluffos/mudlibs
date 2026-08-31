#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
int rt;
int query_auto_load() { return 1; }
create() {
::create();
    set_id(({"knife", "sacrificial knife","a sacrificial knife"}));
    set_name("sacrificial knife");
    set_short("a sacrificial knife");
    set_long( "This is a sacrificing knife.  The knife itself looks as if it contains "
    "mystic powers.");
    set_mass(9);
    set_wc(2);
    set_type("knife");
    set_hands(1);    
    set_hit((:weapon_hit:));
rt=0;
}
int weapon_hit(object atk) {
if(rt==1) return 1;
if(random(100)) return 1;

say("The priest's eyes begin to glow.  An evil acursed look appears on this face.");
this_player()->force_me("say You shall me sacrificed!");
this_player()->force_me("say May the demons of the underworld impower me with this "
"sacrifice!");
atk->set_hp(-1);
rt=1;
        return 1;
    }
