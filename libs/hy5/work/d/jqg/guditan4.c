// guditan4.c

inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIC"谷底水潭"NOR);
     set("long", @LONG
你历尽坚辛，终于到达了水潭底部，水潭四周层层叠叠的都是万年玄冰。
你头顶左上方(zuoshang)隐约透着光亮。水中寒气逼人，阵阵刺骨冰气使你感
觉就象刀刮一样的疼痛，此处看来不可多呆，还是赶快离开吧。
LONG
        );
     set("item_desc", ([
        "zuoshang": HIC"你定睛观瞧，光亮处似乎是一条斜上的水道。\n"NOR,
     ]));
     set("outdoors", "绝情谷");    
     setup();
 
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
//       if ((int)me->query("jing", 1) < 0||(int)me->query("qi", 1) < 0){
//         me->set_temp("last_damage_from","在水潭中被淹");
//         me->unconcious();
//         me->die();
//         return;
//        }       
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
       	if ( !arg || (arg != "zuoshang" && arg != "up") )
       		return notify_fail("你要往哪里潜？\n");
       	if (arg =="zuoshang"){
           if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
		return notify_fail("你身子沉重，用尽全力也无法向上面游去！\n");
          message_vision(YEL"$N两腿用力一蹬，向左上方浮去。\n"NOR, me);
          me->receive_damage("jing", 200);
	  me->receive_damage("qi", 200);
       	  me->move(__DIR__"tongdao");
          me->start_busy(1);
       	  tell_room(environment(me), me->name() + "从斜下方向潜了上来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1;
       	  }
       	else {
          if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
	    return notify_fail("你身子沉重，用尽全力也无法潜回上面!\n");
          message_vision(YEL"$N两腿用力一蹬，向上面浮去。\n"NOR, me);
          me->receive_damage("jing", 200);
          me->receive_damage("qi", 200);
          me->move(__DIR__"guditan3");
          me->start_busy(1);
          tell_room(environment(me), me->name() + "从下面潜了上来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1;
	  } 
     return 1;
}
 