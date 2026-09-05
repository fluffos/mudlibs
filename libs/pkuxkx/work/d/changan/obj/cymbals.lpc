#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铜钹", ({ "tong bo", "bo" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long", "这是一对普通的铜钹。\n");
                set("value", 50000);
                set("material", "copper");
                set("music", "cymbals");
                set("wield_msg", "$N双手拿起一对$n。\n");
                set("unwield_msg", "$N双手放下一对$n。\n");
        }
        init_hammer(5,1);
        setup();
}