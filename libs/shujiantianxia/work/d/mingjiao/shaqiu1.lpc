// shaqiu1.c  小沙丘
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"小沙丘"NOR);
       set("long", @LONG
这是一个堆满黄沙的小沙丘。你一踏上来就迷失了方向。看来要走出这块
沙漠并非易事。
LONG);    
	set("exits", ([
		"east" : "/d/group/entry/mjshamo1",
		"west" : __DIR__"shaqiu2",
		"south" : __DIR__"shaqiu"+(random(3)+1),
		"north" : __DIR__"shaqiu"+(random(3)+1),
	]));             
        set("outdoors", "明教光明顶");
        set("mj_xl", "yinwufu");
	setup();
}

void init()
{
	object me;
	string arg;
	arg = this_object()->query("mj_xl");
	if(interactive(me = this_player())
	 && me->query_temp("mj/xunluo") 
	 && !me->query_temp(arg)
	 && me->query_temp("mj/xunluo") == 8)
		me->add_temp(arg,1);
}
