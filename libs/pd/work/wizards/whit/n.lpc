#define CHAT_D "/daemon/chat"
#define UID_FNETWORK "FNetwork"
int in_use;

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

    s = socket_create(2, "read_callback");
    if (s < 0) {
	return;
    }

    error = socket_bind(s, 5000);
    if (error != 1) {
	socket_close(s);
	return;
    }
    write("");
}

int read_callback(string s) {
    string fname;
    if(s=="FTP:::START") {
	in_use=1;
	write_file("trans.txt", s);
	write("Starting Transfer.\n");
	return 1;
    }
    if(s[0..9]=="FTP:::END|") {
	fname=s[10..];
	cp("down_load_tmp", fname);
	in_use=0;
	return 1;
    }
    if(s[0..8]=="MK_DIR:::") {
	mkdir(s[9..]);
	write("Forming Directory: "+s[9..]);
	return 1; 
    }
    if(in_use) {
	write_file("down_load_tmp", s);
	return 1;
    }
}

