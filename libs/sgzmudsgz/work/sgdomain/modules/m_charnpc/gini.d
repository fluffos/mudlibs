// gini.c the body of gini
inherit PMODULES+"m_charnpc";
inherit __DIR__+"gini/old";
private string my_master,my_master_name;
private int my_lastcall; 
private string my_type;  // what is the type of gini
private int my_life;
private string my_id;
private string my_task;
private int i_will_go=0;
void set_type(string s) {
   my_type=s;
}
string get_type() {
   return my_type;
}


void set_lastcall() {
   my_lastcall=time();
}
int get_lastcall() {
  return my_lastcall;
}

void set_my_task(mixed s) {
	my_task=s;
}
mixed get_my_task() {
	return my_task;
}
string get_my_master() {
	return my_master;
}
string get_my_master_name() {
	return my_master_name;
}
void setup()
{  
	my_life=0;
	call_out("my_heart",5);
}
void extra_init()
{
	my_id=this_object()->query_id()[0];
	my_master=CHAR_D->get_char(my_id,"master");
	if(!objectp(find_body(my_master))) {
		i_will_go=1;
		my_type="gini";
		return;
	}
	my_master_name=find_body(my_master)->query_chinese_id();
	my_type=CHAR_D->get_char(my_id,"g_type");
	set_lastcall();
	add_id(my_type);

}

string query_title(string p_id,string c_id)
{
	my_id=this_object()->query_id()[0];
	my_master=CHAR_D->get_char(my_id,"master");
	if(!objectp(find_body(my_master))) {
		my_type="gini";
		i_will_go=1;		
		return "----";
	}

	my_master_name=find_body(my_master)->query_chinese_id();
	my_type=CHAR_D->get_char(my_id,"g_type");

	return my_master_name+"的"+GINI_D->get_msg(my_type,"title");
}

string long()
{  
   return GINI_D->get_msg(my_type,"long");
}
void my_disappear() {
	string act;
	remove_call_out("my_heart");
// this can't use gini_act, because the master may not on line
	act=GINI_D->get_msg(my_type,"disappear");
	this_object()->simple_action(act);
	CHAR_D->remove_char(my_id);
}
void my_return() {
	string act;
	object o;
	if(sizeof(my_task)) {
		GINI_D->gini_act(my_master,"busy");
		return;
	}
	o=find_body(my_master);
	remove_call_out("my_heart");
	GINI_D->gini_act(my_master,"return");
	CHAR_D->remove_char(my_id);
}
void my_come() {
	string act;
	object o,env;
	o=find_body(my_master);
	env=o->query_room();
	GINI_D->gini_act(my_master,"come");
	o->targetted_action(act,this_object());
}

void my_go() {
	string act;
	object o,env;
	o=find_body(my_master);
	env=o->query_room();
	CHAR_D->put_char(my_id,file_name(env));
	GINI_D->gini_act(my_master,"go");
}

void my_call() {
	GINI_D->gini_act(my_master,"call");
}
void my_birth() {
	string act;
	object o,o_l;
        object lamp;
	o=find_body(my_master);
	o_l=present("gini lamp",o);
	while(objectp(o_l)) {
		o_l->remove();
		o_l=present("gini lamp",o);
	}
	act=GINI_D->get_msg(my_type,"birth");
	o->targetted_action(act,this_object());
        lamp=new("/sgdomain/obj/other/lamp");
	lamp->clear_id();
        lamp->set_id(GINI_D->get_msg(my_type,"lamp_id"),GINI_D->get_msg(my_type,"lamp_name"));
        lamp->add_id("gini lamp");
        lamp->set_long(GINI_D->get_msg(my_type,"lamp_long"));
	lamp->set_unit(GINI_D->get_msg(my_type,"lamp_unit"));
	lamp->move(o);
	o->tagetted_action("$T交给$N一"+lamp->query_unit()+
           "$o\n",this_object(),lamp);
}
void my_ask() {
	GINI_D->gini_act(my_master,"ask");
	GINI_D->gini_act(my_master,"know");
	write(GINI_D->what_can_do());
}
void my_hint() {
	string act;
	object o;
	o=find_body(my_master);
	act=GINI_D->get_msg(my_type,"readhint");
	act+="%^H_GREEN%^"+GINI_D->get_hint()+"%^RESET%^";
	o->targetted_action(act,this_object());
}
void my_do(string str) {
	string act;
	object o;
	o=find_body(my_master);
	GINI_D->gini_act(my_master,"do");
	this_object()->responda(str);
}

void my_heart()
{
	object o;
        string p_id;
	remove_call_out("my_heart");
	if(i_will_go||(!CHAR_D->char_exist(my_id))) {
		CHAR_D->remove_char_d(my_id);
		remove();
	}
	call_out("my_heart",random(20)+120);
	my_life++;
	if(my_life<2) return;
	o=find_body(my_master);
	if(!objectp(o)) {my_disappear(); return;}
	if(o->query_room()!=(this_object()->query_room())) {
		my_go();
		return;
        }

	if(sizeof(my_task)) {
		switch(my_task) {
			case "op" : // old player
				my_test_op();
				return;
			default :
				return;
		}
	}

	if((time()-my_lastcall)>600) {
          my_return();
	  return;
        }

        switch(random(5)) {
		case 0:
			my_hint();
			return;
		default :
			GINI_D->gini_act(my_master,"random");
//			my_hint();
			return;

	}
}
