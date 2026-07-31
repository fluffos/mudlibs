#include <ansi.h>
inherit ITEM;
void create()
{
   set_name("莫名丹", ({"moming dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "粒");
      set("value", 100);
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
   message_vision(HIY + "$N吃下一粒" + name() + NOR + "。\n", me);
   if ((int)me->query("potential") <= 2000) {
         me->add("potential",10);
      }
     message_vision("$N吃下一粒" + name() + "。\n", me);
      tell_object(me,"你好象感到身体发生了细微的变化。\n");
   destruct(this_object());
   return 1;
}

