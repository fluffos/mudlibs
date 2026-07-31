// shengzi.c 

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("绳子", ({ "sheng zi", "sheng" }));
        set_weight(400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "捆");
                set("long", "这是一捆长长的麻绳，最适合于攀爬之用。\n");
                set("value", 40);
                set("material", "leather");
                set("wield_msg", "$N「唰」的一声从腰后抽出一捆$n向外一扬握在手中。\n");
                set("unwield_msg", "$N将手中的$n盘好别回腰后。\n");
        }
        init_whip(5);
        setup();
}
