inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(GRN"洛阳燕菜"NOR, ({ "luoyang yancai", "yancai" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "相传，武则天居洛阳时，东关一块菜地里，长出一个几十斤的大萝卜，\n菜农认为是神奇之物，献给女皇武则天，御厨师把它切成丝、拌粉清\n蒸，配以鲜味汤汁，女皇吃后，其味异常鲜美，大有燕窝风味，赞不\n绝口，赐名“燕菜”。\n");
                set("unit", "盘");
                set("value", 1000);
                set("food_remaining", 10);
                set("food_supply", 10);
                set("material", "meat");
        }
        setup();
}
