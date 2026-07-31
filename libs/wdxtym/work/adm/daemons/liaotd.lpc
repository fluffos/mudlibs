#include <net/socket.h>
#include <localtime.h>
#include <ansi.h> 
inherit F_DBASE;
nosave int fd;
nosave int ret;
string addr="111.229.173.39 3000";
protected void setup();
void close_connection(int fd);
nosave int cc1=0,cc2=0;
protected void create()
{ 
	set("channel_id", "聊天精灵");
	seteuid( geteuid() );
    fd = socket_create(STREAM,"telnet_read_callback","telnet_close_callback" );
	ret = socket_connect(fd,addr,"telnet_read_callback","telnet_write_callback");
	CHANNEL_D->do_channel(this_object(), "sys", "聊天服务开始启动！");
	call_out("setup",1);
}

protected void setup()
{
	if (fd < 0)
	{
		fd = socket_create(STREAM,"telnet_read_callback","telnet_close_callback" );
		CHANNEL_D->do_channel(this_object(), "sys", "socket初始化出错！");
	}else if(cc1=0)
	{
		CHANNEL_D->do_channel(this_object(), "sys", "socket初始化成功！");
		cc1=1;
	}
	if (ret!=EESUCCESS)
	{
		ret = socket_connect(fd,addr,"telnet_read_callback","telnet_write_callback");
        CHANNEL_D->do_channel(this_object(), "sys", "连接出错"+ret+"！");		
	    socket_close(fd);
		return;
	}else if(cc2=0)
	{
		CHANNEL_D->do_channel(this_object(), "sys", "连接成功！");
		cc2=1;
	}
}
void telnet_write_callback(int fd)//连接时发送数据
{

}

public void send_to_remote(string str)//发送数据到聊天服务器
{
	switch (socket_write(fd, str))
	{
	case EESUCCESS:
	case EECALLBACK:
	case EEWOULDBLOCK:
		// 发送数据阻塞
		call_out("send_to_remote", 2);
		return;

	default:
		// 发送失败
		return;
	}
}

void telnet_read_callback(int fd, string mess)//接收数据并发布到聊天频道
{
	string *shuju,qu,name,str;
	object obj;
	obj=new("d/city/npc/liyu");
	if (stringp(mess))
	{
	if(mess=="a")
	{
	send_to_remote("a");
    return;	
	}
    shuju = explode(mess,"║");
	if(sscanf(mess, "%s %s %s", qu, name,str))
	{
	if(name==""||name=="0"||!name)
		name=HIC"跨服使者"NOR;
	obj->set("titleq",YEL+qu+NOR);
	obj->set("titlekq",1);
	obj->set("name",name);
	CHANNEL_D->do_channel(obj,"kuafu", ""+str+"");
	}else{
	CHANNEL_D->do_channel(this_object(), "chat", ""+mess+"");			
	}
	destruct(obj);
	}
}
void telnet_close_callback(int fd)
{
	
}