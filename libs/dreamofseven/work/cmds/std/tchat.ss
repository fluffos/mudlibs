// tchat.c		Shengsan@DS	1999.04.14

int main(object me, string arg)
{
	int i;
	string *t = ( { "pchat","nchat","fchat" } );

	if( arg==(string)me->query_temp("last_channel_msg") )
		return notify_fail("用交談頻道說話請不要重複相同的訊息。\n");

	i = NATURE_D->which_world(environment(me));

	if( !i || i==0 )
		return notify_fail("你現在的時空並不屬於任何時代，所以無法使用tchat指令。\n");
	CHANNEL_D->do_channel(me,t[i-1],arg);
	return 1;

		
}

int help (object me)
{
	write(@HELP
指令格式: tchat <訊息>
 
時代頻道, 把訊息傳給與你同一時代的所有人.

HELP
	);
	return 1;
}