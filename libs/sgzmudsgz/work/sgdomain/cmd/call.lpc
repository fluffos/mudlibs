// call.c  //招随从 Jan 1999
int no_need_hp()
{ // this is used if player doesnt have food and drink
	return 1;
}
void pop_menu()
{
    new(PDOMAIN+"menu/qb")->start_menu();
}
void create_qb(string p_id)
{
    string n_id=p_id+" qb";
	CHAR_D->add_char(n_id);
    CHAR_D->set_char(n_id,"my_master",p_id);
    CHAR_D->set_char(n_id,"name",
        CHAR_D->get_char(p_id,"name")+"的亲兵");
    CHAR_D->set_char(n_id,"is_tmp",1);
    CHAR_D->set_char(n_id,"is_qb",1);
    CHAR_D->set_char(n_id,"body","qb");
    return;
}

void call_guanjia(string p_id) {
	object o_h;
	string *gjs,gj;
	object o_gj;
	o_h=SGHOME(p_id);
	gjs=o_h->check_npc("pos","gj");
	if(!sizeof(gjs)) {
		write("你现在还没有雇佣管家。\n");
		return;
	}
	gj=gjs[0];
	o_gj=o_h->load_npc(gj);
	if(environment(o_gj)!=(this_body()->query_room())) {
		o_gj->move(environment(this_body()));
		o_gj->simple_action("$N风风火火地跑了过来。\n");
	}
	o_gj->special_answer(this_body(),"order");
	return;

}
void call_suicong(string p_id) {
	object o_h;
	string *gjs,gj;
	object o_gj;
	o_h=SGHOME(p_id);
	if(!objectp(o_h)) {
		write("你现在还没有家，哪里来的随从。\n");
		return;
	}
	gjs=o_h->check_npc("pos","sc");
	if(!sizeof(gjs)) {
		write("你现在还没有雇佣随从。\n");
		return;
	}
	gj=gjs[0];
	o_gj=o_h->load_npc(gj);
	if(environment(o_gj)!=(this_body()->query_room())) {
		o_gj->move(environment(this_body()));
		o_gj->simple_action("$N风风火火地跑了过来。\n");
	}
	o_gj->special_answer(this_body(),"order");
	return;

}

void start(string arg)
{
    	object env,o;
    	mixed myarmy;
	string p_id,n_id,p_room;
    	p_id=this_body()->query_id()[0];
    	env=this_body()->query_room();
        this_body()->simple_action("$N回头喊了一声：来人哪！");

	if((env->is_home())&&(env->get_owner()==p_id)) {
		call_guanjia(p_id);
		return;
	}
	call_suicong(p_id);
	return ;
/*
    	p_room=file_name(env);
	myarmy=CHAR_D->get_char(p_id,"myarmy");
	if(!myarmy) myarmy=([]);
	if(!myarmy["qbnum"])
	{
                write("你似乎没有随从可以使唤。\n");
		return;
	}
	create_qb(p_id);
    	n_id=p_id+" qb";
    	CHAR_D->put_char(n_id,p_room);
    	o=CHAR_D->find_char(n_id);
	if(!o)
	{
                write("奇怪，怎么没人？\n");
		CHAR_D->remove_char(n_id);
		return;
	}
	o->simple_action("$N闪身进入。\n");
        o->targetted_action("$N对$T躬身道：$R有何吩咐？\n",this_body());
	call_out("pop_menu",2);
    	return; */
}
