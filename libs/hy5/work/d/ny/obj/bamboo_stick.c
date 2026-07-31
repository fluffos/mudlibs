
// bamboo_stick.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name("竹棒",({"bamboo stick" , "stick"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
		{
		set("unit","根");
		set("value",100);
		set("material","bamboo");
		set("long","这是一根寻常的竹棍,轻巧结实.\n");
		set("wield_msg","$N拿出一根$n握在手中.\n");
	set("uneqip_msg","$N将$n别回腰间.\n");
		}
	init_staff(5);
	setup();
}
