#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "老牛背");
        set("long", @LONG
这里是绝险之地，顾名思义这条山脊就如牛背搬陡峭，艰险
放眼望去，周围云雾飘渺，左边的山谷中密林掩映，星星点
点的王子就是落雁山庄了，右边的山脚下亮绿的一片好象是
一面湖水，对面半山腰有一个瀑布向湖水倾泻而出！
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "southdown": __DIR__"shijianshi",
            ]));
   
       set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        int n;
        object weapon,me=this_player();
        if (arg != "west") return 0;
        message_vision(CYN
"$N整整衣衫，准备昂首一跳！\n"NOR,me);

        if (me->query_skill("dodge") < 150)
        {
               message_vision(CYN
"你不要命了，想想老婆，孩子，女秘书.....\n"NOR,me);
               me->set("move",__DIR__"laoniubei");
                  return 1;
        }
        message_vision(CYN
"看来你是豁出去了，老婆，孩子，女秘书...没什么可留恋的了
你奋不顾身的向下跳去，口中大喊：我党的联络图还在我老婆地窖里!\n"NOR,me);
        me->move(__DIR__"hushui");
              
        return 1;
}

