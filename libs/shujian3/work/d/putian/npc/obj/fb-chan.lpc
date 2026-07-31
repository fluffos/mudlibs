// /d/putian/npc/obj/fb-chan.c
// Lklv 2001.9.12

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("方便铲", ({ "fangbian chan", "zhang", "chan" }));
        set_weight(5500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑黝黝的方便铲，约三十斤，是僧人们常用的兵器。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N拿出一根黑黝黝$n握在手中。\n");
                set("unwield_msg", "$N手臂一转，将手中的$n收了起来。\n");
                set("shaolin",1);
        }
        init_staff(35);
        setup();
}
