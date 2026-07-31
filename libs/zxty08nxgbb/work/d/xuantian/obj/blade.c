// gangdao.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("短刀", ({ "blade" }));
        set_weight(7000);
                set("flag",2);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄轻巧的短刀，隐隐透出一股凶杀之气。\n");
                set("value", 5);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
       init_blade(200,2);
        setup();
}

