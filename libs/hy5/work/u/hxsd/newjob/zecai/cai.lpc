inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"蔬菜"NOR, ({ "xian cai" , "cai"}) );
        set_weight(50); 
        set("no_give",1);
        set("no_put",1);        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把新鲜的蔬菜。\n");
                set("value", 1);
        }
}



