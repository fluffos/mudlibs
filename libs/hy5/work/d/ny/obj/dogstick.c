
// dogstick.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIC "打狗棒" NOR,({"dog stick" , "stick"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
		{
		set("unit","根");
		set("value",100000);
		set("material","jade");
		set("long","这是一根不同寻常的绿玉短棍,轻巧结实.\n");
		set("wield_msg","$N拿出一根$n握在手中.\n");
	set("uneqip_msg","$N将$n别回腰间.\n");
		}
	init_staff(50);
	setup();
}
