// horse.c 

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"先秦陶马"NOR, ({ "tao horse", "horse" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", HIG"这是始皇帝墓中挖掘出来的宝贝。很值钱的喔。\n"NOR);
		set("value", 300000);
		set("material", "greysteal");
		set("no_get",0);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

