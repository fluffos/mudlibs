// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/zhuzitop.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_pick(string arg);
int  timer_pick(object ob);

void create ()
{
	set ("short", "定风柱上");
	set ("long", @LONG

爬上来才看清楚，那放光的原来是一颗核桃大小的明珠(ming zhu)。

LONG);

	set("item_desc", ([ /* sizeof() == 1 */
  		"ming zhu" : "一颗浑圆的珠子，巧妙的嵌在铁柱上，珠子发出淡淡的光晕，
看上去朦朦胧胧的，你不禁伸手过去，想把它取出来。
",
]));

	set("exits", 
	([ //sizeof() == 1
        "down" : __DIR__"yuan",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));

	set("outdoors", __DIR__);

	setup();
}
