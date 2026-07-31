//houyuan.c

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里就是武馆的后院了，四周种满了各种蔬菜，往北是一块庄稼地，东面
用篱笆围起的菜园，里面种着各样的菜，篱笆很破烂，摇摇欲坠。西面是间柴
房，从窗户中可以见到松柴稻草堆得满满的。
LONG
        );
	set("no_fight",1);
        set("exits", ([
               "east" : __DIR__"caiyuan",
               "west" : __DIR__"chaifang",
               "north" : __DIR__"caidi",
               "south" : __DIR__"shilu1",
        ]));
         
        setup();
}