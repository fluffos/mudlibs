// pofeng-dao
// Last Modified by kiden on 2006.10.25
// Modified by iszt@pkuxkx, 2007-03-06, too high damage(190) for a blade stored by many players

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIR"破风刀"NOR, ({"pofeng dao","dao","blade" }) );
   set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",HIR"一把赤金锻成的神兵，通体红若焰，锋芒非常，传说持刀善用者能破千军于须臾间。\n"NOR);
                set("unit", "把");
                set("value", 1000);
                set("material","wood");
                set("wield_msg",HIG"只见"+HIG"红光"+HIG"一现，$n"+HIG"破空而出，刹那间$N斗志大盛，战意腾腾，四周的空气仿佛已经凝结。\n"NOR);
                set("unwield_msg",HIG"$N手腕一收，$n"+HIG"已然入鞘，你心头一松，吐出胸口闷气，瘫坐地上。\n"NOR);
        }
        init_blade(165);
        setup();
}


