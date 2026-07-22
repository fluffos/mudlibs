inherit ITEM;
inherit F_SAVE;

void create(string area)
{
	if( area)	set("area",area);
	if(! restore())	{
		set_name("无效地盘",({"area"}));
		set("no_use",1);
	}
	else	{
		set_name(area+"地盘",({"area"}));
		set("no_use",0);
	}
	set("unit","块");
        seteuid(getuid());
}

string query_save_file() { return DATA_DIR + "area/"+query("area"); }


