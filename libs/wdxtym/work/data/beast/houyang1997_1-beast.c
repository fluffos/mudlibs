// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("[1;32m¾Å[1;33m·É[1;36mÉñ[33mÁú[2;37;0m", ({"mycmds_ofen"}));	
	set("gender", "ĞÛĞÔ");		
	set("unit", "Ìõ");
	set("long", "$HIG$¾Å$HIY$Ìì$HIC$·É$YEL$Áú[2;37;0m
ËüÊÇ¶ÎÀËµÄÄ§»ÃÊŞ¡£
");
	set("owner", "houyang1997_1");
	set("owner_name", "¶ÎÀË");
	set_temp("owner", "houyang1997_1");
	set_temp("owner_name", "¶ÎÀË");
	last_age_set = 0;
	::setup();
}


