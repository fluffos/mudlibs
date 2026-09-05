#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("十三弦古筝", ({ "gu zheng", "zheng" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张梧桐木制作的普通古筝，做工非常精致。\n");
                set("value", 50000);
                set("material", "wood");
                set("music", "zheng");
                set("wield_msg", "$N捧起一张$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        init_staff(5,1);
        setup();
}