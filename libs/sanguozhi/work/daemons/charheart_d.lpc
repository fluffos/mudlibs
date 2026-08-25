// charheart_d.c
// by fire@lima on May 23, 1999
// this is used to control the heart of all chars
// used to replace the old call_out heart in each char obj
#define MAX_FRESH 500
nosave protected object *obj_char,*obj_maker,*obj_guy,*obj_boy,*obj_guard;
nosave protected int my_t;

void act(object *obs){
	int size;
    int num,i;
	object ob;
	size=sizeof(obs);
	if(size==0) return;
    num=size/10;
	if(num>10) num=10;
	if(num==0) num=1;
	for(i=0;i<num;++i) {
		ob=obs[random(size)];
		if(objectp(ob)) {
			if(clonep(ob)) {
//                                tell_user("fire",ob->short());
				ob->my_heart();
			}
		}
	}
}
void ack_guy() {
	string p_area;
	string p_id;
	object o;
	int i;
	for(i=0;i<4;++i) {
		p_area=AREA_D->pick_area();
		if(random(2)) 
		p_id=p_area+" boy";
		else
		p_id=p_area+" "+"/sgdomain/event/ev_guy"->get_type();
		o=CHAR_D->find_npc_char(p_id);
		if(!objectp(o)) continue;
		o->my_heart();
//		tell_user("fire",p_id+"\n");
	}
	
}
void ack_char() {
	string p_id;
	int i,sum;
	int j;
	mixed body;
	object o;
//	sum=sizeof(CHAR_D->list_chars());
//	sum/=100;
	sum=20;
	j=0;
	for(i=0;i<sum;++i) {
		p_id=CHAR_D->pick_char();
		o=CHAR_D->find_npc_char(p_id);
		if(!objectp(o)) continue;
		body=CHAR_D->get_char(p_id,"body");
		if(stringp(body)&&(body!="maker")) continue;
		o->my_heart();
		j++;
		if(j>4) return;
//		tell_user("fire",p_id);
	}
}
void my_heart() {
    call_out("my_heart",2);
	my_t++;
	if(my_t>MAX_FRESH) my_t=0;

//	if(my_t==1) {obj_char=children("/sgdomain/modules/m_charnpc" ); return;}
//	if(my_t==60) {obj_maker=children("/sgdomain/modules/m_charnpc/maker"); return;}
//	if(my_t==120) {obj_guy=children("/sgdomain/modules/m_charnpc/guy"); return;}
//	if(my_t==180) {obj_boy=children("/sgdomain/modules/m_charnpc/boy"); return;}
	if(my_t==30) {obj_guard=children("/sgdomain/modules/m_charnpc/guard"); return;}

	switch(random(10)) {
	case 0:
		act(obj_guard);
		return ;
	case 1:
	case 2:
		ack_guy();
		return ;
	default : 
		ack_char();
		return ;
	}
}
void create()
{
	// nothing here yet
	my_t=0;
//	set_heart_beat(1);
	call_out("my_heart",1);
	return;
}
void remove() {
	remove_call_out("my_heart");
}
int clean_up() {
   return 0; // means never_again
}
