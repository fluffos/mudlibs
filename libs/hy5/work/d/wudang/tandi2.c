// /d/wudang/tandi2.c  水潭底

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"水潭底"NOR);
        set("long", @LONG
你身处水潭潭底，潭底细沙如雪，潭水墨蓝，水寒刺骨，寂静一片，阴深恐怖。
LONG                           
        );
        set("objects",([        
                 __DIR__"npc/eyu" : 1,
             ]));
        set("outdoors", "武当");
        setup();

}
void init()
{
        add_action("do_qian",({"qian","dive"}));
}

int do_qian(string arg)
{       object me;

        me=this_player();
        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("你象条鱼般在水里游来游去!\n");

        if (arg =="down") {
           return notify_fail("你想当泥鳅往地下钻呀!\n");
          }
        else
          {message_vision("$N一蹬腿，往上游去。\n", me);
           me->receive_damage("jing", 50-(int)me->query_skill("dodge", 1)/20);
           me->move(__DIR__"tandi1");
           tell_room(environment(me), me->name() + "从水下冒了上来。\n", ({ me }));
           return 1;
          }

     return 1;
}
/*void drop_ob(object obj)
{    
     ::drop_ob(obj);
   if objectp(present(obj, environment(me)))
    { message_vision(HIY"$N沉到潭底一会就被泥沙掩埋了。\n"NOR, obj);
      destruct(obj);
     }
}

void get_ob(object obj)
{    
   object me,ob;
   me=this_player();
   ::get_ob(obj);
   me->start_busy(2);
   if objectp(present("eyu", environment(me)))
    {if (random(3)>2)
      message_vision(HIW"泥沙突然一阵翻动，一条凶残的鳄鱼被惊醒了。\n"NOR);
      ob=new(__DIR__"eyu");
      ob->kill_ob(me);
     }
}
*/
