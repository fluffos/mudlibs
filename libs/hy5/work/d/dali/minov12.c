//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "滇池沿岸");
	set("long", @LONG
滇池名曰池，实际上是个很大的湖，四面山上水源众多，也浇灌
了大片的农田。池水清澈凉爽，许多罗伽部的妇女在此洗衣挑水。摆
夷并不以渔业为主，不过岸边仍然建有小码头，时常有游船停靠，也
有少量竹舟下水打鱼。西边有条弯弯曲曲的小路沿着滇池南岸而去。
LONG
        );

	set("exits", ([
		"northeast" : __DIR__"minov11",
		"west" : __DIR__"minov19",
		]));

	set("objects", ([
		__DIR__"npc/bywoman.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
