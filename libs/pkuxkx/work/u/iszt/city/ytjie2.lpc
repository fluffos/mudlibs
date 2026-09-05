// Room: /city/yuntaijie2.c
// 云台街：衣店,鞋帽店 

inherit ROOM;

void create()
{
	set("short", "云台街");
	set("long", @LONG
这一条街道本来是很冷清的，但因为最近扬州的商业繁荣，忽然间也就热闹
了起来。北面是一家老字号的鞋帽店，南面店铺的门口挂着一副金字招牌－－
「沈记衣店」。街道的西面飘来一阵香气，让人馋涎欲滴。东面则传来一阵阵鼎
沸的人声。
LONG);
        set("outdoors", "city");

	set("exits", ([
               "east":__DIR__"ytjie3",
		"south" : __DIR__"yidian",
               "west":__DIR__"ytjie1",
		"north" : __DIR__"xiemaodian",
	]));

	setup();
	replace_program(ROOM);
}