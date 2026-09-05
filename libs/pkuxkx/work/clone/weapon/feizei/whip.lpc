#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIY"金蛇带"NOR, ({"jinshe dai","dai","whip"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"纯钢久炼而成之神兵，长约三尺许，其上镀赤金，内镂空，鞭身布满鳞片，极锋利。\n"NOR);
                set("unit", "把");
                set("no_put",1);
                set("value", 100000);
                set("no_give_user",1);
                set("no_steal",1);
                set("weapon_prop/whip",12+random(12));

        }
        init_whip(120+random(50));
        setup();
}
