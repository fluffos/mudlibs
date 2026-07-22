#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  add_action("do_eat", "eat");
}

void create()
{
  set_name( GRN "九转丹" NOR , ({"jiuzhuan dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗金黄色的丹丸，略微能闻到些许香气。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="jiuzhuan dan")   return 0;
  
  me->add_skill("dodge",1);
  message_vision(HIG "$N嗨嗨的叫了几声。\n" NOR, me);
  destruct(this_object());
  return 1;
}

