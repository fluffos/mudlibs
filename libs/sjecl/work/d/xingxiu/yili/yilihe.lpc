// Room: /d/xingxiu/yili.c
// Modify by Lklv 2001.10.16

inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "伊犁河");
        set("long", @LONG
伊犁河位于伊犁城以南，由天山上溶化流下的雪水汇集而成。不少来往的
商旅都将牲口牵至河边饮水，为下一次的旅途做好准备。河水清凉透彻，深不
及膝。
LONG);
        set("outdoors", "伊犁");
	set("exits", ([
		"south" : __DIR__"yili",
		"north" : __DIR__"yili1",
	]));
        set("objects", ([
		__DIR__"../npc/yang" : 1,
		__DIR__"../npc/hgirl" : 1,
        ]));
	setup();
}

#include "/d/xingxiu/job2.h";
