#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("short", "WarStaff");
    set("long", @ENDLONG
This is the WarStaff, said to hold mystical powers in the hands of 
a magic-user.
ENDLONG
    );
    set("id", ({ "staff", "warstaff" }));
    set("name", "WarStaff");
    set("bulk", 100);
    set("mass", 40);
    set("value",2100);
    set("weapon", 5);
    set("damage", ({ 3, 5 }));
    set_weapon_type("quarterstaff") ;
    set("hit_func", "ilzarion's rookie code") ;
    set_material_type("wood") ;
    set("size", 6);
    set("nosecond", 1);
    set("value", 2650) ;
    set_verbs(({ "swing at", "attack" }) );
} 

varargs
int hit_func(object victim, int damage) {
    int i;
    object bad_guy;
    if (victim) bad_guy = environment()->query_current_attacker() ;
    else bad_guy = victim ;
    if (!environment()->query("spellcaster") &&
      (!environment()->query_level("wizard")) &&
      !environment()->query("mage_spell")) return damage ;
    i = random(100) + 1;
    if (i>8) return damage ;
    bad_guy = environment()->query_current_attacker();
    message("combat",
      "The Warstaff strikes with deadly accuracy, bringing "+
      bad_guy->query("cap_name")+ " to "+possessive(bad_guy->query("gender"))+
      " knees!\n", environment(environment()), bad_guy);
    tell_object(bad_guy, 
      "The Warstaff strikes with deadly accuracy, bringing you to your knees!\n");
    return damage + random(20) + 10 ;
}


