// mazemap.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if(me->is_busy())
		return notify_fail("你现在正忙。\n");
        if(! wizardp(me) && (time() - me->query_temp("maze/map") < 15))
		return notify_fail("系统气喘嘘地叹道：慢慢来 ....\n");  
        if(! environment(me)->query("maze"))
		return notify_fail("这里不是迷宫区域，请用 help here 查看。\n");  
	arg = MAZE_D->query_maze_mainobj(me)->display_common_map(environment(me));
	me->start_more(arg);	
	return 1;
}



