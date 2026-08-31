#include "/adm/include/socket.h";
#include "/adm/include/network.h";
#include <security.h>

#define IP "217.160.254.143"
#define CHAT_D "/daemon/chat"
#define UID_FNETWORK "FNetwork"

int in_use, b;
void create_socket();
void go_online();
void create() {
    call_out("setup", 1);
    call_out("remain_active",5);
}
void remain_active() {
    call_out("remain_active", 60);
}
void setup() {
    create_socket();
}
void create_socket() {
    int s, error;
    s = socket_create(DATAGRAM, "read_callback");
    if (s < 0) {
	CHAT_D->do_raw_chat("network"," <network> socket_create:"
	  +socket_error(s)+"");
	return;
    }
    error = socket_bind(s, 6123);
    if (error != EESUCCESS) {
	CHAT_D->do_raw_chat("network", " <network> Socket "
	  "bind error: "+socket_error(s));
	socket_close(s);
	return;
    }
    CHAT_D->do_raw_chat("network", " <network> Network Enabled.");
    this_object()->send_pd("$|ONLINE|||Primal Darkness-II");
}
//  Formats: FTP: FTP:{
//  Lines: $|FROM||FROMMUD||TOMUD|||STR
void send(string message) {
    string *args;
    int s, error;
    string address=IP+" 6124";
    object o;
    s = socket_create(DATAGRAM, "read_callback");
    if (s < 0) {
	write(socket_error(s));
	CHAT_D->do_raw_chat("network", " <network> "+socket_error(s));
	return;
    }
    error = socket_bind(s, 0);
    if (error != EESUCCESS) {
	CHAT_D->do_raw_chat("network", " <network> ("+error+") socket "
	  "create to send: "+socket_error(s));
	socket_close(s);
	return;
    }
    socket_write(s, message, address);
    socket_write(s, message, IP+" 6198");
    socket_close(s);
}

int read_callback(int fd, string msg) {
   string from, fm, tm, str, line;
   if(sscanf(msg, "$|ONLINE|||%s", fm) == 1) {
     CHAT_D->do_raw_chat("network", " <network> "+fm+" is now online.");
     return 1;
   } 
   sscanf(msg, "$|%s||%s||%s||%s|||%s", line, from, fm, tm, str);
   CHAT_D->do_raw_chat(line, ""+from+"@"+fm+" <"+line+"> "+str);
}

