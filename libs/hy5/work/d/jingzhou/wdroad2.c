// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，南边隐约可见到荆州城的城墙。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : "/d/jingzhou/jzbeimen",
		"north" : __DIR__"wdroad3",
	]));

	setup();
	replace_program(ROOM);
}

