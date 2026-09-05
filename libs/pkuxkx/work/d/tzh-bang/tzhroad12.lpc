// tzhroad12.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "村庄的南边");
	set("long", @LONG
    这里是西街的尽头。很多村民从东面走了出来。西面是一间很旧的平房。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"east" : __DIR__"tzhroad15",
	                  "west" : __DIR__"tzhroad14",
                                     "north" : __DIR__"tzhroad10",
	]));

	setup();
	replace_program(ROOM);
}

