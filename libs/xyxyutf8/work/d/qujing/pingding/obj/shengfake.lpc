// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("幌金绳",({"huangjin sheng", "sheng", "fabao"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","根");
    set("value", 100000);
    set("material","cloth");
    set("long","一根可长可短的幌金绳。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
  set("no_sell", "幌金绳乃法宝没人敢买也。\n");
  set("no_drop", "幌金绳乃法宝不可扔弃也。\n");
  set("no_give", "幌金绳乃法宝不可赠人也。\n");
  set("is_monitored",1);
  setup();
} 