// Change by puma
// qq.c

inherit F_CLEAN_UP;
int help(object me);

int main(object me,string qq)
{
	object ob;
	int arg;
	if( !qq)
             return help(me);
        if( sscanf(qq, "%d", arg)!=1 || arg < 0 || arg > 9999999999)
             return help(me);

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        write("请再输入一次你的的QQ：");

	input_to("confirm_new_qq", 1, ob, qq);
	return 1;
}

private void confirm_new_qq(string qq, object ob, string new_qq)
{
	write("\n");
	if( qq!=new_qq ) {
		write("对不起，您输入的QQ前后两次不相同，继续使用原来的QQ。\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("qq", new_qq) ) {
		write("QQ变更失败！\n");
		return;
	}

	ob->save();
	write("QQ变更成功\。\n");
}

int help(object me)
{
	write(@HELP
指令格式 : qq <数字>
 
这个指令可以修改你的人物的QQ。
 
HELP
    );
    return 1;
}
 
