
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIY"铜矿石"NOR, ({"copper ore","ore","copper"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",HIY"这是一大块黄褐色的铜矿石，入手略觉沉重，炼制后似乎可以用来锻造兵器。\n"NOR);
                set("value", 0);
                set("rate", 1); //设置材料等级
                set("rigidity",50+random(30)); //设置材料硬度，也即武器硬度
                set("can_make", "all");
                set("material_attrib", "copper");
                set("power_point", 40+random(30)); //做成后的jiali大小
              }
}
