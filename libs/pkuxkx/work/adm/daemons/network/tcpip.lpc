#include <net/socket.h> 

#include <net/socket_errors.h> 

  

inherit F_DBASE; 

  

int my_socket,socket1,socket2
;

int do_telnet(string arg); 

void tell_me(string str); 

int write_message(string arg); 

  

void create() 

{ 

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

        write_message(cmd); 

        get_char("do_command",0); 

} 

  

int do_telnet(string arg) 

{ 

        int err; 

        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback
k" ); 

        if ( my_socket < 0 ) 

        { 

                tell_me( "无法生成新的Socket，telnet进程被终止。\n" ); 

                return 1; 

        } 

        err = socket_connect( my_socket, arg , "read_callback","write_callback");
 

  

        if( err==EESUCCESS ) 

        { 

                tell_me("正在连接 " + arg + "。。。\n"); 

        } 

        else 

            { 

                        tell_me("无法连接到 " + arg + "，再见！\n"); 

                destruct(this_object()); 

        } 

        return 1; 

} 

int in_close_callback(int fd) 

{ 

            destruct(this_object()); 

} 

int close_socket() 

{ 

            if( socket_close(my_socket) ) 

            { 

            tell_me("正常关闭Socket。\n"); 

            } 

            else 

                    tell_me("无法关闭该Socket。\n"); 

        return 1; 

} 

  

void read_callback(int fd, mixed message) 

{ 

        message("tcpip",(string) message,this_object()); 

} 

  

int write_message(string arg) 

{ 

            if ( strwidth(arg) > 2 && arg[0..1] == " [" ) 

                        arg = replace_string( arg, " ", ""); 

        if(arg[0]==13) arg[0]=10; 

  

        socket_write(my_socket,arg); 

        return 1; 

} 

  

void net_dead() 

{ 

        remove_call_out("time_out")
;
        remove_call_out("time_out"); 

        call_out( "time_out", 10 ); 

} 

  

void time_out() 

{ 

        close_socket(); 

        destruct(this_object()); 

} 


