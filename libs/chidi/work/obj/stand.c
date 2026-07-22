inherit ITEM;
inherit F_SKILL;
inherit F_SAVE;

string query_save_file() { return "/data/npc/"+query("name"); }
void create(string data)
{
	if( data)	set("name",data);
	if(! restore())	{
		set_name("°ë³ÉÆ·",({"machine"}));
	}
	setup();
}


