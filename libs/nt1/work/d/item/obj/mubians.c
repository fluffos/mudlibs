// mubian-stone.c 木变石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIW "木变石" NOR, ({ "mubian stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIW "木变石因为它的颜色和纹理与树木十分相似而得名。木变石的质地细腻，\n"
                                "具有很强的丝绢光泽。\n" NOR);
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

