// jili.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIB"毒蒺藜"NOR, ({ "du jili", "jili" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "枚");
                set("base_weight", 20);
                set("material", "iron");
                set("long", HIG"毒蒺藜是淬毒暗器，寸许大小，发出诡异的光。\n"NOR);
                set("wield_msg", HIC"$N迅速地从身上摸出一些毒蒺藜，捏在手中就待发出！\n"NOR);
                set("unwield_msg",HIC"$N将手里剩下的毒蒺藜一抖就不见了。\n"NOR);
        }
        set_amount(5);
        init_throwing(50);
        setup();
}
