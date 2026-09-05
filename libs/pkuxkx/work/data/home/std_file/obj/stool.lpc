//Created By Pal
//cometh@tom.com
//2003.10.5
//物品类物品模板
#pragma save_binary

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("标准物品", ({ "biaozhun wupin" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "单位");
                set("material", "wood");
        }
		set("no_get",1);
        set("selfcreate",1);
		set("value",VALUE);
		setup();
}

void init()
{
	add_action("do_sit","sitdown");
	add_action("do_standup","standup");
}

int do_sit()
{
	object me;
	me=this_player();
	if( me->query_temp("issitting") )
		return notify_fail("你已经坐在标准物品上了。\n");
	me->set_temp("issitting",1);
	message_vision("$N一屁股坐在标准物品上。\n",me);
	return 1;
}

int do_standup()
{
	object me;
	me=this_player();
	if( !me->query_temp("issitting") )
		return notify_fail("你又没有坐在标准物品上，难道你想站到标准物品上去？\n");
	me->delete_temp("issitting",1);
	message_vision("$N站了起来。\n",me);
	return 1;
}