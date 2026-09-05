
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "旗帜" NOR, ({ "flag" }) );
    set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long",
"这是一杆古时的旗帜，非常锋利，而且很小巧，可以作为宝剑用。\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N从怀里拿出把小旗子，挥动着小手，奶声奶气的喊着“祖国万岁，人民万岁”。\n");
                set("unwield_msg", "一抖手，$N迅快的把手里的小旗子藏到怀里，满是得意之色，心里说“不给你们看了。”\n"); 
        }
       init_sword(200);


        setup();

}




