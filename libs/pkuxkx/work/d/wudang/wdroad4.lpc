// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，四周静悄悄的。东面通向襄阳，南面就是武当山了。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad3",
		"south" : __DIR__"wdroad5",
//		"north" : __DIR__"wdroad3",
	]));

	setup();
	replace_program(ROOM);
}

