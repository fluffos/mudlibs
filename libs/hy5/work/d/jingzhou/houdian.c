// Room: houdian
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
关庙的后殿，堆放着香、烛等杂物。墙上的幔布看起来满新的。

LONG
	);

	set("exits", ([
		"northdown" : __DIR__"houmen",
		"east" : __DIR__"guanmiao",
		]));

	setup();
	replace_program(ROOM);
}

