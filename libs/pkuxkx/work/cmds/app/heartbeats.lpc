// heartbeats.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *info;
	int i;
	string output;

    info = heart_beats();
	output = "目前所有有心跳对象列表:\n";
	for(i=0; i<sizeof(info); i++)
	{
		output+= "\n";
        output += file_name(info[i]);
	}

	me->start_more(output);
	return 1;
}

int help()
{
	write(@LONG
指令格式：heartbeats

返回所有有心跳的对象

LONG
	);
	return 1;
}
