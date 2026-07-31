//LUCAS 2000-6-18
// baihongjian.c 白虹剑
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( HIW "白虹剑" NOR , ({ "baihongjian", "sword", "jian" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
set("treasure",1);
                set("unit", "柄");
                set("long", "这是一口削铁如泥的宝剑,是凌霄城镇派之宝。\n");
                set("value", 10000);
                set("material", "steel");
                set("weapon_prop/personality", 8);
                set("wield_msg", "$N「唰」的一声抽出一柄寒光闪闪的$n握在手中,刹时寒气四射,草木欲结。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(450);
        setup();
}
