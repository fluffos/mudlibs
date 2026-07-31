// golden_sword.c

#include <weapon.h>

  inherit WHIP;

void create()
{
	set_name("打魔鞭", ({ "king whip" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set ("material", "gold");
	}
	init_whip(60);
	setup();
}
