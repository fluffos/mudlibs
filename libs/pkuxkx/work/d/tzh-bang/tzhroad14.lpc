// tzhroad14.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "小平房");
	set("long", @LONG
    这里站在一间小平房，平房已经很旧了，看样子已经很久没有人住了。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
                   "east" : __DIR__"tzhroad12",
	]));

	setup();
	replace_program(ROOM);
}

