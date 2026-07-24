
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("齊眉棍", ({ "qimei gun", "gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "這是一根樺木白臘棍，舉可齊眉，輕重合宜，可攻擊大片敵人。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回腰間。\n");
		set("shaolin",1);
        }
        init_club(15);
        setup();
}

