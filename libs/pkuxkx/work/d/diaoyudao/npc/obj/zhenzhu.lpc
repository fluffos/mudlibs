// zhen_zhu.c 
//cgbii 96.10.3
#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name(HIW"珍珠"NOR, ({"zhen zhu","zhu"}));
        set("long","这是一颗白色、晶莹圆润的珍珠，价值连城。\n"); 
        set_weight( 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("unit","颗");
                set("value",2000);
                set("material", "gold");
                set("armor_prop/armor", 1);
        }
        setup();
}
