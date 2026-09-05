// File		: tingyuan.c
// Created By	: iszt@pkuxkx, 2007-01-22

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
这是一个被冰雪覆盖的庭院，庭院中稀稀落落的长着几支梅花，洁白的雪地
上歪歪扭扭的印着几行不知是什么小动物的脚印。
被雪覆盖的庭院，几支梅花，一棵雪松，松鼠、鹿。东西南北
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。东南方
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"xiaomen",
		"west" : __DIR__"xiangfangwest",
		"east" : __DIR__"xiangfangeast",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
                __DIR__"npc/wangwanyi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
