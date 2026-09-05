// tail.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object* us;
		int i;
        if( !arg ) return help(me);
		us = users();
		for(i=0;i<sizeof(us);i++)
	{
			if(us->query("name") == arg) printf(us->query("id") + "\n");
	}
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : fcname 中文名

此指令可让你根据中文名查找在线id
HELP
    );
    return 1;
}
