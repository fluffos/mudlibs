#include <ansi.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit SURCOAT;

void create()
{
  set_name(HIM"披风"NOR, ({"yuxue pifeng", "pifeng", "cloth" }));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件集天地之灵气所造就的披风。\n");
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
    set("material", "crimsonsteel");
    set("unit", "件");
    set("value", 1000);
    set("no_zm",1);
     set("no_give",1);
    set("armor_prop/armor", 12000);
    set("armor_prop/dodge", 18500000);
    set("armor_prop/spells", 30);
  }
  setup();
}


