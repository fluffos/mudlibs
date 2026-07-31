// Room: 北大街/dali/beijie5.c
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是大理北大街，这里人来人往，大理虽小，但是也颇兴旺，是西南的重
要城市。这里北面是一个赌场，喧哗声不断传来，东面建筑高大，是官府的盐
局。西面就是北大街，往南走就到了大理东大街。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"beijie4",
		"south" : __DIR__"dongjie1",
		"east" : __DIR__"yanju",
		"north" : __DIR__"duchang",
	]));

	set("outdoors", "大理");
	set("objects", ([
		__DIR__"npc/yanxiao" : 1,
		__DIR__"npc/yanxiao2" : 1,
	]));
	set("incity", 1);
	setup();
}
