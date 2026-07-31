#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init()
{
  add_action("do_eat", "eat");
}
void create()
{
  set_name(RED "无敌果" NOR, ({"wudi guo","guo"}));
  set_weight(200);
    set("unit", "枚");
    set("long", "\n一枚采自海中灵福仙山，色红如火，味舔如蜜的香枣。\n");
    set("value", 0);
       set("is_monitored",1); 
    set("drug_type", "补品");
  setup();
}
int do_eat(string arg)
{
  object me = this_player();
  int mana_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
  return notify_fail("你要吃什么？\n");  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  if( howold > 432000 ) {
    me->add("maximum_neili", 10);
    me->add("max_neili", 10);
    me->add("neili", 10);
    me->add("maximum_mana", 10);
    me->add("max_mana", 10);
    me->add("mana", 10);
  message_vision(HIW "\n$N吃下一颗"NOR+HIR"无敌果"NOR+HIW"，只觉体内血气翻腾，丹田火烫！\n"NOR,me);
  destruct(this_object());
  }
  return 1;
}
