#include <std.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"sword", "blade"}));
    set_name("blade of souls");
    set_short("%^BOLD%^%^WHITE%^B%^BOLD%^%^BLACK%^l%^WHITE%^a%^BOLD%^%^BLACK%^d%^WHITE%^e %^BOLD%^%^BLACK%^o%^WHITE%^f %^BOLD%^%^BLACK%^S%^WHITE%^o%^BOLD%^%^BLACK%^u%^WHITE%^l%^BOLD%^%^BLACK%^s%^RESET%^");
    set_long( "This sword appears to be an excellent weapon. Its blade is "
      "crafted of a deep obsidian, inscribed with ornate runes. Its hilt is made of a "
      "fine ivory. The blade casts a faint, eerie light across its surroundings."
    );
    set_mass(80+random(10));
    set_curr_value("gold",110+random(40));
    set_wc(11);
    set_ac(2);
    set_type("blade");
    set_wield("The hilt of the blade molds to your hand.");
    set_unwield("You unwield the sword.");
    set_hit((:this_object(), "weapon_hit":));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 30) {
        write("%^BOLD%^%^BLACK%^Your blade drains the life-force of your opponents soul into your body, adding to your own.%^RESET%^");
        say("%^BOLD%^%^BLACK%^"+(string)this_player()->query_cap_name()+"'s blade draws some power from "+this_player()->query_possessive()+".%^RESET%^");
        result=(random(25+random(30)-random(15))*((this_player()->query_level()/20)+1));
        return result;
    }
}
 int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
