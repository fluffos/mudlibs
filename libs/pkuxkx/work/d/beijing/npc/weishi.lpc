#include "/d/beijing/autok.h"

inherit NPC;

void create()
{
	set_name("康府侍卫", ({
		"shi wei",
		"wei",
		"shi",
	}));
	set("long",
		"这是一个康亲王府侍卫，正警觉的盯着四周。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");
	set("class","officer");

	set("age", 20 + random(20));

	setup();
	set_shiwei_status(80);
}

void init ()
{
    auto_kill(this_player());
}