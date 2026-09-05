//九州画廊

#include <ansi.h>
#include <room.h>
#include <present.h>

inherit ROOM;
int lvl;
int do_qiao(string);
int give_reward(object me);
int do_look(string dir);
int do_get(string);
int do_push(string arg);
int do_kill(string arg);
int do_killall(string arg);
string look_brick(string arg);

void build_name(int lv)
{
	string *shorts = ({ "冀州", "兖州", "青州", "徐州", "扬州", "荆州", "豫州", "梁州", "雍州", });
	string short_name;
	short_name = shorts[lv-1];
	set("short", HIY "第" + chinese_number(lv) + "画廊" HIG "·" HIC + short_name + NOR);
	set("long", 
"这是一间极尽奢华的巨大房间，黄琉璃瓦顶的正中雕有盘卧的巨龙，威武的龙头
往下探着，口衔着宝珠。四周墙边摆着象征江山万代的铜龟、铜鹤，它们摆着优美的
姿势望着远方。铜柱上雕着龙、凤、狮等十个走兽，栩栩如生，两侧有宝象、仙鹤等
陈设，各色装饰的豪华令人叹为观止。石壁上挂着一副巨大的地图，仔细一看，竟是\n"
+HIC + "「" + short_name + "」" NOR "一带的军事布防地形图。\n" );
	set("item_desc", ([
		"wall" : "一堵雪白的墙面，看上去有点奇怪，或许可以推(push)一下试试。\n",
		"brick" : (: look_brick :),
	]));
}

string look_brick(string arg)
{
	if (!this_player()->query_temp(sprintf("lvliu_jiuzhou/%d", lvl)))
			return "你东张西望，看了半天，也没发现地上的砖有什么特别的地方。\n";
	return "守卫武士出现的地方，似乎地砖是活动的，用力敲(qiao)一下就可以离开这里了。\n";
}

int person_count(int check_user)
{
	object *allob = all_inventory(this_object());
	int c = 0;
	for (int i=0;i<sizeof(allob);i++)
	{
		if (!allob[i]->is_character()) continue;
		if (check_user)
		{	
			if (userp(allob[i])) c++;
		}
		else 
		{
			if (!userp(allob[i])) c++;
		}
	}
	return c;
}

object teammate(object me)
{
	object *allob;
	if (!objectp(me)) return 0;
	allob = all_inventory(environment(me));
	for (int i=0;i<sizeof(allob);i++)
	{
		if (userp(allob[i]) && allob[i] != me) return allob[i];
	}
	return 0;
}

void clean_up_this_room()
{
	object *allob;
	if (person_count(1)>0) return; 
	allob = all_inventory(this_object());
	for (int i=0;i<sizeof(allob);i++)
	{
		if (!userp(allob[i])) destruct(allob[i]);
	}
}

void npc_arise(object me, object mate, int rate)
{
    int target_num;
	object ob;
	if (!objectp(me)) return ;
	if (lvl<=2)
	{
		target_num = 2;
	}
	else if (lvl==3)
	{
		target_num = 2 + random(2); //2-3
	}
	else if (lvl==4)
	{
		if (random(lvl)==0)
			target_num = 2;
		else
			target_num = 2 + random(3); //2-4
	}
	else if (lvl==5)
	{
		if (random(lvl)==0)
			target_num = 3;
		else
			target_num = 3 + random(3); // 3-5
	}
	else // (lvl>=6)
	{
		if (random(lvl)==0)
			target_num = 2 * (lvl-2); 
		else
			target_num = 2 * (lvl-2) + random(3); 
		//lv6:8-10; lv7:10-12; lv8:12-14; lv9:14-16
	}

   	for (int a=0; a<target_num; a++ )
   	{
   		ob = new(__DIR__"npc/shouwei");
   		ob->set("job_level", lvl);
   		ob->do_copy(me, rate);
   		ob->move(this_object());
		if (rate>1)
			tell_room(this_object(), HIM + ob->query("name") + HIM "大吼一声，将内力灌注于双臂，顿时觉得充满了力量。\n"NOR);
		ob->set("uni_target/1", me);
   		ob->kill_ob(me);
   		me->kill_ob(ob);
		if (objectp(mate)) 
		{
			ob->set("uni_target/2", mate);
			ob->kill_ob(mate);
			mate->kill_ob(ob);
		}
    }
	me->set_temp(sprintf("lvliu_jiuzhou/%d",lvl),1);
	me->set_temp("lvliu_jiuzhou/lvl",lvl);
	if (objectp(mate)) 
	{
		mate->set_temp(sprintf("lvliu_jiuzhou/%d",lvl),1);
		mate->set_temp("lvliu_jiuzhou/lvl",lvl);
	}
}

// 检查房间里有没有打完一波武士还赖着不走的家伙
int invalid_start()
{
	object *allob;
	string mark;
	allob = all_inventory(this_object());
	mark = sprintf("lvliu_jiuzhou/%d", lvl); 
	for (int i=0;i<sizeof(allob);i++)
	{
		if (userp(allob[i]) && allob[i]->query_temp(mark)) return 1;
	}
	return 0;
}

int do_push(string arg)
{
	object *ob, mate;
	object me=this_player();
	int i;
	if (!arg || arg!="wall")
		return notify_fail("你要推什么？\n");
	ob = all_inventory(this_object());
    for(i=0; i<sizeof(ob); i++)
    {
        if( ob[i]->query("lvliu_jiuzhou_shouwei"))
            return notify_fail("战斗还没结束，你腾不出手去推什么东西！！\n");
    }
	
	if ((int)me->query("lvliu/jiuzhou/start")>time()) // 任务CD中，背进来的？赶出去
	{
		message_vision(HIM"$N伸手在墙上一推，脚下的地砖忽然翻开，原来是个陷阱，$P一下掉了进去。\n"NOR, me);
		tell_object(me, HIC"噗的一下，你掉到一团干草堆上。立马有几位武士扑上来，七手八脚地把你抓住了……\n"
			+HIY"现场一片混乱，只听到有人高喊：「又抓住了一个！」\n\n"NOR);
		me->delete_temp("lvliu_jiuzhou");
		me->move(__DIR__"prison");
		message_vision(HIY"牢门一开，几个武士把$N扔了进来。\n"NOR, me);
		me->set("lvliu/jiuzhou/start",time()+900); 
		return 1;
	}
	
	if (!me->query_temp(sprintf("lvliu_jiuzhou/%d", lvl)))
	{ 
		if (invalid_start())
		{
			message_vision(HIY"$N伸手用力推墙，但是墙壁纹丝不动。也许应该换个人来试试……\n"NOR, me);
			return 1;
		}
		// 进入战斗
		message_vision(HIR"\n$N伸手在墙上一推，传来一阵机关运转的声响，墙角的地砖忽然翻开，跳出一群武士来……\n\n"NOR, me);
		mate = teammate(me);
		if (objectp(mate))
		{
			if ((int)mate->query("combat_exp") > (int)me->query("combat_exp"))
				npc_arise(mate, me, ((int)mate->query("combat_exp")>(2*(int)me->query("combat_exp"))?2:1));
			else
				npc_arise(me, mate, ((int)me->query("combat_exp")>(2*(int)mate->query("combat_exp"))?2:1));
		}
		else 
			npc_arise(me, 0, 1);
	}
	else
	{ // 过关离开
		message_vision(HIW"\n$N伸手在墙上一推，墙面忽然悄无声息地一转，露出了隐藏在墙后的密室。\n"
			"没等$N反应过来，翻转的墙面撞在$P身后。$P跌跌撞撞地冲进密室，迈了四五步才稳住脚步。\n"
			"墙面立时又紧紧地合上了，接缝之处影灭迹绝，就像从来都没有移动过一般。\n\n", me);
		if (lvl<9)
			me->move(__DIR__"jiuzhou_mishi"+sprintf("%d",lvl+1));
		else {
			me->move(__DIR__"jiuzhou_end");
			me->set("lvliu/jiuzhou/start",time()+900-(lvl-1)*60);   
			give_reward(me);
			me->set_temp("lvliu/jiuzhou/pass", 1);
		}
		me->remove_listen_to_die(this_object());
		clean_up_this_room();
	}
	return 1;
}

void init()
{
	object me=this_player();
    object room;

	room = this_object();
	lvl = room->query("room_lvl");

	if (!userp(me) && !me->query("lvliu_jiuzhou_shouwei"))
	{
		me->move(__DIR__"houting");
		return;
	} //无关人等退场

	if (userp(me) && !wizardp(me) // 人太多或者任务CD未到（背进来的）
		&& (person_count(1)>2 || (int)me->query("lvliu/jiuzhou/start")>time()))
	{
		message_vision(HIM"$N脚下的地砖忽然翻开，原来是个陷阱，$P一下掉了进去。\n"NOR, me);
		tell_object(me, HIC"噗的一下，你掉到一团干草堆上。立马有几位武士扑上来，七手八脚地把你抓住了……\n"
			+HIY"现场一片混乱，只听到有人高喊：「又抓住了一个！」\n\n"NOR);
		me->delete_temp("lvliu_jiuzhou");
		me->move(__DIR__"prison");
		message_vision(HIY"牢门一开，几个武士把$N扔了进来。\n"NOR, me);
		me->set("lvliu/jiuzhou/start",time()+900); 
		return;
	}

	add_action("do_qiao","qiao");       
	add_action("do_jiangli","jiangli");
	add_action("do_quit","quit");
	add_action("do_alert","alert");
	add_action("do_push","push");
	add_action("do_kill", "kill");
	add_action("do_kill", "hit");
	add_action("do_killall", "killall");
	add_action("do_killall", "hitall");

	if (userp(me) && !wizardp(me))
	{
		me->delete_temp("lvliu_jiuzhou/into_mishi");
		me->delete_temp("lvliu_jiuzhou/confirm_leave");
		if (lvl==1) me->set_temp("task_stat/lvliu_jiuzhou/start_time",time());
		COMBAT_D->add("task_stat/lvliu_jiuzhou/"+ lvl + "/times", 1);
	}

    me->listen_to_die(room);
}

int do_quit()
{
    write("擅闯山庄重地，居然想走？\n");
    return 1;
}

int do_alert(string arg)
{
	if(this_player()->is_busy()) return 0;
	tell_object(this_player(),"这里与世隔绝，谁也听不到你的召唤，你还是靠自己吧。\n");
	this_player()->add_busy(random(3)+3);
	return 1;
}

// prevent_die() 优先级大于 die_notify()
int prevent_die(object me)
{
	object tasknpc;
	if (!objectp(me) || !userp(me))
		return 0;
	message("vision", HIY"\n几个武士趁乱把死猪一样的"+me->query("name")+HIY"拖走了。\n\n"NOR, environment(me), ({ me }));
	me->clear_condition();
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", 1);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", 1);
	me->add("lvliu/jiuzhou/fail_times",1);
	me->delete_temp("lvliu_jiuzhou");
	me->set("lvliu/jiuzhou/start",time()+900-(lvl-1)*60);   
	if(!living(me) || me->query_temp("lvliu_jiuzhou_goingto_unconcious"))
	{
		if(!living(me)) me->revive();
		me->start_busy(5);
		me->delete_temp("lvliu_jiuzhou_goingto_unconcious");
		tell_object(me, HIC"哗的一声，一桶冷水泼在你的头上，你顿时一个激灵，醒了过来。\n\n"NOR);
	}
	me->remove_listen_to_die(this_object());
	me->move(__DIR__"prison");
	message_vision(HIY"几个武士叉着精疲力竭的$N进了黑牢，打开牢门把$P往里一扔。\n"NOR, me);
	tasknpc = find_object(__DIR__"npc/zongguan");
	if (objectp(tasknpc))
		CHANNEL_D->do_channel(tasknpc, "chat", "很好，又抓住了一个来九州画廊捣乱的！");	
//	if (living(me))
//		me->unconcious();
	return 1;
}

int prevent_unconcious(object me)
{
	if (userp(me)) {
		me->set_temp("lvliu_jiuzhou_goingto_unconcious", 1 );
		message("system", HIR "\n你的眼前一黑，再也支撑不住，一头栽倒在地。\n" HIY "几个武士趁乱把你拖走了……\n\n" NOR,  me);
		prevent_die(me);
		return 1;
	}
	return 0;
}

//当有玩家在此死亡时调用
//有 prevent_die() 时其实这个没用……
int die_notify(object victim)
{
	string system_msg;
	object tasknpc;
	int re,qn,exp;

    if(userp(victim))
    {
        victim->remove_listen_to_die(this_object());
        victim->receive_damage("qi", 0, "在九州画廊的第"+chinese_number(lvl)+"画廊力战而");
		if (environment(victim) != this_object())
		{
			victim->delete_temp("lvliu_jiuzhou");
			return 0;
		}
		if (0) //任务失败暂不倒扣，预留功能
		{
			if (query("room_lvl")>1 && query("room_lvl")<=6)
			{
				re = victim->query_temp("lvliu_jiuzhou/reward_re2");
				qn = victim->query_temp("lvliu_jiuzhou/reward_qn2");
				exp = victim->query_temp("lvliu_jiuzhou/reward_exp2");
			} 
			else if (query("room_lvl")>=7)
			{
				re = victim->query_temp("lvliu_jiuzhou/reward_re2")/5*2;
				qn = victim->query_temp("lvliu_jiuzhou/reward_qn2")/5*2;
				exp = victim->query_temp("lvliu_jiuzhou/reward_exp2")/5*2;
			}
			re=REWARD_D->add_rep(victim,-re);
			qn=REWARD_D->add_pot(victim,-qn);
			exp=REWARD_D->add_exp(victim,-exp);
			victim->add("exp/lvliu_jiuzhou", exp);
			system_msg = victim->query("name")+"在「绿柳山庄·九州画廊」任务中损失";
			system_msg += re+"点江湖声望、";
			system_msg += qn+"点潜能，";
			system_msg += exp+"点经验";
			system_msg += "。";
			tasknpc = find_object(__DIR__"npc/zongguan");
			if (objectp(tasknpc))
				CHANNEL_D->do_channel(tasknpc, "sys_misc", system_msg);	
		}
		victim->add("lvliu/jiuzhou/fail_times",1);
        victim->delete_temp("lvliu_jiuzhou");
    }
    return 1;
}

int do_jiangli()
{
	object me=this_player();
	string jiangli_msg;
	if (!this_player()->is_fighting())
	{
		jiangli_msg="现在退出的话，你现在可以获得奖励：\n";
		jiangli_msg += "  "+ chinese_number(REWARD_D->check_rep(me->query_temp("lvliu_jiuzhou/reward_re")))+"点江湖声望\n";
		jiangli_msg += "  "+ chinese_number(REWARD_D->check_pot(me->query_temp("lvliu_jiuzhou/reward_qn")))+"点潜能\n";
		jiangli_msg += "  "+ chinese_number(REWARD_D->check_exp(me->query_temp("lvliu_jiuzhou/reward_exp")))+"点经验。\n";
		write(jiangli_msg);
		return 1;
	}
	write("等你能活下来，再考虑这些问题吧……\n");
	return 1;
}

int do_qiao(string arg)
{
	int i;
    object *ob;
	object me=this_player();
    ob = all_inventory( environment( me ));

    for(i=0; i<sizeof(ob); i++)
    {
        if( ob[i]->query("lvliu_jiuzhou_shouwei"))
            return notify_fail("战斗还没结束，你腾不出手去敲什么东西！！\n");
    }

	if (arg && arg == "brick")
	{
		if (!me->query_temp(sprintf("lvliu_jiuzhou/%d", lvl)))
			return notify_fail("你东张西望，看了半天，也没发现有什么可以敲的地方！\n");
		
		me->remove_listen_to_die(this_object());
		message_vision(HIC"$N在守卫武士出现的地方摸了半天，找到一块空心地砖，用力一敲，地砖忽然翻转开了……\n"NOR, me);
        me->move(__DIR__"houting");
		message_vision(HIY"噗通一声，$N从上方掉了下来，拍拍屁股上的尘土，长吁了一口气。\n"NOR, me);
		me->set("lvliu/jiuzhou/start",time()+900-(lvl-1)*60);   
		call_out("give_reward",1,me);
		clean_up_this_room();
		return 1;
	}
	return notify_fail("你要敲什么东西？\n");
}

int give_reward(object me)
{
    string msg,system_msg,channel_msg;
	int reward, add, i, cost_time;
	object tasknpc;
	object box;
	int exp,pot,rep;

	if (!me) return 1;
	if (!me->query("biography/jobs/lvliu/jiuzhou"))
	{
		me->set("biography/jobs/lvliu/jiuzhou",time());//个人传记记录第一次完成任务时间
	}
	system_msg = me->query("name")+"在「绿柳山庄·九州画廊」中获得奖励";
	channel_msg = me->query("name")+"在「绿柳山庄·九州画廊」中闯过第"+chinese_number(query("room_lvl"))+"画廊，被奖励";

    if(!objectp(me)) return 1;

	add = 100;
	if (SPECIAL_D("lucky")->active_level(me)>=2 && me->query("age")>=18) //有lucky的玩家奖励多10%
	{
		add = 110;
		write( HIM"你拥有的特技「洪福齐天」提高了任务奖励。\n"NOR);
	}
	write(HIW"你被奖励了：\n");

	exp = REWARD_D->add_exp(me, add*(int)me->query_temp("lvliu_jiuzhou/reward_exp")/100);
	me->add("exp/lvliu_jiuzhou", exp);
	write("\t"+chinese_number(exp)+"点经验；\n");
	system_msg += exp+"点经验，";
	channel_msg += chinese_number(exp)+"点经验、";

	pot = REWARD_D->add_pot(me, add*(int)me->query_temp("lvliu_jiuzhou/reward_qn")/100);
	write("\t"+chinese_number(pot)+"点潜能；\n");
	system_msg += pot+"点潜能，";
	channel_msg += chinese_number(pot)+"点潜能、";

	
	rep = REWARD_D->add_rep(me, add*(int)me->query_temp("lvliu_jiuzhou/reward_re")/100);
	write("\t"+chinese_number(rep)+"点江湖声望。\n\n"+NOR);
	system_msg += rep+"点江湖声望";
	channel_msg += chinese_number(rep)+"点江湖声望！";

	me->add("lvliu/credit", (lvl*lvl*lvl)/10 + 1);

	COMBAT_D->add("task_stat/lvliu_jiuzhou/"+ query("room_lvl") + "/reward/reputy",rep);
	COMBAT_D->add("task_stat/lvliu_jiuzhou/"+ query("room_lvl") + "/reward/potential",pot);
	COMBAT_D->add("task_stat/lvliu_jiuzhou/"+ query("room_lvl") + "/reward/exp",exp);
	//taskview统计
	if (userp(me))
	{
		COMBAT_D->add("task_stat/lvliu_jiuzhou/complete_times",1);
		COMBAT_D->add("task_stat/lvliu_jiuzhou/cost_time",time()-me->query_temp("task_stat/lvliu_jiuzhou/start_time",time()));
		COMBAT_D->add("task_stat/lvliu_jiuzhou/exp",exp);
		COMBAT_D->add("task_stat/lvliu_jiuzhou/pot",pot);
		COMBAT_D->add("task_stat/lvliu_jiuzhou/repute",rep);
		COMBAT_D->add("task_stat/lvliu_jiuzhou/expratio", to_float(exp)/me->query("combat_exp"));
	}
	me->add("lvliu/jiuzhou/times",1);
	if (lvl>=7)
		me->add("lvliu/jiuzhou/7up_times",1);
	me->delete_temp("task_stat/lvliu_jiuzhou");
	me->delete_temp("lvliu_jiuzhou");

	tasknpc = load_object(__DIR__"npc/zongguan");
	if (objectp(tasknpc))
	{
		if(lvl >=7 )
		{
			CHANNEL_D->do_channel(tasknpc, "rumor", channel_msg);
		}	
		system_msg += "。";
		CHANNEL_D->do_channel(tasknpc, "sys_misc", system_msg);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
    if (userp(me))
		me->remove_listen_to_die(this_object());
    return ::valid_leave(me, dir);
}

int do_kill(string arg)
{
	string msg ;
	object npc, me = this_player();
	if (!arg) return 0;
	if( !objectp(npc = present_npc(arg, environment(me))) || !npc->query("lvliu_jiuzhou_shouwei") )
		return 0;
	if ( !living(npc))
	{
		msg = HIM"\n$N对着$n大吼一声：「敢拦" + RANK_D->query_self_rude(me) + "的财路，受死吧！」\n\n"NOR;
		message_vision(msg, me, npc);
		me->kill_ob(npc);
		return 1;
	}
	else if ( me == npc->query("uni_target/1") || me == npc->query("uni_target/2") )
	{
		msg = HIM"\n$N对着$n大吼一声：「敢拦" + RANK_D->query_self_rude(me) + "的财路，受死吧！」\n\n"NOR;
		message_vision(msg, me, npc);
		me->kill_ob(npc);
		npc->kill_ob(me);
		return 1;
	}
	return 0;
}

int do_killall(string arg)
{
	object me = this_player();
	object *obs;
	message_vision( HIM"\n$N双眼通红，大吼一声：「拦" + RANK_D->query_self_rude(me) + "财路的，通通都去死吧！」\n\n"NOR, me);
	obs = all_inventory(environment(me));
	for (int i=0; i<sizeof(obs); i++)
	{
		if (!obs[i]->query("lvliu_jiuzhou_shouwei")) continue;
		if ( me == obs[i]->query("uni_target/1") || me == obs[i]->query("uni_target/2") )
		{
			me->kill_ob(obs[i]);
			obs[i]->kill_ob(me);
		}
	}
	return 1;
}

