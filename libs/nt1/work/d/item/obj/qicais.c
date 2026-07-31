// qicai-stone.c 齐彩石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "齐彩石" NOR, ({ "qicai stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "主要产于在沂蒙山北麓弥河两岸，为半玉半石的石质，质地细润，有光泽。\n"
                                "纹理奇妙，变幻无穷\n" NOR);
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

