// huqing-stone.c 虎睛石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR "虎睛石" NOR, ({ "hujing stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR "虎睛石经过琢磨后，会呈显棕红色或蓝色，闪耀着美丽的金刚光泽。由于\n"
                                "上面多会有条状闪烁蓝光的晶质，使整个玉石看上去像是发光的虎晴，故\n"
                                "名虎晴石，是古时非常高档的玉石原料。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "fire");
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

