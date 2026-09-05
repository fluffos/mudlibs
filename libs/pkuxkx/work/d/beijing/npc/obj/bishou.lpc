// bishou.c 匕首

#include <weapon.h>

#include <ansi.h>

inherit DAGGER;

void create()

{

        set_name(HIR "匕首" NOR, ({ "bi shou", "bi" }));

        set_weight(3000);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "柄");

                set("long", "细看那匕首，剑身如墨，无半点光泽。连柄不过一尺二寸，套在鲨鱼皮的套子之中。\n");

                set("value", 50000);

                set("material", "steel");

                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中，只觉一股寒气扑面而来。\n");

                set("unwield_msg", "$N将手中的$n插回剑鞘，只听嗤的一声轻响。\n");

        }

        init_dagger(140);
        setup();

}



