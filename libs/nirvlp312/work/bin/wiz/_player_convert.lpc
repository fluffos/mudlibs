int level, ex_lv;
string name, password;

#define TOP_DIR "/pfiles/"
cmd_player_convert(string str)
{

    string first_char, tmp, *all_people;
    int x, player_db_id;

    if(this_player()->query_level() < 1000) return 0;
    if(!str)
    {
	write("Please supply a name.\n");
	return 1;
    }
    first_char = extract(str,0,0) + "/";

    if(!restore_object(TOP_DIR + first_char + str))
    {
	write("No such player to convert.\n");
	return 1;
    }
    player_db_id = (int)"/object/mysql/player"->get_player_info(name,"id");
    db_get_rs("delete from players where name='" + name + "'");
    db_get_rs("delete from passwd where fk_player_id=" + player_db_id);
    db_get_rs("insert into players (name,level,xlevel) values('" + name + "'," + level + "," + ex_lv + ")");
    player_db_id = (int)"/object/mysql/player"->get_player_info(name,"id");
    db_get_rs("insert into passwd (fk_player_id,passwd) values(" + player_db_id + ",'" + password + "')");
    write("Complete.\n");
    return 1;
}
