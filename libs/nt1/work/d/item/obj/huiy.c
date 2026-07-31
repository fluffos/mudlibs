// hui-yu.c 灰玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(WHT "灰玉" NOR, ({ "hui yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", WHT "灰玉是墨玉中的下品，多呈灰白色。玉质较差，是民间常见的一种玉石。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "wood");
                set("magic/power", 100);
                set("armor_prop/per", 5);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

