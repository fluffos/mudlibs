// Room: /chengdu/wuguan_cd.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
        set("short", "川中武馆");
	set("long", @LONG
这里是远近闻名的“川中武馆”。
LONG
	);

	set("exits", ([
                "north" : __DIR__"dongjie1",
	]));

	setup();
	replace_program(ROOM);
}

