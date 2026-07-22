// By River@SJ

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL"山脚下"NOR);
	set("long", @LONG
这里已经接近崆峒山的山脚了。崆峒山山史文化悠久，为中国道教发祥地
之一。相传轩辕黄帝到此问道于广成子。秦汉时山上已有庙观建筑，后经历代
修葺，琳宫梵刹遍布诸峰。
LONG );
	set("exits", ([
		"northwest"  : __DIR__"dukou2",
		"southup" : __DIR__"kongdong",
	]));

	set("outdoors", "兰州");
	setup();
}
