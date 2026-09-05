#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_leave();

void create()
{
	set("short", "小路");
	set("long","这是位于山谷口的一条狭窄的泥泞小路，前方是一片平原。放眼望\n"
	+"去，似乎还能看到远处有一座大庄园。向南方向有条隐蔽的小路，穿过\n"
	+"一人多高的野草丛，可以离开(leave)这里。\n");
	set("outdoors", "lvliu");
	set("exits", ([
		"north" : __DIR__"pingyuan1",
	]));
	set("no_die",1);
	setup();
}

void init()
{
	__DIR__"core"->check_change();
	add_action("do_leave", "leave");
}

int do_leave()
{
	object me=this_player();
	if (me->query_temp("confirm_leave_lvliu"))
	{
		me->delete_temp("confirm_leave_lvliu");
		message_vision(HIC"$N离开了绿柳山庄。\n"NOR, me);
		me->move("/d/mingjiao/xiaoyuan");
		return 1;
	}
	tell_object(me, "你这就要离开了么？确定的话就走吧(leave)！\n");
	me->set_temp("confirm_leave_lvliu", 1);
	return 1;
}
