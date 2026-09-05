// tong-ren.c 铜人

inherit NPC;
//inherit F_CLEAN_UP;

void create()
{
	set_name("铜人", ({ "tong ren","tong","ren"}) );
	set("gender", "男性" );
	set("age", 30);
	set_weight(200000);
	set("long", "一个练功用的比武铜人，制作精巧，如同真人一般。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 2000);
	set("eff_qi", 2000);
	set("qi", 2000);
	set("max_jing", 800);
	set("jing", 800);
	set("max_jing", 800);
	set("eff_jing", 800);
	set("jing", 800);


	set("max_neili", 1000);
	set("neili", 1000);


	set("combat_exp", 100000);

	set_skill("force", 80); 
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

//	set("fight_times", 0);	

	set("shen_type",1);set("score",200);setup();
        
	carry_object("/d/quanzhen/npc/obj/longsword");
	carry_object("/d/quanzhen/npc/obj/blade");
	carry_object("/d/quanzhen/npc/obj/cloth")->wear();

}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

/*	if (me->query("damaged"))
		return notify_fail("这个铜人已经被打坏了！\n");	

	if (random(me->query("fight_times")) >= 10) {
		me->set("damaged", 1);
		return notify_fail("这个铜人已经被打坏了！\n");	
	}
*/
	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("你刚跟这个铜人练过功！\n");		

	me->set("last_fighter", ob->query("id"));
//	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 60 , me);	

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], (int)(skill_status[sname[i]]));
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);

		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("force_factor",     hp_status["force_factor"]);
		me->set("combat_exp",(int)(hp_status["combat_exp"]));

	return 1;
}

void init()
{
	add_action("do_wield", "weapon");
	add_action("do_unwield", "unweapon");
}


void renewing(object me)
{
	me->delete("last_fighter");
}

int do_wield(string arg)
{
	object me = this_object();
	object obj;
	string str;

	if(!arg)
		return notify_fail("装备什么？\n");

	if( !objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( obj->query("equipped") )
		return notify_fail("你已经装备著了。\n");

	if( obj->wield() ) {
		if( !stringp(str = obj->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
		message_vision(str, me, obj);
		return 1;
	} 

	return 0;
}


int do_unwield(string arg)
{
	object me = this_object();
	object ob;
	string str;

	if( !arg ) return notify_fail("你要卸下什麽装备？\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("你并没有装备这样东西作为武器。\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}
