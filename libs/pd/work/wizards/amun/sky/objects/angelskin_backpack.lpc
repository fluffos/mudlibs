#include <std.h>
#include <amun.h>
inherit ARMOUR;
inherit PACK;
void create() {
    set_id( ({"angelskin", "angelskin backpack", "backpack", "pack"}) );
    set_name("angelskin backpack");
    set_short("%^BOLD%^%^YELLOW%^A%^WHITE%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^YELLOW%^e%^WHITE%^l%^RESET%^%^ORANGE%^s%^BOLD%^%^YELLOW%^k%^WHITE%^i%^RESET%^%^ORANGE%^n %^BOLD%^%^YELLOW%^B%^WHITE%^a%^RESET%^%^ORANGE%^c%^BOLD%^%^YELLOW%^k%^WHITE%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^c%^WHITE%^k%^RESET%^");
    set_weight(20);
    set_long("%^RESET%^%^ORANGE%^This %^BOLD%^%^YELLOW%^backpack %^WHITE%^was %^RESET%^%^ORANGE%^made %^BOLD%^%^YELLOW%^by %^WHITE%^the %^RESET%^%^ORANGE%^Fallen %^BOLD%^%^YELLOW%^Angels %^WHITE%^in %^RESET%^%^ORANGE%^the %^BOLD%^%^YELLOW%^Temple. %^WHITE%^It %^RESET%^%^ORANGE%^holds %^BOLD%^%^YELLOW%^quite %^WHITE%^a %^RESET%^%^ORANGE%^bit %^BOLD%^%^YELLOW%^for %^WHITE%^being %^RESET%^%^ORANGE%^a %^BOLD%^%^YELLOW%^meer %^WHITE%^backpack.%^RESET%^");
    set_curr_value("gold", 250);
    set_max_internal_encumbrance(1600);
    set_possible_to_close(1);
    set_type("backpack");
    set_limbs( ({"torso"}) );
}

/*
string query_long_look() {
  string ret="", tmp;

  if (tmp = query_long_contents())
    ret += tmp+"\n";
  if (tmp = query_long_full())
    ret += tmp+"\n";

  return ret;
}
*/
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
