//Cracked by Roath

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW "何首乌" NOR, ({"heshouwu","wu"}));
  set_weight(200);
  set("no_get","你手里一松"+this_object()->query("name")+"丹从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗又黑又壮的何首乌。\n");
        set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
 if (!arg || !id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  me->powerup(0,0);
  
  destruct(this_object());
  return 1;
}

