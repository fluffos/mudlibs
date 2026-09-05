// Room: /hangzhou/gongdian4.c
// hubo 2008/4/19

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"玉室"NOR);
        set("long", HIW@LONG
你眼前突然大亮，只见一道阳光从上面数十丈高处的壁缝里照射进来。
阳光照正之处，是一间玉室，看来当年建造者依着这道天然光线，在峰中
度准位置，开凿而成。石室中有玉床、玉桌、玉椅，都雕刻得甚是精致，
床上斜倚着一具骸骨（skeleton）。
LONG
NOR);
        set("exits", ([
                "south" : __DIR__"gongdian3",
                "north" : __DIR__"gongdian5",    
]));
   
           set ("item_desc", ([
                "skeleton" :
"这是一具死了很久的死人骸骨。\n"
        ])  ) ;

        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object paper;
        paper = new(__DIR__"obj/paper");

        if( !arg || arg=="" ) return 0;

        if( arg=="skeleton" )
                 {              
                if (!query("gd_trigger"))
                {
                message_vision(
"$N轻轻的移动下骸骨，想坐在床上休息下，突然发现骸骨下面有一卷羊皮。\n", this_player());
                paper->move(__FILE__);
                set("gd_trigger", 1);
                return 1;
                }
                 message_vision(
"$N轻轻的移动下骸骨，没发现什么异常。\n", this_player());
                return 1;
        }
        return 0;
}


