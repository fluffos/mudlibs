#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIY"凝露黄石"NOR, ({"topaz", "huangshi", "yellow stone" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "块");
                        set("long", "这是五金之英聚成的凝水石。看来柔润晶莹，触手却丝丝寒气刺肤如割。
细细的水珠凝在石面，拂而再聚。\n");
            set("value", 20000);
                        set("imbue", 1);
                        set("no_drop",1);
                        set("no_give",1);
                        set("no_sell",1);
        }

}  
