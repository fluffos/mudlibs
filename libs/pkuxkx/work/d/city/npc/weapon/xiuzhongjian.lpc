//袖中剑

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(WHT"袖中剑"NOR, ({ "xiuzhong jian", "jian" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "只");
                set("long", HIG"这是一只短小的袖中剑。\n"NOR);
                set("value", 10000);
                set("material", "steel");
                set("base_weight", 10);
                set("wield_msg", "$N从怀里拿出一只$n，藏于袖中。\n");
                set("unwield_msg", "$N将袖中的$n拿出揣入怀中。\n");
        }
        set_amount(1);
        init_throwing(70);
        setup();
}

