// lvsong-stone.c 绿松石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIG "绿松石" NOR, ({ "lvsong stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIC "绿松石与著名的土耳其玉是一个品种。其颜色多为苹果绿、蓝绿或天蓝。\n"
                                "绿松石是中国最古老的传统玉石的一种，早在新石器时代，它就经常被用\n"
                                "来作装饰品。中国藏族同胞认为绿松石是神的化身，是权力和地位的象征。\n" NOR);
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

