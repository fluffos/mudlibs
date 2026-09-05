#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("七弦古琴", ({ "gu qin", "qin" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张普通的七弦古琴，做工非常精致。\n");
                set("value", 50000);
                set("material", "wood");
                set("music", "qin");
                set("wield_msg", "$N捧起一张$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        init_sword(15);
        setup();
}