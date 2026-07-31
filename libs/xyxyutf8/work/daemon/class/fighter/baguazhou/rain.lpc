#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_cast(object me)
{
	if(me->query("family/family_name") != "将军府")
        	return notify_fail("这是将军府不传之密！\n");
	if( me->query_level()<35 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 1000 )
                return notify_fail("你的法力不够了！\n");
	if( me->query("kee")<300 )
		return notify_fail("你现在气血不足，画不了符。\n");                
	if( time()<me->query_temp("jjf_rain")+10 )
		return notify_fail("你刚刚画过「神霄雨法符」。\n");
	if( me->query_skill("baguazhou",1)<350 )
		return notify_fail("你的八卦咒等级不够。\n");	
	if( me->query_temp("jjf_raining") )
		return notify_fail("你已经祭出「神霄雨法符」了。\n");	
	return 1;
}	

void rain(object me,object *tmp,object where)
{
	int i;
	object *team;
	if( !me )
		return;
	if( me->query("mana")<100 || !present(me,where) || me->query_temp("jjf_raining")<=0 
	 || !tmp || !arrayp(tmp) || sizeof(tmp)<1 )
	{
		message("vision",HIC+me->name()+HIC"收起「神霄雨法符」的效果。\n"NOR,where,({me}));
		tell_object(me,HIC"你收起「神霄雨法符」的效果。\n"NOR);
		me->set_temp("jjf_rain",time());
		me->delete_temp("jjf_raining");
		return;
	}
	team = me->query_team();
	for(i=0;i<sizeof(tmp);i++)
	{
		if( !tmp[i] || !living(tmp[i]) )
			continue;
		if( team && arrayp(team) )
		{
			if( member_array(tmp[i],team)==-1 )
				continue;
		}
		if( tmp[i]->query("eff_kee")<tmp[i]->query_maxkee()
		 || tmp[i]->query("eff_sen")<tmp[i]->query_maxsen() 
		 || tmp[i]->query("kee")<tmp[i]->query("eff_kee")
		 || tmp[i]->query("sen")<tmp[i]->query("eff_sen") )
		{
			message_vision(HIG"$N"HIG"沐浴在一阵春雨中，感觉整个人焕然一新。\n"NOR,tmp[i]);
			tmp[i]->receive_curing("kee",50);
			tmp[i]->receive_curing("sen",50);
			tmp[i]->receive_heal("kee",100);
			tmp[i]->receive_heal("sen",100);
			me->add("mana",-10);
		}		 		
	}
	me->add_temp("jjf_raining",-5-random(5));	
	call_out("rain",5,me,tmp,where);
}	

int cast(object me, object target)
{       
	int damage,i;
        object seal,where,*tmp,*team;
	string msg;
	
	if( !valid_cast(me) )
		return 0;
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何画符？\n");
        	
        message_vision("$N咬破手指，伸手在桃符纸上画了几下。\n", me);
        me->add("mana", -400);
	me->receive_damage("kee",200,me);
	me->set_temp("jjf_raining",me->query_skill("spells")/50);
	if( seal->query_amount()<2 )
		destruct(seal);
	else	seal->add_amount(-1);		
	if( me->is_fighting() )
		me->start_busy(3);

	msg = HIC "$N"HIC"大喊一声“着”，手一挥，祭出了一张神霄雨法符！\n「呼」地一下飞到半空，化作一阵春雨，淅淅沥沥落将下来。\n"NOR;
	message_vision(msg,me);
	tmp = ({});
	tmp+= ({me});
	where = environment(me);
	team = me->query_team();
	if( team && arrayp(team) )
	{
		for(i=0;i<sizeof(team);i++)
		{
			if( team[i] && living(team[i]) && !me->is_fighting(team[i])
			 && team[i]!=me && present(team[i],where) )
			 	tmp+= ({team[i]});
		}
	}		 	
	call_out("rain",0,me,tmp,where);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：神霄雨法符
        法术所属：八卦咒
        法术效果：一定时间内每5秒在此区域内治疗自身与队友的气血、精神
                  状态结束后冷却时间 10 秒
        法术条件：
                  将军府弟子
        	  人物等级35级
        	  需要桃符纸
                  法力800点，消耗400点
                  气血300点，消耗200点
                  八卦咒350级
STR;
        me->start_more(str);
        return 1;
}

void remove()
{
	int i;
	object me,*usr = users();
	remove_call_out("rain");
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("jjf_raining") )
			{
				me = usr[i];
				message("vision",HIC+me->name()+HIC"收起「神霄雨法符」的效果。\n"NOR,environment(me),({me}));
				tell_object(me,HIC"你收起「神霄雨法符」的效果。\n"NOR);
				me->set_temp("jjf_rain",time());
				me->delete_temp("jjf_raining");
			}
		}
	}
}