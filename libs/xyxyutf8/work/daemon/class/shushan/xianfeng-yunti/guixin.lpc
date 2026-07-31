// ningshen.c
#include <ansi.h>

void remove_buff(object,int);

int exert(object me, object target)
{
	int i,p,n,self,cost=50;
	object *teams,*obj;
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "蜀山派" ) 
        	return notify_fail("你是哪儿偷学来的武功！\n");
	if((int)me->query_skill("xianfeng-yunti",1) < 100)
        	return notify_fail("你的『仙风云体术』还不纯熟！\n");        	
	if( time()<me->query_temp("last_guixin")+8 )
		return notify_fail("绝招用多就不灵了。\n");
		
	p = me->query_skill("xianfeng-yunti",1)/60+14;
	n = me->query_skill("force")/3;
	if( p>600 )
		p = 600;
	self = 0;
	if( !arrayp(teams=me->query_team()) )
	{
		self = 1;
		obj = ({me});
	}
	else
	{
		n = 0;
		i = sizeof(teams);
		obj = ({});
		while(i--)
		{
			target = teams[i];
			if( !target || !living(target)
			 || !present(target,environment(me)) )
				continue;
			if( time()<target->query_temp("shushan_guixin")+p )
				continue;
			if( target!=me )
				cost+= 10;
			obj+= ({target});
			n++;				 
		}
		
	}
	if( cost>100 )
		cost = 100;
	if( n<=1 )
		self = 1;
	if( self>0 )
		cost = 50;
	
	if( me->query("force")<100 )
		return notify_fail("你的内力不足。\n");
	
	message_vision(HIG"\n$N"HIG"念动口诀，脸色苍木之气大盛。待到压抑不住之时，苍木之气骤然绽开，笼罩全场！\n"NOR,me);
	me->set_temp("last_guixin",time());
	me->add("force",-cost);
	i = sizeof(obj);
	while(i--)
	{
		target = obj[i];
		if( !target || !living(target)
		|| !present(target,environment(me)) )
			continue;
		if( time()<target->query_temp("shushan_guixin")+p )
			continue;					
		if( me==target )
		{
			message("vision","一道绿气闪入"+target->name()+"体内。\n",environment(me),target);
			tell_object(me,"你沐浴在苍木之气的绿光之中。\n");
		}
		else	message_vision("一道绿气闪入$N体内。\n",target);
		target->set_temp("shushan_guixin",time());
		target->add_temp("apply/max_kee",n);
		target->add_temp("apply/max_sen",n);
		target->add("eff_kee",n);
		target->add("kee",n);
		target->add("eff_sen",n);
		target->add("sen",n);
		call_out("remove_buff",p,target,n);
	}	
	return 1;
}

void remove_buff(object who,int n)
{
	if( !who )
		return;
	who->add_temp("apply/max_kee",-n);
	who->add_temp("apply/max_sen",-n);
	if( who->query("eff_kee")>who->query_maxkee() )
		who->set("eff_kee",who->query_maxkee());
	if( who->query("kee")>who->query("eff_kee") )
		who->set("kee",	who->query("eff_kee") );
	if( who->query("eff_sen")>who->query_maxsen() )
		who->set("eff_sen",who->query_maxsen());
	if( who->query("sen")>who->query("eff_sen") )
		who->set("sen",	who->query("eff_sen") );		
	message_vision("$N身上的苍木之气慢慢散去。\n",who);
}	

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        内功名称：元灵归心术
        内功所属：仙风云体术
        内功效果：使在场的所有队员的气血、精神后限
        	  在 15-600 秒内增加
                  仙风云体术修为越高，增加值越高
        内功条件：
                  蜀山派弟子
        	  人物等级10级	
                  内力100点，最低消耗50点
                  仙风云体术100级
LONG;
me->start_more(str);
return 1;
} 