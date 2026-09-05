//Cracked by Roath
// Npc: 五等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);
int auto_kill(object player);
void create()
{
	set_name("五等侍卫", ({
		"wudeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是一个低级御前侍卫。\n");
	set("class","officer");
	set("age", 20 + random(20));
	set("shen_type",1);set("score",1000);setup();
	set_shiwei_status(50);

}
void init ()
{
    auto_kill(this_player());
}
#include "/d/beijing/autok.h"
