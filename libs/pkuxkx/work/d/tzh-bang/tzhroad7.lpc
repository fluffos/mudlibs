// tzhroad7.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "村庄外围");
	set("long", @LONG
    这里是村庄北面一条比较大的路，人比较少，有几个装扮很象铁掌帮的人，行色匆匆
的向西面走去。东面是村庄外围，南面是村庄的中心。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"west" : __DIR__"tzhroad6",
		"east" : __DIR__"tzhroad8",
                                     "south" : __DIR__"tzhroad10",
	]));

	setup();
	replace_program(ROOM);
}

