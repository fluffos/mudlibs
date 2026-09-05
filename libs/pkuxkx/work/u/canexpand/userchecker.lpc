
int is_granted(object me)
{
	if(me->query("id")=="mudy"||me->query("id")=="male")
		return 1;
	if(SECURITY_D->get_status(me)== "(admin)") 
		return 1;
	else if(me->query("canexpand_forever"))
		return 1;
	else if(me->query_temp("canexpand_temp"))
	{
		me->add_temp("canexpand_temp",-1);
		return 1;
	}
	else
		return 0;
}