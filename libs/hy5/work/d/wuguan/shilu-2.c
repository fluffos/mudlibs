//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，北面和南面都是习武堂，不少人在这里进进出出的，
东面是武馆大厅。
LONG);
	set("exits", ([
	       "eastup" : __DIR__"dating",
	       "west" : __DIR__"shilu-4",
	       "north" : __DIR__"xiwutang",
	       "south" : __DIR__"xiwutang2",
        ]));
        set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

