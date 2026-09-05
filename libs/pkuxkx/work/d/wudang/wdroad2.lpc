// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，东面通向襄阳，西面就是武当山了。北面开了一家
    镖局。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"wdroad3",
		"east" : __DIR__"wdroad1",
        "north" : __DIR__"biaoju",
	]));

	setup();
	replace_program(ROOM);
}

