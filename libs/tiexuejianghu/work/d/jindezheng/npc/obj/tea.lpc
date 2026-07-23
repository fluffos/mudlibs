#include <weapon.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("青瓷茶碗", ({ "qingci chawan", "chawan", "wan", "tea" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "这是一只青花瓷茶碗。\n");
    set("unit", "只");
    set("value", 40);
    set("max_liquid", 80); 
  }

  set("liquid", ([
    "type": "tea",
    "name": "铁观音茶",
    "remaining": 80,
  ]) );
  setup();
}
