// sroad8.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "大雪山山谷");
	set("long", @LONG
一个宽大山谷，群山环绕，山顶上全是白闪闪的积雪，山谷南方有
两个山洞。附近有几棵说不出什么名字的古树，下面有一些乱七八糟的
零碎(mash)堆摆在那里，不知道里面都有什么。
LONG );
	set("exits", ([
		"enter"  : __DIR__"shandong1",
		"north"  : __DIR__"wangyougu",
		"northup": __DIR__"sroad7",
	]));
	set("outdoors", "xuedao");
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;

	me = this_player();
	if (arg != "mash")
		return notify_fail("你要进入什么？\n");

	if (me->query("family/family_name") != "血刀门")
		return notify_fail("你翻了一下这些零碎，只觉得"
				   "一股血腥气翻涌上来，直欲呕吐。\n");

	message("vision", me->name() + "走到一边不知道在鬼鬼祟祟的干些"
		"什么...突然人不见了！\n", this_object(), ({ me }));
	tell_object(me, "你蹑手蹑脚的掀开这些零碎，越了下"
		    "去，只穿过密道，奔扬州而去。\n");
	me->move("/d/city/datiepu");
	return 1;
}
