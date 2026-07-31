// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("[33m±¦±¦[33m[2;37;0m", ({"mycmds_ofen"}));	
	set("gender", "ÐÛÐÔ");		
	set("unit", "Ö»");
	set("long", "$YEL$±¦±¦$YEL$[2;37;0m
ËüÊÇÎ¢Ð¦µÄÄ§»ÃÊÞ¡£
");
	set("owner", "weixiao_1");
	set("owner_name", "Î¢Ð¦");
	set_temp("owner", "weixiao_1");
	set_temp("owner_name", "Î¢Ð¦");
	last_age_set = 0;
	::setup();
}


