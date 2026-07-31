//LUCAS 2000-6-18
// 寒玉牌 hanyu pai

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIW"寒玉牌"NOR, ({"hanyu pai", "pai"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
set("treasure",1);
                set("long","这是一块雪白的玉牌，触手生寒，凝人气血。\n");
//              set("no_drop", "这样东西不能离开你。\n");
                set("material", "yu");
        }
}

