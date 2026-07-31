 inherit ROOM;
void create ()
{
        set ("short", "阴暗小路");
        set ("long", @LONG
这是一条阴暗潮湿的小路，位于沉香城之西南，周围散落着一些残垣断壁，路
边杂草丛生。由于官府很少管这里，所以治安并不十分好。到处是沉闷的灰色，不
见一丝生机。
LONG);
        set("exits", ([ //sizeof() == 4
                "east" : __DIR__"yinroad1",
                "south" : __DIR__"yinroad3",
        ]));
       set("outdoors", "wolfmount");
        set("type", "road");
        set("coor/x",-650);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
