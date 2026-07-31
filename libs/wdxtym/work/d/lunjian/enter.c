#include <room.h>
inherit ROOM;
#define OUTROOM "/d/fuben/qianchipu/qianchipu"

#define LUNJIAN_DAY			0
#define LUNJIAN_HOUR		21
#define LUNJIAN_PRE			10
#define LUNJIAN_TURN		7
#define LUNJIAN_USER_MIN	5

string *total = ({});
int turn = 0;
mapping allusers = ([]);

private void init_player(object me);
private void message_competition(string msg);
private void auto_check();
private void restore_status(object me);
int check_win(object me);
int check_out(object me);

void create()
{
	set("short", "华山之巅");
	set("long", "这里是华山之巅，也是天下群雄争夺武林至尊的竞技之地。");
	set("exits", ([
		"south" : OUTROOM,
	]));
	set("no_fight",1);
	set("no_fly",1);
	set("objects",([
	]));
	set("action_list",([
		"华山论剑":"jjsign",
		"称号奖励":"lunjiangift",
		"点券兑换":"ljshop",
		"论剑参与奖":"ljsign"
	]));
	setup();
}

void init()
{
	add_action("ljshop","ljshop");
	add_action("jjsign","jjsign");
	add_action("ljsign","ljsign");
	add_action("lunjiangift","lunjiangift");
}

int ljshop(string arg)
{
	string *list,str,file,price;
	int i,yuanbao,value;
	object me,ob;
	int amount;
	mapping goods,times;

	me = this_player();
	goods = ([
		"/clone/lunjian/dan_chongmai4":3,
		"/clone/lunjian/putao":10,
		"/clone/lunjian/wujueling":100,
		"/clone/lunjian/bookbadao":150,
		"/clone/lunjian/wujuetieling":100,
		"/clone/lunjian/xyj":100,
		"/clone/lunjian/book_tianfuxian":5,
		"/clone/lunjian/caomindan":50,
		"/clone/lunjian/da-xidian":50,
	]);
	times = ([
		"/clone/lunjian/wujueling":1,
	]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("lunjian/pot")+"论剑点券，请选择您想兑换的道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,32);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"点券";
			str += sprintf("%s"ZJBR"%s:ljshop look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"点券";
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		if(times[file])
			str += HIR"此物品每个玩家限兑换"+times[file]+"次"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "兑换:ljshop buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];

		if(times[file])
		{
			if(me->query("lunjian/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"此物品每个玩家只能兑换"+times[file]+"次！！"NOR"\n");
			me->add("lunjian/duihuan/"+file->query("id"),1);
		}
		if(me->query("lunjian/pot") < yuanbao)
			return notify_fail(HIM"你的兑换点券不足，多参加参加论剑活动把！！"NOR"\n");
		me->add("lunjian/pot",-yuanbao);
		ob = new(file);
		log_ufile(me,"pay/lunjian", "兑换了"+ob->short()+"。\n");
		tell_object(me,"你成功兑换到了"+ob->short()+"。"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

int valid_leave(object me, string dir)
{
	if(allusers[me->query("id")])
	{
		tell_object(me,"你离开了华山之巅，如果下一轮比赛不在场的话你将失去一次晋级机会。\n");
	}
	return ::valid_leave(me, dir);
}
int ljsign(){
  int now = time();
  object me;
  me = this_player();
  if(me->query("ljsign"))
    return notify_fail("你已经领取过论剑参与奖了！\n");

  if(localtime(now)[6]!=LUNJIAN_DAY)
   return notify_fail("今天好像不是论剑的日子！\n");

  if(me->query("pre_start1"))
    return notify_fail("你好像还没有参与呢\n");

    me->add("jifeng",500);
    me->set("ljsign",1);
    tell_object(me,"你领取了论剑参与奖，点券500\n");

}
int lunjiangift()
{
	object me;
	string str;
	
	me = this_player();
	str = FAMILY_D->bouns_lunjian_leader(me);
	tell_object(me,str);
	return 1;
}

int jjsign()
{
	int now = time();
	object me = this_player();

	if(localtime(now)[6]!=LUNJIAN_DAY
	||localtime(now)[2]!=LUNJIAN_HOUR
	||localtime(now)[1]>LUNJIAN_PRE)
		return notify_fail(ZJOBLONG"报名时间："+LUNJIAN_HOUR+":00-"+LUNJIAN_HOUR+":10。\n");

	if (me->query("combat_exp")<200000)
		return notify_fail("你修为尚浅，还是把功夫练好再来吧。\n");

	if (allusers[me->query("id")])
		return notify_fail("你已经报过名了，目前报名人数："+sizeof(allusers)+"。\n");

	allusers[me->query("id")]=1;
	tell_object(me,"报名成功，请在此稍后，"+LUNJIAN_HOUR+"点10分自动进入竞技场中。\n");
	me->delete("ljsign");
	me->set("pre_start1",1);
	set_heart_beat(1);
	return 1;
}

int sort_total(string user1,string user2)
{
	return (int)allusers[user2]-(int)allusers[user1];
}

private void auto_check()
{
	object tmp1,tmp2,*inv,*rooms,ob;
	string name,msg;
	string *us,room;
	int i;

	rooms = children("/d/lunjian/jingji");
	if(!sizeof(rooms))
	{
		total = sort_array(keys(allusers),(: sort_total :));
		us = filter_array(total, (: find_player($1)&&present(find_player($1),$(this_object())) :));
		if(sizeof(us)<1 || turn >= LUNJIAN_TURN)
		{
			if(allusers[total[0]]<2)
			{
				msg = "听说华山论剑死的死、逃的逃，未能决出【武林至尊】！";
				message_competition(msg);
			}
			else
			{
				if(ob = find_player(total[0]))
					name = ob->query("name");
				else
					name = TOP_D->get_name(total[0]);
				msg = "华山论剑圆满结束，" + name + "奖励100天机点，获得【中神通】的称号！";
				FAMILY_D->set_lunjian_leader("中神通",total[0]);
				message_competition(msg);
                tell_object(ob,"恭喜你获得论剑第一，得到了100天机点，5000灵石奖励\n");
                ob->add("yuanbao",5000);
                ob->add("tianji1",100);
				if(sizeof(total)>1)
				{
					if(ob = find_player(total[1]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[1]);
					msg = name + "奖励40天机点，获得【东邪】的称号！";
					FAMILY_D->set_lunjian_leader("东邪",total[1]);
					message_competition(msg);
				tell_object(ob,"恭喜你获得论剑第二，得到了40天机点，2000灵石奖励\n");
                ob->add("yuanbao",2000);
                ob->add("tianji1",40);
				}

				if(sizeof(total)>2)
				{
					if(ob = find_player(total[2]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[2]);
					msg = name + "奖励20天机点，获得【西毒】的称号！";
					FAMILY_D->set_lunjian_leader("西毒",total[2]);
					message_competition(msg);
					tell_object(ob,"恭喜你获得论剑第三，得到了20天机点，1000灵石奖励\n");
                     ob->add("yuanbao",1000);
                ob->add("tianji1",20);

				}

				if(sizeof(total)>3)
				{
					if(ob = find_player(total[3]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[3]);
					msg = name + "奖励20天机点，获得【南帝】的称号！";
					FAMILY_D->set_lunjian_leader("南帝",total[3]);
					message_competition(msg);
					tell_object(ob,"恭喜你获得论剑第四，得到了20天机点，1000灵石奖励\n");
                    ob->add("yuanbao",1000);
                ob->add("tianji1",20);

				}

				if(sizeof(total)>4)
				{
					if(ob = find_player(total[4]))
						name = ob->query("name");
					else
						name = TOP_D->get_name(total[4]);
					msg = name + "奖励20天机点，获得【北丐】的称号！";
					FAMILY_D->set_lunjian_leader("北丐",total[4]);
					message_competition(msg);
					tell_object(ob,"恭喜你获得论剑第五，得到了20天机点，1000灵石奖励\n");
                    ob->add("yuanbao",1000);
                ob->add("tianji1",20);

				}

				set_heart_beat(0);
				delete("pre_start");
				delete("start");
			}
			allusers = ([]);
			turn = 0;
			return;
		}
		while(sizeof(us)>1)
		{
			tmp1 = find_player(us[0]);
			us -= ({ tmp1->query("id") });
			tmp2 = find_player(us[0]);
			us -= ({ tmp2->query("id") });
			init_player(tmp1);
			init_player(tmp2);
			room = new("/d/lunjian/jingji");
			tmp1->move(room);
			tmp2->move(room);
			tmp1->kill_ob(tmp2);
			tmp2->kill_ob(tmp1);
		}
		if(sizeof(us))
		{
			ob = find_player(us[0]);
			ob->add("lunjian/pot",1);
			allusers[us[0]] += 1;
			tell_object(ob,"你在本轮竞技中幸运轮空，自动晋级，请等待下一轮匹配。\n");
			log_ufile(ob,"lunjian","轮空晋级，点券增加1。\n");
		}
		turn++;
		return;
	}
	for (i = 0; i < sizeof(rooms); i++)
	{
		inv = filter_array(all_inventory(rooms[i]),(: playerp($1) :));
		if(!sizeof(inv))
			destruct(rooms[i]);
		else if(sizeof(inv)==1)
		{
			allusers[inv[0]->query("id")]++;
			inv[0]->add("lunjian/pot",1);
			log_ufile(inv[0],"lunjian","胜利晋级，点券增加1。\n");
			check_win(inv[0]);
		}
	}
}

private void init_player(object me)
{
	tell_object(me, HIY "你来到了华山论剑的比武场..."NOR"\n");
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/want", me->query_want());
	me->set_temp("in_pkd", 1);

	me->set("backup/condition", me->query_condition());
	me->clear_condition();
}

private void message_competition(string msg)
{
	CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

private void restore_status(object me)
{
	mapping my;
	mapping cnd;
	string *ks;
	int i;

	me->delete_temp("in_pkd");
	me->delete_override("unconcious");
	me->delete_override("die");
	me->delete_override("quit");
	me->remove_all_enemy(1);
	me->remove_all_killer();
	me->clear_condition();
	me->receive_damage("qi", 0);
	me->apply_killer(me->query_temp("backup/killer"));
	me->apply_want(me->query_temp("backup/want"));

	cnd = me->query("backup/condition");
	me->delete("backup/condition");
	me->delete_temp("block_msg/all");
	if (! mapp(cnd)) return;
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];
}

void heart_beat()
{
	int i,now = time();
	object tmp1,tmp2,room,*inv;
	string msg;

	room = this_object();

	if(!query("pre_start")&&localtime(now)[1]==LUNJIAN_PRE)
	{
		set("pre_start",1);
		tell_room(this_object(),"1分钟后将进入竞技场，请做好准备。。。\n");
	}
	else if(!query("start")&&localtime(now)[1]==(LUNJIAN_PRE+1))
	{
		set("start",1);
		inv = filter_array(all_inventory(this_object()), (: playerp($1)&&$(allusers)[$1->query("id")] :));
		if(sizeof(inv)<LUNJIAN_USER_MIN)
		{
			msg = "听说本次华山论剑参与人数太少，活动未能成功进行！";
			message_competition(msg);
			delete("pre_start");
			delete("start");
			set_heart_beat(0);
			return;
		}
		while(sizeof(inv)>1)
		{
			tmp1 = inv[random(sizeof(inv))];
			inv -= ({ tmp1 });
			tmp2 = inv[random(sizeof(inv))];
			inv -= ({ tmp2 });
			init_player(tmp1);
			init_player(tmp2);
			room = new("/d/lunjian/jingji");
			tmp1->move(room);
			tmp2->move(room);
			tmp1->kill_ob(tmp2);
			tmp2->kill_ob(tmp1);
		}
		if(sizeof(inv))
		{
			allusers[inv[0]->query("id")] += 1;
			tell_object(inv[0],"你在本轮竞技中幸运轮空，自动晋级，请等待下一轮匹配。\n");
		}
	}
	else if(localtime(now)[1]>LUNJIAN_PRE)
	{
		auto_check();
	}
}

int check_quit(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);

	tell_object(me, "你逃出了竞技场。\n");

	me->move(this_object());
	message("vision", "只见" + me->name() + "慌里慌张的跑了出来。\n",environment(me), ({ me }));
	return 1;
}

int check_out(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n你觉得眼前一阵模糊...这下完了！"NOR"\n");

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);
	me->move(this_object());
	message("vision", "一个黑影倏的窜了出来，随即就是“啪”的一声，就见" + me->name() +"摔倒了地上，一副半死不活的样子。\n", environment(me), ({ me }));
	tell_object(me, "半昏半迷中，你觉得被人拎了起来，又重重的摔倒了地上。\n");
	me->delete("pre_start1");
	if (! living(me))
		me->revive();
	return 1;
}

int check_win(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n你在本轮论剑中获胜晋级！"NOR"\n");

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);
	me->move(this_object());
    me->delete("pre_start1");
	return 1;
}
