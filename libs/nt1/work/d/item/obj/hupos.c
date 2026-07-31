// hupo-stone.c 琥珀

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "琥珀" NOR, ({ "hupo stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "琥珀，中国古代称之为“虎魄”。颜色多呈黄色，光滑亮丽。古人认为琥\n"
                                "珀还能够消痛镇惊，有的地方常给小孩胸前挂一串琥珀，以此驱邪镇惊。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "soil");
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

