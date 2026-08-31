#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("badge");
    set("id", ({ "badge", "pk badge of coolness", "pk badge" }) );
    set_short("%^BOLD%^RED%^PK%^RESET%^ %^BOLD%^BLACK%^B%^RESET%^a%^RESET%^"
      "%^BOLD%^BLACK%^dge of%^RESET%^ %^BOLD%^GREEN%^C%^RESET%^GREEN%^o%^RESET%^"
      "%^BOLD%^GREEN%^olne%^RESET%^GREEN%^s%^RESET%^BOLD%^GREEN%^s%^RESET%^");
    set_long("This badge was handed down from the gods to the great "
      "%^BOLD%^BLACK%^Sir Eios Kendt%^RESET%^ for his greatness in the art of "
      "%^BOLD%^RED%^PK%^RESET%^.");
    set_type("badge");
    set_limbs( ({"torso"}) );
}

int bury()
{
    write("What?");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "eios")
	return 1;
}
