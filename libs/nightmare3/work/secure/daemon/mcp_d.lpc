/*    /daemon/mcp_d.c
 *    from Intermare libs
 */

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <network.h>
#include <socket.h>
#include "mcp_d.h"

inherit DAEMON;

#define PORT_MCP                 (query_host_port() - 4)
#define MAX_ONE_WRITE 3072
#define VALID_INTERMARES ([ "199.199.122.10": ({ "tna", "3996" }), \
			"134.130.76.1": ({ "teu", "4996" }) ])

nosave private int __SocketMCP;
nosave private mapping __Sockets;
nosave private mapping __ValidHosts;

void create() {
    daemon::create();
    set_no_clean(1);
    __Sockets = ([]);
    __ValidHosts = VALID_INTERMARES;
    call_out("setup", 2);
    call_out("clean_sockets", 180);
}

protected void setup() {
    if((__SocketMCP=socket_create(STREAM,"read_callback","close_callback"))<0){
        log_file("inter_copy", "Failed to create socket.\n");
        return;
    }
    if(socket_bind(__SocketMCP, PORT_MCP) < 0) {
        socket_close(__SocketMCP);
        log_file("inter_copy", "Failed to bind port to socket.\n");
        return;
    }
    if(socket_listen(__SocketMCP, "listen_callback") < 0) {
        socket_close(__SocketMCP);
        log_file("inter_copy", "Failed to listen to socket.\n");
    }
}

void listen_callback(int fd) {
    int New;
    string tmp;

    if((New = socket_accept(fd, "read_callback", "write_callback")) < 0)
      return;
    if(!__Sockets[New]) {
        sscanf(socket_address(New), "%s %*s", tmp);
	if (member_array(tmp,keys(__ValidHosts)) == -1) {
	    socket_close(New);
	    log_file("inter_copy", "Illegal connection attempt from "+tmp+".\n");
	} else
	    __Sockets[New] = ([ "address": tmp, "time": time() ]);
    }
}

void write_callback(int fd) {
    int i, pos;
    string str, file;

    if (str = __Sockets[fd]["pos"]) {
	pos = to_int(str);
	file = __Sockets[fd]["file"];
	if (pos == 0) {
	    i = file_size(file);
	    if (i > 0) {
		if (i >= MAX_ONE_WRITE) {
		    str = read_file(file,1,49);
		    socket_write(fd, "store "+file+"\n"+str);
		    __Sockets[fd]["pos"]="50";
		    __Sockets[fd]["file"]=file;
		    map_delete(__Sockets[fd],"write_callback");
		    if (find_call_out("write_tick") == -1)
			call_out("write_tick",1);
		} else {
		    str = read_file(file);
		    socket_write(fd, "store "+file+"\n"+str+"****EOT****\n");
		    close_connection(fd);
		}
	    } else {
		close_connection(fd);
	    }
	}
    }
}

void read_callback(int fd, string str) {
    string *lines;
    string cmd, args;
    int eof, i, j;

    if(str && str != "") {
	str = replace_string(str, "\r", "");
	if (str == "\n" ||  str == "")
	    lines = ({ "" });
	else
	    lines = explode(str,"\n");
	if (__Sockets[fd]["store"]) {
	    eof = 0;
	    if ((i = sizeof(lines)) > 0) {
		if (lines[i-1] == "****EOT****")
		{
		    eof = 1;
		    i--;
		    if (i)
			for (j=0;j<i;j++)
			    write_file(__Sockets[fd]["store"],lines[j]+"\n");
		} else
		    write_file(__Sockets[fd]["store"],str);
	    }
	    if (eof)
	    	close_connection(fd);
	    return;
	}
	sscanf(lines[0], "%s %s", cmd, args);
	switch(lower_case(cmd)) {
	    case "retrieve": retrieve_file(fd, args); return;
	    case "store": store_file(fd, args, lines); return;
	    // add here
	    default: close_connection(fd); return;
	}
    }
}

void close_callback(int fd) {
    socket_close(fd);
    if(fd == __SocketMCP) this_object()->remove();
}

void close_connection(int fd) {
    map_delete(__Sockets, fd);
    socket_close(fd);
}

protected void clean_sockets() {
    int *cles;
    int i;

    i = sizeof(cles = keys(__Sockets));
    while(i--)
      if(time() - __Sockets[cles[i]]["time"] > 180) close_connection(cles[i]);
    call_out("clean_sockets", 180);
}

void remove() {
    if(previous_object() != this_object()) return 0;
    socket_close(__SocketMCP);
    destruct(this_object());
    // return daemon::remove();
}

void write_tick() {
    int i, fd, f, pos;
    string str;

    f = 0;
    i = sizeof(__Sockets);
    while (i--) {
	fd = keys(__Sockets)[i];
	if (__Sockets[fd]["write_callback"])
	    continue;
	if (str = __Sockets[fd]["pos"]) {
	    pos = to_int(str);
	    str = read_file(__Sockets[fd]["file"],pos,50);
	    if (str) {
		socket_write(fd, str);
		__Sockets[fd]["pos"]=sprintf("%d",pos+50);
	        __Sockets[fd]["time"]=time();
		f++;
	    } else {
	        socket_write(fd,"****EOT****\n");
		close_connection(fd);
	    }
	}
    }
    if (f)
	call_out("write_tick",1);
}

 private void retrieve_file(int fd, string file) {
    string str;
    int i;

    if (strlen(file) < 5 || file[0..4] != "/ftp/") {
	log_file("inter_copy", __Sockets[fd]["address"]+" attempted to retrieve: "+file+".\n");
        close_connection(fd);
	return;
    }
    log_file("inter_copy", __Sockets[fd]["address"]+" retrieved: "+file+".\n");
    i = file_size(file);
    if (i > 0) {
	if (i >= MAX_ONE_WRITE) {
	    str = read_file(file,1,49);
	    socket_write(fd, "store "+file+"\n");
	    socket_write(fd, str);
	    __Sockets[fd]["pos"]="50";
	    __Sockets[fd]["file"]=file;
	    if (find_call_out("write_tick") == -1)
		call_out("write_tick",1);
	} else {
	    str = read_file(file);
	    socket_write(fd, "store "+file+"\n");
	    socket_write(fd, str);
	    socket_write(fd,"****EOT****\n");
	    close_connection(fd);
	}
    }
}

 private void store_file(int fd, string file, string *lines) {
    int i, j, eof;

    if (strlen(file) < 5 || file[0..4] != "/ftp/") {
	log_file("inter_copy", __Sockets[fd]["address"]+" attempted to store: "+file+".\n");
        close_connection(fd);
	return;
    }
    log_file("inter_copy", __Sockets[fd]["address"]+" stored: "+file+".\n");
    rm(file);
    eof = 0;
    if ((i = sizeof(lines)) > 1) {
	if (lines[i-1] == "****EOT****")
	{
	    eof = 1;
	    i--;
	}
	for (j=1;j<i;j++)
	    write_file(file,lines[j]+"\n");
    }
    if (!eof)
        __Sockets[fd]["store"]=file;
}

 private void do_send(string file,string dest) {
    int fd;
    if (strlen(file) < 5 || file[0..4] != "/ftp/") {
	log_file("inter_copy", "Someone attempted to send: "+file+".\n");
	return;
    }
    log_file("inter_copy", "Someone send: "+file+" to "+dest+".\n");
    if((fd=socket_create(STREAM,"read_callback","close_callback"))<0){
        log_file("inter_copy", "Failed to create send socket.\n");
        return;
    }
    __Sockets[fd] = ([ "address": explode(dest," ")[0], "time": time(),
			"pos": "0", "file": file, "write_callback": 1, ]);
    if(socket_connect(fd, dest, "read_callback", "write_callback") < 0) {
        socket_close(fd);
	map_delete(__Sockets, fd);
        log_file("inter_copy", "Failed to connect send socket.\n");
    }
}

void send_file(string file, string mud) {
    int i;
    if (!mud || !file) return;
    for (i=0; i<sizeof(__ValidHosts); i++) {
	if (__ValidHosts[keys(__ValidHosts)[i]][0] == mud) {
	    do_send(file,keys(__ValidHosts)[i]+" "+
		__ValidHosts[keys(__ValidHosts)[i]][1]);
	    break;
	}
    }
}
