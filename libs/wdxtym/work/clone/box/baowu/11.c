#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(NOR + WHT "黑龙鞭" NOR, ({ "heilong bian", "heilong", "bian", "whip" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "一支通体漆黑的长鞭，看上去倒是很坚韧。\n" NOR);
                set("unit", "根");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "从腰间取出一卷漆黑的长鞭，凌空挥舞个圈子。\n" NOR);
                set("unwield_msg", WHT "$N" WHT "一声轻哼，将手中黑龙鞭盘好，放回腰间。\n" NOR);
                set("stable", 100);
        }
        init_whip(600+random(320));
        setup();
}
