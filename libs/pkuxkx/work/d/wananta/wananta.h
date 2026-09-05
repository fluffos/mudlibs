//万安寺
//by picewolf
//2009-5-7

#include <ansi.h>
#include <room.h>
inherit ROOM;
int lvl;
int do_qiao(string);
int give_reward(object me);
int do_look(string dir);
int do_get(string);

void init()
{
	object me=this_player();
    object ob,room;
	object *tasknpc;

    int target_num;
	lvl = query("room_lvl");
	room=this_object();


  if ( !userp(me) && me->query("id")!="fanbang wushi" && me->query("id") !="body guard" &&me->query("id") !="jin she"&& me->is_suicong_dizi() != 1)
  {
      me->move("/d/luoyang/wananta");
	  return;
  }
  //到这里结束

  if(wizardp(me) && me->query("env/no_fanseng")) return;

	if (lvl==1 && me->query("id") != "fanbang wushi" && me->query("id") != "body guard" && me->is_suicong_dizi() != 1)
	{
//		 message( "channel:" + "baowei",YEL + "【万安塔】" + me->query("name")+YEL+"开始闯塔。\n"NOR,users());
//		 CHANNEL_D->do_channel(tasknpc1, "baowei", me->query("name")+"开始闯塔。\n");
		 //taskview统计
		 if (userp(me))
		 	{
		 		me->set_temp("task_stat/wat/start_time",time());
		 	}
	}
	if (lvl>1 && me->query("id") != "fanbang wushi" && me->query("id") != "body guard" && me->is_suicong_dizi() != 1)
	{
//		message( "channel:" + "baowei",YEL + "【万安塔】" + me->query("name")+YEL+"到达第"+chinese_number(lvl)+"层。\n"NOR,users());
//		CHANNEL_D->do_channel(tasknpc1, "baowei", me->query("name")+"到达第"+chinese_number(lvl)+"层.\n");
	}
	//************************************ modified by icer
  //数据统计
 if (userp(me))
 {
	 COMBAT_D->add("task_stat/wat/"+ lvl + "/times",1);
 }

	//*****************************************************
	if (lvl<4)
	{
		target_num=1;
	}

	if (lvl==4)
	{
		if (random(lvl)==0)
		{

			target_num=1;
		}
		else
		{
			target_num = lvl-3+random(lvl-2);
		}
		me->set_temp("wanansi/fscount",target_num);
	}

	if (lvl>4)
	{
		if (me->query_temp("wanansi/fscount")==1)
		{
			if (random(lvl+2)==0)
			{
				target_num=1;
			}
			else
			{
				target_num = lvl-3+random(lvl-2);
			}
		}
		else if(random(lvl+3)==0)
		{
			target_num=1;
		}
		else
		{
			target_num = lvl-2+random(lvl-2);

			me->set_temp("wanansi/fscount",target_num);
		}
	}

    if(!me->query_temp(sprintf("wanansi/%d",lvl)) && interactive(me))
    {
    	for (int a=0;a< target_num;a++ )
    	{
    		ob = new(__DIR__"npc/fanseng");
   		    ob->set_temp("seeme",me->query("id"));
    		ob->set("job_level", lvl);
    		ob->do_copy(me);
    		ob->move(this_object());
    		ob->kill_ob(me);
    		me->kill_ob(ob);
    	}
		me->set_temp(sprintf("wanansi/%d",lvl),1);
		me->set_temp("wananta/lvl",lvl);
    }


	add_action("do_qiao","qiao");       //敲锣
	add_action("do_jiangli","jiangli");
	add_action("do_look","look");
	add_action("do_quit","quit");
	add_action("do_get","get");
	add_action("do_alert","alert");
    add_action("do_kouling","kouling");
    set("real_dark",1);
    //测试期间假死
    set("no_die",1);
	set("no_sleep_room",1);
    set("least_msg",1);
    this_player()->listen_to_die(this_object());
}

int do_quit()
{
    write("胜负未分，生死未判，居然想走？\n");
    return 1;
}

int do_alert(string arg)
{
	if(this_player()->is_busy()==1) return 0;

	if(random(this_player()->query("kar"))<15)
	{
		tell_object(this_player(),"这塔里杀气可怖，你的侍卫心胆俱寒，竟然弃你而去！你不禁恼羞成怒。\n");
		this_player()->add_busy(random(3)+3);
		return 1;
	}
	return 0;
}

//当有玩家在此死亡时调用
int die_notify(object victim)
{
    object* obs;
    object suicong;
	string system_msg;
	object tasknpc;

	//********************************** modified by icer
	int re,qn,exp;
	//***************************************************

	tasknpc = load_object("/d/luoyang/npc/luzhangke");
    if(userp(victim))
    {

		//********************************** modified by icer
		if (query("room_lvl")>1 && query("room_lvl")<6)
		{
			re = victim->query_temp("wanansi/reward_re2");
			qn = victim->query_temp("wanansi/reward_qn2");
			exp = victim->query_temp("wanansi/reward_exp2");
		} else if (query("room_lvl")>5)
		{
			re = victim->query_temp("wanansi/reward_re2")/5*2;
			qn = victim->query_temp("wanansi/reward_qn2")/5*2;
			exp = victim->query_temp("wanansi/reward_exp2")/5*2;
		}
			//victim->add("repute", 0-re);
			//victim->add("potential",0-qn);
			//victim->add("combat_exp", 0-exp);
			re=REWARD_D->add_rep(victim,-re);
			qn=REWARD_D->add_pot(victim,-qn);
			exp=REWARD_D->add_exp(victim,-exp);
//记录万安塔获得的经验 by seagate@pkuxkx 2012/12/17
	    victim->add("exp/wananta", exp);
//记录一般情况下万安塔获得失败的次数 by seagate@pkuxkx 2012/12/17
      victim->add("wananta/fail_times",1);
			system_msg = victim->query("name")+"在万安塔任务中损失";
			system_msg += re+"点江湖声望、";
			system_msg += qn+"点潜能，";
			system_msg += exp+"点经验";
			system_msg += "。";
			CHANNEL_D->do_channel(tasknpc, "sys_misc", system_msg);
		  //数据统计
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/reputy",re);
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/potential",qn);
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/exp",exp);
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/times",1);

		//***************************************************



        victim->delete_temp("wanansi");
        victim->receive_damage("qi", 0, "在万安塔第"+chinese_number(lvl)+"层力战而");
        obs = all_inventory( environment( victim ));
        for(int i=0; i<sizeof(obs); i++)
        {
            if( obs[i]->query("id") == "fanbang wushi" && obs[i]->query("uni_target") == victim)
            {
                destruct(obs[i]);
            }
        }

		if(objectp(suicong = present(victim->query("id") + " suicong")))
		{
			tell_object(victim,"你的随从弟子悲痛不已，在万安塔久久的等候你。\n");
			suicong->move("/d/luoyang/wananta");
		}

        victim->remove_listen_to_die(this_object());
    }
    return 1;
}

int do_jiangli()
{
	object me=this_player();
	string jiangli_msg;



	if (!this_player()->is_fighting())
	{

		jiangli_msg="你现在可以获得奖励：";
		jiangli_msg += chinese_number(REWARD_D->check_rep(me->query_temp("wanansi/reward_re")))+"点江湖声望";
		jiangli_msg += chinese_number(REWARD_D->check_pot(me->query_temp("wanansi/reward_qn")))+"点潜能、";
		jiangli_msg += chinese_number(REWARD_D->check_exp(me->query_temp("wanansi/reward_exp")))+"点经验";
		/*if (lvl>3)
		{
			jiangli_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级功夫";
		}
		*/

		jiangli_msg += "！\n";
		write(jiangli_msg);
		return 1;
	}

	write("能活下来再说吧。。。\n");
	return 1;
}

int do_kouling(string arg)
{
    object me=this_player();
    if (!me->query_temp("wat_randomcode/code"))
    return 0;
    if (arg==(string)me->query_temp("wat_randomcode/code"))
    {
        me->delete_temp("wat_randomcode/code");
        me->set_temp("wat_randomcode_verified",1);
        ANTIROBOT_D->same_as_fullme(me);
        tell_object(me,"恭喜你，答对了口令，你可以敲锣离开了，你被允许下次进入万安塔的时间被提前了一分钟。\n");
        return 1;
    }
    else
    {
        me->delete_temp("wat_randomcode/code");
        me->set_temp("wat_randomcode_failed",1);
        tell_object(me,"答错了口令，你被允许下次进入万安塔的时间将被推迟，赶紧敲锣离开吧。\n");
        return 1;
    }
}

int get_code(object me)
{
            object where;
            string code;
            while (!objectp(where) ||
                  !where->isroom()||
                  TASK_D->place_belong(where)=="不明区域"||
                  base_name(where) == "/adm/daemons/taskd"||
                  where->query("no_fullme_scan"))
                    {where=TASK_D->random_place();}
                   code=where->query("short");
                   code=replace_string(code,HIY,"");
                   code=replace_string(code,YEL,"");
                   code=replace_string(code,HIG,"");
                   code=replace_string(code,GRN,"");
                   code=replace_string(code,HIB,"");
                   code=replace_string(code,BLU,"");
                   code=replace_string(code,WHT,"");
                   code=replace_string(code,HIW,"");
                   code=replace_string(code,HIR,"");
                   code=replace_string(code,RED,"");
                   code=replace_string(code,HIM,"");
                   code=replace_string(code,MAG,"");
                   code=replace_string(code,HIC,"");
                   code=replace_string(code,CYN,"");
                   code=replace_string(code,NOR,"");
                   me->set_temp("wat_randomcode/code",code);
                   ANTIROBOT_D->mxpantirobot_ex(me,code);
            tell_object(me,HIG+"请用kouling命令回答当日万安塔的口令，如果错误，将受到一定惩罚。\n"+NOR);
            return 1;
}

int do_qiao(string arg)
{
	int i;
    object *ob;
    object suicong;
	object me=this_player();
    ob = all_inventory( environment( me ));

    if(me->is_suicong_dizi() == 1) return 0;

    for(i=0; i<sizeof(ob); i++)
    {
        if( ob[i]->query("id") == "fanbang wushi" && ob[i]->query("uni_target") == me)
            return notify_fail("战斗还没完呢，瞎敲什么！！\n\n");
    }


	if (arg && arg == "luo")
	{
        i=1+random(6);//6层及以下随机加入图片检查，挂低层万安塔最近比较猖獗，Zine
		if ((wizardp(me)||lvl==i)&&!me->query_temp("wat_randomcode")&& !ANTIROBOT_D->stopped())
        {
            return get_code(me);
        }

        this_player()->move("/d/luoyang/wananta");
		this_player()->remove_listen_to_die(this_object());
		if(objectp(suicong = present(me->query("id") + " suicong")))
		{
			tell_object(me,"你的随从弟子毫不犹豫的跟上了你了。\n");
			suicong->move("/d/luoyang/wananta");
		}

		if(lvl < 5)
		{
			me->set("wananta/start",time()-(lvl-1)*120);        //每过一层，冷却时间减少两分钟. 5层以上无效，否则某些id刷经验太狠了。
		}
		else
		{
			me->set("wananta/start",time()-(lvl-1)*50);
		}
        if (me->query_temp("wat_randomcode"))
        {
            me->set("wananta/start",(int)me->query("wananta/start")+600-(int)me->query_temp("wat_randomcode_verified")*660+(int)me->query_temp("wat_randomcode_failed")*300);
            me->delete_temp("wat_randomcode");
            me->delete_temp("wat_randomcode_verified");
            me->delete_temp("wat_randomcode_failed");
        }
		call_out("give_reward",1,this_player());
        if (lvl>=4)//加入任务完成统计，完成塔四以上算完成一次。
        {
            me->add("newjobs/completed/wat",1);
        }
		return 1;
	}
	return notify_fail("敲什么敲？\n");
}



int give_reward(object me)
{
    string msg,system_msg,channel_msg;
	int reward, i, cost_time;
	object tasknpc;
	object box;

	int exp,pot,rep,skill;

	if (!me) return 1;
	if (!me->query("biography/jobs/wananta"))
	{
		me->set("biography/jobs/wananta",time());//个人传记记录第一次完成任务时间ZINE
	}
	if (!me->query("biography/jobs/wananta6")&&me->query_temp("wananta/lvl")>=6)
	{
		me->set("biography/jobs/wananta6",time());//个人传记记录第一次完成任务时间ZINE
	}
	system_msg = me->query("name")+"在万安塔任务中获得奖励";
	channel_msg = me->query("name")+"在万安塔任务中闯过"+chinese_number(query("room_lvl"))+"关，被奖励";


	box=new("/d/wananta/npc/obj/box");

	if (me->query_temp("wananta/lvl")>6)
	{
		box->move(me);
		write(CYN"鹿杖客说道：阁下武艺不凡，我家郡主特赠厚礼，请笑纳！\n"NOR);
		write(CYN"鹿杖客给你一个宝盒。\n"NOR);
	}

    if(!objectp(me)) return 1;

	tasknpc = load_object("/d/luoyang/npc/luzhangke");
	write(HIW"你被奖励了：\n");

	rep = REWARD_D->add_rep(me,me->query_temp("wanansi/reward_re"));
	write("\t"+chinese_number(rep)+"点江湖声望。\n");
	system_msg += rep+"点江湖声望、";
	channel_msg += chinese_number(rep)+"点江湖声望、";


	pot = REWARD_D->add_pot(me,me->query_temp("wanansi/reward_qn"));
	write("\t"+chinese_number(pot)+"点潜能；\n");
	system_msg += pot+"点潜能，";
	channel_msg += chinese_number(pot)+"点潜能、";

	exp = REWARD_D->add_exp(me,me->query_temp("wanansi/reward_exp"));
//记录万安塔获得的经验 by seagate@pkuxkx 2012/12/17
	me->add("exp/wananta", exp);
//记录一般情况下万安塔获得奖励的次数 by seagate@pkuxkx 2012/12/17
  me->add("wananta/normal_times",1);
	write("\t"+chinese_number(exp)+"点经验；\n"+NOR);
	system_msg += exp+"点经验";
	channel_msg += chinese_number(exp)+"点经验";

	if (lvl > 6 && random(10) > 0)
	{
		write(HIC"你的「"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"))+"」进步了！\n"NOR);
		skill = me->query_temp("wanansi/reward_count");
		skill = REWARD_D->check_skill(skill);
		system_msg += "，"+chinese_number(skill)+"级"+me->query_temp("wanansi/reward_skill");
		channel_msg +="，"+chinese_number(skill)+"级"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"));
		REWARD_D->add_skill(me,me->query_temp("wanansi/reward_skill"),skill);

	}


	channel_msg += "！\n";

    if(lvl > 6)
    {
    	CHANNEL_D->do_channel(tasknpc, "rumor", channel_msg);
    }

	system_msg += "。";

	CHANNEL_D->do_channel(tasknpc, "sys_misc", system_msg);

	destruct(tasknpc);
	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/reward/reputy",rep);
	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/reward/potential",pot);
	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/reward/exp",exp);
	//taskview统计
	if (userp(me))
	{
		COMBAT_D->add("task_stat/wananta/complete_times",1);
		COMBAT_D->add("task_stat/wananta/cost_time",time()-me->query_temp("task_stat/wat/start_time",time()));
		COMBAT_D->add("task_stat/wananta/exp",exp);
		COMBAT_D->add("task_stat/wananta/pot",pot);
		COMBAT_D->add("task_stat/wananta/repute",rep);
		COMBAT_D->add("task_stat/wananta/expratio",to_float(exp)/me->query("combat_exp"));
		COMBAT_D->add("task_stat/wananta/skill",skill);
	}
	me->delete_temp("task_stat/wananta");
	me->delete_temp("wanansi");


	return 1;
}

int valid_leave(object me, string dir)
{
    int i;
    object *ob;

	if(!userp(me) && !me->is_suicong_dizi()) return notify_fail("恪守职守，不得乱走！\n");

    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++)
    {
        if(!ob[i]->is_character() && !ob[i]->query_temp("seeme"))
        {
            destruct(ob[i]);
            continue;
        }
        if( ob[i]->query("id") == "fanbang wushi" && ob[i]->query("uni_target") == me)
            return notify_fail("武士漠然挡住了你：生死未判，就想走么？\n");
    }
    me->remove_listen_to_die(this_object());


    return ::valid_leave(me, dir);
}

int do_look(string dir)
{
	if(dir == "up")
	{
		write("两层间并无空隙，你无法看到上面一层的情况。\n");
		return 1;
	}
	return 0;
}

int do_get(string arg)
{
	if (arg && arg == "wushi" || arg== "fanbang wushi")
	{
		write("你要干什么？\n");
		return 1;
	}
	if (arg && arg== "all")
	{
		write("一次捡一样吧。\n");
		return 1;
	}
	return 0;
}
