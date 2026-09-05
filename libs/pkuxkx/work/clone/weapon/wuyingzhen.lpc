// weapon: wuyingzhen.c 无影针

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name("无影针", ({ "wuying zhen", "zhen", "needle" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("unit", "把");
                 set("base_unit", "根");
                set("long", HIG"这是一只暗器。\n"NOR);
                set("value", 100);
                set("base_weight", 5);
                set("material", "steel");
                set("wield_msg", "$N从腰间锦囊中轻轻拈起一根$n，捏在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间锦囊。\n");
        }
        set_amount(1); //不要改，否则暗器门会出错
        init_throwing(20);
        setup();
}

