 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "厨房");
        set("long", @LONG
西面的一间是厨房。厨房中飘出饭香。正中一张方桌，桌上放着两个刚煎
好的荷包蛋，还有新鲜的豆腐、莴笋和用盐水煮的花生。
LONG
        );
        set("exits", ([ 
        "east": __DIR__"cabin4",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",-1160);
        set("coor/y",130);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
