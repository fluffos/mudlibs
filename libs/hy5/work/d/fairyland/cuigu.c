// Room: /u/qingyun/jyzj/cuigu.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"洞天福地"NOR);
	set("long", @LONG
出得洞来，突然间阳光耀眼，你闭着眼定一定神，再睁开眼来，面前竟是
个花团锦簇的翠谷，红花绿树，交相掩映。山洞离地竟然不过丈许。你轻轻一
跃，便已着地，脚步下踏着的是柔软细草，鼻中闻到的是清幽花香，耳中听到
的是鸣禽间关，眼前呈现的是鲜果悬枝，你怎么也不会想到经过黑黝黝的洞穴
之后，竟会有这样一个洞天福地。
LONG	);
	set("exits",([
		"north" :   __DIR__"cuigu1",
		"eastup" : __DIR__"shanbi",
		"west" :  __DIR__"pubu",
	]));
	set("objects", ([
		__DIR__"obj/rock" : 1,
	]) );
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
	object me = this_player();

	if (arg == "dong") {
		message("vision", me->name() + "一个溜身，钻进了山洞。\n", environment(me), ({me}));
		write("你急急忙忙的钻进了洞里，头撞上了山石，直痛你得哇哇大叫。\n");
		me->move(__DIR__"shandong");
		message("vision", me->name() + "钻了进来，头部撞到了山石上。\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
