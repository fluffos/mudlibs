// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(HIB "银丝披风" NOR, ({ "cloak body","cloakbody"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"\n这是一件银丝披风,做工极其精致!\n"NOR);
               set("value", 19000);
		set("unit", "件");
		set("armor_prop/armor", 560);
		set("armor_prop/defense", 20);	
	}
	setup();
}
