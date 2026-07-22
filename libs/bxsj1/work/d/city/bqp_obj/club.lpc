
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("戒棍", ({ "jie gun", "gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long","这是一根坚实的");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("shaolin",1);
        }
        init_club(15);
        setup();
}

