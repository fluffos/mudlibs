// tongdao.c

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"水底通道"NOR);
    set("long", @LONG
你屏气凝神，潜伏在水底中的一条斜向上的通道之中。阳光从头顶水面上
直照下来，水中温度和旭温暖，四下里水草丛生，周围数条不知名的白鱼缓缓
游动。身体下面的水中却有阵阵寒气传上来。
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
// 	me->set_temp("last_damage_from","在水潭中被淹");
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
          me->receive_damage("jing", 50);
	  me->receive_damage("qi", 50);
          me->move(__DIR__"guditan4");
          me->start_busy(1);
          tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1; 
       	  }
       	else {
     	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
	  return notify_fail("你身子沉重，用尽全力也无法潜回上面!\n");
         message_vision(YEL"$N手脚齐划，顺着水势向上面浮去。\n"NOR, me);
         me->move(__DIR__"tanmian");
         tell_room(environment(me), me->name() + "从下面波的一声潜了上来。\n", ({ me }));
         message_vision (HIC"$N只觉得眼前一亮，一丝阳光透过水面照在$N的身上。\n"NOR,me);
         return 1;
	 } 
     return 1;
}
