// yangzhi-yu 羊脂玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIW "羊脂玉" NOR, ({ "yangzhi yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIW "羊脂玉多是从白色细腻的大理岩中采集而出。其质地非常坚硬，并具有油\n"
                                "脂样的光泽，酷似羊脂，被誉为“白玉之冠”。名传千古的和氏璧就是以\n"
                                "羊脂玉制成。\n" NOR);
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

