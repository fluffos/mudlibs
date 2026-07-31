//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "水田");
	set("long", @LONG
这是一片低洼平地的农田，除了田埂，全部都被水淹没着，一些
普麽部的妇女赤着脚在田里插秧。这个地区雨水充足，虽然没有江河
流过，无需特别的灌溉，每至春夏田里自然雨水溢满。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov76",
		]));

	set("objects", ([
		__DIR__"npc/tynong" : 1,
		__DIR__"npc/niu" : 1,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
