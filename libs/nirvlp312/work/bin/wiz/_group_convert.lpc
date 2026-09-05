int level, ex_lv;
string name, password;

#define TOP_DIR "/pfiles/"
cmd_group_convert(string str)
{
    string tmp, *all_people;
    int x, player_db_id;

    if(this_player()->query_level() < 1000) return 0;
    if(!str || strlen(str) > 1)
    {
       write("Please supply a single letter.\n");
       return 1;
    }
    str += "/";
    all_people = get_dir(TOP_DIR + str);

    for(x = 0; x < sizeof(all_people); x++)
    {
        tmp = extract(all_people[x],0,strlen(all_people[x])-3);
        restore_object(TOP_DIR + str + tmp);
        if(level)
        {
            write("Converting: " + name + "\n");
            player_db_id = (int)"/object/mysql/player"->get_player_info(name,"id");
            db_get_rs("delete from players where name='" + name + "'");
            db_get_rs("delete from passwd where fk_player_id=" + player_db_id);
            db_get_rs("insert into players (name,level,xlevel) values('" + name + "'," + level + "," + ex_lv + ")");
            player_db_id = (int)"/object/mysql/player"->get_player_info(name,"id");
            db_get_rs("insert into passwd (fk_player_id,passwd) values(" + player_db_id + ",'" + password + "')");
        }
    }

    return 1;
}
