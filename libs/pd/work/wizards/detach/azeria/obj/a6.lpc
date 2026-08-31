#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Holy Battle armour");
    set_short("%^BOLD%^%^YELLOW%^Ho%^BLUE%^ly Ba%^WHITE%^tt%^RESET%^%^BLUE%^l%^BOLD%^%^YELLOW%^e Ar%^RESET%^%^BLUE%^m%^BOLD%^%^BLUE%^ou%^WHITE%^r%^RESET%^");
    set_long("This Armour was formed for the great battle of The Hellion. "
"It belongs to one of the great priest of the battle.");
    set_id( ({ "armour" , "holy battle armour" }) );
    set_ac(8);
    set_mass(30);
     set_curr_value("gold",150+random(40));
    set_type("body armour");
    set_limbs( ({ "right leg","left leg","right arm","left arm","torso","head"
}) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
