int time_on;

int find_age(string name)
{int AGE;
    object WHO;
    if((WHO = find_player(name)))
	WHO->save_me();
    seteuid("Root");
    if(!"/secure/login"->test_user(name))
    {write("No such person exists on FR Mud.\n");
	return 0;
    }
    restore_object("/players/"+name[0..0]+"/"+name, 1);
    AGE = -time_on;
    return AGE;
}
