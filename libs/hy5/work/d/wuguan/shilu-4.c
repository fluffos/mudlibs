//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，北面过去就是后院了，南面是西练功场，
西面传来阵阵饭菜的香气，那里是武馆的饭厅。东面过去是武馆大厅。
LONG);
	set("exits", ([
          "east" : __DIR__"shilu-2",
          "south" : __DIR__"lang3",
          "north" : __DIR__"shilu-3",
          "west" : __DIR__"fanting",
        ]));
        set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

