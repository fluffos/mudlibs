#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIC "侠客行战靴" NOR, ({ "xkx shoes", "shoes" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
