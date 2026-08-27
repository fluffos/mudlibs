// jitui.c 雞腿

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("烤雞腿", ({ "jitui", "tui" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枝烤得香噴噴的雞腿。\n");
                set("unit", "根");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
                set("wield_msg", "$N抓起一根$n，握在手中當武器。\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}

int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("啃得精光的雞腿骨頭", ({ "bone" }) );
        set_weight(150);
        set("long", "一根啃得精光的雞腿骨頭。\n");
        return 1;
}
