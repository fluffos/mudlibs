// by snowcat oct 15 1997
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIG"战袍"NOR, ({"zhan pao", "cloth"}));
  set("level",10);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件战袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
    set("armor_prop/armor", 30);
	set("no_sell",1);
  }
  setup();
}

