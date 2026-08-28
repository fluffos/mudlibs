
main (string str)
{
    object ob;
    string text;

    if (str)
    {
	ob = find_living (str);
	if (!ob)
	{
	    write ("No such living thing.\n");
	    return 1;
	}
    }
    else
	ob = this_player();

    text = sprintf("^cW^bb%-78s^c0\n",
      "MOVEMENT MESSAGE INFORMATION");

    text += sprintf ("msgin   : ^c1%s^c0\n", ob->query_msgin ());
    text += sprintf ("msgout  : ^c1%s^c0\n", ob->query_msgout ());
    text += sprintf ("mmsgin  : ^c1%s^c0\n", ob->query_mmsgin ());
    text += sprintf ("mmsgout : ^c1%s^c0\n", ob->query_mmsgout ());
    text += sprintf ("^bb%-78s^c0\n", "");
    message("standard", text, this_player());
    return 1;
}

