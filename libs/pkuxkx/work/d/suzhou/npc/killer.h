void delete_init_num(object me)
{
        me->delete("init_num");
        return;
}
int is_stupid_long()
{
	return 1;
}
void init()
{
	add_action("do_drill","drill");
	add_action("do_guide","guide");
}
void relay_message(string msgclass, string msg)
{
    object ob=this_object();
    object me=query("owner");
	string busy="否",target="无";
	if (ob->is_busy())
	busy="是";
	if (objectp(query("uni_target"))&&stringp(query("uni_target")->name()))
	target=query("uni_target")->name()+"("+query("uni_target")->query("id")+")";
	if (query("starting_drill")&&environment(me)==environment(ob)&&living(me))
	{
		if (time()-query("show_status")>2)
		{
			set("show_status",time());
			tell_object(me,"\n【<"+HBWHT+HIB+ob->name()+"简明状态"+NOR+">"+HIR+"气:"+NOR+ob->query("qi")+"/"+ob->query("eff_qi")+HIC+"内:"+NOR+ob->query("neili")+HIY+"忙:"+NOR+busy+"对手:"+target+"】\n");
		}
		tell_object(me,replace_string(msg,"你",ob->name())+"\n");
	}
}

int do_guide(string arg)
{
	int flag=0;
	object me=this_player(),ob=this_object(),target;
	string *legal_cmds=({"perform","exert","yun","wield","unwield","wear","remove","eat","throw"});
	if (me!=query("owner"))
	return 0;
	if (!arg)
	{
		tell_object(me,"你想指点"+query("name")+"什么？\n");
		return 1;
	}
	if (!living(ob))
	{
		tell_object(me,ob->name()+"已经这样了，还指点什么啊？\n");
		return 1;
	}
	for (int i=0;i<sizeof(legal_cmds);i++)
	{
		if (strsrch(arg,legal_cmds[i])!=-1)
		flag=1;
	}
	if (!flag&&!wizardp(me))
	{
		tell_object(me,"你能指点"+ob->name()+"做的，只有perform,exert,yun,wear,remove,throw,eat,wield或者unwield这些战斗相关的命令。\n");
		return 1;
	}
	if (!objectp(target=query("uni_target")))
	{
		tell_object(me,ob->name()+"现在没有对手，指点也是白费。\n");
		return 1;
	}
	if (!present(target,environment(ob)))
	{
		tell_object(me,ob->name()+"现在没有对手，指点也是白费。\n");
		return 1;
	}
	command(arg);
	tell_object(ob,HIW+me->name()+HIW+"指导"+ob->name()+"，此刻战斗应该用"+HBRED+WHT+arg+NOR+HIW+"，更加合理。\n"+NOR);
	return 1;
}
int kill_eachother(object npc,object ob,object me)
{
	if (npc&&ob&&environment(npc)==environment(ob)&&!npc->is_fighting(ob))
	{
		npc->kill_ob(ob);
		ob->kill_ob(npc);
	}
	remove_call_out("kill_eachother");
	call_out("kill_eachother",2,npc,ob,me);
	return 1;
}
int npc_show_up(object me,object ob)
{
	object npc=new(__DIR__"antikiller");
	npc->move(environment(ob));
	npc->set("uni_target",ob);
	ob->set("uni_target",npc);
	ob->set("chat_chance", 0);
	ob->set("starting_drill",1);
	npc->do_copy(me);
	kill_eachother(npc,ob,me);
	tell_room(environment(ob),HIR"这时"+npc->name()+"跳出来，不由分说，和"+ob->name()+"打了起来。\n"NOR,({me}));
	return 1;
}
int do_drill()
{
	object me=this_player(),ob=this_object();
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (query("owner")!=me||me->query_temp("shenlong_zhanglao/target_ob")!=ob)
	{
		me->add_busy(3);
		command("say 干嘛？");
		return 1;
	}
	if (environment(this_object())->query("no_fight")) 
	{
		tell_object(me,"这里训练根本施展不开，换个地方吧。\n");
		return 1;
	}
	if (me->query_temp("shenlong_zhanglao/start_drill")==ob)
	{
		tell_object(me,"你不是已经开始训练了吗？\n");
		return 1;
	}
	me->set_temp("shenlong_zhanglao/start_drill",ob);
	tell_room(environment(ob),HIB+me->name()+HIB+"遵照神龙长老的意思，开始训练"+ob->name()+"。\n"NOR,({me}));
	remove_call_out("npc_show_up");
	call_out("npc_show_up",1+random(2),me,ob);
	tell_object(me,BLINK+HIC+"你可以用guide命令指导"+ob->name()+"战斗，比如guide yun qi,guide perform dagger.yingxiong等等。\n"+NOR);
	return 1;
}
void do_leave()
{
        if(!this_object())
                return;
        message_vision("$N看了看天色，自言自语道：“天色不早了，得去干活了。”\n", this_object());
        destruct(this_object());
}
int ask_fight()
{
        if (this_object()->query("owner")==this_player()) {
        	if (environment(this_object())->query("no_fight")) 
        	{
        		command("say 此处教导比武有些不便，我们换一处地方来！");
        		random_move();
        	}
        	else command("say 这里不是挺好吗？");
        } else command("taoyan");
        return 1;
}
int ask_rumors()
{
        if (this_object()->query("owner")==this_player())
                command("say 听说有个叫"+this_player()->query("name")+"的会来指导(drill)我，就是你么？");
        else
                command("say 听说闯王宝藏里面有不少好东西，嘿嘿～～嘿嘿～～");
        return 1;
}

varargs void wield_weapon(string weapon)
{
        if(!weapon && query("use_weapon1"))
                wield_weapon(query("use_weapon1"));
        if(!weapon && query("use_weapon2"))
                wield_weapon(query("use_weapon2"));
        if(!weapon)
                return;
        switch(weapon)
        {
        case "sword":
                carry_object("/clone/weapon/changjian")->wield();
                break;
        case "blade":
                carry_object("/clone/weapon/gangdao")->wield();
                break;
        case "staff":
                carry_object("/clone/weapon/gangzhang")->wield();
                break;
        case "whip":
                carry_object("/clone/weapon/changbian")->wield();
                break;
        case "zhen":
                set("gender", "无性");
                carry_object("/d/city/obj/flower_shoe")->wear();
                carry_object("/d/city/obj/pink_cloth")->wear();
                carry_object("/d/city/obj/goldring")->wear();
                carry_object("/d/city/obj/necklace")->wear();
                carry_object("/d/quanzhou/obj/xiuhua")->wield();
                carry_object("/d/riyuejiao/obj/xiuhuajia");
                break;
        case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
                break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
        case "hammer":
                carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
                break;
        default:
        }
        return;
}
int generate(object where)
{
    where = MAP_D->random_place();
    return 1;
}
int whisper_to_me(object me,object killer)
{
    command("whisper "+ me->query("id")+ " 你果然不同凡响啊，我有个兄弟"+killer->query("name")+"("+killer->query("id")+")，在"+MAP_D->place_belong(environment(killer))+"等候指导，人送绰号"+killer->query("nickname")+"！" );
	command("wave");
    return 1;
}
int tell_owner()
{
	object killer,where;//盗宝人的killer
	int newkiller,i;
	object me=query("owner");
	if (!me||!living(me))
	return 1;
	if (environment(me)!=environment(this_object()))
	return 1;
	if (this_object()->query("hyd/step") != 5)
	{
		newkiller = this_object()->query("hyd/step") + 1;
		killer=new(__DIR__"killer"+newkiller);
		killer->do_copy(me);
//过滤非法任务地点和不明区域 by segate@pkuxkx
	while (!objectp(where) || 
			!where->isroom()||
			MAP_D->place_belong(where)=="不明区域"||
			base_name(where) == "/adm/daemons/taskd")
			{
				me->set_temp("map/keepsameregion",1);
				where = MAP_D->random_place_ex(me);
			}
	me->set_temp("shenlong_zhanglao/where",MAP_D->place_belong(where));
	me->set_temp("shenlong_zhanglao/killer",killer->query("name"));
	me->set_temp("shenlong_zhanglao/target_ob",killer); //加一个判断
	me->set_temp("shenlong_zhanglao/finish",this_object()->query("hyd/step"));
	delete("starting_drill");
	message_vision("$N说道：“$n果然不同凡响啊，我有个兄弟"+killer->query("name")+"("+killer->query("id")+")，在"+MAP_D->place_belong(where)+"等候指导，人送绰号"+killer->query("nickname")+"！”\n",this_object(),me);
	command("wave");
	if (environment(this_object())->query("least_msg"))
	whisper_to_me(me,killer);
	killer->move(where);
	for (i=0;i<3;i++) 
	killer->random_move();
	tell_object(me,HIB+"你可以选择继续指导，也可以回去复命。\n"+NOR);
	}
	else
	{
		me->set_temp("shenlong_zhanglao/finish",8);
		delete("starting_drill");
		message_vision("$N道：“阁下不愧是长老找来的高手啊！”\n",this_object());
		tell_object(me,"你可以回去复命了。\n");
	}
	destruct(this_object());
	return 1;
}
void die()
{
	object me = query("owner"),killer = query("uni_target");
	if (objectp(me))
	{
		tell_object(me,query("name")+"已经死了，这个任务是无法完成了。\n");
		me->set("shenlong_zhanglao/last_job_status","fail");
	}
	if (objectp(killer))
	killer->leave();
	::die();
}

void unconcious()
{
	call_out("die",1);
}

int do_copy(object me)  
{                       
        int exp;
        int skill, str,extra=0;
        int index;
        int factor;
        if(!objectp(me)) return 0;
        exp=me->query("combat_exp");
        index=me->query("shenlong_zhanglao/times")/250;
        //family_skill会set npc的chat_chance_combat为100，这个变态！
        //必须把family_skill放在最前面！
		if (query("hyd/step")==1)
		extra=1;
		skill=pow(exp/100.0,1.0/3)*(10+extra);
		family_skill(this_object(), "shenlongjiao", skill, 1);
		set("chat_chance_combat", 0);
		set("combat_exp",exp);    
		set("level",me->query("level")+random(5));
		str=me->query_str();
		if ( str > 150 ) 
		str=150;
		if ( me->query("shenlong_zhanglao/times") < 1000 )
		{
			set("max_qi", str * 250);
			set("eff_qi", str * 250);
		}
		else if ( me->query("shenlong_zhanglao/times") < 5000 )
		{
			set("max_qi", str * 200);
			set("eff_qi", str * 200);
		}
		else if ( me->query("shenlong_zhanglao/times")<= 12500 )
		{
			set("max_qi", str * 150 );
			set("eff_qi", str * 150 );
		}
		else 
		{
			set("max_qi", str * 75 );
			set("eff_qi", str * 75 );
		}
		set("qi", query("eff_qi"));
		set("max_jing", me->query("max_jing"));
        set("eff_jing", me->query("max_jing"));
        set("jing", me->query("max_jing"));
        set("max_neili", me->query("max_neili"));
        set("neili", me->query("max_neili"));
        set("max_jingli", me->query("max_jingli"));
        set("jingli", me->query("max_jingli"));
        set("jiali",100);
        set("owner",me);
		set("gender",me->query("gender"));
        wield_weapon();
}

int accept_object(object me,object ob)
{
	if (me=query("owner")&&ob->query_temp("buyer")==me&&ob->npc_only())
	{
		command("say 那我就不客气了。");
		return 1;
	}
	return notify_fail(query("name")+"不想要"+ob->query("name")+"。\n");
}