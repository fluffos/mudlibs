//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
一片临湖的稻田，田里积满了水，田埂很高，且干燥，可以供走
动，田间挖掘了相当多的引水沟渠。南诏雨水充足，河湖众多，虽然
是山地地区，灌溉也不成问题。此去东边有些杆栏民居。
LONG
        );

	set("exits", ([
		"southwest" : __DIR__"minov21",
		"east" : __DIR__"minov23",
		]));

	set("objects", ([
		__DIR__"npc/bynong.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
