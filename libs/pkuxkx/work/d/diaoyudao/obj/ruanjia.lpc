//jia.c
#include <weapon.h>
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
   set_name("护体软甲",({"ruan jia","jia"}));
set_weight(2400);
if(clonep())
set_default_object(__FILE__);
else
{
set("long","韦小宝的贴身宝贝，此甲用某种特殊物质所做，坚韧无比，乃是罕见的宝物。\n");
set("material","cloth");
set("unit","件");
set("value",300000);
set("wear_msg",HIY"刹那间，天云变色，$N被一片金光包了起来。\n"NOR);
set("remove_msg",HIY"$N将$n脱了下来，$N周身顿觉暗淡.\n"NOR);
set("armor_prop/armor",500);
setup();
}
}
