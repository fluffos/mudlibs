#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("竹箫", ({ "zhu xiao", "xiao" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根普通的六孔竹制洞箫，做工非常精致。\n");
                set("value", 50000);
                set("material", "bamboo");
                set("music", "shaw");
                set("wield_msg", "$N将一根$n放在嘴边。\n");
                set("unwield_msg", "$N将嘴边的$n放了下来。\n");
        }
        init_sword(5,1);
        setup();
}