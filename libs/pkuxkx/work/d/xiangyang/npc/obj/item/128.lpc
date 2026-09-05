
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("千年松果", ({"songguo","guo"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个黑色的松果．\n");
                set("unit", "个");
   set("no_give", 1);
}
  setup();
  }

void init()
{
  add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me = this_player();
  if (arg!="songguo" && arg!="guo") 
    return 0;
  me->set("food", (int)me->max_food_capacity()*3+random(120));
message_vision(HIG "$N捏起一颗千年松果送进嘴里吞下。\n" NOR, me);
  tell_object(me, "顿时你觉得腹中生热，飘飘欲仙！\n");
  destruct(this_object());
  return 1;
}
