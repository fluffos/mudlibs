// snoop.c
// by Find.

nomask varargs object snoop(object snooper,object snoopee)
{
	if( !previous_object() || (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(objectp(snooper) && objectp(snoopee))
	{
		if( (wiz_level(snooper) < wiz_level(snoopee))
		&& (wizhood(snooper) != "(admin)") )
			return 0;
	}

	if(!objectp(snoopee))
		return efun::snoop(snooper);
	else
		return efun::snoop(snooper,snoopee);
}
