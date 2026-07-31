inherit ROOM;
#include <ansi.h>

void create()
{
set("short", HIR"明帅工作室"NOR);
set("long", @LONG
这里是明帅的工作室。房间里黑乎乎的，有一只打碎了半边的灯泡挂在
空中荡来荡去。地板年久失修，踩上去吱呀吱呀地响。一把断了一条腿
的凳子斜靠在墙角边。地上堆满了各种各样破破烂烂的大鱼大肉。有些
已经放了好久，并开始发霉腐烂了。
LONG	);
set("valid_startroom",1);
set("no_steal", "1");
	set("exits", ([
		"wm" : "/d/city/wumiao",
		"xs" : "/d/xueshan/guangchang",
		"kd" : "/d/city/kedian",
		"cs" : "/d/city/guangchang",
                "puma" : "/u/puma/workroom",
       ]));

	setup();
}

