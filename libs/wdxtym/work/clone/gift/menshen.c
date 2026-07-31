// menshen.c

#include <ansi.h>
#include <room.h>

inherit ITEM;

void setup() {}

void create()
{
	set_name(HIM "门神" NOR, ({ "men shen", "menshen" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一张画的五颜六色的门神，常常"
			    "被人贴在门上用来驱除妖邪。\n");
		set("unit", "张");
	}

	set("no_get", 1);
	setup();
}

void init()
{
	object env;
	object me;
	object ob;

	if (! objectp(env = environment()))
		return;

	if (! clonep(env) || base_name(env) != CHAT_ROOM)
		return;

	if (! stringp(env->query("owner_id")) ||
	    ! stringp(env->query("startroom")))
		return;

	me = this_player();
	if (! interactive(me) || env->welcome(me))
		return;

	if (objectp(ob = present("magic gourd", me)) &&
	    ob->query_temp("onwer_id") == me->query_temp("id"))
	{
		message_vision("门神大喝一声：“何方妖孽，也"
			       "敢来此？”说罢手中铜锤一荡...\n"
			       "$N赶紧举起" + ob->name() + "，取下塞子，"
			       "只见一道金光闪过，门神被吸进了葫芦！\n"
			       "过了半晌，一股青烟从葫芦口袅袅升起...\n", me);
		destruct(this_object());
		return;
	}

	message_vision("门神大喝一声：“何方妖孽，也"
		       "敢来此？”说罢手中铜锤一荡，"
		       "将$N一锤打得飞了出去！\n", me);
	me->move(env->query("startroom"));
	me->start_busy(3);
	message("vision", "只听“蓬”一声，" + me->name() +
		"飞了出来，身上青一块儿紫一块儿的。\n",
		environment(me), ({ me }));
}
