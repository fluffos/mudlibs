// yuanbao.c 

#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY"金元宝"NOR, ({"jin yuanbao" , "bao"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "yuanbao");
                set("long", "这是一锭金元宝，金灿灿的看着多可爱啊。\n");
                set("unit", "锭");
                set("base_value", 10000);
                set("base_unit", "锭");
                set("base_weight", 200);
        }
        set_amount(1);
}


