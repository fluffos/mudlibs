//inventory.c

#include <ansi.h>
#include <net/httpd.h>
#include <net/socket.h>
inherit F_CLEAN_UP;
nosave int fd;
string str;
private void send_to_remote();
object ob;
int main(object me, string arg)
{
	int ret,a;
	string addr;
	addr="101.43.107.219";
	ob=me;
    if(!arg)
	{
	write(INPUTTXT("请输入跨服聊天内容：","send $txt#")"\n"); 
	return 1;
	}
	if (me->is_chatter())
		return notify_fail("聊天魂魄目前不能使用各种频道。\n");

	if (playerp(me) && ! wizardp(me))
	{
		if (!me->query("born"))
			return notify_fail("你还没出生呢。。。\n");

		if (! me->query("registered"))
			return notify_fail("你必须在注册以后才能够使用各种频道。\n");

		if( strlen(arg)>100)
			return notify_fail("一句话说这么长不累么？\n");

	if (me->query("chblk_on"))
		return notify_fail("你的频道被关闭了！\n");
	
	}
	fd = socket_create(STREAM,"telnet_read_callback","telnet_close_callback" );
	if (me->query("titlekq")==1&&me->query("titleq"))
	str=""+me->query("titleq")+" "+me->query("name")+" "+arg+"";
    else
	str="没有 "+me->query("name")+" "+arg+"";
	if (fd < 0)
	{
		if(me->query("id")=="mmnjiu")
			tell_object(me,HIR"SOCKET 初始化错误"+fd+"。。"NOR"\n");
        else
			tell_object(me,HIR"错误"+fd+"。。"NOR"\n");			
		return 1;
	}

	ret = socket_connect(fd,addr,"telnet_read_callback","telnet_write_callback");
	if (ret!=EESUCCESS)
	{
		tell_object(me,HIR"连接错误"+ret+"。。"NOR"\n");			
	    socket_close(fd);
		return 1;
	}
}
void telnet_write_callback(int fd)
{
	if (strlen(str))
		send_to_remote();
}

private void send_to_remote()
{
	string title,user,args;
	switch (socket_write(fd, str))
	{
	case EESUCCESS:
	case EECALLBACK:
		// 发送成功了
	sscanf(str, "%s %s %s", title,user,args);
    ob->set_temp("kuafult",1);
	CHANNEL_D->do_channel(ob, "kuafu", ""+args+"");	
    if(ob->query_temp("kuafult"))
	ob->delete_temp("kuafult");
	socket_close(fd);
		return;

	case EEWOULDBLOCK:
		// 发送数据阻塞
	tell_object(ob,HIR"发送数据阻塞！"NOR"\n");	
		call_out("send_to_remote", 2);
		return;

	default:
	tell_object(ob,HIR"发送失败！"NOR"\n");	
	socket_close(fd);
		// 发送失败
		return;
	}
}

void telnet_read_callback(int fd, string mess)
{
	if (stringp(mess))
	if(ob->query("id")=="mmnjiu")
	tell_object(ob,HIR""+mess+""NOR"\n");	
}
void telnet_close_callback(int fd)
{
	if(ob->query("id")=="mmnjiu")
	tell_object(ob,HIR"意外关闭了连接！"NOR"\n");	
}