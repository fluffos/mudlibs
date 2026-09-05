//setmail 设置email

inherit F_CLEAN_UP;
#define MAIL_FILE "/adm/tmp/mailuser"
#include <ansi.h>
int help(object me);

int main(object me,string arg)
{
		string add_cmd;
		string fname,lname;

		if (me->query("id") == "players" || me->query("id") == "pkuxkx"|| me->query("id") == "webmaster"|| me->query("id") == "root"|| me->query("id") == "postmaster"|| me->query("id") == "icer")
				return notify_fail("对不起，你的id比较特殊，不能申请email。\n");
        if ( !arg || sscanf(arg, "%s %s", lname, fname) != 2 )
                return help(me);
		if (me->query("combat_exp") < 1000000)
				return notify_fail("对不起，北侠邮箱名额有限，请在经验超过1M以后再申请。\n");
        if (!me->query("havegot_newmail"))
			add_cmd = me->query("id") + "," + fname + "," + lname;
		else
			return notify_fail("你已经申请过北侠邮箱了，如要修改姓名或密码，请登录http://app.pkuxkx.net。\n");
		
		write_file(MAIL_FILE, add_cmd + "\n"); 
			write(HIW"已发出申请北侠邮箱" + me->query("id") + "@pkuxkx.net的请求，请等待最多24小时后进入http://app.pkuxkx.net或http://mail.pkuxkx.net\n");
			write(HIW"使用" + me->query("id") + "@pkuxkx.net作为帐号，以“pkuxkx”作为密码登录北侠邮箱。\n");
			write(HIW"如果24小时后仍无法登录北侠邮箱，请联系pkuxkx@gmail.com。\n");
			write(HIW"登录后请立即在登录-设置-修改密码中修改你的初始密码，并在设置-转发和POP/IMAP中选中“针对所有邮件启用POP”启动POP功能。\n");
			write(HIW"北侠邮件客户端工具的设置为： \n"NOR);
			write(HIW"接收邮件(POP3)服务器: pop.gmail.com  需要SSL: 使用SSL:是 端口:995\n" + NOR);
			write(HIW"发送邮件(SMTP)服务器: smtp.gmail.com 使用验证:是 使用STARTTLS（或SSL）:是 端口:465或587\n"NOR);
			write(HIW"帐户名: 你的id@pkuxkx.net （需要输入完整域名）\n"NOR);
            me->set("havegot_newmail",1);
		return 1;
}





int help(object me)
{
write(@HELP
指令格式 : setmail(空格)姓(空格)名 


使用这个命令可以为你申请自己的id@pkuxkx.net的电子信箱。
申请邮箱之后请等待最多24小时即可连线http://app.pkuxkx.net 或 http://mail.pkuxkx.net
用“你的id@pkuxkx.net ”为帐号，以“pkuxkx”为初始密码登录北侠邮箱。如果24小时后还无法登录邮箱，请联系pkuxkx@gmail.com。
登录后请立即在登录-设置-修改密码中修改你的初始密码，并在设置-转发和POP/IMAP中选中“针对所有邮件启用POP”启动POP功能。
北侠邮件客户端工具的设置为： 
接收邮件(POP3)服务器: pop.gmail.com  需要SSL: 使用SSL:是 端口:995
发送邮件(SMTP)服务器: smtp.gmail.com 使用验证:是 使用STARTTLS（或SSL）:是 端口:465或587
帐户名: 你的id@pkuxkx.net （需要输入完整域名）

HELP
    );
    return 1;
}
