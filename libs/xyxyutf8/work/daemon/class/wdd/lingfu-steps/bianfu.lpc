#include <ansi.h>
inherit F_DBASE;
inherit SSERVER;

void remove_effect(object me, int dodge_amount,int defense,int attack,int spells_succ,int spells_dodge)
{
	if( !me )
		return;
        me->delete_temp("powerup");
        me->add_temp("apply/dodge",-dodge_amount);
        //闪避率	
        me->add_temp("apply/defense",-defense);	
        me->add_temp("apply/attack",-attack);	
        me->add_temp("apply/spells_succ",-spells_succ);		
	me->add_temp("apply/spells_dodge",-spells_dodge);
        me->delete_temp("apply/limbs");
        message_vision(HIB"$N"HIB"渐感浑身难受，摇了摇脑袋，现出了原形。\n"NOR,me);
}

int perform(object me, object target)
{
        int skill_spells, skill_dodge,spells_dodge,dodge_amount,howlong,defense,attack,spells_succ;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	
        skill_dodge = me->query_skill("dodge");            
        if( skill_dodge<400 ) 
        	return notify_fail("你的轻功还不够高明，变了蝙蝠也飞不起来。\n");
        skill_spells=me->query_skill("spells");        
        if( skill_spells<400 ) 
        	return notify_fail("你的妖法不够纯熟。\n");
	if( (int)me->query("force") < 300 )      
                return notify_fail("你的法力不够。\n");
        if( me->query("sen")<100)
              return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        message("vision",HIB+me->name()+HIB"嘴里念念有辞，突然黑雾弥漫"+(me->query("gender")=="女性"?"她":"他")+"的全身，一股浓郁的妖气横空暴涨，只见黑雾中飞出一只闪着血红眸子的大蝙蝠！\n"NOR,environment(me),({me}));
	tell_object(me,HIY"你念动真言，施展灵蝙身法，顿时化作一巨大蝙蝠！\n"NOR);
	
	if( me->is_fighting() )
		me->start_busy(3);
	
        me->add("force", -100);
        me->receive_damage("sen",50);
        me->set_temp("powerup", 1);
        me->set_temp("apply/limbs",({
		"头部",  "颈部", "胸口",  "后心",  "左肩",  "右肩",  "左臂", "右臂",
  		"左手",  "右手", "腰间",  "小腹",  "左腿",  "右腿",  "左脚", "右脚",
  		"翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",
	}));

        dodge_amount = me->query_skill("dodge");
        //轻功有效等级
        me->add_temp("apply/dodge",dodge_amount);
        defense = dodge_amount/150;
        if( defense>30 )
        	defense = 30;
        //闪避率	
        me->add_temp("apply/defense",defense);	
        
        attack = dodge_amount/15;
        //命中率
        me->add_temp("apply/attack",attack);	
        
        //法术命中率
        spells_succ = me->query("daoxing")/72000+1;
        if( spells_succ>30 )
        	spells_succ = 30;
        me->add_temp("apply/spells_succ",spells_succ);		
        
        //法术闪避率
        spells_dodge = skill_spells/150;
        if( spells_dodge>30 )
        	spells_dodge = 30;
	me->add_temp("apply/spells_dodge",spells_dodge);		
        
        howlong = me->query_skill("yaofa",1)/5+5+random(5);
        if( howlong>150) howlong=150;

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dodge_amount,defense,attack,spells_succ,spells_dodge:), howlong);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：化身为蝠
        外功所属：灵蝠身法
        外功效果：一定时间内化身为蝠，增强自身的闪避率与命中率
                  战斗中使用，自身busy 3 秒
                  状态不可叠加
        外功条件：
                  人物等级 30 级
                  内力300点，消耗100点
                  精神100点，消耗50点
                  轻功有效等级 400 级
                  法术有效等级 400 级
STR;
        me->start_more(str);
        return 1;
}