#include <std.h>
#include <vampq.h>

inherit OBJECT;

void create()  {
::create();
	set_name("Blood Key");
	set("id", ({"key"}) );
	set_short("%^RESET%^%^RED%^Blood %^RESET%^Key");
	set_long("%^RESET%^The %^RED%^ruby%^RESET%^ at the end of this key is %^BOLD%^%^RED%^blood red%^RESET%^ in colour. At the end of the key %^BOLD%^%^RED%^blood%^RESET%^ drips slowly... %^BOLD%^%^BLACK%^Deathly%^RESET%^...");
	set_weight(1);
}
int query_auto_load() {
	if (this_player()->query_level() >=30)
		return 1;
}
