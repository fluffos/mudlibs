// /clone/weapon/tiejili.c
// by leontt 2000/10/26

inherit COMBINED_ITEM;
#include <ansi.h>
#include "/inherit/item/embed.h"

void create()
{
        set_name(CYN"铁蒺藜"NOR, ({ "tie jili","jili"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", CYN"这是一个很阴毒的暗器，上面长满了倒刺。\n"NOR);
               set("unit", "些");
               set("damage", 6);
               set("value", 400);
               set("base_value", 400);
               set("base_unit", "个");
               set("base_weight", 200);
               set("material", "steel");
               set("embed", 1);
        }
        set_amount(1);
}
