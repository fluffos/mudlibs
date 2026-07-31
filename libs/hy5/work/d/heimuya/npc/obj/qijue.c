// weapon: xiuhua.c 绣花针
// Jay 4/7/96
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIR"七绝针"NOR, ({ "qijue zhen", "zhen", "qijue" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根精钢细磨的七绝针。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N用拇指和食指从鬓间拈出一根$n。\n");
                set("unwield_msg", "$N将手中的$n插回鬓间。\n");
        }
        init_sword(400);
        setup();
}

