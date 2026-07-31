// created by angell 5/7/2001

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIY "锦衣披风" NOR, ({"jinyi pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件锦缎所制的披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 100);
    set("armor_prop/spells", 20);
    set ("armor_prop/force", 40);
    set("armor_prop/parry", 30);
    set("armor_prop/armor", 25);
  }
  setup();
}

