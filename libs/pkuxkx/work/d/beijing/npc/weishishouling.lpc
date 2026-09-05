#include "/d/beijing/autok.h"
inherit NPC;

void create()
{
	set_name("侍卫首领", ({
		"shiwei shouling",
		"shouling",
		"shiwei",
	}));
	set("long",
		"他是康亲王府的卫士首领，一副趾高气昂的样子。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("class","officer");
	set("age", 20 + random(20));

	setup();
	set_shiwei_status(120);
}

void init ()
{
    auto_kill(this_player());
}