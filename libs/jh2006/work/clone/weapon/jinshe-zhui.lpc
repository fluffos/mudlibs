#include <ansi.h>
inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"
void create()
{
        set_name("金蛇锥", ({ "jinshe zhui","jinshe","zhui" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "这是一枚两寸来长，成蛇形的暗器。\n");
               set("unit", "些");
               set("damage", 50);
               set("unique", 2);
               set("base_value", 30000);
               set("base_unit", "枚");
               set("base_weight", 1000);
               set("material", "steel");
               set("embed", 1);
        }
        set_amount(3+random(8));

}

