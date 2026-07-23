#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIW"钢杵"NOR,({"gang chu","chu"}));
        set_weight(100000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit","根");
                set("value",100);
                set("material","black_steel");
                set("long",HIW"这是一根精钢所铸的降魔杵，千锤百炼，反射出闪闪的寒光。\n"NOR);
               set("unwield_msg","$N一声长啸，将钢杵放回背后。\n");
        }
        init_staff(20);
}
