inherit NPC;
#include <ansi.h>
#include "cs_map.h"

#define CT_ROOM	__DIR__"ctroom"
#define T_ROOM	__DIR__"troom"
#define DIE_ROOM	__DIR__"die_room"
#define TimeLimitPerRound 300
//防止机器人玩获利，如果有机器人现象，#define Anti_robot 1
#define Anti_Robot	1		

string play();
string start();
void DeclairTWin();
void DeclairCTWin();
void Declair(string team, string msg);
void NextGame();
int  EndGame();
void Reward(object me, string type, int kills);

nosave int TCount = 0, CTCount = 0, TLifes = 0, CTLifes = 0;
#define MAX_DIFFERENCE  0

void StartGame();
void StopGame();

void create()
{
	set_name("反恐精英大赛裁判",({"referee","caipan"}));
	set("nickname","恐怖之王");
	set("long",@LONG
他是一位五十来岁的中年人。
传说他帮拉登安过雷，教萨达姆打过枪。
LONG);
	set("str",20);
	set("age",58);
	set("max_qi",3000);
	set("combat_exp",10000000000);
	set_skill("unarmed",20);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
	
	set("inquiry",([
				"比赛"	:	(:play:),
				"play"	:	(:play:),
				"开始"	:	(:start:),
				"start"	:	(:start:),
              	]));

}

int die(object ob)
{
	object* allitem;
	int i, kills;
	if(!ob || !ob->query_temp("cs"))
		return 0;
	if(ob->query_temp("cs/die"))			//刚加入游戏，被设置了die
	{
		ob->move(__DIR__"die_room");
		return 1;
	}
	allitem = all_inventory(ob);
	for(i = 0; i < sizeof(allitem); i++)
	{
		if(allitem[i]->query("cs/type") > 1)		//#define	CS_MAINGUN	3
		{
			message_vision(NOR"$N倒在血泊中，手中的" + allitem[i]->query("name") + "掉了出来。\n", ob);
			if(query_temp("started"))
				allitem[i]->move(environment(ob));
			else
				destruct(allitem[i]);
		}
		else if(allitem[i]->query("cs/type"))
			destruct(allitem[i]);
	}
	ob->set_temp("cs/die", 1);
	ob->move(__DIR__"die_room");
	
	if(ob->query_temp("cs/killedby"))
	{
		kills = 1;
		if(ob->query_temp("cs/killedbyheadshot"))
			kills *= 2;
		if(ob->query_temp("cs/killedbyknife"))
			kills *= 2;
		ob->query_temp("cs/killedby")->add_temp("cs/kills", kills);
		Reward(ob->query_temp("cs/killedby"), "kill", kills);
		ob->add("cs/kills",kills);
	}
	ob->add_temp("cs/killeds", 1);	
	ob->add("cs/killeds", 1);		
	ob->delete_temp("cs/killedbyheadshot");
	ob->delete_temp("cs/killedbyknife");
	ob->delete_temp("cs/killedby");
	
	if(ob->query_temp("cs/team") == "t")
		TLifes--;
	else
		CTLifes--;
	if(CTLifes <= 0 && TLifes > 0 && CTCount > 0 && TCount > 0)
		DeclairTWin();
	if(TLifes <= 0 && CTLifes > 0 && !query_temp("bomb_position") && CTCount > 0 && TCount > 0)
		DeclairCTWin();

	return 1;
}

int SelectTeamForPlayer(object ob, string team)
{
	string targetTeam;
	int count = 0;
	if(!ob->query_temp("cs/card"))
		return 0;
	if(team == "auto")
	{
		if(TCount == CTCount)
			targetTeam = random(2) ? "ct" : "t";
		else if(TCount >= CTCount + MAX_DIFFERENCE)
			targetTeam = "ct";
		else if(CTCount >= TCount + MAX_DIFFERENCE)
			targetTeam = "t";
		else
			targetTeam = random(2) ? "ct" : "t";
	}
	else if(team == "t")
	{
		if(TCount >= CTCount + MAX_DIFFERENCE)
			return 0;
		else 
			targetTeam = "t";
	}
	else //if(team == "ct")
	{
		if(CTCount >= TCount + MAX_DIFFERENCE)
			return 0;
		else
			targetTeam = "ct";
	}
	
	if(ob->query_temp("cs/team") == targetTeam)
		return 0;
	die(ob);	//进入死亡房间
	if(ob->query_temp("cs/team"))
		count = 1;
	ob->set_temp("cs/team", targetTeam);
	if(targetTeam == "ct")		//join ct
	{
		Declair("all",  ob->query("name") + "(" + ob->query("id") + ")加入了警察组！" );
		CTCount++;
		TCount -= count;
		ob->set_temp("cs/teamname",HIB" <警察>"NOR);
	}
	else
	{
		Declair("all",  ob->query("name") + "(" + ob->query("id") + ")加入了匪徒组！" );
		TCount++;
		CTCount -= count;
		ob->set_temp("cs/teamname",HIY" <匪徒>"NOR);
	}
	if(CTCount >= 1 && TCount >= 1 && !query_temp("started"))
		NextGame();
	return 1;
}

int quit(object ob)
{
	
	if(ob->query_temp("cs/team") == "ct")
		CTCount--;
	else
		TCount--;
	die(ob);
	ob->delete_temp("cs");
	Declair("all",  ob->query("name") + "(" + ob->query("id") + ")退出了反恐精英大赛！" );
	ob->move(environment());
	if(CTCount <= 0 || TCount <= 0)
		StopGame();
}
void QuitGame()
{
	int i;
	object* cards = children(__DIR__"obj/card");
	object target;
	Declair("all", " 比赛结束！\n");
	delete_temp("started");
	StopGame();	
	for(i = 0; i < sizeof(cards); i++)
	{
		target = cards[i]->query("owner");
		if(!target || !target->query_temp("cs"))
			continue;
		target->delete_temp("cs/die");
		quit(target);
		destruct(cards[i]);
	}
}
string play()
{
	object me = this_player();
	object ob;
	int robottimes, denytime;
	if(me->query_temp("cs"))
		return("怎么样，被杀得爽不爽？\n");
	command("look " + me->query("id"));
	if(me->query("combat_exp") < 50000)
		return("你太嫩了，去钓鱼混点经验再来吧。\n");
	if(Anti_Robot)
	{
		robottimes = me->query("cs/robot_times");	//怀疑为robot的次数
		if(robottimes < 0)
			robottimes = 0;
		denytime = robottimes * 10 + 60 + me->query_temp("log/time") - time();
		if(denytime > 0)
		{
			//如果在登陆后很短的时间内加入cs，则计算怀疑次数，增加的次数按平方根增长
			robottimes = robottimes + robottimes < 3 ? 1 : to_int(sqrt(robottimes));
			me->set("cs/robot_times", robottimes);		

			if(robottimes > 3)
			{
				//怀疑次数超过10次，拒绝本次加入请求
				denytime = robottimes * 10 + 60 + me->query_temp("log/time") - time();
				message_vision(query("name") + "对着$N上上下下打量了一番，说道：\"我强烈怀疑你是机器人，想忽悠我？！\"\n", me);
				tell_object(me, HIR"公平竞赛，允许机器人参加比赛，但是杜绝利用机器人获利！\n"NOR);
				tell_object(me, HIR"请你于" + chinese_number((denytime/600 + 1) * 10) + "分钟后再来比赛。\n"NOR);
				return("一边凉快去!\n");
			}
			//如果在登陆后很短的时间内加入cs，则计算怀疑次数，增加的次数按平方根增长
			me->add("cs/robot_times", robottimes < 3 ? 1 : to_int(sqrt(robottimes)));
		}
		else if(robottimes > 1 && !me->query_temp("join_cs_after_login"))
		{
			me->add("cs/robot_times", -1);
			me->set_temp("join_cs_after_login", 1);
		}
	}
	ob=new(__DIR__"obj/card");
	ob->set("owner", me);
	ob->set("referee", this_object());
	ob->move(me);
	me->set_temp("cs/card",ob);
	me->set_temp("cs/skill", me->query_skill("cs-skill", 1));
	me->set_temp("cs/hp",(1000 + me->query_temp("cs/skill")) / 10);
	me->set_temp("cs/die", 1);
	me->set_temp("cs/money",1000);
	command("ok " + me->query("id"));
	SelectTeamForPlayer(me, "auto");
	return("嗯，那给你一块参赛牌吧。好好干，别垫底！\n");
}

string start()		//比赛开始
{
	if(query_temp("started"))
		return("比赛已经开始了啊！\n");
	if(TCount <= 0 || CTCount <= 0)
		return("对手都没有，怎么开始？\n");
	set_temp("started",1);
	NextGame();
	return("好吧，你们赶紧去准备，我这就安排场地，比赛马上就开始！\n");
}

void NextGame()
{
	if(TCount <= 0 || CTCount <= 0)
	{
		Declair("all", " 反恐精英大赛结束！");
		delete_temp("started");
		return;
	}
	if(query_temp("started"))
		return;
	set_temp("started",1);
	remove_call_out("StartGame");
	call_out("StartGame", 0);
}    
void DeclairTWin()
{
	Declair("all", " 匪徒取得胜利！\n");
	set_temp("last_win_team", "t");
	StopGame();
	NextGame();
}
void DeclairCTWin()
{
	Declair("all", " 警察取得胜利！\n");
	set_temp("last_win_team", "ct");
	StopGame();
	NextGame();
}

void Declair(string team, string msg)
{
	object* cards = children(__DIR__"obj/card");
	object target;
	int i;
	for(i = 0; i < sizeof(cards); i++)
	{
		target = cards[i]->query("owner");
		if(!target || !target->query_temp("cs"))
			continue;
		if(team == "all" || target->query_temp("cs/team") == team)
		{
			tell_object(target, msg + NOR"\n");
		}
	}
}
void DestructWeapon(string weapon)
{
	object* weapons = children(weapon);
	int i;
	for(i = 0; i < sizeof(weapons); i++)
	{
		if(!environment(weapons[i]) || !userp(environment(weapons[i])))
			destruct(weapons[i]);
	}
}
void StopGame()
{
	delete_temp("bomb_position");
	if(query_temp("c4"))
	{
		destruct(query_temp("c4"));
		delete_temp("c4");
	}
	delete_temp("started");
	DestructWeapon(__DIR__"obj/ak47");
	DestructWeapon(__DIR__"obj/awp");
	DestructWeapon(__DIR__"obj/deserteagle");
	DestructWeapon(__DIR__"obj/knife");
	DestructWeapon(__DIR__"obj/m4a1");
}
void StartGame()
{
	object* cards = children(__DIR__"obj/card");
	object target,c4, knife;
	int i,c4carrier;
	c4carrier = random(TCount);
	TLifes = CTLifes = 0;

	StopGame();	
	set_temp("started", 1);
	for(i = 0; i < sizeof(cards); i++)
	{
		target = cards[i]->query("owner");
		if(!target || !target->query_temp("cs"))
			continue;
		if(target->query_temp("cs/die"))
		{
			knife = new(__DIR__"obj/knife");
			knife->move(target);
		}
		target->delete_temp("cs/die");					//revive player
		target->set_temp("cs/hp",(1000 + target->query_temp("cs/skill")) / 10);
//		target->set_temp("cs/bullets", 1000);
		if(target->query_temp("cs/team") == "t")
		{
			target->delete_temp("cs/planting");
			target->move(T_ROOM);
			if(TLifes == c4carrier)
			{
				c4 = new(__DIR__"obj/c4");
				set_temp("c4", c4);
				c4->move(target);
				message_vision("$N得到了"+c4->query("name")+"。\n", target);
			}
			TLifes++;
		}
		else if(target->query_temp("cs/team") == "ct")
		{
			target->delete_temp("cs/defusing");
			target->move(CT_ROOM);
			CTLifes++;
		}
		if(target->query_temp("cs/team") == query_temp("last_win_team"))
		{
			Reward(target, "win", 0);
		}
		else
			Reward(target, "lose", 0);
	}
	Declair("all", HIW" 比赛正式开始，共有"+ (CTCount + TCount)+"人参赛，其中CT有"+CTCount+"人，T有"+TCount+"人。"NOR);
	remove_call_out("EndGame");
	call_out("EndGame", TimeLimitPerRound / 5);
	set("start_time", time());
	set("end_time", query("start_time") + TimeLimitPerRound);
	
}

int EndGame()
{
	int timeRemaining = query("end_time") - time();
	string msg;
	if(timeRemaining <= 0)
	{	
		Declair("all", HIW"警察保护目标成功！\n");
		DeclairCTWin();
		return 0;
	}
	msg = HIW"游戏还有";
	if(timeRemaining >= 60)
		msg += chinese_number(timeRemaining / 60) + "分";
	if(timeRemaining % 60)
		msg += chinese_number(timeRemaining % 60) + "秒";	
	msg += "结束！\n";
	Declair("all", msg);
	call_out("EndGame", (timeRemaining > 3) ? timeRemaining / 3 : 1);
	return 1;
}

int Bombed()
{
	object* cards = children(__DIR__"obj/card");
	object target, bomb;
	int i, damage, player_position, distance, bomb_position = query_temp("bomb_position");
	string msg;
	bomb = query_temp("c4");
	for(i = 0; i < sizeof(cards); i++)
	{
		target = cards[i]->query("owner");
		if(!target || !target->query_temp("cs"))
			continue;

		player_position = RoomIndex(base_name(environment(target)));
		distance = Distance(player_position, bomb_position);
		if(distance < 0)
			continue;
		if(distance == 0)
			msg = HIR"只听嘀、嘀、嘀声突然变得紧促起来，突然一声巨响就从你脚下传来，你感觉到周围的房屋都在颤抖。\n"NOR;
		else if(distance < bomb->query("bomb_range"))
			msg = RED"只听嘀、嘀、嘀声突然变得紧促起来，突然一声巨响就从不远处传来，你感觉到周围的房屋都在颤抖。\n"NOR;
		else
			msg = NOR"远处传来一声闷响，似乎有什么东西爆炸了。\n"NOR;
		tell_object(target, msg); 

		//hurt player now
		damage = bomb->query("damage");
		damage = damage * (100 - 100 * distance / bomb->query("bomb_range") ) / 100;
		if(damage > 0)
			cards[i]->receive_bomb_damage(damage);
	}
}

void Reward(object me, string type, int kills)
{
	int points = 0;
	object xiandan;
	if(type == "plant_c4" || type == "defuse_c4")
		points = 40;
	else if(type == "kill")
		points = kills * 10;
	else if(type == "win")
		points = 30;
	if(me->query_skill("cs-skill", 1) < 100)
		me->improve_skill("cs-skill", points);
	if(me->query_skill("cs-skill", 1) / 50 > me->query("xiantian/spi/cs") && me->query("xiantian/spi/cs") < 2)
	{
		//每50级增加一点灵性，最多两点
		me->add("spi", 1);
		me->add("xiantian/spi/cs", 1);
		tell_object(me, HIC"你的灵性增加了！\n"NOR);
		command("char* addoil " + me->query("id"));
	}
	me->add_temp("cs/money", points * 30);
	if(points > 0)
		tell_object(me, HIC"你获得了" + chinese_number(points * 30)+"CS币。\n"NOR);
	if(type == "lose")
	{
		me->add_temp("cs/money", me->query_temp("cs/money") / 10);
		if(me->query_temp("cs/money"))
			me->set_temp("cs/money", 1000);
	}	
        if(me->query_temp("cs/kills") / 10 > me->query_temp("cs/reward_count") && !random(5))
	{
		xiandan = new (__DIR__"obj/csxiandan");
		xiandan->set("owner", me);
		xiandan->move(me);
                command("hslj* highhand " + me->query("id"));
                command("hslj 奖励" + me->query("name") + "一颗" + xiandan->query("name") + "。\n"NOR);
		me->add_temp("cs/reward_count", 1);
	}
}
