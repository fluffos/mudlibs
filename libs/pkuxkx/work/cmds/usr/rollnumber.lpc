#include <ansi.h>

inherit F_CLEAN_UP;

//int help();
int main()
{
	int roll_num;
	string roll_num1;
	object me=this_player();
	if (base_name(environment(me)) != "/d/wizard/biwuchang")
		return notify_fail("这里不能抽奖？\n");
	if (time()-me->query_temp("rolled")<120)
		return notify_fail("你刚刚抽过！\n");
	roll_num=random(100)+1;
	roll_num1=sprintf("%d",roll_num);
	me->set_temp("rolled",time());
	message_vision(HIW"$N抽中了"+roll_num+"。\n"NOR, me);
	return 1;
}

/*
int help()
{
write( @TEXT
指令格式：rollnumber

这个指令让你随机抽取1-100之间的数字。
TEXT
);
return 1 ;
}
*/



