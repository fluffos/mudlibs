#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
set_name(HIY"七星剑"NOR,({"qixing sword","sword"}));
set_weight(8000);
if(clonep())
set_default_object(__FILE__);
else
{
set("unit","把");
set("long","这是一把锋利无比的，杀气四溢的剑.\n");
set("value",1000);
set("material","steel");
set("wield_msg",HIY"[嗖]的一声$n脱鞘而出。\n"NOR);
set("unwield_msg",HIY"$n自$N手中直插进入剑鞘。\n"NOR);
}
init_sword(80);
setup();
}
