// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/qingzhensi.c

inherit ROOM;

void create()
{
	set("short", "清真寺");
	set("long", @LONG
这里是长安城内的清真寺，因其位于鼓楼西北的化觉巷内，故又称化觉巷
清真大寺，是长安规模最大的伊斯兰教寺院。寺中一非常醒目的大牌楼，精镂
细雕，飞檐翘角，刻着“敕赐礼拜寺”，颇为壮观。
LONG
        );
	set("exits", ([
		"south" : __DIR__"westjie4",
		"north" : __DIR__"dadian",
	]));
        set("objects", ([
                __DIR__"npc/gongzi" : 1,
        ]));
	set("incity",1);
	setup();
}