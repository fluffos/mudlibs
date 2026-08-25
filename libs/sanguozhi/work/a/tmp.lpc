void asf(string a) {
	object o;
	o=load_object("/a/"+a);
	o->trans();
	write(a);
}
void move_maker(string a) {
       string rm,nm;
       string *mm;
	int s;
	rm=CHAR_D->get_char(a,"shd_room");
	mm=explode(rm,"/");
	s=sizeof(mm);
	nm="/a/"+mm[s-2]+"/"+mm[s-1];
	CHAR_D->set_char(a,"shd_room",nm);
	write(a);	
	
}
void create() {
	string *ars;
/*	ars=AREA_D->list_areas();
	foreach(string s in ars) {
		call_out("asf",random(100),s);
	} */
	ars=CHAR_D->check_char("is_maker",1);
	foreach(string s in ars) {
		call_out("move_maker",random(100),s);
	}
}
