#pragma save_binary
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"天蚕丝"NOR, ({"cai si","cai","si"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                 set("long","这是根透明的天蚕丝，似乎是制造衣服的绝好材料。\n");
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
