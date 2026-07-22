#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{       
	object weapon;
	string msg,force_skill,force_skill_name;
        int damage, int_attack;
        
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )        
        	return notify_fail("「神猴狂舞」只能在战斗中使用。\n");
	if(me->query("family/family_name") != "方寸山三星洞")
		return notify_fail("[神猴狂舞]是斜月三星洞不传之密！\n");
	weapon = me->query_temp("weapon");	
	if( !weapon
	 || ( weapon->query("skill_type")!="stick"
	   && weapon->query("use_apply_skill")!="stick" ) )
		return notify_fail("你以为你是谁？没棒也发神猴狂舞！\n"); 
	if( (int)me->query_skill("stick", 1) < 180 
	 || (int)me->query_skill("qianjun-bang", 1) < 180 
	 || (int)me->query_skill("jindouyun", 1) <150 
	 || (int)me->query_skill("wuxiangforce", 1) <150 )
		return notify_fail("你有的功夫还不够娴熟，不会使用「神猴狂舞」。\n");
	if( (int)me->query("max_force") < 1800 )
        	return notify_fail("以你现在的内力修为还使不出「神猴狂舞」。\n");
        if( (int)me->query("force") < 800 )
		return notify_fail("你的真气不够！\n");
	if( time()<me->query_temp("puti_wu")+5 )
		return notify_fail("你现在一身臭汗，哪里舞得动。\n");

	int_attack = me->query_temp("apply/attack");
			
        msg = HIY "$N"HIY"使出方寸山绝技「神猴狂舞」，身法陡然加快！\n$N"HIY"忽然猛一吸气，抡棒回舞，劈向$n"HIY"$l！\n" NOR;
        me->add("force",-100);
        me->set_temp("puti_wu",time());
        me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM);
        me->set_temp("pfm_msg",0);
        if( damage<1 )
        {
        	msg = HIC "\n但见$n"HIC"虽挡住这一击，却也无法再维持澎湃的乱舞。\n" NOR;
		me->add_temp("apply/attack",5);
        }
	else	msg = HIC "\n初时似乎出手不重，但其波浪状的棍影后浪击前浪，一浪高过一浪，连绵不尽！\n"NOR;

        me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,msg);
        me->set_temp("pfm_msg",0);

	if( me->query("force")<500 )
	{
		tell_object(me,"你待要再出第二击，却发现自己的内力不够了！\n");	
		me->set_temp("apply/attack",int_attack);
		return 1;
	}

        if( damage<1 )
		me->add_temp("apply/attack",5);

	force_skill = target->query_skill_mapped("force");
	if( !force_skill ) force_skill_name = "基本内功";
	else	force_skill_name = to_chinese(force_skill);
   
	if(random(5)>2)
		msg = HIC"\n但见$N"HIC"倒拖$w"HIC"，突然一个仰身,大喝一声,募的绕身回劈,$n"HIC"眼前一黑！\n"NOR;
	else	msg = HIG"\n但见$N"HIC"倒拖$w"HIC"，突然狂啸一声,抡棍横扫,声势刚烈,$n"HIC"早已吓慌了手脚！\n"NOR;
	
	me->add("force",-80);
        me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,msg,HIR"$n"HIR"惊骇之下，"+force_skill_name+HIR"顿时破绽百出，根本无从招架！\n"NOR);
        me->set_temp("pfm_msg",0);
	
	if( (int)me->query_skill("qianjun-bang", 1)>300 )
	{
		if( me->query("force")<300 )
		{
			tell_object(me,"你待要再出一击，却发现自己的内力不够了！\n");	
			me->set_temp("apply/attack",int_attack);
			return 1;
		}
		if(random(5)>2 )
    		{
        		msg = HIY"\n$N"HIY"一声咆哮，$w"HIR"竟然脱手飞出，如游龙般翱翔青宇，破空射向$n"HIY"的$l！\n"NOR;
	       		msg+= HIY"$n"HIY"大吃一惊，但见$N"HIY"空手猱身而上，双手擒拿点拍，攻势凌厉之极！\n" NOR;
     		}
		else 	msg = HIG"\n$N"HIG"长啸一声，一式「天地鹤翔」，腾空飞起，$w"HIG"迸出无数道棍影，弥漫天际！\n"NOR;
        	if( damage<1 )
			me->add_temp("apply/attack",10);
	
		me->add("force",-50);
        	me->set_temp("pfm_msg",1);
        	damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,msg);
        	me->set_temp("pfm_msg",0);
        }	

	me->set_temp("apply/attack",int_attack);
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：神猴狂舞
        外功所属：千钧棒
        外功效果：对敌进行连续攻击，最高3次
        	  命中递增
		  冷却时间 5 秒
        外功条件：
        	  方寸弟子
        	  人物等级20级
        	  千钧棒法180级
        	  基本棍法180级
 		  筋斗云150级
 		  小无相功150级	  
 		  内力修为十八年     	  	
                  内力800点，消耗100点，第二击增加消耗80点，第三击增加消耗50点
LONG;
	me->start_more(str);
	return 1;
}