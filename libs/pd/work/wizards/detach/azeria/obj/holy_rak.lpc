#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Holy Battle armour");
    set_short("%^YELLOW%^Ho%^BLUE%^l%^BOLD%^%^BLUE%^y "
      "Ba%^WHITE%^tt%^RESET%^%^BLUE%^l%^YELLOW%^e "
      "Ar%^RESET%^%^BLUE%^m%^BOLD%^%^BLUE%^ou%^BOLD%^%^WHITE%^r%^RESET%^");
    set_long("This Armour was formed for the great battle of The Hellion. "
      "It belongs to one of the great priest of the battle.");
    set_id( ({ "armour" , "holy battle armour" }) );
    set_ac(8);
    set_mass(30);
    set_type("body armour");
    set_limbs( ({ "first arm","second arm","third arm","fourth arm","torso","abdomen"}) );
}                  
int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}
