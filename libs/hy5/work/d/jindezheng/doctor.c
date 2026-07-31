inherit NPC;
inherit F_SAVE;

string query_save_file() { return DATA_DIR + "npc/"+query_temp("name"); }
void create()
{
	if(! restore())	{
		set_name("°ë³ÉÆ·",({"machine"}));
	}
	setup();
}


