// bian.c

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("追魂鞭", ({ "zhuihun bian", "bian","whip" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根五金混合牛筋编成的的软鞭。\n");
                set("value", 900);
                set("material", "leather");
                set("wield_msg", "$N「唰」的一声从腰中抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n盘在腰上。\n");
        }
        init_whip(25);
        setup();
}
