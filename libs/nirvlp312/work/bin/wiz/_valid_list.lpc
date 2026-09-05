cmd_valid_list(string str)
{
    string action, value, *rs;
    mixed *all;
    int x;

if(this_player()->query_level() < 1000) return 0;
    if(!str)
    {
        all = db_get_rs("select path from valid_list order by path");
        write("Valid MySQL callers\n");
        for(x = 0; x < sizeof(all); x++)
        {
            rs = all[x];
            write(" " + rs[0]+"\n");
        }
        return 1;
    }

    if(sscanf(str,"%s %s",action,value) != 2)
    {
        write("Syntax: valid_list [action value]\n");
        return 1;
    }

    if(action != "add" && action != "remove")
    {
        write("Valid actions are 'add' or 'remove'.\n");
        return 1;
    }

    if(action == "add")
    {
        all = db_get_rs("select path from valid_list where path='" + value + "'");

        if(sizeof(all))
        {
            write("Record already exists.\n");
            return 1;
        }

        db_get_rs("insert into valid_list (path) VALUES('" + value + "')");
        all = db_get_rs("select path from valid_list where path='" + value + "'");
        if(!sizeof(all)) write("Failed.\n");
        if(sizeof(all)) write("Success.\n");
        return 1;
    }

    all = db_get_rs("select path from valid_list where path='" + value + "'");
    if(!sizeof(all))
    {
        write("No such record to remove.\n");
        return 1;
    }
    db_get_rs("delete from valid_list where path='" + value + "'");
    all = db_get_rs("select path from valid_list where path='" + value + "'");
    if(!sizeof(all)) write("Success.\n");
    if(sizeof(all)) write("Failed.\n");

    return 1;

}
