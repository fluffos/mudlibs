/* lpMud socket( telnet )
 */
#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>

inherit CHARACTER;

// nosave int my_socket,socket1,socket2;
int my_socket,socket1,socket2;
// nosave object me;
object me;
int is_gb=1;
int do_telnet(string arg);
int write_message(string arg);

void create()
{
        set_name("Telnet socket", ({ "telnet wizard", "telnet" }) );
        set("long",
                "这是用来连接其他 mud 的精灵。\n");
                set_weight(3000);
                set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "个");
                        set("material", "unknow");
                }
        set("no_shown",1);
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
    string str;
    if(strsrch(cmd,"telnet")==0){
            str=replace_string(cmd,"telnet ","");
            tell_me(HIR"开始连接"+str+"\n"NOR);
                do_telnet(str);
    } else if(cmd=="exit mud"){
            socket_close(my_socket);
              //           QUIT_D->leave_world(this_object());
        return ;
    } else if(cmd=="gb_code") {
    	is_gb=1;
    } else if (cmd=="big5_code") {
    	is_gb=0;
    } else write_message(cmd);
input_to("do_command",0);
}

int do_telnet(string arg)
{
        int err;
        
        socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 ) {
                tell_me( "Failed to create socket.\n" );
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS ) {
                        tell_me("Connect to " + arg + "\n");
                        set("connected",1);
        }
        else{
                        tell_me("Can't connect to " + arg + "\n");
                        socket_close(my_socket);
        }
        return 1;
}
int in_close_callback(int fd)
{
        delete("connected");
        tell_me(HIR+fd+"号socket已经关闭!\n"NOR);
}
int close_socket()
{
        if( socket_close(my_socket) ) {
            tell_me("Closed telnet socket.\n");
        }
        else
            tell_me("Close telnet socket fail.\n");
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
       // if(query("connected"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
                set("connected",1);
        }
}

int write_message(string arg)
{
        if( !arg ) arg="";
        if(! is_gb) arg= LANGUAGE_D->GB2Big5(arg);
     //   if(query("connected"))
        socket_write(my_socket,arg+"\n");
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
              //           QUIT_D->leave_world(this_object());
}
