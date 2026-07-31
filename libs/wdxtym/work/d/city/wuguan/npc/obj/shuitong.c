//shuitong.c

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("水桶", ({ "shui tong", "tong", "hammer"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只水桶，普通百姓的日常用品。\n");
                set("value", 50);
                set("material", "steel");
                set("wield_msg", "$N拿出一只$n担在肩中。\n");
                set("unwield_msg", "$N将肩上的$n放了下来。\n");
        }
        init_hammer(10);
        setup();
}
