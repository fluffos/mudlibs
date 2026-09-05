// channel block command..
// Modified by Marz, 04/18/96
// changed for new channel by akuma on 1999/8/20

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
	if (!arg)
		return notify_fail("<Syntax>: unblock <player id> <channel name>\n");
		
	if (sscanf(arg, "%s %s", who, ch_name) != 2) 
    {
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1) 
        {
			return	notify_fail("<Syntax>: unblock <player id> <channel name>\n");
		}		
	}

    if (who == "rumor") 
    {
		CHANNEL_D->set_block(who, 0);
 		CHANNEL_D->do_channel(me, "sys", "谣言频道打开了！\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)谣言频道给打开了。\n", 
            me->name(), me->query( "id" ), who->name(), who->query( "id" ) ) );
        return 1;
    }
	
    if (who == "chat") 
    {
		CHANNEL_D->set_block(who, 0);
		CHANNEL_D->do_channel(me, "sys", "聊天频道ｏｋａｙ！\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)聊天频道给打开了。\n",
            me->name(), me->query( "id" ), who->name(), who->query( "id" ) ) );
        return 1;
    }

    if (who == "new") 
    {
		CHANNEL_D->set_block(who, 0);
 		CHANNEL_D->do_channel(me, "sys", "新手频道打开了！\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)新手频道给打开了。\n", 
            me->name(), me->query( "id" ), who->name(), who->query( "id" ) ) );
        return 1;
    }
	
	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("这个人不在！\n");
	
	if (ch_name == ""||ch_name == " "||ch_name == "all")
	{		
		if ((int)ob->query("chblk_rumor"))
			ob->delete("chblk_rumor");
		if ((int)ob->query("chblk_chat"))
			ob->delete("chblk_chat");
        if ((int)ob->query("chblk_new"))
			ob->delete("chblk_new");
		tell_object(me, (string)ob->query("name")+"的所有频道被打开了。\n");
        log_file( "acct/block", sprintf( "%s(%s)把%s(%s)所有频道给打开了。\n",
            me->name(), me->query( "id" ), ob->name(), ob->query( "id" ) ) ); 
	} 
	else if (ch_name == "rumor") 
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
		return notify_fail("<Syntax>: unblock <player id> <channel name>\n");
	}		
	
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : unblock <某人> <频道名>

此命令将打开某人的频道。如果没有频道名就打开所有合法频道。
<某人>　也可以是频道名。
<频道名> 可以是rumor 或 chat 或 new

HELP
    );
    return 1;
}
