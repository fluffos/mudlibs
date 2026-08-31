#include <std.h>
#include <vampq.h>

inherit OBJECT;

void create() {
::create();
set_name("Message");
    set_short("%^RESET%^%^ORANGE%^A small piece of paper%^RESET%^");
	set_long("The note reads:\n\n%^ORANGE%^My dearest friend,\n\nI hope this cloak gets to you in time... I do not trust these old sea dogs but alas, they are the cheapest around and considering the cargo, what choice did I have?\n\nThe girl you have been searching for is rumored to wandering around Tirun. I heard she had an uncle there who owned quite a large house. If his reputation serves me correctly... He is a Dr. of some sort. Prehaps he will do for a sacrifice too? I really do believe that if she is to be anywhere on the mainland there would be the place to search.\n\nWe can't let her escape again! The magics within the mirror will not work forever!\n\n%^RESET%^The note is signed in blood:\n\n%^BOLD%^%^RED%^Kil'thraa%^RESET%^");
	set_id(({"message", "note", "paper"}));
	set_mass(5);
	set_value(0);
}

int query_auto_load() {
    if(this_player()->query_level() >= 40 && this_player()->query_race() == "human") return 1;
}
