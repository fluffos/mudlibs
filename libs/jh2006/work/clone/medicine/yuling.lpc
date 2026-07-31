#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("玉灵散", ({"yuling san", "yuling","san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 20000);
      set("unit", "些");
      set("long","这是一份华山派的玉灵散，用于解热毒。\n");
      set("base_value", 20000);
      set("base_unit", "份");
      set("base_weight", 30);
   }
   set_amount(1);
}

int init()
{
   add_action("do_eat", "fu");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

   if (!me->query_condition("hot_poison"))
           return notify_fail("你现在不需要用玉灵散。\n");
   else {       
        if(me->query_condition("hot_poison") > 10)
           me->apply_condition("hot_poison", me->query_condition("hot_poison")-10);
        else
           me->clear_condition("hot_poison");
        message_vision("$N服下一份玉灵散，神色渐渐开始好转，身上的热毒也开始消散了。\n", this_player());
        add_amount(-1);
        return 1;
        }
}
