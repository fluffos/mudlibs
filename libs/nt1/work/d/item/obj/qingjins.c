// qingjin-stone.c 青金石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIC "青金石" NOR, ({ "qingjin stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIC "青金石在古代称为“璆琳”或“琉璃”，因其色多为青色，民间认为青色\n"
                                "是通天之路的颜色，所以经常被用来制做皇帝的葬器。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "gold");
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

