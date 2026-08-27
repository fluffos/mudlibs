// wiz.c

string wizhood(mixed ob)
{
	return SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{
	return SECURITY_D->get_wiz_level(ob);
}
/* move to override.c
varargs object snoop( object snooper, object snoopee )
{
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	if( snoopee )
	{
		if(wiz_level(snooper) < wiz_level(snoopee)) return 0;
		return efun::snoop( snooper,snoopee );
	}
	else return efun::snoop( snooper );
}
*/

int adminp(mixed ob)
{
	return (SECURITY_D->get_wiz_level(ob)==SECURITY_D->query_admin_level());
}
