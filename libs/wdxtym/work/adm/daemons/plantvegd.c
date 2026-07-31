inherit F_DBASE;
inherit F_SAVE;

mapping caidis;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(caidis) )
		caidis= ([]);
}

string query_save_file() { return DATA_DIR + "plantvegd"; }

int add_vegetable(object who, string seed, int num)
{
	string player_id = who->query("id");
	
	if(caidis[player_id][num] != "none")
		return 0;
	else
	{
		caidis[player_id][num] = seed->query("seed_info") + (["time" : seed->query("time_need") + time()]);
		save();
		return 1;
	}
}

mapping query_vegetable(object who, int num)
{
	object player_id = who->query("id");
	
	return caidis[player_id][num];
}

int delete_vegetable(object who, int num)
{
	string player_id = who->query("id");
	
	caidis[player_id][num] = "none";
	save();
	return 1;
}

int create_player_caidi(object who)
{
	string player_id = who->query("id");
	
	if(caidis[player_id])
	{
		return 0;
	}
	caidis += ([player_id : ([0 : "none"])]);
	save();
	return 1;
}

int query_kaitong(object who)
{
	string player_id = who->query("id");
	if(caidis[player_id])
	{
		return 0;
	}
	return 1;
}

int add_player_caidi(object who)
{
	string player_id = who->query("id");
	int caidi_count;
	
	
	if(!caidis[player_id])
	{
		return 0;
	}
	
	caidi_count = sizeof(caidis[player_id]);
	caidis[player_id] += ([caidi_count : "none"]);
	save();
	return 1;
}

mapping query_player_caidi(object who)
{
	string player_id;
	mapping caidi;
	
	player_id = who->query("id");
	caidi = caidis[player_id];
	
	if(sizeof(caidi) && mapp(caidi))
		return caidi;
	else
		return 0;
}

int query_caidi_count(object who)
{
	string player_id = who->query("id");
	
	return sizeof(caidis[player_id]);
}