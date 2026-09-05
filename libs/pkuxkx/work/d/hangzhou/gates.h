//朝廷转大宋的guard任务
#include <ansi.h>
#define KILLER_LIMIT 30//一个房间最多生成多少个killers
nosave int *kill_base_a = ({2, 3, 4, 5});
nosave int *job_upgrade_a = ({50, 100, 150, 200});
int job_upgrade_num(int rank) {return job_upgrade_a[rank];}

nosave int *exp_base_a = ({10000, 50000, 100000, 150000});
nosave int *exp_bonus_a = ({1000, 1500, 2000, 3000});
int exp_bonus(int rank) { return exp_bonus_a[rank]; }
//守门相关，移植自北京

void remove_need_pancha(object player)
{
	if (!player)
		return;
	if (player->query_temp("pancha_stage") == 1)
	player->delete_temp("need_pancha");
}
void job_reward(object player, int rank, int kill_num, int fail_num)
{
    int exp_reward, job_finish, exp_player, exp_bonus;
    int kill_base, exp_base, job_upgrade, sc;
    int kill_finish;
    float kill_ratio, ftemp_a, ftemp_b;
	object JOB_Record;
    // sanity check
	if (!player || rank < 0 || rank > 3 || kill_num < 0 || fail_num < 0) 
	{
		write("BUG: 请告诉北大侠客行的巫师：job_reward sanity check error.\n");
		return;
	}

	player->add("chaoting/gate", 1);

	kill_base = kill_base_a[rank];
	exp_base = exp_base_a[rank];
	job_upgrade = job_upgrade_a[rank];
	exp_bonus = exp_bonus_a[rank];
	exp_player = player->query("combat_exp");
	job_finish = player->query("chaoting/gate");

	kill_finish = kill_num - fail_num;
	sc = 1;
	if (kill_finish <= 0)
	{
		sc = 0;
		kill_finish = 0;
		player->add("chaoting/job_fail", 1);
	}


    /* kill numbers and player exp take effect */
//暂时取消此限制
/*
    if (exp_player > exp_base)
    {
	kill_finish = kill_finish * exp_base/exp_player;
    }
*/
	ftemp_a = kill_finish;
	ftemp_b = kill_base;
	kill_ratio=ftemp_a/ftemp_b;
	if (kill_ratio > 2.0)
    {
       /* I hope log and floating point numbers work */
       kill_ratio = 1.0 + 0.5 * sqrt(kill_ratio);
       if (kill_ratio > 6.0) kill_ratio = 6.0;//好像不太可能达到
    }
//	if (player->query_temp("chaoting/night_job"))
//	kill_ratio += 0.1;

    /* primary reward: I wish the mixed float/int arithmetic is all right */
    exp_reward = exp_bonus * kill_ratio / 2; /* half hour job */

    if (job_finish > 3 * job_upgrade / 2)
    {
		exp_reward = exp_reward * job_upgrade / (job_finish-job_upgrade);
    }

//    exp_reward = exp_reward * (95+random(10))/200;  // 暂时注释，增加奖励
	player->add("combat_exp", exp_reward);
	player->add("exp/chaoting", exp_reward);
	player->add("potential",  exp_reward/8);
	player->add("pot/chaoting",  exp_reward/8);
	player->add("score", sc);
	JOB_Record=find_object("/d/hangzhou/npc/fuyin");
	JOB_Record->RECORD_TEST(player,exp_reward,exp_reward/8,"shoumen");
	if (exp_reward > 0)
	{
    player->add("combat_exp", player->query_temp("chaoting/newjob/guard/gateexp"));
    player->add("exp/chaoting", player->query_temp("chaoting/newjob/guard/gateexp"));
    tell_object(player, "你的经验增加了" + chinese_number(exp_reward + player->query_temp("chaoting/newjob/guard/gateexp")) + "点！\n");
    tell_object(player, "你的潜能增加了" + chinese_number(exp_reward/8) + "点！\n");
    if (sc) tell_object(player,"你对"+HBGRN+HIR+"大宋朝廷"+NOR+"的贡献度提高了。\n");
	}
	else
    tell_object(player, "你本次守门任务看来做得并不成功！\n");
	player->delete_temp("chaoting/newjob/guard");
    tell_object(player, "到目前为止你已经守城门" + chinese_number(job_finish) + "次！\n");
    tell_object(player, "到目前为止你已经任务失败" + chinese_number(player->query("chaoting/job_fail")) + "次！\n");
     //测试用，成功后删除
     // tell me more details
	if (wizardp(player))
	{
	tell_object(player, "job_finish = "+job_finish+"\n");
	tell_object(player, "kill_finish = "+kill_finish+"\n");
	tell_object(player, "kill_ratio = "+kill_ratio+"\n");
	}

}
void reward_shiwei(int rank, object player)
{
	message_vision("城门的钟敲了两下，$N的换班时间到了。\n", player);
	job_reward (player, rank, player->query_temp("chaoting/newjob/guard/kill_num"), player->query_temp("chaoting/newjob/guard/fail_num"));
}
int obj_in_env(string file, object env)
{
	object *obs;
	int n=0;
	obs = filter_array(children(file), (: clonep :));
	if (!sizeof(obs))
	return 0;
	for (int i=0;i<sizeof(obs);i++)
	if (env==environment(obs[i]))
	n+=1;
	return n;
}
void gen_killer()
{
    object env = this_object();
    int killers ;
    object *inv, killer;
    int    i, outer=0,shiwei_present = 0;

    remove_call_out("gen_killer");
    call_out("gen_killer", 10);
	if (env->query("short")=="丽正门"||env->query("short")=="和宁门")
    killers = obj_in_env("/d/hangzhou/npc/killer2.lpc", env);
	else
	{
		outer=1;
		killers = obj_in_env("/d/hangzhou/npc/killer1.lpc", env);
	}
	inv = all_inventory(env);
    for (i=sizeof(inv)-1; i>=0; i--)
	{
        if (  userp(inv[i])
			  && living(inv[i])
			  && inv[i]->query("class")=="officer"
			  && (inv[i]->query_temp("chaoting/newjob/guard/can_pancha")||inv[i]->query_temp("chaoting/newjob/guard/can_allow")) )
	   {
	   	if (member_array(NATURE_D->outdoor_room_event(),({"event_sunrise" ,"event_morning","event_noon","event_afternoon"}))==-1)
			{//night
		        if (inv[i]->query_temp("chaoting/newjob/guard/day") )
				{	if (outer)
					{
						if (inv[i]->query("pin") <= 6)
						reward_shiwei(1, inv[i]);
						else
						reward_shiwei(0, inv[i]);
					}
					else	reward_shiwei(2, inv[i]);//值白班的奖励
				}
				else if (inv[i]->query_temp("chaoting/newjob/guard/night"))
				{
					shiwei_present++;
				}
	    	}
		else
			{
			  if (inv[i]->query_temp("chaoting/newjob/guard/night"))
				{
					if (outer)
					{
						if (inv[i]->query("pin") <= 6)
						reward_shiwei(2, inv[i]);
						else
						reward_shiwei(1, inv[i]);
					}
					else reward_shiwei(3, inv[i]);//值夜班的奖励
				}
				else if (inv[i]->query_temp("chaoting/newjob/guard/day") )
				{
					shiwei_present++;
				}
	    	}
        }
    }

    if (shiwei_present == 0) return;

	if (killers>=KILLER_LIMIT) return;
	if (member_array(NATURE_D->outdoor_room_event(),({"event_sunrise" ,"event_morning","event_noon","event_afternoon"}))==-1)
	{
		if (outer)
		{
			killer= new("/d/hangzhou/npc/killer1.lpc");
			killer->upgrade(1);
		}
		else
		{
			killer = new("/d/hangzhou/npc/killer2.lpc");
			killer->upgrade(3);
		}
		killer->move(env);
		message_vision("$N快步走了过来。\n", killer);
    }else
	{
		if (outer)
		killer= new("/d/hangzhou/npc/killer1.lpc");
		else
		killer = new("/d/hangzhou/npc/killer2.lpc");
		killer->move(env);
		message_vision("$N快步走了过来。\n", killer);
    }
    return;
}

int do_guard()
{
    object player = this_player();
	object ob=this_object();
	mapping gate_dir=(["余杭门":"south", "钱塘门":"east", "清波门":"east", "东青门":"west","嘉会门":"north","丽正门":"north","和宁门":"south"]);
    string dir;
	if (player->query("class")!="officer") return 0;

    if (player->query("pin") < 6)
        return notify_fail("你已经不用守城门啦。\n");
    if (player->query_temp("chaoting/newjob/guard/can_pancha")||player->query_temp("chaoting/newjob/guard/can_allow"))
	return notify_fail("你已经在守门了。\n");

    if (!player->query_temp("chaoting/newjob/guard/job"))
	return notify_fail("你得先去问问府尹大人，你今天值班的地方是那儿？\n");
    if (player->query_temp("chaoting/newjob/guard/job") != query("short"))
 	return notify_fail("这里不是你要守的地方。快去"+
	    player->query_temp("chaoting/newjob/guard/job")+"吧。\n");
    if (player->query_temp("chaoting/newjob/guard/day") && NATURE_D->outdoor_room_event()!= "event_sunrise"&&!wizardp(player))
    {
	player->delete_temp("chaoting/newjob/guard");
	return notify_fail("辰时已过你才来城门，今天就不用你守了！\n");
    }

    if (player->query_temp("chaoting/newjob/guard/night") &&NATURE_D->outdoor_room_event()!= "event_evening"&&!wizardp(player))
    {
	player->delete_temp("chaoting/newjob/guard");
	return notify_fail("戌时已过你才来城门，今天就不用你守了！\n");
    }
    player->set_temp("chaoting/newjob/guard/start_job_time", time());
	if (query("short")=="丽正门"||query("short")=="和宁门")
    {
		player->set_temp("chaoting/newjob/guard/can_pancha", 1);
		message_vision("$N一叉腰，对身旁的官兵道：今天看本官如何查问过往闲人。\n",player);
		tell_object(player, "你可以盘查 (pancha) 过往行人。\n");
	}
	else
	{
		player->set_temp("chaoting/newjob/guard/can_allow", 1);
		message_vision("$N一叉腰，对身旁的官兵道：今天有我在，看谁敢带家伙进城。\n",player);
		tell_object(player, "你也可以私放 (allow) 带兵器的人进城。\n");
	}
	dir=gate_dir[COLOR_D->uncolor(ob->query("short"))];
	ob->set("enter_dir",dir);
	player->set_temp("chaoting/newjob/guard/fail_num", 0);
    player->set_temp("chaoting/newjob/guard/kill_num", 0);
	remove_call_out("gen_killer");
	call_out("gen_killer", 1);
    return 1;
}

void reply_pancha(object obj, object shiwei)
{
	int exp,min_exp;
	if (!obj || !shiwei)
		return;
    exp = obj->query("combat_exp");
    min_exp = 80000;

    if (random(exp) < 30000) obj->set_temp("pancha_stage", 4);
    if (member_array(NATURE_D->outdoor_room_event(),({"event_sunrise" ,"event_morning","event_noon","event_afternoon"}))==-1) min_exp = min_exp * 2;
    if (random(exp) > min_exp) obj->set_temp("pancha_stage", 4);

    if (random(exp) < 50000 && obj->query_temp("pancha_stage")==4)
    {
	message_vision("$N低声答道：小人进城观光，请大人高抬贵手。\n", obj);
	message_vision("$N笑道：好吧，慢慢逛吧。\n", shiwei);
	return;
    }
    if (random(exp) < 50000 && obj->query_temp("pancha_stage")==4)
    {
	message_vision("$N答道：在下有公干在身，请大人放行。\n", obj);
	message_vision("$N道：不敢，请。\n", shiwei);
	return;
    }

    if (exp < 400000)
    {
	message_vision("$N嘿嘿嘿笑了两声，道：小人想进城干点勾当。\n", obj);
	message_vision("$N一言不发，陡然向$n发难。\n", obj, shiwei);
    } else  {
	message_vision("$N冷笑了两声，道：你管的着么？\n", obj);
	message_vision("$N大喝一声，狗贼给我让道！\n", obj);
    }
    obj->set_temp("pancha_stage", 3);
    obj->kill_ob(shiwei);
    shiwei->kill_ob(obj);
}

int do_pancha(string name)
{
    object me = this_player(), obj;

    if (! me->query_temp("chaoting/newjob/guard/can_pancha"))
	return 0;

    if (! name || name=="" )
        return notify_fail("你想盘查谁？\n");

    if (!objectp(obj = present(name, environment(me))))
         return notify_fail("这里没有这个人。\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("看清楚点，这不是活人。\n");

    if (!living(obj))
	return notify_fail("等他醒了再说吧。\n");

    if (obj->query_temp("pancha_stage") != 1)
	{
		if (obj->query_temp("pancha_by")==me)
		return notify_fail("你正在盘查他。\n");
		else
		return notify_fail(obj->query_temp("pancha_by")->query("name")+"正在盘查他。\n");
	}
    message_vision("$N对着$n看了两眼，慢吞吞的说道：干什么的呀？\n",
        me, obj);
    obj->set_temp("pancha_stage", 2);
	obj->set_temp("pancha_by",me);
    remove_call_out("reply_pancha");
    call_out("reply_pancha", 2, obj, me);
    return 1;
}
int do_allow(string name)
{
    object me = this_player(), obj;

    if (! me->query_temp("chaoting/newjob/guard/can_allow"))
	return 0;

    if (! name || name=="" )
        return notify_fail("你想让谁进城？\n");

    if (!objectp(obj = present(name, environment(me))))
         return notify_fail("这里没有这个人。\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("看清楚点，这不是活人。\n");

    if (!living(obj))
	return notify_fail("等醒了再说吧。\n");

	if (!me->is_fighting())
	{
    message_vision("$N对着$n大大咧咧地说道："
        "今天官爷心情好，就破例让你进城吧。\n", me, obj);
    	}
    	else if(obj->is_fighting() && obj->query_temp("outer_gate_killer"))
    	{
    		message_vision("$N对着$n说道：算了，算了，好汉不吃眼前亏，就放你进城去吧。”\n", me, obj);
    		if(me->is_fighting(obj)) me->remove_enemy(obj);
    		obj->remove_all_enemy();
    obj->set_temp("outer_gate_allowed", 1);
    me->add_temp("chaoting/newjob/guard/fail_num", 1);
    		obj->do_move();
    		return 1;
    	}
    	else return notify_fail("你还是先解决眼前的敌人再说吧。\n");
    obj->set_temp("outer_gate_allowed", 1);
    me->set_temp("chaoting/newjob/guard/fail_num", 1);
    return 1;
}
void check_auto_kill(object me, object bing, object shiwei)
{
    if (!userp(me))
    {	// npc auto kill
    	if (me->query_temp("attempt_outer_gate"))
    	{
    	    if (bing)
    	    {
    	    	me->set_temp("outer_gate_killer", 1);
        		message_vision("$N对着$n大喝道：挡我者死！\n", me, bing);
        		me->kill_ob(bing);
        		bing->kill_ob(me);
    	    } 
            else if (shiwei)
    	    {
    	    	me->set_temp("outer_gate_killer", 1);
        		message_vision("$N对着$n大喝道：挡我者死！\n", me, shiwei);
        		me->kill_ob(shiwei);
        		shiwei->kill_ob(me);
    	    }
    	}
        else
        {
    	    me->set_temp("attempt_outer_gate", 1);
    	}
    }
}
int valid_leave(object me, string dir)
{
	object *env,bing,shiwei,*shiweis=({}),shiwei2,*shiwei2s=({});
	int i, stage, shiwei_present=0, bing_present = 0,shiwei2_present=0;
	env = all_inventory(environment(me));
	if (!query("is_GaTe")||me->JZ_BING()||me->DASONG_BING())
	return ::valid_leave(me, dir);
	if (userp(me)&&me->query_temp("chaoting/newjob/guard/job")!=query("short")) return ::valid_leave(me, dir);
	for (i=sizeof(env)-1; i>=0; i--) 
	{
		if( living(env[i]) && env[i]->query("id") == "guan bing" )
		bing_present = 1;
		if (userp(env[i]) && living(env[i]) &&env[i]->query("class")=="officer" )
		{
			if (env[i]->query_temp("chaoting/newjob/guard/can_pancha"))
			{
				shiwei2s+=({env[i]});
				shiwei_present=1;
			}
			if (env[i]->query_temp("chaoting/newjob/guard/can_allow"))
			{
				shiwei2_present=1;
				shiweis+=({env[i]});
			}
		}
	}
	if (me->query("class")=="officer" && me->query_temp("chaoting/newjob/guard/job")==query("short"))
	return notify_fail("你还没完成守门的任务呢，怎么能离开？\n");
	if(shiwei2_present&&me->query("HZ_mob")==1) 
	{
		shiwei=shiweis[random(sizeof(shiweis))];
		if (bing_present)
		message_vision("官兵拦住$N说道：看告示了没有？" + "你想进城？先问问"+shiwei->query("name")+"大人吧！\n", me);
		else
		message_vision("$N拦住$n说道：想进城先得过我这关吧？\n", shiwei, me);
		check_auto_kill(me, bing, shiwei);
		return notify_fail("\n");
	}
	if (arrayp(shiwei2s)&&sizeof(shiwei2s)>=1)
	shiwei2=shiwei2s[random(sizeof(shiwei2s))];
	stage=me->query_temp("pancha_stage");
	if (me->query_temp("pancha_by")&&present(me->query_temp("pancha_by"),environment(me))&&living(present(me->query_temp("pancha_by"),environment(me))))
	shiwei2=me->query_temp("pancha_by");
	if (shiwei2)
	switch (stage) 
	{
		case 2:	// shiwei is pancha me, waiting for me to reply
		return notify_fail("守门侍卫正在盘查你呢。\n");
		case 1:
		return notify_fail(shiwei2->query("name")+"指了指你道，你等会儿，我还得查查你呢。\n"); 	// we need to wait for shiwei to pancha us
		case 3:
		shiwei2->add_temp("chaoting/newjob/guard/fail_num", 1);// we are killing shiwei
		message_vision("$N趁着侍卫们不注意，溜了！\n", me);
		me->delete_temp("pancha_stage");
		return ::valid_leave(me, dir);
		case 0:	// ok, we can leave now
		default:
		return ::valid_leave(me, dir);
    }
}


