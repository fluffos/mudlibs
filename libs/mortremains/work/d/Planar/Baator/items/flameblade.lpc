//ilz

#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(4);
    set("author", "cyanide");
    set_weapon_type("sword/long");
    set("value",   3000);
    set("id", ({ "flame blade", "sword", "blade" }) );
    set("short", "The Flaming Blade of Malphas");
    set("long", wrap("This is the legendary flaming blade of "+
	"Malphas, the High Commander under Bel. The blade is long and "+
	"wavy, and is incredibly sharp. As you pick it up, blue flames "+
	"flicker along the blade. This weapon is rumored to be "+
	"especially effective against trolls and undead."));
    set("name", "Flame blade");
    set("hit_func", 1); 
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;

}
int hit_func(object targ, int damage){
    if (targ->query("undead")) damage*=2;
    if (targ->query("race") == "troll") damage*=2;
    return damage;
}

