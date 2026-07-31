//writen by lnwm
//chufang.c 

#include <room.h>

inherit ROOM;
string *things = ({
            "tang",
            "yan",
            "layou",
            });


void create()
{
        set("short","厨房");
        set("long",@LONG
农家的小厨房，用石头砌成。厨房右侧是一口灶，灶边有一口大缸，缸
里满满地装了清水。厨房左侧有一个碗柜，碗柜上整整齐齐地摆着碗筷和油
瓶等调味品。碗柜上方的墙壁上也整整齐齐地挂着菜刀，锅铲，饭勺等工具
厨房里和堂屋里一样，也收拾得非常干净。
LONG);
        set("exits",
        ([
        "east"       :      __DIR__ "yuanluo",
          
        ]));
        
    set("search_things", ([
                "碗柜"      :       __DIR__ "obj/" + things[random(sizeof(things))],
                        ]) );

    setup();
    replace_program(ROOM);

}

