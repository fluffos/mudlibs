/* lpMud socket( telnet )
 */
//这个程序非常不完善,本想做成类似bbs一样.无奈我对socket不太懂.所以只能做成这个样子.
//后人可以常识完善它./2000/4/27/ rongg@xbtxII
#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <user.h>

//inherit F_DBASE;
inherit CHARACTER;

nosave int my_socket,socket1,socket2;
int do_telnet(string arg);
void tell_me(string str);
int write_message(string arg);
int get_command(string cmd,object ob);
int do_rehash();
int is_gb=1;
void create()
{
        set_name("连线精灵", ({ "telnet wizard" }));
        set("no_shown",1);
        set_weight(3000);
        set_max_encumbrance(0);
        if( clonep() ) set_default_object(__FILE__);
        
        else {
             set("unit", "个");
             set("material", "unknow");
        }

        setup();

}
void receive_message(string type, string str)
{
        if( type!= "write"&&type!="tcpip" ) return;
        receive(str);
}

void tell_me(string str)
{
        message("tcpip",str,this_object());
}


void do_command(string cmd)
{
    get_char("do_command",0);    
//    input_to("do_command",0);    
    write_message(cmd);
}

int do_telnet(string arg)
{
        int err;
        close_socket();
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
	if( query("connected") )      socket_close(my_socket);
        if ( my_socket < 0 ){
                tell_me( "无法生成新的Socket，telnet进程被终止。\n" );
                input_to("get_command",1,this_object());
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback");

        if( err==EESUCCESS ){
            tell_me("正在连接 " + arg + "。。。\n");
	    set("connected",1);
        }
        else
            {
            tell_me("无法连接到 " + arg + "，请重新输入指令！\n");
            input_to("get_command",1,this_object());
            return 1;
            //destruct(this_object());
        }
        return 1;
}


int in_close_callback(int fd)
{
        delete("connected");
        tell_me(HIR+fd+"号socket已经关闭!10秒之后自动关闭.再见........\n"NOR);
        //call_out("do_rehash",2);
        call_out("time_out",10);

}
/*
int do_rehash()
{
        string str;
        str="你要telnet到哪里？(telnet 地址 端口)\n";
        tell_me(str+"\n");
	input_to("get_command",1,this_object());    
	return 1;
}
*/
int close_socket()
{
        if( query("connected") ) {
            if( socket_close(my_socket) ) {
                tell_me("Telnet socket 正常关闭.\n");
                delete("connected");
             }
             else  tell_me("无法关闭改Socket!\n");
        }
        else  tell_me("并没有连接.\n");
	input_to("get_command",1,this_object());    
        return 1;
}



void read_callback(int fd, mixed message)
{
        if(!is_gb)message = LANGUAGE_D->Big52GB(message);
        tell_me( (string) message );
}

void write_callback(int fd)
{
        int res;
        if(query("connected"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
                set("connected",1);
        }
}

int write_message(string arg)
{
        if( !arg ) arg="";
        if(! is_gb) arg= LANGUAGE_D->GB2Big5(arg);
        if ( strwidth(arg) > 2 && arg[0..1] == " [" )
            arg = replace_string( arg, " ", "" );
        if(arg[0]==13) arg[0]=10;
        if(query("connected"))
            socket_write(my_socket,arg);
        return 1;
}

void net_dead() 
{ 
        remove_call_out("time_out"); 
        call_out( "time_out", 10 ); 
} 

void time_out() 
{ 
        close_socket(); 
	QUIT_D->leave_world(this_object());
//        destruct(this_object()); 
//碰到admin使用的时候无法摧毁admin的身体
}

int get_command(string cmd,object ob)
{
    string str;
    if(strsrch(cmd,"telnet")==0){
            str=replace_string(cmd,"telnet ","");
            tell_me(HIR"开始连接"+str+"\n"NOR);
            do_telnet(str);
            do_command("");
            return 1;
    }
    else if(cmd=="help"){
        str="你可以执行下列命令:telnet 地址 端口 disconnect(离线)\n"
            "help(获得帮助) gb_code(简体字) big5_code(繁体字) \n";
        tell_me(str+"\n");
        input_to("get_command",1,this_object());
    }
    else if(cmd=="gb_code") {
    	str="字体转换为简体字\n";
    	is_gb=1;
        tell_me(str+"\n");
	input_to("get_command",1,this_object());    
    }
    else if (cmd=="big5_code") {
    	is_gb=0;
        str="字体转换为繁体字\n";
        tell_me(str+"\n");
        input_to("get_command",1,this_object());
    }
    else if(cmd=="disconnect"){
                socket_close(my_socket);
                tell_me("Telnet socket 正常关闭.再见\n");
	        QUIT_D->leave_world(this_object());
                return 1;

    }
    else {
         str="你可以执行下列命令:telnet 地址 端口 disconnect(离线)\n"
             "help(获得帮助) gb_code(简体字) big5_code(繁体字) \n";
         tell_me(str+"\n");
         input_to("get_command",1,this_object());
    }
    return 1;
}


protected void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
                    socket_close(my_socket);
	            QUIT_D->leave_world(this_object());
		    break;
		case DUMP_IDLE:
	            tell_me(HIR"你发呆时间太久了,自动断线,欢迎下次在来,再见...\n"NOR);
	            socket_close(my_socket);
	            QUIT_D->leave_world(this_object());
       		    break;
		default: return;
	}
}
