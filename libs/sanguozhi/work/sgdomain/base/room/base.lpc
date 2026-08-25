#define PICPATH "/sgdomain/base/pic/"
string p_area;
string f_id;
string r_id;
string p_type;
// all rooms of bases should use this function to
// initinize
void base_init() {

}
void init_para(string a_id,string fd,string rid,string t) {
	p_area=a_id;
	f_id=fd;
	r_id=rid;
	p_type=t;
	base_init();
}
string get_type() {
	return p_type;
}

int is_base() {
	return 1;
}

string get_area() {
	return p_area;
}

string get_f_id(){
	return f_id;
}
string get_r_id() {
	return r_id;
}

int get_status() {
	int p_status;
	string p_id;
	object o_h=SGBASE(p_area,f_id);
	p_status=o_h->get_room(r_id,"status");
	if(!p_status) {
		p_status=100; // new
		o_h->set_room(r_id,"status",p_status);
	}
	return p_status;
}
void set_status(int s) {
	object o_h=SGBASE(p_area,f_id);
	o_h->set_room(r_id,"status",s);
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

string get_base() {
	return p_area+"_"+f_id;
}
object get_master() {
	return SGBASE(p_area,f_id);
}
string get_base_room_long() {
	object oh;
	int level;
	string fname;
	oh=get_master();
	level=oh->get_level();
	fname=PICPATH+f_id+level+".pic";
	return read_file(fname);
}