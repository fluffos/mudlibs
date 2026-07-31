#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
  set_name(HIG"战盔"NOR, ({ "tiekui", "kui" }) );
  set("level",2);
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","一顶沉重的大铁盔，顶上有一尖柄。\n");
    set("value", 1000);
    set("material", "cloth");
    set("armor_prop/armor", 30);
    set("armor_prop/personality", 1);
	set("no_sell",1);
  }
  setup();
}

