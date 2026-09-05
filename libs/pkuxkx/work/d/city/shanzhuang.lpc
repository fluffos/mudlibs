// Room: /city/shanzhuang.c
// YZC 1998/3/22
// --by kuer-- 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"正气山庄"NOR);
	set("long", @LONG
这里就是传说中的正气山庄了，据说正气山庄的人都是侠肝义胆的英雄好汉，
所以如果你有甚么悲愤冤屈的事情，都可以到这里来申述，即便你是素不相识的
人，他们也会仗义相助的。大堂的摆设很简朴，只有在大堂的正中悬挂着一块匾
额，上书「忠孝礼义信」五个大字。走进大堂，你顿时觉得一股堂堂正正的气魄，
不觉之间生起一股崇拜敬仰的心情。
LONG);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("objects", ([
		__DIR__"npc/dragon" : 1,
	]));
	set("exits", ([
		"north": __DIR__"damen",
        "west": __DIR__"jiaoji_kantai",		    
	]));
	setup();
	"/clone/board/zhengqi_b"->foo();
	replace_program(ROOM);
}