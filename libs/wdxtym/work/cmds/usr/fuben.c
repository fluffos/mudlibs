//cmds/std/
//玩家命令

#include <ansi.h>
 
inherit F_CLEAN_UP;
int check_ip(object *team)
{
	int i, j;
	for (i = 0;i < sizeof(team);i ++) {
		for (j = i + 1;j < sizeof(team);j ++) {
			if (team[i] && team[j] && query_ip_number(team[i]) == query_ip_number(team[j]))
				return 0;
		}
	}
	return 1;
}

int main(object me, string arg)
{
	object env;
	string *fubenls,*txt,str;
	int i;
	mapping info;
	mixed *fbtime;
	object *team = me->query_team();
	int total,max,min;
	int lv, qi_lv, jing_lv, exp_lv, neili_lv, lv2;

	env = environment(me);
	if (!env||!(fubenls=FUBEN_D->query_where(base_name(env)))) return 0;

	if(!arg)
	{
		txt = ({});
		str = ZJOBLONG"本地玩家副本列表：\n"ZJOBACTS2+ZJMENUF(2,2,9,30);
		for(i=0;i<sizeof(fubenls);i++)
		{
			if(mapp(info = FUBEN_D->query_info(fubenls[i])))
			{
				fbtime = localtime(info["time"]);

				txt += ({ HIM+info["cname"]+NOR"副本"ZJBR+HIG+info["owner"]+NOR"-"
						+fbtime[2]+"-"+fbtime[1]+"-"+fbtime[0]+":fuben "+fubenls[i] });
			}
		}
		str += implode(txt,ZJSEP);
		write(str+"\n");
		return 1;
	}

	if(!mapp(info = FUBEN_D->query_info(arg)))
		return notify_fail("没有这个副本！\n");

	if(info["owner"]!=me->query("id"))
		return notify_fail("这不是你的副本！\n");
	
	if(sizeof(team)>info["team"])
		return notify_fail("本副本限制最多"+info["team"]+"人进入！\n");

	me->set_temp("fuben_path", arg);

	lv = to_int(pow(to_float(me->query("combat_exp")*10),0.333333333));
	qi_lv = me->query("max_qi");
	jing_lv = me->query("max_jing");
	neili_lv = me->query("max_neili");
	exp_lv = me->query("combat_exp");
	
	if (info["enter"]->query_temp("go_fuben")) 
		return notify_fail("你无法再次进入这个副本。\n");
	
	if (sizeof(team)>0) {
		if (sizeof(team) < 0)
			return notify_fail("探险十分危险，你的团队人数太少。\n");
		if (sizeof(team) > 5) 
			return notify_fail("探险人数不宜过多，人数太多更容易暴露。\n");
		if (team[0] != me) 
			return notify_fail("只有队伍的首领才可以带队进行探险。\n");
		
		if (!check_ip(team))
			return notify_fail("你的队伍是同IP组建，无法进行探险。\n");
                        
		max = min = me->query("combat_exp");
		for (i = 0;i < sizeof(team);i ++)
		{
			if (!team[i])
				return notify_fail("你的队伍出现了问题，请解散并重新组建。");
			if (!present(team[i], env))
				return notify_fail("怎么好象人不全啊？" + team[i]->query("name") + "怎么没来？\n");
			if (team[i]->query_condition("killer"))
				return notify_fail("这里不欢迎杀人狂魔，"+team[i]->query("name")+"请回吧！"NOR"\n");
			if (me == team[i])
				continue;

			if (!interactive(team[i]))
				return notify_fail("你还是将" + team[i]->query("name") + "换成其他人吧。\n");
                        
			total += team[i]->query("combat_exp");
			if (team[i]->query("combat_exp") > max)
				max = team[i]->query("combat_exp"); 
			if (team[i]->query("combat_exp") < min)
				min = team[i]->query("combat_exp");
		}
		if (min / (max / 100) < 50||(max-min)>2000000)
			return notify_fail("探险过程十分危险，你们的修为差距太大了。\n");
		
			for (i = 0;i < sizeof(team);i ++)
			{
				lv2 = to_int(pow(to_float(team[i]->query("combat_exp")*10),0.333333333));
				if (lv2 > lv)
					lv = lv2;
				if (team[i]->query("max_qi") > qi_lv)
					qi_lv = team[i]->query("max_qi");
				if (team[i]->query("max_jing") > jing_lv)
					jing_lv = team[i]->query("max_jing");
				if (team[i]->query("max_neili") > neili_lv)
					neili_lv = team[i]->query("max_neili");
				if (team[i]->query("combat_exp") > exp_lv)
					exp_lv = team[i]->query("combat_exp");
			
				team[i]->move(info["enter"]);
				team[i]->set_temp("baozang/sk_lv", lv);//设定队伍最高技能等级
				team[i]->set_temp("baozang/qi_lv", qi_lv);//设定队伍最高气血
				team[i]->set_temp("baozang/jing_lv", jing_lv);//设定队伍最高气血
				team[i]->set_temp("baozang/neili_lv", neili_lv);//设定队伍最高内力
				team[i]->set_temp("baozang/exp_lv", exp_lv);//设定队伍最高修为
			} 
			info["enter"]->add_temp("go_fuben", 1);
	} else {
		me->move(info["enter"]);
		me->set_temp("baozang/sk_lv", lv);//设定队伍最高技能等级
		me->set_temp("baozang/qi_lv", qi_lv);//设定队伍最高气血
		me->set_temp("baozang/jing_lv", jing_lv);//设定队伍最高气血
		me->set_temp("baozang/neili_lv", neili_lv);//设定队伍最高内力
		me->set_temp("baozang/exp_lv", exp_lv);//设定队伍最高修为
		info["enter"]->add_temp("go_fuben", 1);
	}
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : fuben
 
这个指令可以显示当前场景的玩家副本。
 
see also : score
HELP );
    return 1;
}


