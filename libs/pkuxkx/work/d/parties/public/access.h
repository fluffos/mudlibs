int deny_access(object me)
{
    string *denied_visitors=query("denied");
    if (sizeof(denied_visitors)<1)
    return 0;
    if (member_array(me->query("id"),denied_visitors)!=-1)
    return 1;
	return 0;
}

int owner_access(object me)
{
	if (SECURITY_D->get_wiz_level(me) >= 6)
	return 2;
    if (me->query("id")==query("owner"))
    return 1;
	return 0;
}

int valid_access(object me)
{
    if (member_array(me->query("id"),GUIDER_D->app_list(query("owner")))!=-1)
    return 1;
	return 0;
}

int old_student(object me)
{
    if (member_array(me->query("id"),GUIDER_D->oldapp_list(query("owner")))!=-1)
    return 1;
	return 0;
}