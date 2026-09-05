#include <ansi.h>.c
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( HIB "冰魄杖" NOR, ({ "bingpo zhang","zhang","staff" }) );
    	set_weight(6000);
 	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",
"这是星宿派的镇派之宝，
相传是丁春秋走遍天山，采集万年寒璧做成，
它通体几乎透明，发出淡淡的青光，寒气逼人。\n"
);
                set("value", 10000);
                set("material", "steel");
                set("rigidity", 150);
                set("wield_msg", WHT "$N"WHT"从腰间拔出一根寒气逼人的$n"WHT"握在手中。\n"
NOR);
                set("unequip_msg", WHT "$N"WHT"将手中的$n"WHT"插入腰间。\n" NOR);
}
     		init_staff(120);
        	setup();
}
