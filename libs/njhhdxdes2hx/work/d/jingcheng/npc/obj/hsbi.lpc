// hsbi.c 

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB"和氏璧"NOR, ({ "heshi bi", "bi" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", HIR"战国时秦赵会于渑池，双方逞口舌之利，摆兵势之威\n
几乎大战一场，争的就是这块璧玉。\n"NOR);
		set("value", 500000);
		set("material", "greysteal");
		set("no_get",0);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

