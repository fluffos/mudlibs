#pragma save_binary
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIB"天香鱼胶"NOR, ({"yu jiao","yu","jiao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是块乳白色的天香鱼胶，摸起来手感滑腻，极其柔韧，似乎是制造衣服的绝好材料。\n");
                set("value", 0);
				set("for_create_cloth",1);
                set("material", "fish");
              set("treasure",1);
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
