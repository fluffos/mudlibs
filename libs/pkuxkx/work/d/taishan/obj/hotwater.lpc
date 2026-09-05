// hotwater.c 热水
// by Zine
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("水壶", ({ "re shui", "shui","water"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "壶");
		set("long", "这是一壶热水。\n");
		set("value", 20);
		set("material", "iron");
		
	}
	setup();
}
