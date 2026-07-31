// hanyanguan 旱烟管

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("旱烟管", ({ "han yanguan", "yanguan" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一支铜制的旱烟管，里面还剩点烟末。。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N摸出一支旱烟管，点上火，叼在嘴角，慢慢喷出烟雾。\n");
                set("unwield_msg", "$N把旱烟管在鞋底上嗑一嗑，小心地放回怀里。\n");
        }
        init_staff(28);
        setup();
}

