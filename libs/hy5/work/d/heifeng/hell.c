// /d/heifeng/hell.c

inherit ROOM;

void create()
{
        set("short", "牢房");
        set("long", @LONG
这里是山寨的牢房。通常用来关押一些人质。一个牢头正在
屋里溜哒着，嘴里不停的嘀咕着什么。西边有一道门，门上挂着
一把大铁锁。
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"corr05",
//            "east"   : __DIR__"corr04",
//            "west"   : __DIR__"hell1",
]));

	set("objects", ([
		"/clone/npc/man" : 3,
	]));
        setup();
        replace_program(ROOM);
}

