
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(WHT"铁矿石"NOR, ({ "iron ore","ore","iron"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",WHT"这是一大块灰白色的铁矿石，入手略觉沉重，炼制后似乎可以用来锻造兵器。\n"NOR);
                set("value", 0);
                set("rate", 1); //设置材料等级
                set("rigidity",40+random(30)); //设置材料硬度，也即武器硬度
                set("can_make", "all");
                set("material_attrib", "iron");
                set("power_point", 30+random(30)); //做成后的jiali大小
              }
}
