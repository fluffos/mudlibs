#define LOGFILE "/TOFIX"

main (string str)
{
    object ob;
    string tmp;

    if (!str || str == "")
    {
	tail (LOGFILE);
	return 1;
    }
    ob = find_object(TIME_D);

    tmp = sprintf("[%s] %s -> %s\n",
      ctime(time()), capitalize(THIS->query_name()), str);

    write_file (LOGFILE, tmp);
    write (tmp);
    write ("Done, line added to " + LOGFILE + ".\n");
    return 1;
}

