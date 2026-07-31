// Modify By River 98/12
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("熟铜棍", ({ "shu tonggun", "gun" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根精铜打造的长棍，可攻击大片敌人。\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("dali",1);
        }
        init_club(25);
        setup();
}

