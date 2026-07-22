// zhongjipifeng.c 终极披风
 
#include <armor.h>
 
inherit SURCOAT;
 
void create()
{
        set_name(HIR "终极披风" NOR,({ "zhongji pifeng", "pifeng" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "顶");
                set("long", "这是一件终极防具,目前还没有人穿过它,他的效果让人无法想象\n");
                set("wear_msg", HIY "$N穿上一件终极披风,顿觉身轻如燕,欲欲如飞.\n" NOR);
                set("value", 15000000);
                set("armor_prop/dodge", 150);
        }
        setup();
}

