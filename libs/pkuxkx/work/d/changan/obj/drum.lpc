#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("腰鼓", ({ "yao gu", "gu" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long", "这是一面源自彝族的牛皮腰鼓，做工非常精致。\n");
                set("value", 50000);
                set("material", "cowhide");
                set("music", "drum");
                set("wield_msg", "$N将一面$n放在腰边双手拿起敲鼓的棍子。\n");
                set("unwield_msg", "$N将腰边的$n和双手的棍子收了起来。\n");
        }
        init_hammer(5,1);
        setup();
}