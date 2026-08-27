string query_ext_destination(string dir,object who)
{
    string *path;
    int i,j;
    path  = environment(who)->query_dest_dir();
    for(i=0; i<sizeof(path); i++)
    {
	if(path[i]==dir)
	{
	    return(path[i+1]);
	}
    }
    tell_object(who,"\nNo existe esa direccion!\n\n");
}
int scout(string str,object who)
{
    int j;
    string look, path;
    string *dirs;
    object env;
    if(!who) who = this_player();
    if(who->query_gp() < 2) 
    {
	tell_object(who,"Estas demasiado cansado.\n");
	return 1;
    }
    who->adjust_gp(-2);
    if(!str) {  tell_object(who,"\nSintaxis 'explorar <direccion>'\n"); return(1); }
    env = environment(who);
    if(!env) return 0;
    if(env->query_exit(str))
    {
	path = query_ext_destination(str,who);
	look = (string)path->long();
	if(who == this_player())
	{
	    tell_object(who,sprintf("%-*=s",this_player()->query_cols(),look)+"\n");
	}
	else tell_object(who,look+"\n");
	return(1);
    }
    if(who->query_gp() < 8)
    {
	tell_object(who,"Estas demasiado exhausto.\n");
	return 1;
    }

    who->adjust_gp(-8);
    tell_object(who,"\nDirection ilegal.\nPrueba una de estas jovencillo:\n");
    dirs = environment(who)->query_direc();
    for(j=0; j<sizeof(dirs); j++)
	tell_object(who,dirs[j]+"\n");
    return(1);
}

help()
{
    return "Explorar allows you to scout the land ahead.\n"
    "Explorar <direccion> to use the command.\n"
    "Note that the FULL direction must be used.\n"
    "i.e. \"explorar sur\" would work, \"explorar s\" wouldn't.\n"
   "Cost: 2gp for sucess. 10gp for being silly.\n"
    "\n";
}
