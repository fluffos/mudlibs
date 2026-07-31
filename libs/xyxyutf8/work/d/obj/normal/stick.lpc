#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
        set_name(HIG"长棍"NOR, ({"gun", "bang", "stick"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("no_sell", 1);
		set("long", "一把淡青色的短棒，上面有暗红流动，如同一条火蛇般绕在棒上。\n");
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
				set("no_sell",1);

        }
        init_stick(70);
        setup();
}

