#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIW"龙树院"NOR);
        set("long", @LONG
你进入了一间小松木屋，木屋门上挂了一个牌匾，上边写着“龙树院”，
你吃了一惊，想不到大名鼎鼎的天龙寺龙树院竟然就是这间小屋。四周的窗户
都打开着，从窗外透射进一丝阳光将木屋内照亮。
LONG);

        set("outdoors", "天龙寺");
        set("exits", ([             
               "out" : __DIR__"songlin-1",
                      ]));
        set("objects",([
                __DIR__"npc/kurong" : 1,
        ]));

        setup();
}

