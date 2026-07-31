// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
      set_name("阴阳二气瓶",({"yinyang erqi ping", "ping", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100);
    set("material","cloth");
      set("long","大鹏明王随身法宝，假若把人装在瓶中，一时三刻化为浆水。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
    set("no_sell", "阴阳二气瓶乃法宝没人敢买也。\n");
    set("no_give", "阴阳二气瓶乃法宝不可赠人也。\n");
  set("is_monitored",1);
  setup();
} 

