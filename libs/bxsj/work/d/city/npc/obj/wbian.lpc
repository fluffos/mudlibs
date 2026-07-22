// wbian.c

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("黑龙鞭", ({ "bian", "wulongbian","whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑油油的软鞭。\n");
                set("value", 50);
                set("material", "leather");
                set("wield_msg", "$N「唰」的一声从腰后抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n别回腰后。\n");
        }
        init_whip(5);
        setup();
}
