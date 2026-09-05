/*  <SecCrypt CPL V3R05>  */

//  Room:  /d/city/club3
#include <ansi.h>
inherit  ROOM;

void  create  ()
{
    set  ("short",  HIC"麻将馆"NOR);
    set  ("long",
CYN"这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱
子上贴满了各种广告：有换房的，有卖家具的，但其中最多的还是
找打牌搭档的广告。你可以向小姐打听有关玩法(play)和规则(rule)
的消息。\n"NOR
);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
//        "down"  :  __DIR__"clubpoem",
//        "north":  __DIR__"piggy",
                "up":  __DIR__"duchang",
    ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"npc/mj"  :  1,
       ]));

    setup();
    replace_program(ROOM);
}
