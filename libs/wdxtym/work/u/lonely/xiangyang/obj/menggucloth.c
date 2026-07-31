#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(NOR + YEL "ци╧ееш" NOR, ({ "cloth" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
