// tzhroad5.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
    差不多到了青石大道边缘，四周还是静悄悄的。不过两边树林慢慢少了。
东边是去铁掌帮的必经之路。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"south" : __DIR__"tzhroad4",
		"east" : __DIR__"tzhroad6",
	]));

	setup();
	replace_program(ROOM);
}

