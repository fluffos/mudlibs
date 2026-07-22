inherit ITEM;
inherit F_SAVE;

void create(string id)
{
	if(id)		set("par",id);
	if(! restore())	{
		set_name("Ê§°ÜÆ·",({"id"}));
		set("no_use",1);
	}
	else	{
		set_name(query("name"),({query("id")}));
		set("no_use",0);
	}
	set("unit","¿é");
        seteuid(getuid());
}

string query_save_file()
{
	string id;

	id=(string)query("par");
	if(! stringp(id))	return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}


