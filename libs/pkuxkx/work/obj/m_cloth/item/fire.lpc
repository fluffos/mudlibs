#pragma save_binary
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"赤炼火铜"NOR, ({"chilian huotong","huo","tong"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是块火红色的金属，摸起来却出奇柔软，似乎是制造衣服的绝好材料。\n");
                set("value", 0);
				set("for_create_cloth",1);
                set("material", "steel");
              set("treasure",1);
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
