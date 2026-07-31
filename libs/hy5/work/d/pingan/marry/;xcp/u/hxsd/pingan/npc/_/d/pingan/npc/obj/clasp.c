//clasp.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name( YEL "凤翅金钗" NOR, ({ "clasp" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "一支金丝七宝攒珠凤翅钗环。\n");
        set("unit", "支");

        set("value", 100000);


        set("material", "gold");
                set("armor_prop/armor", 0);
        set("armor_prop/personality", 15);
        set("wear_msg", "$N轻轻地把一支$n插在发髻上。\n");
        set("remove_msg", "$N轻轻地把一支$n从发髻上除了下来。\n");

                set("female_only", 1);

        }
        setup();
}
