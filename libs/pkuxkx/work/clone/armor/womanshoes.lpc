#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIY "三寸金莲" NOR, ({ "sancun shoes", "shoes" }));
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
