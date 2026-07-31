#include <ansi.h>
inherit ITEM;
inherit F_FOOD; 
void create()
{
                set_name("龙鲤鱼", ({ "dragonfish" }) );
    set_weight(500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
        set("long", HIY"一条闪闪生辉的鲤鱼，鳞片阔大且光滑。\n"NOR);
        set("unit", "条");
        set("value", 5000);
        set("food_remaining", 3);
        set("food_supply", 10);
        set("marks/catfood", 1);
    }
    
} 
void init() {
        ::init();
        call_out("badfish", 120);
} 
void badfish() {
        set("long", "已经不再新鲜的鱼散发着一股腥臭味。\n");
        set("name", "散发着腥臭味的鱼");
        set("marks/catfood", 0);
        set("value", 0);
}  

