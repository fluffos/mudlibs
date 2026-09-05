// whip
// created by zine

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("牧羊鞭", ({ "muyang bian","bian"}));
    set_weight(1300);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("unit", "根");
			set("long", "这是郭靖放羊的鞭子。\n");
			set("value", 1);
			set("material", "steel");
			init_whip(1);
		}
	setup();
}
