// user list

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        int i;

	ob = filter_array(objects(), (: userp :));
	for(i=0; i<sizeof(ob); i++)
		write(sprintf("%10s : %40O%s\n", ob[i]->query("id"), ob[i],
		interactive(ob[i])?"":" 断线中"));
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ulist

将线上所有玩家的/obj/user number 显示出来。
HELP
    );
    return 1;
}
