inherit SSERVER;

int valid_cast(object me)
{
	if(me->query("family/family_name")!="大雪山") 
                 return notify_fail("你不会鸟语，如何招百禽相助？！\n");
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");
	if( me->query_skill("dengxian-dafa",1)<100 )
		return notify_fail("你的登仙大法等级不够。\n");
	return 1;
}	

int cast(object me, object target)
{       
        object soldier;

	if( !valid_cast(me) )
		return 0;
		
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤护法！\n");
        if( objectp(me->query_temp("invocation")) )
                return notify_fail("你刚叫过护法，他们都被你叫烦了！\n");
        message_vision("$N喃喃地念了几句咒语。\n", me);
        me->add("mana", -80);
        me->receive_damage("sen", 30);

        if( random(me->query("max_mana")) < 150 ) {
                message("vision", "但是什么也没有发生。\n",environment(me));
                return 1;
        }

        seteuid(getuid());
        soldier = new("/d/xueshan/npc/hufabird");
        if( !soldier->invocation(me) ){
                message("vision", "但是什么也没有发生。\n",environment(me));
                if( soldier ) destruct(soldier);
                return 1;
        }
        return 3;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：召唤护法
        法术所属：登仙大法
        法术效果：召唤一位护法与自己并肩作战
        	  当召唤者离线或昏迷，护法会消失
		  当召唤者法力小于10时，护法会消失
		  护法会持续消耗召唤者的法力
        法术条件：
                  雪山弟子
        	  人物等级15级
                  法力100点，消耗80点，护法存在期间会持续消耗法力
                  精神50点，消耗30点
                  登仙大法 100 级
                  
STR;
        me->start_more(str);
        return 1;
}