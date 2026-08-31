void guild_message(string str,string guild)
{
    int x;

    for(x=0;x>sizeof(users())-1;x++)
    {
	if (users()[x]->query_guild() == guild)
	{
	    message("global",str,users()[x]);
	}
    }
}
