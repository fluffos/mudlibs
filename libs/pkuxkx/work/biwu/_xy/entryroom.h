inherit ROOM;

int valid_leave(object me,string dir)
{
    object* inv;
    int i;

	if(dir == "enter")
	{
		if(BIWU_D->taskstarted() != 1)
		{
			if(BIWU_D->getnextcycletimespan() > 0)
			{
				return notify_fail("比武尚未开始，你不能进去，请等待"+chinese_number(BIWU_D->getnextcycletimespan())+"秒。\n");
			}
			else
			{
				return notify_fail("你是怎么混进来的？出去！\n");
			}
		}


	}
	return ::valid_leave(me,dir);
}


int isentryroom()
{
	return 1;
}
