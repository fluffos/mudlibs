#define SOCKET "/daemon/network/socket"
#include <daemons.h>
#include <socket.h>
#define ERROR(s) CHAT_D->do_raw_chat("network", s);
int get_socket();

void create() {
   string s;
   s=catch(call_other(SOCKET, "???"));
   if(s) error("Cannot load network daemon without socket daemon.");
}

int send_file(object tp, string location, string file, string contents) {
        if(file_size(file) != sizeof(contents)) { write("Error: filesize != contents"); return 0; }
        return SOCKET->send_packet(location,"|ftp| location: "+location+" file: "+file+" size: "+file_size(file)+" user: "+tp->query_name()+" contents: "+contents);
}
int send_chat(object tp, string txt) {
        SOCKET->send_global_packet("|chat| line: newbie user: "+tp->query_name()+" text: "+txt);
}
void recieve_file(string file) {
	string *a, filename;
	a=explode(file, "\n");
	filename=a[0];
	a[0]=0;
	file = implode(a, "\n");
}
