// gao-stone.c 锆石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "锆石" NOR, ({ "gao stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "锆石具有亮丽的金属光泽，多为半透明。民间认为佩带红锆石可以起到催\n"
                                "眠作用，可以驱走瘟疫，战胜邪恶。\n" NOR);
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

