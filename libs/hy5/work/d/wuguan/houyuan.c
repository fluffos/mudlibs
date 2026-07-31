//cool 98.4.18
inherit ROOM;
void create()
{
	set("short", "后院");
	set("long", @LONG
这里是后院，都是些干活做事的地方，东面过去都是柴房，西面是
一个水房。人们忙忙碌碌的进出，干着自己的活。
LONG);
	set("exits", ([
               "east" : __DIR__"chaifang",
               "west" : __DIR__"shuifang",
	       "north" : __DIR__"houyuan2",
	       "south" : __DIR__"shilu-3",
        ]));
        set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

