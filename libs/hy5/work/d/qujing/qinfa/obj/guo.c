// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "野参果" , ({"yeshen guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("long", "一个神奇的野参果。\n");
    set("value", 1000);
    set("drug_type", "补品");
  }
  set("no_give","野参果不能给人。\n");
  set("no_drop","野参果不能乱丢。\n");
  set("no_get","野参果不是你的吧。\n");
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="yeshen guo" && arg!="guo") 
    return 0;
  
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("jing", (int)me->query("max_jing"));
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("jing", (int)me->query("max_jing"));
  me->set("eff_qi", (int)me->query("max_qi"));
  me->set("qi", (int)me->query("max_qi"));
  me->set("neili", (int)me->query("max_neili"));
  me->set("neili", (int)me->query("max_neili"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  me->start_busy (10);
  message_vision(HIG "$N抓出野参果往嘴巴里一塞！\n\n" NOR, me);
  tell_object(me, "一股仙力慢慢从体内弥散开来……\n\n");
  destruct(this_object());
  return 1;
}

