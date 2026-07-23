#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("清心散", ({"qingxin san", "qingxin","san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 5000);
      set("unit", "些");
      set("long","这是一份星宿派的清心散，可以解毒。\n");
      set("base_value", 5000);
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

   if (!me->query_condition("xx_poison"))
           return notify_fail("你现在不需要用清心散。\n");
   else {       
        if(me->query_condition("xx_poison") > 5)
           me->apply_condition("xx_poison", me->query_condition("xx_poison")-5);
        else
           me->clear_condition("xx_poison");
        message_vision("$N服下一份清心散，脸上的阴气消散了一点。\n", this_player());
        add_amount(-1);
        return 1;
        }
}
