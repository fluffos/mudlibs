// wiz.c

string wizhood(mixed ob)
{
	return SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{   
     string euid;

     if (objectp(ob))
        {
		euid = geteuid(ob);
		if (! euid) euid = getuid(ob);
	 }
	else if (stringp(ob)) euid = ob;

      
       
	return SECURITY_D->get_wiz_level(ob);
}
