//Cracked by Roath
// Npc: 六等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);
int auto_kill(object player);
void create()
{
	set_name("六等侍卫", ({
		"liudeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是一个刚从官兵里提拔出来的侍卫。\n");
	set("class","officer");
	set("age", 20 + random(20));
	setup();
	set_shiwei_status(30);

}

void init ()
{
    auto_kill(this_player());
}

#include "/d/beijing/autok.h"
