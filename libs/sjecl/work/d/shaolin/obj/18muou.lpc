// 18muou.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("十八木偶", ({ "muou", "ou" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盒");
		set("long", HIY "这是一个小木盒，盒中垫着棉花，并列着三排木偶，神情或喜\n"+
			"悦不禁，或痛哭流泪，或裂嘴大怒，或慈和可亲，无一相同。\n"NOR);
		set("value",0);
		set("treasure", 1);
		set("material", "wood");
	}
}
