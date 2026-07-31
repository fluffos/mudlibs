//lotus.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIM "并蒂莲" NOR, ({ "lotus","flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一对蒂开放的莲花。\n");
                set("unit", "对");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);

        }
        setup();
}
