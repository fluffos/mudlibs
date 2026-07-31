//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
一小片在山坡下的竹林里开垦出来的农田，临有溪流，种植着水
稻。台夷生活很大程度上依靠农业，从事农业的却基本上是妇女。男
子大都专司狩猎和捕鱼。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov67",
		]));

	set("objects", ([
		__DIR__"npc/tynong" : 1,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
