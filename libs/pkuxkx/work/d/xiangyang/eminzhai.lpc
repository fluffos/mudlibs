#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "民宅");
	set("long",
	CYN"这里是一间民宅,主人似乎是一狩猎为生,墙上挂着几张毛皮,墙角立着一
柄猎叉,土炕上躺着一位六十多岁的老猎人,古铜色的脸膛,白发苍苍,肩膀高高肿起来,
好象是受了伤,老人痛苦不堪,不住地呻吟着.\n"NOR
	);
        set("objects", ([
		__DIR__"npc/liehu" : 1,
        ]));
	set("exits", ([
		"south" : __DIR__"caiyuan"          
	]));

	setup();
}

