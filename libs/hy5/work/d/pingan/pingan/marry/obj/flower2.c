//begonia.c
//by chx 5/21/98

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIM "海棠花" NOR, ({ "begonia","flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一朵娇艳美丽的海棠花。\n");
                set("unit", "朵");
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
