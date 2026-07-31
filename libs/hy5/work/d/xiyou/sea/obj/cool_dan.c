#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "±ÌË®µ¤" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¿Å");
    set("long", "±ÌÓÍÓÍµÄÒ»¿Å±ÌË®µ¤¡£\n");
    set("value", 500);
    set("no_sell", 1);
  }
  
  setup();
}

