// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>
#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name(HIC"点钢枪"NOR, ({"steel spear", "qiang", "spear"}));
  set_weight(4000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long", "这是一把点钢枪，舞起来明幌幌如龙离海。\n");
    set("value", 500);
    set("material", "iron");
    set("wield_msg", "$N一招「龙离黑海」拿出一把$n挺在手中。\n");
    set("unwield_msg", "$N放下手中的$n。\n");
  }

  init_spear(55);
  setup();
}

