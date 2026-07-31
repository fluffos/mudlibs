//shanyu-jin 珊瑚金
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("珊瑚金", ({ "shanhu jin", "shanhu","jin" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根珊瑚做成的拐杖，是灵蛇岛旁海底的特产，由数种金属\n"
"混和，在海底中厉千万年而成珊瑚，削铁如切豆腐，打石如敲棉\n"
"花，不论多锋利的利刃，遇之立折。\n"
);
                set("value", 1000000);
                set("treasure", 1);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(100);
        setup();
}
