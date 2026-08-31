#include <std.h>
inherit PACK;
void create() {
    ::create();
    set_id( ({"sack"}) );
    set_name("sack");
    set("short", "%^BLUE%^Et%^BOLD%^he%^CYAN%^r%^WHITE%^ea%^CYAN%^l%^BLUE%^%^BOLD%^ Sa%^RESET%^%^BLUE%^ck%^RESET%^");
    set_weight(19);
    set("long", "%^CYAN%^This is a holy sack from the Guild of the Ethereal. To store items use <put item in sack>. Use <close sack> and <open sack> to keep it opened or closed.%^RESET%^");
    set_curr_value("gold", 50);
    set_max_internal_encumbrance(900);
    set_possible_to_close(1);
}

int query_auto_load() {
    if(this_player()->query_guild() == "ethereal") {
	return 1;
    }
}


