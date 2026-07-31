// mo-yu.c 墨玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(GRN "墨玉" NOR, ({ "mo yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN "黑玉中色黑如漆的叫墨玉，也就是古人常说的玄玉。墨玉有的非常莹辙，\n"
                                "甚至可以作为镜子。墨玉是古代玉石中极为珍稀的一种。\n" NOR);
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

