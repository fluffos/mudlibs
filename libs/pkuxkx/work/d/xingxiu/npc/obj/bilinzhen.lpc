// weapon: bilinzhen.c 碧磷针

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIG"碧磷针"NOR, ({ "bilin zhen", "zhen", "needle" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("base_unit", "根");
                set("long", HIG"这是一根星宿独门暗器－碧磷针，上面微微罩着一层幽绿的磷光。\n"NOR);
                set("value", 100);
                set("base_weight", 5);
                set("material", "steel");
                set("wield_msg", "$N从腰间锦囊中轻轻拈起一根$n，捏在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间锦囊。\n");
        }
        set_amount(1);
        init_throwing(20);
        setup();
}

