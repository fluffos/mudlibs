#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("choker");
    set("id", ({"choker", "satanic choker"}) );
    set_short("%^BOLD%^RED%^S%^RESET%^RED%^ata%^RESET%^BOLD%^RED%^n%^RESET%^"
      "%^RED%^i%^RESET%^BOLD%^RED%^c%^RESET%^ %^BOLD%^RED%^C%^RESET%^RED%^ho%^RESET%^"
      "%^BOLD%^RED%^k%^RESET%^RED%^e%^RESET%^BOLD%^RED%^r%^RESET%^");
    set_long("A choker made of %^BOLD%^BLACK%^barbed wire%^RESET%^.  The choker "
      "is covered in %^BOLD%^RED%^b%^RESET%^RED%^l%^RESET%^BOLD%^RED%^o%^RESET%^"
      "%^RED%^o%^RESET%^BOLD%^RED%^d%^RESET%^, as it tightens if the master's requests "
      "are not obeyed.  A small %^BLUE%^pentagram%^RESET%^ dangles off the choker.");
    set_type("collar");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "lyssandra")
	return 1;
}
