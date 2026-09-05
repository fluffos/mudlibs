//洛阳，扩展地图
//by kiden
//2006-9-8
//modified by iszt@pkuxkx, 2007-02-11

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。西北方向一座雄关傲然而立，
那就是赫赫有名的虎牢关了。东北是一条小路，
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"hulaoguan",
		"southeast" : "/d/shaolin/xiaojing1",
		"northeast" : "/d/qilincun/xiaolu5",
	]));

	set("objects", ([
	      __DIR__"npc/randomnpc" : 1,
	]));
	set("outdoors", "luoyang");
	setup();
	replace_program(ROOM);
}
