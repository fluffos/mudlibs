#pragma save_binary

#include <priv.h>
#include <config.h>
#include <net/socket.h>
#include <net/daemons.h>
#include <mudlib.h>

inherit DAEMON ;
 
mapping requests;

void create() {
   seteuid(getuid(this_object()));
   requests = ([ ]);
}

void query_userid() {
   string socket, address;
   int port, line, tmp;
   socket = socket_address( previous_object() );
 
   if(!socket)  return;
 
   if(sscanf(socket, "%s %d", address, port) != 2)  return;
 
   line = socket_create(STREAM, "socket_shutdown");

   if(line < 0)  return;
 
   if(socket_connect(line, address + " 113","receive_data","write_data") < 0) {
   previous_object()->query_link()->set("userid", 0);
   socket_close(line);
   return ; }
 
   requests[line] = ({ previous_object(), port });
 
}
 
void write_data(int line) {
   int ret;
 
   ret = socket_write(line, requests[line][1] + "," + mud_port() + "\n");
 
   if(ret < 0) {
     socket_close(line);
     requests[line][0]->query_link()->set("userid", 0);
     map_delete(requests, line);
   }

}
 
void receive_data(int line, string info) {
   string tmp, machine, name, userid;
   if(previous_object() || !requests[line] || !requests[line][0] || !info ||
      sscanf(info, "%s : USERID : %s : %s\r\n", tmp, machine, name) != 3) {
     socket_close(line);
     map_delete(requests, line);
   return; }

   userid = name + "@" + query_ip_name(requests[line][0]);
 
   requests[line][0]->query_link()->set("userid", userid);

   socket_close(line);
   map_delete(requests, line);
 
}
 
mapping query_requests() {  return requests;  }
 
