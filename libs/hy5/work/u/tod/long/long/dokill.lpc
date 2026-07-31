inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{
	object ob1,ob2;
	string ob1name,ob2name;

	if ( arg ) 
	{
		if ( sscanf(arg,"%s %s",ob1name,ob2name)!=2 )
			return notify_fail("指令错误！\n");
		ob1 = present(ob1name,environment(me));
		ob2 = present(ob2name,environment(me));
		if (!ob1 || !ob2)
			return notify_fail("没有这个人!\n");
		message("channel:chat", 
		HIW"【擂台上】"+sprintf("这里30秒后现场直播%s对%s的比武",ob1->name(),ob2->name()) + "\n"NOR, users());
		remove_call_out("kill_each");
              call_out("kill_each",30,ob1,ob2);
		return 1;			
	}
	return 0;
}

private void kill_each(object ob1,object ob2)
{
	message("channel:chat", 
		HIW"【擂台上】"+sprintf("%s对%s的比武现在开始",ob1->name(),ob2->name()) + "\n"NOR, users());
	ob1->kill_ob(ob2);
	ob2->kill_ob(ob1);
}
