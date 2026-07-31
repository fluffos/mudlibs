inherit F_DBASE;
inherit F_SAVE;

mapping farmd;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(farmd) )
		farmd = ([]);
}

string query_save_file() { return DATA_DIR + "farmd"; }

int query_player_farmd(object who)    //玩家是否开通牧场功能
{
    string player_id = who->query("id");
    
    if (undefinedp(farmd[player_id]))
        return 0;
    else
        return 1;
}

int set_player_farmd(object who)    //开通牧场功能
{
    string player_id = who->query("id");
    
    if (undefinedp(farmd[player_id]))
    {
        farmd += ([player_id : (["animal_amount" : 0, "animal" : ([])])]);
        save();
        return 1;
    }
    
    return 0;
}

int get_animal_amount(object who)    //获得玩家可养殖数量
{
    string player_id = who->query("id");
    
    if (undefinedp(farmd[player_id]))
        return 0;
    else
        return farmd[player_id]["animal_amount"];
}

int add_animal_amount(object who)    //增加玩家养殖数量
{
    string player_id = who->query("id");
    
    farmd[player_id]["animal_amount"] = farmd[player_id]["animal_amount"] + 1;
    save();
    
    return 1;
}

mapping get_animal(object who)    //获得养殖情况
{
    string player_id = who->query("id");
    
    if (undefinedp(farmd[player_id]))
        return ([]);
    else
        return farmd[player_id]["animal"];
}

int add_animal(object who, string animal_name)    //增加农场中动物
{
    string player_id = who->query("id");
    int i;
    
    for(i = 0; i < farmd[player_id]["animal_amount"]; i++)
    {
        if (undefinedp(farmd[player_id]["animal"][i]))
        {
            farmd[player_id]["animal"] += ([i : (["name" : animal_name, "time" : time()])]);
                    
            save();
            
            return i + 1;
        }
    }
}

int delete_animal(object who, int i)
{
    string player_id = who->query("id");
    
    map_delete(farmd[player_id]["animal"], i);
    save();
    
    return 1;
}

int sort_farmd(object who)
{
    string player_id = who->query("id");
    mapping new_map = ([]);
    int temp;
    int i = 0;
    
    
    if (undefinedp(farmd[player_id]))
        return 1;
    
    if (!sizeof(farmd[player_id]["animal"]))
        return 1;
    
    foreach(temp in keys(farmd[player_id]["animal"]))
    {
        new_map += ([i : farmd[player_id]["animal"][temp]]);
        i++;
    }
    farmd[player_id]["animal"] = new_map;
    
    save();
    return 1;
}