
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("金丝甲", ({ "bao jia", "jia" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是平西王收藏多年，爱之如命的一件宝甲，相传是当年魏武帝曹操所用之物
价值连城\n");
                set("material", "gold");
                set("unit", "件");
                set("value", 60000);
                set("wear_msg", BLU "$N披上了一件华美无比的宝甲。\n" NOR);

                set("remove_msg", YEL "$N将金丝甲脱了下来。\n" NOR);
                 set("armor_prop/armor", 500);
                 set("no_sell",1);
                 set("sell_in_playershop",1);
        }
        setup();
}

