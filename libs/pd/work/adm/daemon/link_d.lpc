// Hopefully this works out very smoothly

#include <link_info.h> /* each individual server */
#include <daemons.h>

#ifdef SERVER
 string *allowed_servers = ({ "63.84.93.196","127.0.0.1" });
 int listen_socket;
 mapping connected_servers = ([]);
 string setup_connections();
#endif
#ifdef LEAF
 int connect_socket;
 mixed *buffer_out = ({});
 int append_buffer(mixed buf);
#endif
#define disp(s) (CHAT_D->do_raw_chat("driver",mud_name()+" %^BLUE%^%^BOLD%^<driver>%^RESET%^ "+s))

void create()
{

#ifdef SERVER
  disp("Warming up link server....");
  setup_connections();
  connected_servers = ([]);
  disp("Done, allowing connections.");
#endif

}
#ifdef LEAF
string connect_server()
{
 int wtf;
 mapping auth;
 string bleh;
 disp("Attempting to connect to [63.84.93.196:3031]");
 connect_socket = socket_create(1, "cRead_callback", "cClose_callback");
 if (connect_socket < 0) return "blah dont work";
 if (wtf=socket_connect(connect_socket, "63.84.93.196 2349", "cRead_callback", "write_callback") < 0)
   return "eh didnt work";
 disp("Connected to server, requesting authorization.");
 call_out("send_authorization", 2);
 return "Ok.";
}

int send_authorization() { 
 int wtf;
 mixed auth = (["mud":SERVER_NAME, "pass":PASSWORD]);
 append_buffer( "How are you doin"); 
 
}

int write_callback(int fd)
{
 if (!sizeof(buffer_out)) return 1;
 disp("Output = "+buffer_out [ 0 ]);
 socket_write( fd, buffer_out [ 0 ]);
 buffer_out -= buffer_out [ 0 ];
}
int append_buffer(mixed buf)
{
 buffer_out += ({ buf });
}

#endif
#ifdef SERVER
string setup_connections()
{
 int i;
 if ((listen_socket = socket_create(0, "", "close_callback")) < 0)
  return socket_error(listen_socket);
 if (i = socket_bind(listen_socket, LISTEN_PORT) < 0) 
   return socket_error(i);
 if (i = socket_listen(listen_socket, "listen_callback") < 0)
   return socket_error(i);
 return "Ok.";  
}

int listen_callback(int fd)
{
 int new_fd;
 string ip, port;
 mapping t;
 new_fd = socket_accept(fd, "read_callback", "close_callback");
 sscanf(socket_address(new_fd), "%s %s", ip, port);
 disp(ip+" has connected to the link server.");
 if (member_array(ip, allowed_servers)==-1)
   {
    disp(ip+" has been denied access to connect.");
    socket_close(new_fd);
    return 1;
   } 
 disp(ip+" access to connect has been allowed."); 
// socket_write(new_fd, "Access Allowed: "+ip);
// socket_write(new_fd, t);
 connected_servers[new_fd] = "unverified";
}

int read_callback(int fd, mixed msg)
{
 string mudname, pass;
 message("info", "msg = "+msg+"\n", users());
// if (!connected_servers[fd]) return 0;
 disp("got callback \""+msg+"\"\n"); 
 if (connected_servers[fd]=="unverified")
   {
    if (!mapp(msg))
      {
       socket_write(fd, "You need to register first.\n");
       socket_close(fd);
       map_delete(connected_servers, fd);
       return 1;
     }
  }
 disp(socket_address(fd)+" has been verified, linking complete.\n"); 
}
int close_callback(int fd)
{
}
#endif


