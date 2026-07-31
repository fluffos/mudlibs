#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW "花房" NOR);
	set("long", @LONG
这里是小花园的一个花房，这里没什么东西，只有一个老实的花
农在这里卖些花种，赚些生活费。
LONG
	);

	set("exits", ([ 
		"east" : __DIR__"xiaohuayuan",
	]));

	set("objects",([ 
		__DIR__"npc/huanong" : 1,
	])); 

	set("no_fight", 1);   
	setup();
}
