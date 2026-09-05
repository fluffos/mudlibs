// sanleng-ci 三棱刺
// by seagate@pkuxkx 2011.02.21

#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name(RED"三棱刺"NOR, ({"sanleng ci"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "三棱刺是一种十分常见的暗器，百炼精钢锻造而成的三面血槽的短刀。\n");
                set("unit", "些");
                set("base_unit", "枚");
                set("value", 1000);
                set("base_weight", 15);
        }
        set_amount(1); //不要改，否则暗器门会出错
        init_throwing(160);
        setup();
}