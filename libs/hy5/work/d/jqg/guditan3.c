// guditan3.c

inherit ROOM;
#include <ansi.h> 
void create()
{
    set("short", HIC"谷底水潭"NOR);
    set("long", @LONG
你屏气凝神，潜伏在水潭的中间。水潭位处谷底，地势低寒，你向四周望
去，四面蓝森森，青郁郁，寒气逼人，似乎结满玄冰。你只觉得寒气刺骨，冷
不可耐。
LONG
        );
    set("outdoors", "绝情谷");
    setup();
 
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
//       if ((int)me->query("jing", 1) < 0||(int)me->query("qi", 1) < 0){
//	me->set_temp("last_damage_from","在水潭中被淹");
//       	me->unconcious();
//       	me->die();
//       	return ;
//       }       
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
       	if ( !arg || (arg != "down" && arg != "up") )
       		return notify_fail("你要往哪里潜？\n");
       if (arg =="down"){
  	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 
            return notify_fail("由于重力不够，你无法继续下潜!\n");
          message_vision(HIG"$N一个猛栽，潜了下去。\n"NOR, me);
          me->receive_damage("jing", 150);
          me->receive_damage("qi", 150);
          me->move(__DIR__"guditan4");
          me->start_busy(1);
          tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1; 
       	  }
       	else {
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 30) 
	  return notify_fail("你身子沉重，用尽全力也无法潜回上面!\n");
          message_vision(YEL"$N两腿用力一蹬，向上面浮去。\n"NOR, me);
          me->receive_damage("jing", 150);
          me->receive_damage("qi", 150);
          me->move(__DIR__"guditan2");
          me->start_busy(1);
          tell_room(environment(me), me->name() + "从下面潜了上来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1;
	  } 
    return 1;
}
 