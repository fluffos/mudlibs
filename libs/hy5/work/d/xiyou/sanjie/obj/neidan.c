// neidan.c 纯阳内丹

#include <ansi.h>

inherit ITEM;



void create()
{
  set_name(HIM "纯阳内丹" NOR, ({"chunyang neidan","neidan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "纯阳先师积聚了四百年功力而成的内丹。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  
  set("is_monitored",1);
  setup();
}

