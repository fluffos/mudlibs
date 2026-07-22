// cracked by vikee 2/09/2002   vikee@263.net
// wlist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who;
	string *list,name,id;

	write(MUD_NAME + "目前的巫师(含客座巫师及荣誉玩家)
─────────────────────────────────────\n");
	list = sort_array(SECURITY_D->query_wizlist(), 1);
	for(int i=0; i<sizeof(list); i++)
	{
		id = list[i];
		who = find_player(id);
		if( !who )
		{
			who = FINGER_D->acquire_login_ob(id);
			if( !who )
				name = id+"<离线>";
			else
			{
				name = sprintf("%s(%s)<离线>",who->query("name"),who->query("id"));
				if( who )
					destruct(who);
			}
		}
		else
		{
			if( who->query("env/invisibility") && !wizardp(me) )
				name = sprintf("%s(%s)<离线>",who->query("name"),who->query("id"));
			else	name = sprintf("%s(%s)<在线>",who->query("name"),who->query("id"));	
		}	
		printf("%-15s%c", name,  (i%3==2) ? '\n' : ' ');
	}
	write("\n");
	write("─────────────────────────────────────\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wlist

用途 : 列出目前所有的巫师名单(含客座巫师)。
HELP
     );
     return 1;
}
