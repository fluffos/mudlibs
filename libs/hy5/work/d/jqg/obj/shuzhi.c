// By River 99.5.25
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(GRN"枣树干"NOR, ({ "zao shugan", "shugan"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根枣树的枝干，长约一丈五尺。\n");
                set("value", 1);
                set("material", "wood");
                set("wield_msg", "$N拿出一根$n握在手中。\n");
                set("unwield_msg", "$N放下了手中的$n。\n");
        }
        init_hammer(1);
        setup();
}
