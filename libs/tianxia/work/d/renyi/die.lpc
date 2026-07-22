
int user_cant_die(object who)
{
	if(objectp(who) && !mapp(who->query("enyi_class")) )
	{
		who->remove_mask_name();
		who->remove_mask_id();
	}

	return 0;
}
