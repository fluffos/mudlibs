// bian.c 鞭

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("蛇鞭", ({ "bian", "whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条用蛇皮制成的长鞭，做工粗糙。\n");
                set("value", 30);
                set("material", "fur");
                set("wield_msg", "$N「唰」的一声从腰后抽出一条$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n别回腰后。\n");
		set("no_return",1);
        }
        init_whip(30);
        setup();
}

