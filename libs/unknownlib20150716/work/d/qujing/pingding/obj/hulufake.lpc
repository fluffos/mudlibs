// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("紫金红葫芦",({"hu lu", "hu", "lu", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100000);
    set("material","cloth");
    set("long","一只红里透紫的金葫芦。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
  set("no_sell", "紫金红葫芦乃法宝没人敢买也。\n");
  //set("no_drop", "紫金红葫芦乃法宝不可扔弃也。\n");
  set("no_give", "紫金红葫芦乃法宝不可赠人也。\n");
  set("is_monitored",1);
  setup();
} 
