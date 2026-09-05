#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这里是段誉休息和会见弟子的地方，旁人可不能轻易进来哦。屋子虽小，但收拾得很干净。
一张小床临窗摆放，可以看到外面的风景。
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                  "south" : __DIR__"fudi",
        ]));
        
    set("no_fight",1);
    set("no_steal",1);
        setup();
        replace_program(ROOM);
}

