// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("Ï«[2;37;0m", ({"mycmds_ofen"}));	
	set("gender", "´ÆĞÔ");		
	set("unit", "Ìõ");
	set("long", "$NOR$Ï«[2;37;0m
ËüÊÇÂåÖñµÄÄ§»ÃÊŞ¡£
");
	set("owner", "wswzly_1");
	set("owner_name", "ÂåÖñ");
	set_temp("owner", "wswzly_1");
	set_temp("owner_name", "ÂåÖñ");
	last_age_set = 0;
	::setup();
}


