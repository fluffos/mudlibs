// weapon: chuanxinding.c 穿心钉

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(RED"穿心钉"NOR, ({ "chuanxin ding", "ding", "nail" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "枚");
                set("long", HIR"这是一根星宿独门暗器－穿心钉，刃口上开启的血槽让人望而生畏。\n"NOR);
                set("value", 100);
                set("base_weight", 5);
                set("material", "steel");
                set("wield_msg", "$N从腰间锦囊中轻轻拈起一根$n，捏在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间锦囊。\n");
        }
        set_amount(1);
        init_throwing(50);
        setup();
}

