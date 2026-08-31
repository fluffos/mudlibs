#include <socket.h>
#include <network.h>
#include <daemons.h>
#define NETWORK "/daemon/network/network"
#define ERROR(s) CHAT_D->do_raw_chat("network", s)
#define VALID_CONNECTIONS ({ "builders", "ns", "server" })

mapping s=([]);

int get_fd(string);
int send_packet(string, string);

void m(string s) { message("", s, find_player("whit")); }

void create() { seteuid("Root"); call_out("reload", 2); }

void reload() {
   int x, fd;
   fd=socket_create(MUD, "read_callback", "closed");
   if(fd < 0) {
     ERROR("Socket <network> Error creating socket. "+socket_error(fd));
     return;
   }
   socket_bind(fd, 6123);
   x=socket_listen(fd, "inbound");
   if(x != EESUCCESS) {
     ERROR("Socket <network> Error connecting: "+socket_error(x));
   } else
   ERROR("Socket <network> Now accepting inbound connections.");
}

void inbound(int fd) {
	string sock, addr;
	int port;
	sock = socket_address(fd);
	ERROR("Network <network> Inbound connection.");
	socket_accept(fd, "read_callback", "write_callback");
}

void read_callback(int fd, string txt) {
	string a,b,c,d,e,f,*ar;
	int x, size;
	if(!s[fd]) {
		if(sscanf(txt, "|%s| |%s|", a, b) != 2) {
			ERROR("Socket <network> Warning: "+socket_address(fd)+" did not correctly identify itself.  Killing the connection.  "+txt);
			socket_close(fd);
			map_delete(s, fd);
			return;
		}
		s[fd]=(["name":a,"full_name":b]);
		ERROR("Socket <network> "+a+" has now connected.");
		return;
	}
	sscanf(txt, "|%s| %s", a,b);

	switch(a) {
		case "ftp":
			sscanf(b, "location: %s file: %s size: %d user: %s contents: %s", f, c, size, d, e);
			if(!find_player(d) || !interactive(find_player(d))) { 
				socket_write(fd, "|error| user: "+d+" error: Your character must be logged on both ports due to security restrictions."); 
				return; 
			}
			if(f != "server") {
				if(member_array(VALID_CONNECTIONS, f) == -1) 
					socket_write(fd, "|error| user: "+d+" error: A connection is not available to that client.");
				send_packet(f, txt);
			}
			if(!master()->check_access(c, find_player(d))) {
				socket_write(fd, "|error| user: "+d+" error: You have insuffient access to the file on this port. File="+c);
				return;
			}
			if(member_group(c, "creator") == -1) {
				socket_write(fd, "|error| user: "+d+" error: You have insuffient access to the file on this port.");
				return;
			}
			ar = explode(c, "/");
			for(x=0; x < sizeof(ar)-1; x++) 
				if(file_size("/"+implode(ar[0..x], "/")) != -2) mkdir("/"+implode(ar[0..x], "/"));
			if(file_exists(c))
				cp(c, c+"."+d);
			rm(c);
			x = write_file(c, e);
			if(file_size(c) != size) socket_write(fd, "|error| user: "+d+" error: Filesize did not match!  Filesize result: "+file_size(c)); else
			if(!x)
				socket_write(fd, "|error| user: "+d+" error: write_file failed."); else
			socket_write(fd, "|ok| user: "+d);
			break;
		case "error": 
			sscanf(b, "user: %s error: %s", c, d);
			if(!find_player(c)) { ERROR("Socket <network> Error was not able to received by "+c+".  The error was: "+d); return; }
			message("network", "%^BOLD%^%^RED%^Network tells you: %^RESET%^"+d, find_player(c));
			break;
		case "mkdir":
			sscanf(b, "dir: %s", c);
			mkdir(c);
			break;
		case "ok":
                        sscanf(b, "user: %s", c);
                        if(!find_player(c)) return;
//                        message("network", "%^BOLD%^%^RED%^Network tells you: %^RESET%^Send file was successful.", find_player(c));
			break;
		case "close":
			socket_close(fd);
			ERROR("Socket <network> "+s[fd]["name"]+" closed the link.");
			map_delete(s, fd);
			break;
		case "chat":
			sscanf(b, "line: %s user: %s text: %s", c, d, e);
			CHAT_D->do_raw_chat(c, capitalize(d)+"@"+capitalize(s[fd]["full_name"])+" <"+c+"> "+e);
			return;
			break;
	}
}

int send_packet(string l, string packet) {
	int fd;
	fd = get_fd(l);
	if(!fd) { ERROR("Socket <network> A connection was not available to "+l); return; }
	socket_write(fd, packet);
}

int send_global_packet(string packet) {
	int i;
	mixed *ar;
	i=sizeof(ar = keys(s));
	while(i--) 
	        socket_write(ar[i], packet);
}

void closed(int fd) {
    if (s && s[fd] && s[fd]["name"])
      ERROR("Socket <network> The connection to "+s[fd]["name"]+" was closed unexpectedly.");
    else
      ERROR("Socket <network> A connection was closed unexpectedly.");
}

int get_fd(string loc) {
        int i;
        mixed *k;
        i=sizeof(k = keys(s));
        while(i--)
                if(s[k[i]]["name"] == loc) return k[i];
        return 0;
}

int remove() {
	int i;
	int *k;
	i=sizeof(k = keys(s));
	while(i--) socket_close(k[i]);
}
