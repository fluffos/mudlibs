#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIM"神龙鞭"NOR, ({"shenlong bian","bian","whip"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"神龙岛镇岛之宝，神龙鞭！\n"NOR);
                set("unit", "条");
                set("no_put",1);
                set("value", 0);
                set("no_store",1);
                set("no_give_user",1);
                set("no_steal",1);
                set("weapon_prop/whip",12+random(12));

        }
        init_whip(100+random(50));
        setup();
}
