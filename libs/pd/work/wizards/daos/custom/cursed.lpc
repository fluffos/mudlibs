#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("amulet");
    set("id", ({"amulet", "cursed skull amulet of the dead"}) );
    set_short("%^BOLD%^BLACK%^C%^RESET%^BOLD%^MAGENTA%^u%^RESET%^BOLD%^BLACK%^r"
      "%^BOLD%^MAGENTA%^s%^RESET%^BOLD%^BLACK%^e%^RESET%^BOLD%^MAGENTA%^d%^RESET%^ "
      "Skull %^RED%^Amulet%^RESET%^ of the %^BOLD%^BLACK%^Dead%^RESET%^");
    set_long("This %^RED%^amulet%^RESET%^ is made from the %^BOLD%^BLACK%^skull"
      "%^RESET%^ of a once %^BOLD%^RED%^powerful%^RESET%^ %^BOLD%^BLACK%^n%^RESET%^"
      "%^BOLD%^MAGENTA%^e%^RESET%^BOLD%^BLACK%^c%^RESET%^BOLD%^MAGENTA%^r%^RESET%^"
      "%^BOLD%^BLACK%^o%^RESET%^BOLD%^MAGENTA%^m%^RESET%^BOLD%^BLACK%^a%^RESET%^"
      "%^BOLD%^MAGENTA%^n%^RESET%^BOLD%^BLACK%^c%^RESET%^BOLD%^MAGENTA%^e%^RESET%^"
      "%^BOLD%^BLACK%^r%^RESET%^.  Dark %^MAGENTA%^shadows%^RESET%^ %^BLUE%^s%^RESET%^w"
      "%^BLUE%^i%^RESET%^r%^BLUE%^l%^RESET%^ within the %^RED%^eyes%^RESET%^ and it "
      "seems to be filled with the %^BOLD%^YELLOW%^power%^RESET%^ of the %^BOLD%^"
      "%^BLACK%^soul%^RESET%^ held within.");
    set_type("amulet");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "teeto")
	return 1;
}
