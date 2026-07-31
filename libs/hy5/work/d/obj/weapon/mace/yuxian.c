
//Junhyun BY 2002.05.16
#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
  set_name(YEL "鱼线" NOR, ({"yu xian", "mace"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("value", 18000);
    set("material", "steel");
    set("long", "姜子牙钓鱼用的鱼线，怎么看都跟普通的细绳没什么区别。\n");
    set("wield_msg", "$N从鱼杆顶端取下$n，拿在手里甩了甩，似乎非常顺手。\n");
    set("unwield_msg", "$N把手中的$n卷了卷放在自己的怀中，爱惜无比。\n");
  }
  
  init_staff(95);
  setup();
}

