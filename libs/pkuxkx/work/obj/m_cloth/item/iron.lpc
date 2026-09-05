#pragma save_binary
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIC"神秘金属"NOR, ({"shenmi jinshu","jinshu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是块从没有见过的神秘金属，摸起来手感滑腻，似乎感觉不到重量，似乎是制造衣服的绝好材料。\n");
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
