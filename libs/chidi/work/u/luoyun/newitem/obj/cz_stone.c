#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"创造宝石"NOR, ({"chuangzao stone", "baoshi","stone"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_drop",1);
                set("material","baoshi");//进化宝石类标志
                set("express","can_shenghua");//可进化标志
                set("unit","颗");
                set("point",70);//成功率70%
                set("no_put",1);
                set("lvl",7);//可以合成+0至+7的装备
                set("no_give",1);
                set("no_sell",1);
                set("long",HIG"传说中神界用于进化的宝石(合成进化物品成功率:70%)
使用范围：0－7级的装备进化合成。\n"NOR);
        }
        setup();
}
void owner_is_killed() { destruct(this_object()); }
