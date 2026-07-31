// Room: /d/city/workroom.c
//星星lywin4/29

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "找钱小屋");
  set ("long", @LONG
这是一间用来找钱的小屋子！你想找钱吗？想的话就zhaoqian吧。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"guangchang",
]));
  set("outdoors", "city");

  setup();
}

void init()
{
        add_action("do_zhaoqian", "zhaoqian");
}


int do_zhaoqian()
{
        object me,ob;
        me = this_player();

        if(me->is_busy())
             return notify_fail("不要太心急！找钱也慢点来吧！\n");

        if(me->query("qi")<10)
             return notify_fail("你还是先休息一下吧，找钱不容易，累坏了不好。。\n");
             me->start_busy(3);
        message_vision("$N埋头在找钱......\n", me);
        message_vision("$N莫名其妙就找到钱了。\n", me);
                me->receive_damage("qi", 10);
                ob=new("/clone/money/silver");
                ob->set_amount(5+random(10));
                ob->move(me); 
                    return 1;
}
