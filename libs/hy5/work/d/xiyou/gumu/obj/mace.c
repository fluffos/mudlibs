//打神鞭
//ivy

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
  set_name("打神鞭", ({"killgod mace", "mace"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 180);
    set("material", "iron");
    set("long", "姜子牙的打神鞭，据说可以上打众神，下打群鬼。\n");
    set("wield_msg", "$N念了个咒，$n悠悠的飞上了半空！\n");
    set("unwield_msg", "$N右手捏了个决，$n飞回$N的腰间。\n");
  }
  
  init_staff(500);
  setup();
}

