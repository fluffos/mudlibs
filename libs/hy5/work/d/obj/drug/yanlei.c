#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(CYN "眼泪" NOR, ({"yanlei","lei"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "滴");
    set("long", "一滴仙女的眼泪,据说吃了它可以健脾开胃。\n");
    set("value", 5000);
// set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
  call_out("self_dest",600);
}

void self_dest()
{
    object env;
    if(this_object()) {
        if(env=environment(this_object()))
            tell_object(env,name()+"没到地面就消失了。\n");
        destruct(this_object());
    }
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int food,water;
  object me = this_player();
  if (arg!="yanlei" && arg!="lei") 
    return 0;

  food=(int)me->max_food_capacity()/2+random(120)-60;
  water=(int)me->max_water_capacity()/2+random(120)-60;
  if (me->query("food")>food) me->set("food",food);
  if (me->query("water")>water) me->set("water",water);

  message_vision(HIG "$N小心的将这滴眼泪送进嘴里吞下。\n" NOR, me);
  tell_object(me, HIG"顿时你觉得一股清凉之气，在五脏六腑中游走，所到之处，说不出的舒坦！\n"NOR);
  destruct(this_object());
  return 1;
}
