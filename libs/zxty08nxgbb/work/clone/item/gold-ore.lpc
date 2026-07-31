
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(YEL"金矿石"NOR, ({"golden ore","ore","golden"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",YEL"这是一大块价值不菲的金矿石，入手颇有些沉重，炼制后似乎可以用来锻造兵器。\n"NOR);
                set("value", 100);
                set("rate", 2); //设置材料等级
                set("rigidity",100+random(30)); //设置材料硬度，也即武器硬度
                set("can_make", "all");
                set("material_attrib", "gold");
                set("power_point", 100+random(30)); //做成后的jiali大小
              }
}
