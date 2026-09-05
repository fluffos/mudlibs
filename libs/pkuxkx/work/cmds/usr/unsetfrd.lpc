// unsetfrd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg || arg=="" ) return notify_fail("参数错误！\n");

	me->delete("friends/" + arg);
	write("Ok.\n");
	return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式:  unsetfrd <玩家ID>
 
这个指令可以让你删除好友列表中的好友。
 
相关指令: setfrd
 
HELP
    );
    return 1;
}
