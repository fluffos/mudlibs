inherit "/cmds/guider/guidercmd";

int get_cost(object me) {return 1;}


int exec_cmd(object me, string str)
{
	object ob, where, *ob_list;
	int i;

	if (!str)
	{
		tell_object(me,"指令格式：whereapp <学员的ID>\n");
		return 0;
	}
	ob = find_player(str);	
	
	if (!ob) 
	{
		tell_object(me,"现在没这个人。\n");
		return 0;
	}
    if(check_apprentice(me,ob)!=1) 
	{
		tell_object(me,"他/她不是你当前的学生。\n");
		return 0;
	}
    
	where = environment(ob);
	if (!where) 
	{
		tell_object(me,"这个人不知道在那里耶...\n");
		return 0;
	}
	printf("%s(%s)现在在%s的%s.\n",
		(string)ob->name(),
		(string)ob->query("id"),
        TASK_D->place_belong(where),
		(string)where->query("short"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: whereapp <学员的ID>

这个指令是用来得知你的学生目前所在的位置.

HELP
	);
	return 1;
}

