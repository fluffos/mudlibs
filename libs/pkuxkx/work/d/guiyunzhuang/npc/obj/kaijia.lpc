#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
set_name(HIC"金轮铠甲"NOR,({"jinlun kaijia","kaijia"}));
set_weight(4000);
set("no_put",1);
if(clonep())
set_default_object(__FILE__);
else
{
set("long","这是一件灵光四溢的铠甲，坚韧无比。\n");
set("material","steel");
set("unit","件");
set("value",10000);
set("wear_msg",HIY"只听[哗]的一声$N身上多了件金光四溢的铠甲.\n"NOR);
set("remove_msg",HIY"$N将$n从身上托下来。\n"NOR);
set("armor_prop/armor",100);
}
setup();
}
