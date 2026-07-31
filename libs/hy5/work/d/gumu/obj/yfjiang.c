// yfjiang.c 玉峰浆
// By Kayin @ CuteRabbit Studio 1999/3/23 new
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIC"玉峰浆"NOR, ({"yufeng jiang", "jiang"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "瓶");
      set("value", 1000);
      set("long","这是一只很精致的细口小瓶,你拔开瓶塞里边飘出浓浓的幽香.\n");
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

   message_vision("$N吃下一瓶" + name() + "。\n", me);
   if ((int)me->query_condition("feng_poison") > 0) {
    if ((int)me->query_condition("feng_poison") < 11) {
      me->apply_condition("feng_poison", 0);
      message_vision("$N身上被蜇的地方麻痒消退,不过被蛰的大包还有些疼痛。\n", me); }
   else {
   me->apply_condition("feng_poison", (int)me->query_condition("feng_poison") -10);
      message_vision("$N身上被蛰的地方渐渐不怎么痒了。\n", me);
   }
   destruct(this_object());
   return 1;
  }
     if ((int)me->query_condition("yufeng_poison") > 0) {
    if ((int)me->query_condition("yufeng_poison") < 21) {
      me->apply_condition("yufeng_poison", 0);
      message_vision("$N身上的玉峰针毒进退,脸色看上去好多了。\n", me); }
   else {
   me->apply_condition("yufeng_poison", (int)me->query_condition("yufeng_poison") -20);
      message_vision("$N身上的麻痒渐渐减轻。\n", me);
   }
   destruct(this_object());
   return 1;
  }

    else tell_object(me, "你觉得浑身无比清爽。\n" NOR );
        me->set("eff_jing",this_player()->query("max_jing"));
 	me->set("jing",this_player()->query("max_jing"));
	me->set("eff_qi",this_player()->query("max_qi"));
	me->set("qi",this_player()->query("max_qi"));


   destruct(this_object());
   return 1;
}
