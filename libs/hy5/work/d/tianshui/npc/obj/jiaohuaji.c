// jiaohuaji.c
#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;
void create()
{
        set_name("叫化鸡", ({ "jiaohua ji", "chicken", "ji" }) );
        set_weight(550);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只包着荷叶的叫花鸡，散发着扑鼻的香气，让人垂涎欲滴。\n");
                set("unit", "只");
                set("value", 90);
                set("food_remaining", 8);
                set("food_supply", 80);
                set("wield_msg", "$N抓起一只$n，握在手中当武器。\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}
int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("啃得精光的鸡腿骨头", ({ "bone" }) );
        set_weight(150);
        set("long", "一根啃得精光的鸡腿骨头。\n");
        return 1;
}
