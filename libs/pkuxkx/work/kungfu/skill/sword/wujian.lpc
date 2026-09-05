// wujian.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(WHT"无形剑气"NOR,({ "jian qi", "jian", "sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "团");
		set("value", 100);
		set("material", "air");
		set("long", "这是一团虚无的剑气。\n");
		set("wield_msg", WHT"$N凝聚$n，握在手中。\n"NOR);
		set("unequip_msg", "$N散去手中的$n。\n");
	}
	init_sword(280+random(41));
	setup();
    call_out("dest",20);
}

int dest()
{
    object ob=this_object();
    if (ob)
    {
        destrcut(ob);
    }
    return 1;
}
