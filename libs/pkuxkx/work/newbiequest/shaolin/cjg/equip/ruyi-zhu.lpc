// ruyi-zhu 如意珠
// by seagate@pkuxkx 2011.02.21

#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name(WHT"如意珠"NOR, ({"ruyi zhu"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "如意珠是一种十分常见的暗器，百炼精钢铸造而成的小型钢珠。\n");
                set("unit", "堆");
                set("base_unit", "颗");
                set("value", 1000);
                set("base_weight", 15);
        }
        set_amount(1); //不要改，否则暗器门会出错
        init_throwing(100);
        setup();
}