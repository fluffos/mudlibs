// heilv-yu.c 黑绿玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIG "黑绿玉" NOR, ({ "heilv yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG "此玉石多呈黑绿色，经过琢磨之后呈暗绿色或绿色，上有深浅不同的花斑。\n"
                                "黑绿玉具有如玻璃般的油脂光泽，因其硬度较低，所以易于雕琢，是一种\n"
                                "较为普及的玉石。 \n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "water");
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

