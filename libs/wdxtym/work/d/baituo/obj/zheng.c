// zheng.c

#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_ZHENG;

void create()
{
	set_name("古筝", ({ "guzheng" }));
	set_weight(300);
	
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "台");
		set("long", "一台看上去有些陈旧的古筝。\n");
		set("value", 50);
		set("material", "wood");
	      set("icon","01028");
	}
	setup();
}

void init()
{
	add_action("play_zheng", "play");
}
