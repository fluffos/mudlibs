#include <std.h>

inherit ARMOUR;

void create() {
    ::create();

    set("id", ({"collar", "leather collar", "black leather collar" }) );
    set_name("collar");
    set_short("A small, black leather collar");
    set_long("%^BOLD%^%^BLACK%^The small, black leather collar rests beautifully tight around the "
      "neck and is held by a silver buckle in the back.  A %^BOLD%^%^WHITE%^silver%^ %^BOLD%^%^BLACK%^%^plate "
      "at the front of it is inscribed in a bold and beautiful font which looks to have been engraved by a very "
      "adept hand.  \nUpon further inspection, the inscription reads, %^BOLD%^%^MAGENTA%^@%^RESET%^ %^GREEN%^}->-- "
      "%^MAGENTA%^D%^ %^BOLD%^%^BLACK%^u%^RESET%^ %^MAGENTA%^e%^ %^BOLD%^%^BLACK%^r%^RESET%^ %^MAGENTA%^a%^ "
      "%^GREEN%^--<-{ %^BOLD%^MAGENTA%^@%^\n");
    set_type("collar");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "sugarcandy")
	return 1;
}
