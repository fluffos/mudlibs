// wushi_dao.c
//cgbii 96.10.3
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("武士刀", ({ "dao" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄东瀛制造的刀，刀长约一尺八，普通东瀛武士常用的武器。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(30);
        setup();
}
