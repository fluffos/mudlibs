// Room: /chengdu/cdbj.c
// oooc: 1998/06/24

inherit ROOM;

void create()
{
        set("short", "威武镖局");
	set("long", @LONG
门前两个威武的石狮子，四间开的大红门，边上是大红灯笼高
高挂。不时有几个镖师进进出出，门口是几个看守门户的镖师，个
个看上去体格魁梧，手底下很有些功夫的样子，大门正中是块金匾，
上书『威武镖局』四个金字。这里就是远近闻名的成都威武镖局了。
LONG
	);

	set("exits", ([
                "east" : __DIR__"beijie2",
	]));

        set("objects", ([
            __DIR__"npc/biaotou" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

