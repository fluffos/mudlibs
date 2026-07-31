#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("七星海棠", ({"qixing haitang", "qixing","yaowu"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 5000);
      set("unit", "些");
      set("long","这是一种奇特的花草，剧毒。\n");
      set("base_value", 5000);
      set("base_unit", "份");
      set("base_weight", 30);
   }
set("make/drug",1);
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
   me->apply_condition("xx_poison", 50);
 destruct(this_object());
 return 1;
}
