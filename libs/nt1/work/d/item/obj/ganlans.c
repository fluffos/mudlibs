// ganlan-stone.c 橄榄石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIG "橄榄石" NOR, ({ "ganlan stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG "橄榄石因其颜色多为橄榄绿色而得名，多产于北部地区。古时候称橄榄石\n"
                                "为“太阳的宝石”，人们相信橄榄石所具有的力量像太阳一样大，可以驱\n"
                                "除邪恶，降伏妖术。橄榄石颜色艳丽悦目，为人们所喜爱，给人以心情舒\n"
                                "畅和幸福的感觉，故被誉为“幸福之石”。\n" NOR);
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

