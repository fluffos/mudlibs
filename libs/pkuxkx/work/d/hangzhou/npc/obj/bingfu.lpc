inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(YEL"兵符"NOR, ({ "bing fu", "fu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("value", 0);
				set("no_put",1);
                set("material", "bronze");
                set("long", YEL"这是一枚青铜兵符，可以用来调兵围剿(weijiao)。\n"NOR);
        }
        setup();
}
int is_bingfu()
{
	return 1;
}
void init()
{
	add_action("do_datan","datan");
}
int do_datan()
{
	object me=this_player(),env,maze;
	if (!me->query_temp("hansz/task_place"))
	return 0;
	if (!objectp(me->query_temp("hansz/task_place")))
	return 0;
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	env=environment(me);
	if (env==me->query_temp("hansz/task_place")||(MAP_D->place_belong(env)==query("jianxi_in_area")&&env->query("short")==query("jianxi_in_room")))//建立个人副本，进入
	{
		if (me->query_temp("hansz/entry_given"))
		{
			if (objectp(me->query_temp("hansz/entry"))&&me->query_temp("hansz/entry")->isroom())
			me->move(me->query_temp("hansz/entry"));
			else
			tell_object(me,"出来了再想进去可难了。\n");
			return 1;
		}
		maze=new("/d/hangzhou/yewai");
		message_vision(HIC"$N"+HIC+"心中暗道：就是这里了，于是紧跟着几个形迹可疑的人走去。\n"NOR,me);
		maze->start(me);
		return 1;
	}
	else
	{
		tell_object(me,"这里并不是韩蕲王让你打探消息的地点。\n");
		me->add_busy(2);
		return 1;
	}
	
}
