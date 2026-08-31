//  New FTP System

#define fail(x) return notify_fail(x+"\n")
#define NETWORK "/daemon/network/network"
#define SOCKET "/daemon/network/socket"
int recurse(string, string);

int cmd_ftp(string s) {
	string a,b;
	int size;
	if(!s || s=="") fail("Syntax: <ftp [location] [file or dir]>");
	if(sscanf(s, "%s %s", a,b)!=2) fail("Syntax: <ftp [location] [file or dir]>");
	if(!SOCKET->get_fd(a)) fail("Could not find a connection for that location.");
	if(b == "*") b="";
	b=resolv_path("cwd", b);
	size=file_size(b);
	seteuid(geteuid(previous_object()));
	switch(size) {
		case -2:
			recurse(b, a); 
			break;
		case -1:
			fail("ftp: cannot find file");
			break;
		case 0:
			fail("ftp: cannot send blank file");
			break;
		default:
			"/daemon/network/network"->send_file(this_player(), a, b, read_file(b));
			break;
	}
		return 1;
}

int recurse(string s, string loc) {
	int i,x;
	string *dir, *dir2 = ({});
	i=sizeof(dir = get_dir(s+"/"));
	while(i--) {
		write("Current file: "+s+"/"+dir[i]);
		switch(file_size(s+"/"+dir[i])) {
			case -2:
				SOCKET->send_packet("|mkdir| dir: "+s+"/"+dir[i]);
				recurse(s+"/"+dir[i], loc);
				break;
			case -1: 
			case 0:
				break;
			default:
				write("File: "+s+"/"+dir[i]);
				NETWORK->send_file(this_player(), loc, s+"/"+dir[i], read_file(s+"/"+dir[i]));
				break;
		}
	}
	return 1;
}
