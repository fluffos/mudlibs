//sms 通过飞信发送短信给自己

inherit F_CLEAN_UP;
#define SMS_FILE "/adm/tmp/sms"
#include <ansi.h>
int help(object me);

int main(object me,string arg)
{
	string sms_cmd;
	string phone_no,fetion_pass,sms_content;
	


	if (time()-me->query_temp("sms/last_time") < 10)
		return notify_fail("对不起，10秒钟内只能发送一条短信。\n");
	if ( !arg || sscanf(arg, "%s %s %s", phone_no, fetion_pass, sms_content) != 3 )
		return help(me);
	if (strwidth(sms_content) > 120) 
		return notify_fail("对不起，你的短信内容不能超过60个汉字或120个字母。\n");
	sms_cmd = phone_no + " " + fetion_pass + " \"" + replace_string(sms_content,"\"","'") + "\"";
	write_file(SMS_FILE, sms_cmd + "\n"); 
	me->set_temp("sms/last_time",time());
	log_file("user/sms", me->query("name") + "(" + me->query("id") + ")于" + ctime(time()) + "发送了一条短信。\n");
	write("你的短信将在十秒钟内发送，如果一分钟内还未收到短信请确认你的手机已经开通飞信且登录密码正确，并且移动飞信服务状态正常。\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : sms(空格)自己的手机号(空格)飞信密码(空格)短信内容

使用这个命令之前请先开通移动飞信服务(免费，开通方法见http://www.fetion.com.cn/，
非移动手机无法开通)，之后就可以使用本命令免费向自己的手机发送短信（使用飞信客户端
可以向自己或飞信好友发送短信）。发送格式范例如下：
sms 1380000000 password 这是一条示例短信
以上命令将给手机号码为1380000000，飞信密码为password的手机发一条短信，内容为“这是
一条示例短信”。
本命令发送的短信内容不能超过60个汉字或120个字母，每10秒钟内限发一条短信。
声明：本命令是否能成功运行依赖于移动飞信系统的稳定性，不保证100%成功。本命令也不是
中国移动的广告，只是为玩家提供一个更方便的提醒方法。
有关安全性：本命令在系统内临时保存用户的手机号密码不超过10秒钟，之后将删除，但仍将
保留一条格式为“姓名(id)在 某时间 发送了一条短信”这样的记录以备万一，具体短信内容、
手机号与飞信密码不会记录。

HELP
    );
    return 1;
}


