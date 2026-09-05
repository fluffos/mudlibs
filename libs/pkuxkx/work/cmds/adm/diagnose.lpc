//关闭login，逐一踢出玩家，用来诊断系统问题出在哪个玩家身上。
//非特殊情况不得使用。

#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object* us ;
	object ob;
	int i;

	us = children(USER_OB);
	//锁定login
	LOGIN_D->set_wizlock(5);

	i =0;
	if(arrayp(us) && (!arg || arg==""))
	{
				ob = us[i];
				while(wizardp(ob)) 
				{
					if(i==sizeof(us) - 1) return 1;
					ob = us[i++];
				}
        seteuid(ROOT_UID);
				tell_object(ob,"对不起，为了排查系统故障，请暂时退出。谢谢合作。\n");
				write("踢出"+ob->query("id")+"\n");
        ob->save();
        destruct(ob);
        seteuid(getuid());
	}
	else
	{
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 没有这个人?\n");
        seteuid(ROOT_UID);
				tell_object(ob,"对不起，为了排查系统故障，请暂时退出。谢谢合作。\n");
				write("踢出"+ob->query("id")+"\n");
        ob->save();
        destruct(ob);
        seteuid(getuid());

	}
	write("login已经被锁定，排查问题结束后请用wizlock 0解除锁定，否则玩家不能登录\n");
	return 1;
  
}
int help(object me)
{
write(@HELP
指令格式 : diagnose [某人]。不带参数，自动踢出用户列表第一个人。否则踢出指定玩家。
HELP
    );
    return 1;
}
