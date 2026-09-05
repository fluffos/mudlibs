
inherit "/cmds/guider/guidercmd";

int get_cost(object me) {return 5;}

int exec_cmd(object me, string str)
{
	object ob;
	int i;
	if (!str) 
	{
		tell_object(me,"<Syntax>: Summon <player id>\n");
		return 0;
	}
	ob = LOGIN_D->find_body(str);
	if (!ob) 
	{
		tell_object(me,"咦... 有这个人吗？\n");
		return 0;
	}

    if(check_apprentice(me,ob)!=1) 
	{
		tell_object(me,"他/她不是你当前的学生。\n");
		return 0;
	}

	// moving
	tell_room(environment(ob),"一朵白云飘来，"+
		(string)ob->query("name")+"不由自主的向上飞去，不见了踪影。\n", ob);
	tell_object(ob,"你感觉一股神秘的力量将你带到了一朵白云上……\n");
	ob->move(environment(me));
    tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前。\n");
	tell_object(ob,"转眼你发现自己身在"+(string)me->query("name")+"面前。\n");
	tell_room(environment(ob),(string)ob->query("name")+"从白云中飘落在你面前。\n",({me,ob}));

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : summonapp <某人>

此指令可让你(你)将某人抓到你面前。
HELP
    );
    return 1;
}