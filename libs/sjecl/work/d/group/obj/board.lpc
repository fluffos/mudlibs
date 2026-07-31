// board.c
// Create by mxzhao

inherit ITEM;

#include <ansi.h>
#include <group.h>

void create()
{
	set_name("留言板", ({ "board", }));
	set_weight(5000);

	if (clonep())
	{
		set_default_object(__FILE__);
	}
	else 
	{
		set("unit", "个");
		set("long", "这是一个留言板。你可以把它放在帮派区域，供大家留言。\n");
		set("value", 20000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}

	setup();
}

void init()
{
	add_action("do_drop", ({"drop","fangzhi","放置"}));
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());

	if( !arg || !id(arg) || env!=me )
	{
		return 0;
	}

	env = environment(me);

	if( !me->query("group/id") ) 
	{
		tell_object(me, "你并没有开帮立派，要" 
			+ name() + "何用？\n");
		return 1;
	}

	if( !GROUP_D->site_now(me->query("group/id")) )
	{
		tell_object(me, GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_board(this_object(), me, env,"$N开始小心地摆放" 
		+ name() + "……\n", "你忙碌了半天，总算把" + name() + "放置好。\n");
	return 1;
}

