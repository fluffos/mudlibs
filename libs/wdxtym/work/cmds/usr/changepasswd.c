//cpasswd.c by XiaoYao
// Modify by snowman@SJ 01/05/1999.

#include <ansi.h>
#include <login.h>;

int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	
	seteuid(ROOT_UID); // add by Yuj@SJ 1999-6-2
	if( me != this_player(1) ) return 0;
		
	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
	{
		write(INPUTTXT("你想请输入新密码：","changepasswd "+me->query("id")+" $txt# ")+"\n");
		return 1;
	}

	ob = LOGIN_D->find_body(id);
	if(!ob) return notify_fail("你只能修改自己的密码。\n");
	
	link_ob=ob->query_temp("link_ob");
	if(link_ob && me->query("id")==ob->query("id")) {
		link_ob->set("password",crypt(password,"$1$ShuJian"));
		link_ob->save();
		write("你的游戏密码已经更改为："+password+"\n");
		write(HIR"请同步修改你的客户端密码，否则你将无法登陆。"NOR"\n");
		write(HIY+ZJSIZE(22)"请立即把客户端密码改成："+password+"
请立即把客户端密码改成："+password+"
请立即把客户端密码改成："+password+"
重要的事情说三遍，
另外重新登录时不要选择 上次登录"NOR"\n");
		log_file("changepw", sprintf("%s：%s(%s)把%s(%s)的密码改为 %s\n", ctime(time()), me->query("name"), me->query("id"),
				 ob->query("name"), ob->query("id"), password));
		return 1;
	}
	else
		return notify_fail("你只能修改自己的密码。\n");
	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : changepasswd ID 新密码

这个指令可以修改自己的游戏密码，游戏里修改完密码后，还需进入客户端的用户中心把旧密码改成新密码。
请务必保持客户端和游戏密码相互一致，否则将无法正常登陆。

HELP
    );
    return 1;
}
