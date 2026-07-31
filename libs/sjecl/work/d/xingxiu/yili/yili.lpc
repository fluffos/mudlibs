// Room: /d/xingxiu/yili.c
// Modify by Lklv 2001.10.16

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "惠远");
	set("long", @LONG
伊犁，又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼中西交
通的要冲，是丝绸之路上重要的旅站之一。伊犁城位于北面天山雪水汇集而成
的伊犁河以北。
LONG);
	set("outdoors", "伊犁");

	set("exits", ([
		"west" : "/d/xingxiu/shanjiao",
		"northwest" : "/d/xingxiu/xxh",
		"north" : __DIR__"yilihe",
		"south" : "/d/xingxiu/silk10",
	]));

	set("objects", ([
		__DIR__"../npc/shangren" : 1,
        ]));
	setup();
}

#include "/d/xingxiu/job2.h";
