#include <armor.h>

inherit CLOTH;
#include <math.h>
void create()
{
		set_name("铁甲", ({ "armor" }) );
		set_weight(20000);
		if( clonep() )
		set_default_object(__FILE__);
        else {
				set("unit", "件");
				set("material", "steel");
				set("value", 5000);
				set("armor_prop/armor", 200);
        }
        setup();
}

int npc_only()
{
	return 1;
}
int price(object me)
{
	int value=query("value"),time,*times=({});
	string *anti=({});
	if (arrayp(query("anti_job")))
	anti=query("anti_job");
	if (anti==({}))
	return value;
	for (int i=0;i<sizeof(anti);i++)
	times+=({me->query(anti[i])});
	time=max(times);
	if (time<=1000)
	value=value;
	else if (time<=1800)
	value*=2;
	else if (time<=2600)
	value*=3;
	else if (time<=6000)
	value*=(time/800);
	else
	value*=(time/500);
	return value;
}