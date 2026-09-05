#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
   set_name("清心散", ({"qingxin san", "san"}));
   set_weight(100);
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "些");
      set("base_unit", "包");
      set("base_weight", 100);
      set("value", 100);
   }
   set_amount(5);
   setup();
}

int init()
{
   add_action("do_eat", "eat");
   add_action("do_eat", "fu");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

  

   message_vision("$N吃下一包" + name() + "。\n", me);
   if ((int)me->query_condition("xxx_poison") > 0) {
      me->apply_condition("xxx_poison", 0);}
   if ((int)me->query_condition("xx_poison") > 0) {
      me->apply_condition("xx_poison", 0);}
   if((int)me->query_condition("s-poison")>0) {
      me->apply_condition("s-poison",0); 
  }
   if((int)me->query_condition("fs-poison")>0) {
      me->apply_condition("fs-poison",0);
  }

   if(query_amount()<=1)
	{
	   write("你把"+name()+"吃完了。\n");
	}
	add_amount(-1);
   return 1;
}
