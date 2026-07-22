// 檀香扇

#include <weapon.h>
#include <ansi.h>

inherit SWORD;


void create()
{
        set_name(GRN "檀香扇" NOR, ({ "tanxiang shan", "shan" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把沉甸甸的檀香木宝扇。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", GRN "$N展开扇子，轻轻地扇了扇。\n" NOR);
                set("unwield_msg", GRN "$N刷的一声合上扇子，放回袖中。\n" NOR);
        }
        init_sword(40);
        setup();
}

