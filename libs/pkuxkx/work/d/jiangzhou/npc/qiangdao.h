#include <ansi.h>
void move();
int ask_fight();
int ob_escape();
int esc2(object ob);
void init()
{
	object ob=this_object();
	add_action("do_none", "steal");
	add_action("do_none", "attack");
	add_action("do_none", "beg");
	set("hyw_npc",1);
	set("random_npc",1);
	if (ob->query("task_type")==5&&ob->query("killername")==this_player()->name())
	call_out("esc2",1,ob);
	else if(random(3)>1&&this_player()->query("id") == ob->query("killer"))  
	{
		kill_ob(this_player());
		exer();
	}
}
int esc2(object ob)
{
	object where;
	while (	!objectp(where) || 
			!where->isroom()||
			TASK_D->place_belong(where)=="不明区域"||
			base_name(where) == "/adm/daemons/taskd"||
			where==environment(ob))
	where = TASK_D->random_place();
	message_vision("$N远远看到"+this_object()->query("killername")+"，赶紧迅速离去。\n",this_object());
	command("rumor "+ob->query("name")+"被"+ob->query("killername")+"发现行踪，决定远走天涯，隐姓埋名。");
	this_object()->move(where);
}
int ob_escape()
{
	object ob=this_object();
	if (ob->query("escaped")<5)
	{
		ob->start_busy(0);
		if (ob->query("eff_jing")>ob->query("max_jing")*4/5)
		ob->set("eff_jing", query("max_jing"));
		else
		ob->set("eff_jing", query("max_jing")*4/5);
		if (ob->query("eff_qi")>ob->query("max_qi")*4/5)
		ob->set("eff_qi", query("max_qi"));
		else
		ob->set("eff_qi", query("max_qi")*4/5);
		if (ob->query("neili")>ob->query("max_neili")*2/3)
		ob->set("neili", query("max_neili"));
		else
		ob->set("neili", query("max_neili")*2/3);
		message_vision(HIW+"$N跳出战团，狼狈避走。\n"+NOR,ob);
        ob->random_move();
        if (random(2))
        ob->random_move();
		ob->add("escaped",1);
		remove_call_out("check_status");
		call_out("check_status",3);
		return 1;
    }
	if (!ob->query("wont_escape"))
	{
		ob->set("wont_escape",1);
		message_vision(HIR+"$N见退无可退，决定横下心来应战。\n",ob);
		return 1;
	}
    return 1;
}

int message_show_killer(object me)
{
	if (me&&living(me)&&me->query_temp("hyw/2ndname")&&me->query_temp("hyw/2ndplace"))
	tell_object(me,"有江湖小道消息，据说"+me->query_temp("hyw/2ndname")+"正在"+me->query_temp("hyw/2ndplace")+"隐姓埋名。\n");
	return 1;
}

int check_status()
{
	object ob = this_object(),me,where;
	string name,*tmp,*pinying,loc;
	if (!ob->query("killer"))
	return 1;
	if (!me=find_player(ob->query("killer")))
	return 1;
	if (ob->query("task_type")!=4&&ob->query("task_type")!=3)
	return 1;
	if (ob->is_fighting(me)&&ob->query("task_type")==4&&
        (ob->query("qi") <=(ob->query("max_qi")/100)*50 || ob->query("eff_qi") <=(ob->query("max_qi")/100)*50 
        || ob->query("jing") <= (ob->query("max_jing")/100)*50 || ob->query("eff_jing") <= (ob->query("max_jing")/100)*50))//轻功高手
	return ob_escape();
    if (!ob->query("hide")&&ob->query("task_type")==3&&ob->is_fighting(me)&&(ob->query("qi")<ob->query("max_qi")||ob->query("jing")<ob->query("max_jing")))
	{
		name=NAME_D->create_name();
		tmp=explode(name,"@");
		pinying=explode(tmp[1]," ");
		me->set_temp("hyw/2ndname",ob->query("name"));
		set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
		ob->delete("title");
		if (ob->query("gender")=="女性")
		ob->set("long","她是韩家的仇人，曾被"+me->query("name")+"追杀，现在隐居于此地。\n");
		else
		ob->set("long","他是韩家的仇人，曾被"+me->query("name")+"追杀，现在隐居于此地。\n");
		while (	!objectp(where) || 
				!where->isroom()||
				TASK_D->place_belong(where)=="不明区域"||
				base_name(where) == "/adm/daemons/taskd"||
				where==environment(ob))
		where = TASK_D->random_place();
		ob->set("hide",1);
		ob->move(where);
		me->set_temp("hyw/2ndplace",TASK_D->place_belong(where));
		tell_object(me,me->query_temp("hyw/2ndname")+"稍稍接战，立刻退走。\n");
		call_out("message_show_killer",random(4)+5,me);
		return 1;
	}
	remove_call_out("check_status");
	call_out("check_status",3);
	return 1;
}

void leave()
{
	object me,ob = this_object();
	if (!ob->query("killer"))
	{
		message_vision(HIR+"$N一闪身就不见了。\n" NOR,ob);
		destruct(ob);
		return;
	}
	if (!me=find_player(ob->query("killer"))) 
	{
		message_vision(HIR+"$N一闪身就不见了。\n" NOR,ob);
		destruct(ob);
		return ;
	}
    call_out("leave",30);
	return;
}

void do_copy(object me)
{
	object ob,robber,armor,*npc_random_armor;
	mapping skills, hp_status, skill_status;
	string *sname;
	int factor,exp,count,tempskill,lianxu,f;
	ob = this_object();
	tempskill = 0;
	f=random(11);
	if (me->query("hsz_auto"))
	{
		f+=10;
	}
	me->set_temp("hyw/factor",f);
	exp = me->query("combat_exp");
	tempskill = to_int(pow(exp/100,0.333)*10*(95+f)/100);
	if (tempskill==0)
	tempskill=10;
	skills = ob->query_skills();
	for (int i=0;i<sizeof(skills);i++)
	skills[keys(skills)[i]] = tempskill;
	hp_status = me->query_entire_dbase();
	ob->set("str", hp_status["str"]+random(2));
	ob->set("int", hp_status["int"]+random(2));
	ob->set("con", hp_status["con"]+random(2));
	ob->set("dex", hp_status["dex"]+random(2));
	ob->set("combat_exp",me->query("combat_exp")/100 * (95 + f));// exp浮动较大，0.8至1.2倍玩家经验 Zine
	ob->set("qi", hp_status["max_qi"]);
	ob->set("eff_qi",hp_status["max_qi"]);
	ob->set("max_qi",hp_status["max_qi"]);
	ob->set("max_neili", hp_status["max_neili"]);
	ob->set("neili", hp_status["max_neili"]);
	ob->set("max_jingli", hp_status["max_jingli"]);
	ob->set("jingli", hp_status["jingli"]);
	ob->set("level",me->query("level")+random(10));
	if (ob->query("jing") < 3000)
	{
		ob->set("eff_jing",3000);
		ob->set("max_jing",3000);
		ob->set("jing",3000);
	}
	if (ob->query("qi") < 3000)
	{
		ob->set("eff_qi",3000);
		ob->set("max_qi",3000);
		ob->set("qi",3000);
	}
	if (ob->query("qi")>20000)//为武当长气血的一点点福利 Zine
	{
		ob->set("eff_qi",20000);
		ob->set("max_qi",20000);
		ob->set("qi",20000);
	}
	for (int i=1;i<10;i++)
	{
		armor=new("/obj/gem/armor");
		armor->gen_armor(i);
		armor->set("no_get",1);
		if (random(10)>4)
        armor->move(ob);
        else
		destruct(armor);
	}
	npc_random_armor=all_inventory(ob);
	if (random(100)>74)
	{
		npc_random_armor[random(sizeof(npc_random_armor))]->delete("no_get");
		ob->set("gene_armor",1);
	}
	command("remove armor 2");
	command("wear all");
}
//死亡管理
void die()
{
	object han,ob,killer,env;
	ob=this_object();
	env=environment(ob);
	if(!objectp(killer = get_damage_origin_object()) || killer->query("id")!= ob->query("killer"))
	{
		message_vision(HIR+ob->name()+"长笑一声：嘿嘿，你有帮手，爷不奉陪了。\n"NOR,ob);
		destruct(ob);
		return;
	}
	killer=ob->get_damage_origin_object();
	if(killer->query_temp("hyw/start"))
	{
		killer->set_temp("hyw/done",1);
		if (ob->query("task_type")==3)
		killer->set_temp("hyw/spec_task",1);
		if (ob->query("task_type")==2)
		{
			if (!han=present("han yuanwai",env))
			{
				killer->delete_temp("hyw/done");
				tell_object(killer,"你不禁后悔不迭，韩员外要你当着他的面杀死"+ob->query("name")+"，而你早把这事忘在脑后了。\n");
			}
            else
            {
				if (!han->query("is_hanyuanwai"))
				{
					killer->delete_temp("hyw/done");
					tell_object(killer,"你不禁后悔不迭，韩员外要你当着他的面杀死"+ob->query("name")+"，而你早把这事忘在脑后了。\n");
                }
				else
				{
					message_vision("从$N身上掉了出来一颗"+HIC+"天★日魂"+NOR+"。\n"+NOR,ob);
					message_vision("$N两眼放光，一把抢过$n"+NOR+"手中的"+HIC+"天★日魂"+NOR+"。\n",han,killer);
					message_vision("$N将手中"+HIC+"天★日魂"+NOR+"放进了锦囊。\n",han);
                }
            }
        }
        if ((ob->query("task_type")==3&&!ob->query("gene_armor"))||(random(100)>66 &&!ob->query("gene_armor")))
        {
            GEM_D->drop(this_object(),killer);
            ::die();
            return;
        }
    }
    ::die();
}

void unconcious() 
{   
	if (this_object()->query("task_type")==2)
	return ::unconcious();
	else
	call_out("die",1);
}

int do_none()
{
    return 1;
}
int ask_fight()
{
	if (this_object()->query("killer")==this_player()->query("id")) 
	{
		if (environment(this_object())->query("no_fight")) 
		{
			command("say 此处比武多有不便，你且随我来！");
			random_move();
		}
		else command("say 要打便打，不必多言！");
	} 
	else command("say 就你也配跟我讨教功夫？！");
	return 1;
}
