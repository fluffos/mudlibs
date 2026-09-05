
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	object* user_list;
	if(arg == "sleep") 
	{
		user_list= filter_array(users(),(:$1->query("disable_type") == "<睡梦中>":));
	}
	else
	{
		return notify_fail("目前只支持sleep参数\n");
	}
	
	printf("id        name            sleepat         sleeped plan    \n");
	for(i=0;i<sizeof(user_list);i++)
	{
		printf("%-10s%-16s%-16d%-8d%-8d\n",user_list[i]->query("id"),
			user_list[i]->query("name"),
			user_list[i]->query_temp("debug_sleep/start"),
			time() - user_list[i]->query_temp("debug_sleep/start"),
			user_list[i]->query_temp("debug_sleep/duration"));
	}
	return 1;
}

int help()
{
	write("查看所有线上玩家状态。支持参数: sleep \n");
	return 1;
}