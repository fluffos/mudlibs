// tzhroad3.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
    你走在一条青石大道上，四周静悄悄的。两边都是茂密的树林。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"south" : __DIR__"tzhroad2",
		"north" : __DIR__"tzhroad4",
	]));

	setup();
	replace_program(ROOM);
}

