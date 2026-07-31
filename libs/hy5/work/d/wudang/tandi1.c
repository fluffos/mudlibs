// /d/wudang/tandi1.c  水潭底

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"水潭底"NOR);
        set("long", @LONG
你身处碧绿潭水中，潭水清澈，水寒刺骨，周围鱼虾罕见，如进了死城一般。
LONG                           
        );
	set("outdoors", "武当");
        setup();

}
void init()
{
       add_action("do_qian",({"qian","dive"}) );
}

int do_qian(string arg)
{       object me;

        me=this_player();
        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("你象条鱼般在水里游来游去!\n");

        if (arg =="down") {
           if (! present("lianxin shi", me))
              return notify_fail("由于重力不够，你无法继续下潜!\n");
          message_vision("$N一个猛栽，潜了下去。\n", me);
          me->receive_damage("jing", 60-(int)me->query_skill("dodge", 1)/20);
          me->move(__DIR__"tandi2");
          tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));
          return 1;
          }
        else
          {message_vision("$N一蹬腿，往上游去。\n", me);
           me->receive_damage("jing", 50-(int)me->query_skill("dodge", 1)/20);
           me->move(__DIR__"shuitan");
//           me->clear_condition("diving");
           tell_room(environment(me), me->name() + "从水下冒了上来。\n", ({ me }));
           return 1;
          }

     return 1;
}
/*void drop_ob(object obj)
{    
     ::drop_ob(obj);
   if objectp(present(obj, environment(me)))
    {  message_vision(HIY"$N渐渐向潭底沉去。\n"NOR, obj);
      destruct(obj);
    }
}
*/
