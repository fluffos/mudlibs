// zxgift.c
#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
	mixed *local, *last;
	int index,ran=random(10);
	string str="";
	int k = 0;
	int p = 0;
	int t2;
	int w;
	int exp,pot,gold;
	int time;
	object gift;
	seteuid(getuid());	
	
	local = localtime(time());
	time = me->query("zxgift/time");
	last = localtime(time);
	//不是同一天
	if(local[7] != last[7])
	{
		me->delete("zxgift");
		me->set("zxgift/time", time());
	} 
	if(me->query("zxgift/num")>=7)
	{
    tell_object(me, "你今天的在线奖励已经全部领取完了！\n");
    return 1;	
	}
	p = me->query("zxgift/num");
	t2 = time() - me->query("zxgift/time");
	
	if ( p < 1 && t2 >= 5*60) {
		exp = 100 + random(200);
		pot = 100 + random(200);
		gold = (1 + random(10));
		k = 5;
	} else
	if ( p < 2 && t2 >= 10*60) {
		exp = 500 + random(500);
		pot = 500 + random(500);
		gold = (10 + random(11));
		k = 10;
	} else
	if ( p < 3 && t2 >= 30*60) {
		exp = 1000 + random(1000);
		pot = 1000 + random(1000);
		gold = 10 + random(21);
		k = 30;
	} else
	if ( p < 4 && t2 >= 60*60) {
		exp = 1500 + random(1500);
		pot = 1500 + random(1500);
		gold = 10 + random(41);
		k = 60;
	} else
	if ( p < 5 && t2 >= 120*60) {
		exp = 2000 + random(2000);
		pot = 2000 + random(2000);
		gold = 10 + random(71);
		k = 120;
	} else
	if ( p < 6 && t2 >= 240*60) {
		exp = 5000 + random(5000);
		pot = 5000 + random(5000);
		gold = 10 + random(91);
		k = 240;
	} else
	if ( p < 7 && t2 >= 480*60) {
		exp = 10000 + random(10000);
		pot = 10000 + random(10000);
		gold = 10 + random(291);
		k = 480;
	} 	
	if(p < 1)w=5*60;
	else if(p < 2)w=10*60;
	else if(p < 3)w=30*60;
	else if(p < 4)w=60*60;
	else if(p < 5)w=120*60;
	else if(p < 6)w=240*60;
	else if(p < 7)w=480*60;
	
	if (k > 0) {
		if (ran > 6) {
			me->add("combat_exp", exp);
			str += "修为"+chinese_number(exp);
		} else
		if (ran > 3) {
			me->add("balance", gold);
			str += "存款"+MONEY_D->money_str(gold);
		} else {
			me->add("potential",pot);
			str += "潜能"+chinese_number(pot)+"点";
		}

		//me->set("zxgift/time", time());
		me->add("zxgift/num", 1);
		tell_object(me, "你距上次领奖时间超过了"+CHINESE_D->chinese_time(k)+"分钟，获得了在线奖励："HIC+str+NOR"！\n");
	} else
		tell_object(me, "你现在无法"+query_idle(me)+"领取！你已经在线"HIC+CHINESE_D->chinese_time(t2)+NOR"，你距离下次领取奖励还差"HIG+CHINESE_D->chinese_time(w-t2)+NOR"！\n");

	return 1;
}

