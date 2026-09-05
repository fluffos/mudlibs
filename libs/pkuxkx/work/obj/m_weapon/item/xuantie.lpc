#pragma save_binary
//hanbing.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"千年玄铁"NOR, ({ "xuan tie","tie"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一块千年玄铁，乌黑黯淡，拿在手中极为沉重，似乎是制造兵器的绝好材料。\n");
                set("value", 100);
				set("for_fix_weapon",1);
                set("material", "steel");
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
