// ruyi-zhu 柳叶刀
// by seagate@pkuxkx 2011.02.21

#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name(HIW"柳叶刀"NOR, ({"liuye dao"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "柳叶刀是一种十分常见的暗器，百炼精钢锻造而成的形如柳叶的薄片飞刀。\n");
                set("unit", "些");
                set("base_unit", "把");
                set("value", 1000);
                set("base_weight", 15);
        }
        set_amount(1); //不要改，否则暗器门会出错
        init_throwing(130);
        setup();
}