//Cracked by Roath
// Npc: 三等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);
int auto_kill(object player);
void create()
{
	set_name("三等侍卫", ({
		"sandeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是一个御前侍卫，看来可能是个满族王公大臣子弟。\n");
     	set("follow_killer", 1);
	set("class","officer");
	set("age", 20 + random(20));
	set("shen_type",1);set("score",500);setup();
	set_shiwei_status(100);

}
void init ()
{
    auto_kill(this_player());
}
#include "/d/beijing/autok.h"
