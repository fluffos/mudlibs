// mubei 墓碑

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("墓碑", ({ "mu bei","bei" }) );
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "碑上写的是「先考黄府君诚本之墓」。\n");
                set("material", "stone");
                set("wield_msg", "$N对着地上一座坟磕了个头，说声对不起，搬起一座墓碑。\n");
                set("unwield_msg", "$N把墓碑往地上一放，不小心砸到自己的脚。\n");
        }
        init_hammer(30);
        setup();
}

