// group guard.h
// by augx@sj  3/25/2002

#define RENASCENCE_TIME		30
#define EXP_DEC			3
#define SKILL_DEC		3
#define MAX_EXP_DEC		200000

void calculate_state()
{
	object ob = this_object();
	mapping my = ob->query_entire_dbase(), skl;
	string *sname;
	int times,i,lmt;

	lmt = (int)ob->query("combat_exp");
	if(lmt<0) lmt=0;
	for(i=to_int(pow(10.0*lmt,0.3333333)); to_int(i*i/10.0*i)<=lmt; i++);
	lmt = i;

	skl = ob->query_skills();
	if (sizeof(skl)) {
		sname = keys(skl);
		foreach (string item in sname) {
			if (!intp(skl[item]) || skl[item]<0) ob->delete_skill(item);
			else if (SKILL_D(item)->type()=="martial" && skl[item]>lmt)
				skl[item] = lmt;
		}
	}

	if( ob->query("int")*10 < ob->query_skill("literate") )
		ob->set_skill("literate",ob->query("int")*10);

	my["max_jing"] 	= (200 + (my["con"] + my["int"]) * 16) * 5/6;
	my["max_qi"] 	= (200 + (my["con"] + my["str"]) * 16) * 1/1;
	my["eff_jingli"]= (200 + (my["con"] + my["dex"]) * 16) * 2/3;
	my["max_neili"]	= (ob->query_skill("force")-ob->query_temp("apply/force"))*8
				+ ob->query("combat_exp")/1000 + ob->query_temp("apply/neili");

	times = ( (ob->query_skill("literate",1)+1) + (ob->query_skill("force",1)/2+1) ) / 2;

	my["max_jing"]	= my["max_jing"]	* times / 25;
	my["eff_jingli"]= my["eff_jingli"]	* times / 25;
	my["max_qi"] 	= my["max_qi"]		* times / 25;

	my["eff_jing"]	= my["max_jing"];
	my["jing"]	= my["max_jing"];
	my["eff_qi"]	= my["max_qi"];
	my["qi"]	= my["max_qi"];
	my["jingli"]	= my["eff_jingli"];
	my["neili"]	= my["max_neili"];
}

void create()
{
	int i,j;
	mixed name;

	seteuid(getuid());

	if ( restore() ) {
		set_name( query("name"), ({ query("id"),query("id1"),query("id2"),"group guard","guard" }));
		setup();
		calculate_state();
		//if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
		//if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();

		if( !clonep(this_object()) ) call_out("dest",5);
		return;
	}

	i = random(4);
	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"] + ({ "group guard" , "guard" }));
	set("gender", (i==0?"女性":"男性"));
	set("age", 20 + random(30));
	set("long", "这是位威风凛凛的保镖，身体壮实，一看就是武功高手！\n");
	set("unique", 1);
	set("location", 1);
	set("no_get", 1);
	set("no_quest", 1);

	i = 100;
	set("str", j=(10+random(24)) );	i -= j;
	set("dex", j=(10+random(24)) );	i -= j;
	set("con", j=(10+random(24)) );	i -= j;
	set("int", i );

	set("shen_type", 1);
	set("shen", 0);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);

	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("literate", 100);

	/*
	set("chat_chance", 3);
 	set("chat_msg", ({
 		"保镖说道：“你们都给我老实点，不要惹是生非！”\n",
 	}) );
 	*/

	set("no_clean_up",1);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	calculate_state();

	if( !clonep(this_object()) ) call_out("dest",5);
}

void dest()
{
	destruct( this_object() );
}

/*
void kill_ob(object ob)
{
	return;
}
*/

int accept_fight(object ob)
{
	if( ob->query("group/id") != query("group/id") ) {
		command("say 在下正在工作之中，恕不奉陪。");
		return 0;
	}
	return 1;
}

void die()
{
	int i;
	int *sv;
	string *sk;
	string ob_file;
	object room,killer;

	killer = query_temp("last_damage_from");
	if( objectp(killer) && userp(killer) && killer->query("group") && killer->query("group/id")==query("group/id") ) {
		rm( base_name(this_object()) + ".lpc" );
		rm( query_save_file() + ".o" );
		GROUP_D->mirror_file( base_name(this_object())+".lpc","","defile" );
		GROUP_D->mirror_file( query_save_file()+".o","","defile" );

		if( !query("startroom") ) return;
		if( !(room=find_object(query("startroom"))) )
			if( !(room=load_object(query("startroom"))) )
				return;

		ob_file = replace_string( base_name(this_object())+".lpc" , "/d/group/"+query("group/id")+"/", "" );
		if( !GROUP_D->create_room(
			base_name(room)+".lpc",
			room->query("short"),room->query("long"),
			GROUP_D->get_room_exits(room),replace_string(GROUP_D->get_room_objects(room),"__DIR__`"+ob_file+"`:1,",""),
			room->query("group1"),room->query("group2"),
			room->query("outdoors")?0:1 )
		)
			return;

		set("startroom","");
		GROUP_D->encrypt_file(base_name(room)+".lpc");
		GROUP_D->update_room(base_name(room)+".lpc");

		::die();
		return;
	}

	if ( mapp(query_skills()) ) {
		sv = values( query_skills() );
		sk = keys( query_skills() );
		for(i=0;i<sizeof(sv);i++)
			if( sv[i]>0 ) set_skill(sk[i],sv[i]-SKILL_DEC);
	}

	i = query("combat_exp")* EXP_DEC/100 + 1;
	i = MIN(i,MAX_EXP_DEC);
	if(i<100) i=0;
	add("combat_exp", -i);
	if( query("combat_exp") < 0 ) set("combat_exp",0);

	this_object()->clear_condition();
	this_object()->remove_all_killer();

	calculate_state();
	save();

	if( !(room=find_object("/d/group/emptyroom")) )
		room = load_object("/d/group/emptyroom");
	tell_room(environment(this_object()),"\n"+name()+"惨叫一声，逃走了！\n");
	move(room);
	call_out("do_renascence",RENASCENCE_TIME,room);
}

void do_renascence(object room)
{
	object sroom;
	if( !room || environment(this_object())!=room || !query("startroom") ) return;
	if( !(sroom=find_object(query("startroom"))) )
		if( !(sroom=load_object(query("startroom"))) )
			return;
	move(sroom);
	tell_room(sroom,CYN+name()+"快步走了过来。"NOR"\n");
}

int skill_count()
{
	int i,j,k;
	mapping skills;
	int * sv;

	skills = query_skills();
	if( !mapp(skills) ) return 0;
	sv = values(skills);
	j = sizeof(sv);

	for(i=0,k=0;i<j;i++)
		k += sv[i];

	return k;
}

int save()
{
	if( !clonep(this_object()) ) return 0;
	delete("clone_by_wizard");
	return ::save();
}

void init()
{
	::init();
}
