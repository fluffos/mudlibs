//angelcloth.c
#include <weapon.h>
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
set_name("天使之衣",({"angel cloth","cloth"}));
set_weight(2400);
if(clonep())
set_default_object(__FILE__);
else
{
set("long","这是一件洁白无暇的衣裳.\n");
set("material","silk");
set("unit","件");
set("value",300000);
set("wear_msg",HIW"白云慢慢聚拢，将$N笼罩了起来。\n"NOR);
set("remove_msg",HIY"白云慢慢升起，在半空中又聚拢，回到$N的手中。\n"NOR);
set("armor_prop/armor",500);
setup();
}
}
