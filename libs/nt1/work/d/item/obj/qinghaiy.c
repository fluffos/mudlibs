// qinghai-yu.c 青海玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "青海玉" NOR, ({ "qinghai yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "青海玉因其产于青海而得名。玉质透明度较高，但缺乏滋润感与浑厚感，\n"
                                "玉内经常有乳白色的条状白斑，被称之为水线，打磨后的青海玉十分美丽，\n"
                                "光彩夺目。\n" NOR);
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

