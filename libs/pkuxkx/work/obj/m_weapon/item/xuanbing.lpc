#pragma save_binary
//hanbing.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"万年玄冰"NOR, ({ "xuan bing","bing"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一块万年玄冰，通体晶莹剔透，在阳光的照耀下居然不化，拿在手中轻若无物，\n似乎是制造兵器的绝好材料。\n");
                set("value", 0);
				set("for_create_weapon",1);
                set("material", "ice");
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
