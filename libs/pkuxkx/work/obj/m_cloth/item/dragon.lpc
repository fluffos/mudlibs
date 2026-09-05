#pragma save_binary
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"毒龙角"NOR, ({"dragon jiao","dragon","jiao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long","这是一只毒龙角，摸起来手感粗糙，极其坚硬，似乎是制造衣服的绝好材料。\n");
                set("value", 0);
				set("for_create_cloth",1);
                set("material", "dragon");
              set("treasure",1);
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
