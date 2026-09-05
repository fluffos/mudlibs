
inherit "/cmds/guider/guidercmd";

int get_cost(object me) {return 10;}

int exec_cmd(object me, string arg)
{
	object ob;
	string who, ch_name;
	
	if (!arg)
	{
		tell_object(me,"<命令格式>: unblock <某人> <频道>\n");
		return 0;
	}
		
	if (sscanf(arg, "%s %s", who, ch_name) != 2) 
    {
		tell_object(me,"<命令格式>: unblock <某人> <频道>\n");
		return 0;
	}
	
	ob = LOGIN_D->find_body(who);
	if (!ob) 
	{
		tell_object(me,"这个人不在！\n");
		return 0;
	}

    if(!check_apprentice(me,ob)) 
	{
		tell_object(me,"他/她不是你的学生。\n");
		return 0;
	}

    ob->delete("chblk_on");
    
	if (ch_name == "rumor") 
    {
		if ((int)ob->query("chblk_rumor"))
			ob->delete("chblk_rumor");
        tell_object(me, (string)ob->query("name")+"的谣言频道被打开了。\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)谣言频道给打开了。\n",
            me->name(), me->query( "id" ), ob->name(), ob->query( "id" ) ) );
	} 
	else if (ch_name == "chat") 
    {
		if ((int)ob->query("chblk_chat"))
			ob->delete("chblk_chat");
		tell_object(me, (string)ob->query("name")+"的聊天频道被打开了。\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)聊天频道给打开了。\n",
            me->name(), me->query( "id" ), ob->name(), ob->query( "id" ) ) );
	} 
    else if (ch_name == "new") 
    {
		if ((int)ob->query("chblk_new"))
			ob->delete("chblk_new");
		tell_object(me, (string)ob->query("name")+"的新手频道被打开了。\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)新手频道给打开了。\n",
            me->name(), me->query( "id" ), ob->name(), ob->query( "id" ) ) );
	} 
	else 
    {
		tell_object(me,"<命令格式>: unblock <某人> <频道>\n");
		return 0;
	}		
	
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : unblockapp <某人> <频道名>

此命令将打开某人的频道。
<频道名> 可以是rumor 或 chat 或 new

HELP
    );
    return 1;
}
