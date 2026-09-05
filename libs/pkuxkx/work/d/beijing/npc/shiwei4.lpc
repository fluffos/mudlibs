//Cracked by Roath
// Npc: 四等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);
int auto_kill(object player);
void create()
{
	set_name("四等侍卫", ({
		"sideng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是御前侍卫，看来可能是个满族王公大臣子弟。\n");
	set("class","officer");
	set("age", 20 + random(20));
	set("shen_type",1);set("score",1000);setup();
	set_shiwei_status(80);

}
void init ()
{
    auto_kill(this_player());
}
#include "/d/beijing/autok.h"
