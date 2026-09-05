// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;
    object ob;

    if(arg && objectp(ob=present(arg,environment(me))) && living(ob))
    {
    	cmds = ob->query_commands();        
        write(ob->name());
    }
    else
    {
    	cmds = me->query_commands();
        write("你");
    }
	write("身上及四周的物品与所在的环境提供以下指令：\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(@TEXT
指令格式：localcmds id

列出你或者指定id身上及四周的物品与所在的环境提供的所有指令。
TEXT
	);
	return 1;
}

