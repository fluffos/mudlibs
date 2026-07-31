// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("[33mĞÇÒ¹[2;37;0m[2;37;0m", ({"mycmds_ofen"}));	
	set("gender", "´ÆĞÔ");		
	set("unit", "Ìõ");
	set("long", " $YEL$ĞÇÒ¹$NOR$[2;37;0m
ËüÊÇÅ·Ñô³ËĞÇµÄÄ§»ÃÊŞ¡£
");
	set("owner", "y999_1");
	set("owner_name", "Å·Ñô³ËĞÇ");
	set_temp("owner", "y999_1");
	set_temp("owner_name", "Å·Ñô³ËĞÇ");
	last_age_set = 0;
	::setup();
}


