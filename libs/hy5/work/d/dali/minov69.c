//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "竹楼");
	set("long", @LONG
一间标准的台夷竹楼，四面墙壁皆是竹子，正中砌了一座正方形
的灶台，其内架置着铁炉。夷族传统席地而睡，是以屋内无床，延墙
摆有垫褥，屋舍内除了石堆祭台外别无家具。
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov68",
		]));

	set("objects", ([
		__DIR__"npc/tykid" : 1,
	]));

	set("cost", 2);
	setup();
}
