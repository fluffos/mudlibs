
int level, time_on;

int get_level(string name)
{

    seteuid("Root");
    if (!"/secure/login"->test_user(name))
	return 0;
    level = 0;
    restore_object("/players/"+name[0..0]+"/"+name,1);
    return level;

}

int get_time_on(string name)
{

    seteuid("Root");
    if (!"/secure/login"->test_user(name))
	return 0;
    time_on = 0;
    restore_object("/players/"+name[0..0]+"/"+name,1);
    return (-time_on);

}

