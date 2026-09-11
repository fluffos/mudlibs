string p_type;
string p_owner;

void set_type(string t) {
	p_type=t;
}
string get_type() {
	return p_type;
}
void set_owner(string id) {
	p_owner=id;
}

string get_owner() {
	return p_owner;
}

int is_home() {
	return 1;
}

string get_id() {
	string f_name=file_name(this_object());
	string *fs;
	fs=explode(f_name,"/");
	return fs[<1];
}


int get_status() {
	int p_status;
	string p_id;
	object o_h=SGHOME(p_owner);
	p_id=get_id();
	p_status=o_h->get_room(p_id,"status");
	if(!p_status) {
		p_status=100; // new
		o_h->set_room(p_id,"status",p_status);
	}
	return p_status;
}
void set_status(int s) {
	string p_id;
	object o_h=SGHOME(p_owner);
	p_id=get_id();
	o_h->set_room(p_id,"status",s);
}
int ruin() {
	int p_status=get_status();
	p_status-=random(3);
	if(p_status<10) p_status=10; // the worst situation;
	set_status(p_status);
	return p_status;	
}
void repair() {
	set_status(100);
}
