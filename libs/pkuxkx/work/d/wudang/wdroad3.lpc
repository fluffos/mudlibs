// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，四周静悄悄的。东面通向襄阳，西面就是武当山了。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"wdroad4",
		"east" : __DIR__"wdroad2",
	]));

	setup();
	replace_program(ROOM);
}

