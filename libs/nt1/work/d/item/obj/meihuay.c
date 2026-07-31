// meihua-yu.c 梅花玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "梅花玉" NOR, ({ "meihua yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "梅花玉的底色多为墨绿或黑色，上面衬以白、绿、红色的梅花状朵枝，姿\n"
                                "态万千，栩栩如生，很是惹人喜爱。后世到东汉初期，梅花玉被汉光武帝\n"
                                "正式封为“国宝”。\n" NOR);
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

