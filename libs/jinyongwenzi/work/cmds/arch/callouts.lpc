// callouts.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *info;
	int i;
	string output;

	output = sprintf("%-40s %-20s %s\n", "物件", "函数", "延迟时间"); 
	if( arg && arg!="" )
		info = filter_array(call_out_info(), (: $1[1]==$2 :), arg);
	else
		info = call_out_info();

	for(i=0; i<sizeof(info); i++)
        output += sprintf("%-60O %-20s %5d\n",
			info[i][0], info[i][1], info[i][2]);

	me->start_more(output);
	return 1;
}

int help()
{
	write(@LONG
指令格式：callouts [<函数名称>]

List all the system callouts, or, a particular callouts 
specified as a parameter.

LONG
	);
	return 1;
}
