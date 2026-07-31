
#include <ansi.h>
inherit ITEM;
int do_eat(string arg);
void create()
{
   set_name(HIW"养气补虚丹"NOR, ({ "dan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "药物");
     set("unit", "枚");
     set("value", 2000);
   }
   setup();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||(arg!="dan"&&arg!="丹"))
  return notify_fail("你要吃什么？\n");
  if(!present(arg,ob))
  return notify_fail("你身上没有这个东西！\n");
  if(ob->query("eff_qi")>=ob->query("max_qi"))
  return notify_fail("你现在气血充沛，没有必要吃丹药。\n");
  message_vision("$N吃下了一枚"+this_object()->name()+"\n",ob);
  ob->set("eff_qi",ob->query("max_qi"));
  ob->start_busy(1);
  destruct(this_object());
  return 1;
}