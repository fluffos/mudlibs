// /u/dubei/wudang/taoyuan1

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","峰顶");
        set("long", @LONG
这里是武当后山的峰顶，四周树木青翠，桃化绽放。地上有许多不知名的
草本植物，纵横交错。一些不显眼的植物结出了许多褐色的坚果。
LONG                           
        );
        set("tenghuang_count",500);

        set("outdoors","武当");        

        set("exits", ([
                 "down" : __DIR__"hsxl1",
                 "west" : __DIR__"taoyuan2",
                 "east" : __DIR__"taoyuan3",
        ]));
        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));      
}
 
int do_wa(string arg)
{ 
        object tenghuang;
        object me;
        me = this_player();

        if (!( present("yao chu", this_player())))
             return notify_fail("你伸出两手，胡乱在地上乱刨！\n");

        if ( !arg || arg != "caoyao" )
             return notify_fail("你挖什麽？\n");

        if (!(int)me->query_temp("mark/wd_mission"))
             return notify_fail("你要做什麽？\n");

        if( me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢。\n");

        if ((int)me->query("jingli") < 80) 
             return notify_fail("你太累了！\n");

        if( random(5) != 3){
           me->add("jingli",-40);
           return notify_fail("你轮起药锄，向地上刨去,只挖出了一些野草。\n"); 
        }

        if (query("tenghuang_count") > 0 && random(10) > 1) {
          message_vision("$N轮起药锄，忽然间挖到了一株藤黄。\n",me);
          add("tenghuang_count", -1);
          tenghuang = new(MEDICINE_D("wudang/tenghuang"));
          tenghuang->move(me);
          me->start_busy(1);
          me->add("jingli", -60);
        }
        else  message_vision("$N费了半天劲，只挖到一些野草。\n", me);
        return 1;
}
