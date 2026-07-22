// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("羊脂玉净瓶",({"jing ping", "jing", "ping", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100000);
    set("material","cloth");
    set("long","一只几乎透明的羊脂玉净瓶。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
  set("no_sell", "羊脂玉净瓶乃法宝没人敢买也。\n");
  //set("no_drop", "羊脂玉净瓶乃法宝不可扔弃也。\n");
  set("no_give", "羊脂玉净瓶乃法宝不可赠人也。\n");
  set("is_monitored",1);
  setup();
} 