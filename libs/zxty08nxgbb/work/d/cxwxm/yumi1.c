// yumi1.c
// marry 99 .8
inherit ROOM;

void create()
{
        set("short", "玉米地");
        set("long", @LONG
这是一片茂盛的玉米地，这里的玉米不知是什么优良品种，都有两人多高，在
这里面走，很容易迷路。
LONG
        );

       set("exits", ([
               "north" : __DIR__"tianye",
               "south" : __DIR__"yumi2",
               "east" : __DIR__"yumi3",
               "west" : __DIR__"pubu",
       ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
