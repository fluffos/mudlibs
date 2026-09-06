#include <drink_defs.h>
inherit DRINK_FILE;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("oil flask");
	set_id(({ "oil", "flask", "flask of oil"}));
	set_short("flask of oil");
	set_value(50);
	set_weight(1);
	set_drinker_mess("AAARGGHHHHHHHH!!!\n");
	set_empty_container("flask");
	set_strength(-1);
    }
}

query_thief_item() { return 1; }
