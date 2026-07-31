// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("金收[2;37;0m", ({"xxc"}));	
	set("gender", "雌性");		
	set("unit", "条");
	set("long", "sdd[2;37;0m
它是除夕的魔幻兽。
");
	set("owner", "balei_1");
	set("owner_name", "除夕");
	set_temp("owner", "balei_1");
	set_temp("owner_name", "除夕");
	last_age_set = 0;
	::setup();
}


