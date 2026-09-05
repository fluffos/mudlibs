int remove_mysql(string what, string where, string condition)
{

    if(this_player()->query_level() < 1000) return 0;

    if(!what || !where || !condition) return 0;

    db_get_rs("delete from " + where + " WHERE " + condition + " = '" + what + "'");
    return 1;
}

cmd_remove_player(string str)
{
    object them;
    int userid;

    if(this_player()->query_level() < 1000) return 0;
    if(!str)
    {
        write("Whom would you like to remove?\n");
        return 1;
    }

    str = lower_case(str);
    them = find_player(str);

    if(them && str == them->query_real_name())
    {
        write("Destructing player.\n");
        tell_object(them,"You are being removed.\n");
        destruct(them);
    }

    userid = (int)"/object/mysql/player"->get_player_info(str,"id");

    if(!userid)
    {
      write("No such player to remove.\n");
      return 1;
    }

    write("Removing the following items for player " + capitalize(str) + ":\n");
    write("  .o file");
    rm("/pfiles/" + extract(str,0,0) + "/" + str + ".o");
    write(", MySQL player info");
    remove_mysql(str,"players","name");
    write(", Mail");
    remove_mysql(str,"mail","msg_to");
    write(", Board records");
    remove_mysql(str,"board_records","name");
    write("\n");
    return 1;
}
