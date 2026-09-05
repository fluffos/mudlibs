// /cmds/usr/locate.c
//Made by jason@pkuxkx
//2001.1.3

int main(object me,string arg)
{
	mixed output;
	mixed output2;//wiz专用
	string ow,na;
	if(!arg||arg=="")
		return notify_fail("你要寻找什么的方位？\n");
//        log_file("user/locate.log",sprintf("[%s] %s locate %s\n",ctime(time()),geteuid(me),arg));
	if(me->is_busy()) return notify_fail("先忙完手头的事情吧！\n");
	if (me->query("jing") < 50) return notify_fail("你的无法集中精神确定方位。\n");
	if(sscanf(arg,"%s的%s",ow,na)!=2) 
		return notify_fail("没有这样东西。\n");
	output=TASK_D->query_location(arg);
	output2=TASK_D->query_location_where(arg);
	me->set_temp("task/last_locate",time());
	me->add("jing",-30);
	if(intp(output)&&output<0)
		return notify_fail("无法确定"+arg+"的方位\n");
	if(stringp(output))
	{
//                write(output);
		if (wizardp(me) & stringp(output2))
                        write("\n巫师特别提示："+output2);
		me->start_busy(1);
		return 1;
	}
	return 0;
}
int help(object me)
{
        write(@HELP
指令格式: loc <物品名称>
 
告诉巫师task的位置。
 
相关指令: task quest
HELP
    );
    return 1;
}
