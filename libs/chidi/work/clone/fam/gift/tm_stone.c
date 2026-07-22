#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HBRED"天使之心"NOR, ({"tianshi stone", "baoshi","stone"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","baoshi");//进化宝石类标志
                set("express","can_shenghua");//可进化标志
                set("unit","颗");
                set("point",50);//成功率50%                
                set("lvl",9);//可以合成+0至+9的装备                
                set("long",HIB"高級類的进化宝石(合成进化物品成功率:50%)
使用范围：0－9级的装备进化合成。\n"NOR);
        }
        setup();
}
void owner_is_killed() { destruct(this_object()); }
