// afkd.c 托管行为管理器

#include <command.h>
#define AFK_DIR "/adm/daemons/afk/"

inherit F_DBASE;
inherit F_SAVE;

mapping afk_user;

void load_afks();

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "挂机精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "挂机系统已经启动。");
	if( !restore() && !mapp(dbase) )
		load_afks();
}

string query_save_file() { return DATA_DIR + "afkd"; }

int clean_up()
{
	return 1;
}

void save_afk_user()
{
	object *obs;
	mapping tmp;
	int i;

	afk_user = ([]);
	obs = filter(users(),(: $1->query("afk") :));
	for(i=0;i<sizeof(obs);i++)
	{
		afk_user[obs[i]->query("id")] = obs[i]->query("afk");
		afk_user[obs[i]->query("id")]["room"] = base_name(obs[i]->query("afk/room"));
	}
	CHANNEL_D->do_channel( this_object(), "sys", i+"位玩家离线数据已保存。");
	save();
}

void load_afk_user()
{
	string u,room;
	object login_ob;
	object env,user_ob;

	if (! mapp(afk_user))
		return;

	foreach (u in keys(afk_user))
	{
		if(stringp(room = afk_user[u]["room"]))
		{
			env = find_object(room);
			if(!env) env = load_object(room);
		}
		if (! objectp(user_ob = LOGIN_D->find_body(u)))
		{
			login_ob = new(LOGIN_OB);
			login_ob->set("id", u);
			if (! login_ob->restore())
			{
				destruct(login_ob);
				map_delete(afk_user, u);
				log_file("afk", sprintf("closed：没有玩家(%s)。\n", u));
				continue;
			}
	
			user_ob = LOGIN_D->make_body(login_ob);
			if (! user_ob)
			{
				destruct(login_ob);
				map_delete(afk_user, u);
				log_file("afk", sprintf("closed：无法生成玩家(%s)。\n", u));
				continue;
			}
	
			if (! user_ob->restore())
			{
				destruct(login_ob);
				destruct(user_ob);
				map_delete(afk_user, u);
				log_file("log", sprintf("closed：无法读取玩家(%s)的档案。\n", u));
				continue;
			}

			catch(LOGIN_D->enter_world(login_ob, user_ob));
			if (! objectp(env))
			{
				destruct(login_ob);
				destruct(user_ob);
				map_delete(afk_user, u);
			}
			user_ob->move(env);
			user_ob->set("afk",afk_user[u]);
			user_ob->set("afk/room",env);
			user_ob->set_heart_beat(1);
		}
	}
}

string *afk_list()
{
	return keys(dbase);
}

void load_afks()
{
	string str, str2, *files, *line, *tmp_msg, file;
	int i, j, num;
	mapping bonusd;
	mapping bonuso;
	mapping max,need,npc,room;

	dbase = ([]);
	files = get_dir(AFK_DIR);
	for(i=0;i<sizeof(files);i++)
	{
		file = read_file(AFK_DIR+files[i]);
		if (!file) continue;
		bonusd = ([]);bonuso = ([]);need = ([]);npc = ([]);room = ([]);
		tmp_msg = ({});max = ([]);
		line = explode(file, "\n");
	   	for (j=0;j<sizeof(line);j++)
		{
			if(line[j] == "" || line[j][0] == '\n' || strsrch(line[j],"//")==0) continue;

			if(sscanf(line[j],"#%s",str) == 1)
			{
				if(sscanf(str,"NAME %s",str) == 1)
				{//托管行为名称
					set(files[i]+"/name",str);
				}
				else if(sscanf(str,"TYPE %d",num) == 1)
				{//消息推送方式：1随机，2循环
					set(files[i]+"/type",num);
				}
				else if(sscanf(str,"ROUND %d",num) == 1)
				{//如果是随机方式则在num心跳之后给予奖励
					set(files[i]+"/round",num);
				}
				else if(sscanf(str,"ROOM %s",str) == 1)
				{//环境要求
					if(sscanf(str,"file:%s",str) == 1)
					{//指定环境房间文件
						room["file"] = str;
					}
					else if(sscanf(str,"%s:%d",str,num) == 2)
					{//要求房间属性
						room[str] = num;
					}
				}
				else if(sscanf(str,"NEED %s",str) == 1)
				{//玩家数据属性最低要求
					if(sscanf(str,"%s:%d",str,num) == 2)
					{
						need[str] = num;
					}
				}
				else if(sscanf(str,"MAX %s",str) == 1)
				{//玩家数据属性上限要求
					if(sscanf(str,"%s:%d",str,num) == 2)
					{
						max[str] = num;
					}
				}
				else if(sscanf(str,"NPC %s",str) == 1)
				{//要求NPC在身边
					if(sscanf(str,"%s:%s",str,str2) == 2)
					{
						npc[str] = str2;
					}
				}
				else if(sscanf(str,"DATA %s",str) == 1)
				{//数据属性奖励
					if(sscanf(str,"%s:%d",str,num) == 2)
					{
						bonusd[str] = num;
					}
				}
				else if(sscanf(str,"OBJ %s",str) == 1)
				{//物品奖励
					if(sscanf(str,"%s:%d",str,num) == 2)
					{
						bonuso[str] = num;
					}
				}
			}
			else tmp_msg += ({ line[j] });
		}
		set(files[i]+"/msg",tmp_msg);
		set(files[i]+"/bonusd",bonusd);
		set(files[i]+"/bonuso",bonuso);
		set(files[i]+"/room",room);
		set(files[i]+"/need",need);
		set(files[i]+"/max",max);
		set(files[i]+"/npc",npc);
	}
	save();
}

void study_afk(object me)
{
	string name,exp,file,*msg;
	int i,cost,fix,num,need_lvl,min,max,imp;
	object book,room,env;
	mapping needs,need_sk,skill;
	mixed *local;
	
	fix = 100;
	if(me->query_condition("db_exp"))
		fix *= 2;
	
	local = localtime(time());
	if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 )
		fix *= 2;//开服挂机奖励翻倍。一周?还是？

	if(me->query("afk"))
	{
		env = environment(me);
		file = me->query("afk/file");
		room = me->query("afk/room");
		book = me->query("afk/book");
		if(!book || !mapp(query(file)) || env!=room || !present(book,me) || !mapp(book->query("skill")))
		{
			me->delete("afk");
			return;
		}

		if((me->query("potential")-me->query("learned_points")) < env->query("study_cost"))
		{
			tell_object(me,"你的潜能不足，无法进行研读了。\n");
			me->delete("afk");
			return;
		}

		name = book->query("skill/name");
		exp = book->query("skill/exp_required");
		if(me->query("combat_exp") < exp)
		{
			tell_object(me,"你的战斗修为需要达到" + exp + "才能研读"+book->query("name")+"学习"+to_chinese(name)+"。\n");
			me->delete("afk");
			return;
		}
		min = book->query("skill/min_skill");
		if(me->query_skill(name,1) < min)
		{
			tell_object(me,"你的"+to_chinese(name)+"需要达到" + min + "才能研读"+book->query("name")+"学习"+to_chinese(name)+"。\n");
			me->delete("afk");
			return;
		}
		max = book->query("skill/max_skill");
		if(me->query_skill(name,1) > max)
		{
			tell_object(me,"你的"+to_chinese(name)+"等级已经超出"+book->query("name")+"的学习范围了。\n");
			me->delete("afk");
			return;
		}

		if (mapp(needs = book->query("skill/need")))
		{
			foreach (need_sk in keys(needs))
			{
				need_lvl = needs[need_sk];
				if (functionp(need_lvl))
					need_lvl = evaluate(need_lvl);
				else
				if (! intp(need_lvl))
					need_lvl = 0;

				if (me->query_skill(need_sk, 1) < need_lvl)
				{
					tell_object(me,"你研读了一会儿，发现如果不通晓" + to_chinese(need_sk) + "的话，恐怕难以领会上面的含义。\n");
					me->delete("afk");
					return;
				}
			}
		}

		if (!SKILL_D(name)->valid_learn(me) || !XUE_CMD->can_learn(me, name))
		{
			tell_object(me,"不符合"+to_chinese(name)+"的学习条件，挂机中断。\n");
			return;
		}

		if(present("huiling dan",me)&&me->query("combat_exp")<200000&&me->query("neili")<1000)
			me->force_me("use huiling dan");

		if(me->query("neili")>100)
			me->force_me("exert regenerate");
		else if(me->query("max_neili")>200)
		{
			if(present("huxin dan",me))
			{
				me->force_me("use huxin dan");
				me->force_me("dazuo "+me->query("max_qi")/3);
				return;
			}
			else
			{
				me->force_me("exert recover");
				me->force_me("dazuo "+me->query("qi")/3);
				return;
			}
		}
		cost = (book->query("skill/jing_cost") * 20 + book->query("skill/difficulty") - me->query_int()) / 20;
		if (cost < 10) cost = 10;

		if ((int)me->query("jing") < cost)
		{
			tell_object(me,"你觉得精神有些不济，休息中。。。\n");
			return;
		}
		msg = query(file+"/msg");
		tell_object(me,replace_string(msg[random(sizeof(msg))],"$B",book->query("name"))+"\n");
		imp = 0;
		for (i = 0; i<100; i++)
		{
			if ((int)me->query("jing") > cost)
				me->receive_damage("jing", cost );
			else if (SKILL_D("force/regenerate")->exert(me, me))
			{
				tell_object(me,"你觉得精神好了一些，继续读书。\n");
				i--;
				continue;
			}
			else
			{
				tell_object(me,"你觉得精神有些不济，休息中。。。\n");
				me->set("jing", 1);
				return;
			}

			if(file_size(SKILL_D(name)+".c")>0)
			{//提升技能熟练度
				num = me->query_skill("literate", 1) / 10 + 1;
				imp += num;
				me->improve_skill(name,num*fix/100);
			}
		}
		tell_object(me,sprintf("你的%s熟练 + %d。\n",to_chinese(name),imp));

		tell_object(me,"line_msg\n");
	}
}

void research_afk(object me)
{
	string str,file,*msg;
	int fix,improve,i,type,round,step,imp;
	object book,room,env;
	string *ks,skill,skill_name,action_name;
	mixed *local;
	
	fix = 1;
	if(me->query_condition("db_exp"))
		fix *= 2;
		
	local = localtime(time());
	if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 )
		fix *= 2;//开服挂机奖励翻倍。一周?还是？
	
	if(me->query("afk"))
	{
		env = environment(me);
		file = me->query("afk/file");
		room = me->query("afk/room");
		skill = me->query("afk/skill");
		if(!mapp(query(file)) || env!=room || ! "/cmds/skill/learn"->can_learn(me, skill))
		{
			me->delete("afk");
			return;
		}

		if((me->query("potential")-me->query("learned_points")) < (1+env->query("research_cost")))
		{
			tell_object(me,"你的潜能不足，无法进行研究了。\n");
			me->delete("afk");
			return;
		}

		if (! me->can_improve_skill(skill))
		{
			tell_object(me,"也许是缺乏实战修为，你感到难以继续研究" + to_chinese(skill) + "的问题了。\n");
			me->delete("afk");
			return;
		}

		step = me->query("afk/step");
		type = query(file+"/type");
		round = query(file+"/round");
		msg = query(file+"/msg");

		skill_name = to_chinese(skill);
		if(!(action_name=SKILL_D(skill)->query_skill_name()))
			action_name = skill_name;

		if(type == 1)
		{
			if(step < round)
			{
				str = replace_string(msg[random(sizeof(msg))],"$A",action_name)+"\n";
				str = replace_string(str,"$S",skill_name);
				tell_object(me,str);
			}
		}
		else
		{
			round = sizeof(msg);
			if(step < round)
			{
				str = replace_string(msg[step],"$A",action_name)+"\n";
				str = replace_string(str,"$S",skill_name);
				tell_object(me,str);
			}
		}

		step++;
		if(step > round)
		{
			improve = me->query_skill(skill,1) + me->query_int()/4;

			imp = env->query("research_improve");
			improve = (improve+imp)*fix;
			me->improve_skill(skill,improve);
			me->add("learned_points",1+env->query("research_cost"));
			tell_object(me,sprintf("你的%s熟练 + %d。\n",to_chinese(skill),improve));
			tell_object(me,"line_msg\n");
			step = 0;
		}
		me->set("afk/step",step);
	}
}

void derive_afk(object me)
{
	string str,file,*msg;
	int fix,improve,i,type,round,step;
	object book,room,env;
	string *ks,skill,skill_name,action_name;
	mixed *local;
	
	fix = 100;
	if(me->query_condition("db_exp"))
		fix *= 2;

	local = localtime(time());
	if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 )
		fix *= 2;//开服挂机奖励翻倍。一周?还是？
	
	if(me->query("afk"))
	{
		env = environment(me);
		file = me->query("afk/file");
		room = me->query("afk/room");
		skill = me->query("afk/skill");
		if(!mapp(query(file)) || env!=room)
		{
			me->delete("afk");
			return;
		}

		if (me->query("experience") < me->query("learned_experience")+100+env->query("research_cost")*10)
		{
			tell_object(me,"你的实战积累不足了，感悟中断。\n");
			me->delete("afk");
			return;
		}

		if (! me->can_improve_skill(skill))
		{
			tell_object(me,"也许是缺乏实战修为，你感到难以继续提升" + to_chinese(skill) + "了。\n");
			me->delete("afk");
			return;
		}

		if (SKILL_D(skill)->no_derive(me))
		{
			me->delete("afk");
			return;
		}

		step = me->query("afk/step");
		type = query(file+"/type");
		round = query(file+"/round");
		msg = query(file+"/msg");

		skill_name = to_chinese(skill);

		if(type == 1)
		{
			if(step < round)
			{
				str = replace_string(msg[random(sizeof(msg))],"$S",skill_name)+"\n";
				tell_object(me,str);
			}
		}
		else
		{
			round = sizeof(msg);
			if(step < round)
			{
				str = replace_string(msg[step],"$S",skill_name)+"\n";
				tell_object(me,str);
			}
		}

		step++;
		if(step > round)
		{
			improve = 50+me->query_skill(skill)/2+me->query_int();

			if (me->query_int() >115)
				improve = improve*(195+(me->query_int()-115)/2)/100;
			else if (me->query_int() >20)
				improve = improve*(80+me->query_int())/100;

			if(improve>380) improve = 380 + (improve - 380)/2;

			improve *= 5;
			improve += improve*env->query("research_cost")/10;
			me->improve_skill(skill,improve*fix/100);
			me->add("learned_experience",100+env->query("research_cost")*10);
			tell_object(me,sprintf("你的%s熟练 + %d。\n",to_chinese(skill),improve*fix/100));
			tell_object(me,"line_msg\n");
			step = 0;
		}
		me->set("afk/step",step);
	}
}

void practice_afk(object me)
{
	string str,file,*msg;
	int fix,improve,i,type,round,step;
	object book,room,env;
	string *ks,skill, skill_basic,skill_name,action_name;
	mixed *local;
	
	fix = 100;
	if(me->query_condition("db_exp"))
		fix *= 2;

	local = localtime(time());
	if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 )
		fix *= 2;//开服挂机奖励翻倍。一周?还是？
	
	if(me->query("afk"))
	{
		env = environment(me);
		file = me->query("afk/file");
		room = me->query("afk/room");
		skill = me->query("afk/skill");
		if(!mapp(query(file)) || env!=room)
		{
			me->delete("afk");
			return;
		}

		if (! me->can_improve_skill(skill))
		{
			tell_object(me,"也许是缺乏实战修为，你感到难以继续提升" + to_chinese(skill) + "了。\n");
			me->delete("afk");
			return;
		}
		if (me->query_skill(skill,1)>=me->query_skill(SKILL_D(skill)->type(),1))
		{
			tell_object(me,"你的"+to_chinese(SKILL_D(skill)->type())+"不足，难以继续提升" + to_chinese(skill) + "了。\n");
			me->delete("afk");
			return;
		}

		step = me->query("afk/step");
		type = query(file+"/type");
		round = query(file+"/round");
		msg = query(file+"/msg");

		skill_name = to_chinese(skill);

		if(type == 1)
		{
			if(step < round)
			{
				str = replace_string(msg[random(sizeof(msg))],"$S",skill_name)+"\n";
				tell_object(me,str);
			}
		}
		else
		{
			round = sizeof(msg);
			if(step < round)
			{
				str = replace_string(msg[step],"$S",skill_name)+"\n";
				tell_object(me,str);
			}
		}

		step++;
		if(step > round)
		{
			improve = 2+me->query_skill(skill)/30+me->query_int()/10;

			if (me->query_int() >20)
				improve = improve*(80+me->query_int())/100;

			me->improve_skill(skill,improve*fix/100);
			tell_object(me,sprintf("你的%s熟练 + %d。\n",to_chinese(skill),improve*fix/100));
			tell_object(me,"line_msg\n");
			step = 0;
		}
		me->set("afk/step",step);
	}
}

void check_user(object me)
{
	string str,file,*msg,*ds,*os,*rs,*needs,*npcs,*maxs;
	int fix,i,type,round,step;
	object *obs,obj,room,env;
	mapping d,o,r,need,npc,max;
	mixed *local;

	if(me->is_busy()) return;

	fix = 100;
	if(me->query_condition("db_exp"))
		fix *= 2;
	
	local = localtime(time());
	if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 )
		fix *= 2;//开服挂机奖励翻倍。一周?还是？

	if(me->query("afk"))
	{
		if (me->query_team())
		{
			tell_object(me,"请先退出或者解散队伍再进行挂机！\n");
			me->delete("afk");
			return;
		}
		if (me->is_fighting())
		{
			tell_object(me,"进入战斗，挂机结束！\n");
			me->delete("afk");
			return;
		}
		if(me->query("afk/file")=="dushu")
		{
			study_afk(me);
			return;
		}
		else if(me->query("afk/file")=="research")
		{
			research_afk(me);
			return;
		}
		else if(me->query("afk/file")=="derive")
		{
			derive_afk(me);
			return;
		}
		else if(me->query("afk/file")=="practice")
		{
			practice_afk(me);
			return;
		}
		env = environment(me);
		file = me->query("afk/file");
		room = me->query("afk/room");
		if(!mapp(query(file))||env!=room)
		{
			me->delete("afk");
			return;
		}
		need = query(file+"/need");
		if(sizeof(needs=keys(need)))
		{
			for(i=0;i<sizeof(needs);i++)
			{
				if(me->query(needs[i])<need[needs[i]])
				{
					tell_object(me,"你的"+to_chinese(maxs[i])+"需要达到"+max[maxs[i]]+"才能进行挂机"+query(file+"/name")+"。\n");
					me->delete("afk");
					return;
				}
			}
		}

		max = query(file+"/max");
		if(sizeof(maxs=keys(max)))
		{
			for(i=0;i<sizeof(maxs);i++)
			{
				if(me->query(maxs[i])>max[maxs[i]])
				{
					tell_object(me,"你的"+to_chinese(needs[i])+"超过"+need[needs[i]]+"了,挂机中断。\n");
					me->delete("afk");
					return;
				}
			}
		}

		r = query(file+"/room");
		if(sizeof(rs=keys(r)))
		{
			for(i=0;i<sizeof(rs);i++)
			{
				if(base_name(env)!=r[rs[i]]&&env->query(rs[i])!=r[rs[i]])
				{
					//tell_object(find_player("luoyun"),sprintf("11==%O   22==%O   r=%O   ri=%O\n", base_name(env), r[rs[i]], env->query(rs[i]), r[rs[i]]));
					tell_object(me,"你所在的地方不能进行挂机"+query(file+"/name")+"。\n");
					me->delete("afk");
					return;
				}
			}
		}

		npc = query(file+"/npc");
		if(sizeof(npcs=keys(npc)))
		{
			for(i=0;i<sizeof(npcs);i++)
			{
				if(!objectp(present(npc[npcs[i]],env)))
				{
					tell_object(me,"你需要有"+npcs[i]+"在身边才能进行挂机"+query(file+"/name")+"。\n");
					me->delete("afk");
					return;
				}
			}
		}

		step = me->query("afk/step");
		type = query(file+"/type");
		round = query(file+"/round");
		msg = query(file+"/msg");

		if(type == 1)
		{
			if(step < round)
				tell_object(me,msg[random(sizeof(msg))]+"\n");
		}
		else
		{
			round = sizeof(msg);
			if(step < round)
				tell_object(me,msg[step]+"\n");
		}

		step++;
		if(step > round)
		{
			d = query(file+"/bonusd");
			o = query(file+"/bonuso");
			if(sizeof(ds=keys(d)))
			{
				str = "你的";
				for(i=0;i<sizeof(ds);i++)
				{
					if(file_size(SKILL_D(ds[i])+".c")>0)
					{
						me->improve_skill(ds[i], d[ds[i]]*fix/100);
						str += sprintf("%s熟练 + %d", to_chinese(ds[i]), d[ds[i]]*fix/100);
					}
					else if(ds[i]=="potential")
					{
						str += sprintf("%s + %d", to_chinese(ds[i]), me->improve_potential(d[ds[i]]*fix/100));
					}
					else
					{
						me->add(ds[i], d[ds[i]]*fix/100);
						str += sprintf("%s + %d", to_chinese(ds[i]), d[ds[i]]*fix/100);
					} 
					if(i<(sizeof(ds)-1)) str += "，";
					else str += "。\n";
				}
				tell_object(me,str);
			}
			if(sizeof(os=keys(o))&&(interactive(me)||me->query("zjvip/times")))
			{
				str = "你获得了";
				for(i=0;i<sizeof(os);i++)
				{
					obj = new(os[i]);
					if(obj->query_amount()) obj->set_amount(o[os[i]]);
					str += obj->short();
					obj->move(me);
					if(i<(sizeof(os)-1)) str += "，";
					else str += "。\n";
				}
				tell_object(me,str);
			}
			if(env->query("afk"))
			{
				env->do_afk(me);
			}
			tell_object(me,"line_msg\n");
			if(!me->query("afk")) return;
			step = 0;
		}
		me->set("afk/step",step);
	}
}
