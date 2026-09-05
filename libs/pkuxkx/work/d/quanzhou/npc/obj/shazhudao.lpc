// shazhudao

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("杀猪刀", ({ "sha zhudao", "dao", "blade" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄杀猪刀。\n");
                set("value", 1500);
                set("rigidity", 5);
                set("material", "steel");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_blade(10);
        setup();
}


