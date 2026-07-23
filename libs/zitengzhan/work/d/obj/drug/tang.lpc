
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  switch (random(4)) {
    case 0:
      set_name( HIW "芝麻酥糖" NOR , ({"xi tang", "tang"}));
    case 2:
      set_name( HIW "太妃糖" NOR , ({"xi tang", "tang"}));
      break;
    case 3:
      set_name( HIW "咖啡糖" NOR , ({"xi tang", "tang"}));
      break;
    case 4:
      set_name( HIW "大白兔糖" NOR , ({"xi tang", "tang"}));
  }
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "包");
    set("long", "一包至尊宝的喜糖.\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="tang" && arg!="xi tang")	return 0;
  if (me->query("wizgift/cookie_2000_eaten") <=5)
 {
  me->add("wizgift/cookie_2000_eaten",1); 
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  me->add("potential",200);
  me->add("combat_exp",200);
  me->save();
  log_file("static/TANGGIFT","["+ctime(time())+"] "+
  sprintf("%s(%s)吃了一颗%O\n",
  this_player()->query("name"),this_player()->query("id"),
  this_object()));

 }
  message_vision(HIG "$N吃下一颗喜糖.
\n" ,me);
  destruct(this_object());
  return 1;
}

