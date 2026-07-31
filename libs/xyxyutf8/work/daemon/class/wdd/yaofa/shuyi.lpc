#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string name() 
{
	return NOR RED"鼠疫成灾"NOR;
}
        
string *msg = ({
        HIR"$N"HIR"默运混天气功，集起浑身戾气，赤色光芒在眼中跳动，瞳孔瞬间成深红，形如魔神，场中压力大增，陡然间，冷哼一声“看我无底洞绝学”，一团红雾喷出，散向场中。\n"NOR,
        MAG"$n"MAG"猝不及防，躲闪不及，竟吸入了少许红雾，顿觉胸中气血翻腾，四肢无力，神志竟似有些迷糊。\n"NOR,
        HIW"$N"HIW"手中$w"HIW"跳动，随意地划出一式刀意，却是浑然天成，无懈可击，无路可退，$n"HIW"眼露恐惧之色，仿佛听到了刀上千万冤魂怨灵的桀桀笑声，正是一招“万骨功成”。\n"NOR,
        HIB"$N"HIB"趁此机会，身形疾走，$n"HIB"只觉得前后左右俱是$N"HIB"的身影，分不清哪个是真哪个是假，正惊疑间，一剑平胸刺来，正是一招“九九归一”。\n"NOR,
        HIY"$N"HIY"趁机变式为爪，步法连绵，撒出一片爪影罩向$n"HIY"。\n"NOR,
        "",
});

string *request_skills = ({
        "yaofa","yinfeng-zhua","qixiu-jian","kugu-blade",
});

int valid_cast(object me)
{
	object *enemys;
	int i,t,flag =0,lvl=600;        
	if( !me )
        	return 0;
	if( me->query_level()<60 )
		return notify_fail("你的人物等级不够。\n");        	
	if( me->query("family/family_name")!="陷空山无底洞" )
        	return notify_fail("你不能使用这项技能。");
	if( me->query("mana")<800 )
        	return notify_fail("你的法力不足。\n");
	if( me->query("sen")<200 )
        	return notify_fail("你的精神不足。\n");
	for(i=0;i<sizeof(request_skills);i++)
        {
        	if( me->query_skill(request_skills[i],1)<lvl )
                	return notify_fail("你的『"+to_chinese(request_skills[i])+"』等级不够！\n");
        }
        if( !me->is_fighting() )	
        	return notify_fail(name()+"必须在战斗中使用。\n");      
	t = me->query_skill("yaofa",1)-lvl;
	t/= 50;
	t = 20-t;
	if( t<5 )  t = 5;
	if( t>8 ) t = 8;
	if( time()<me->query_temp("wdd_shuyi")+t )
        	return notify_fail("绝招用多了就不灵了!\n");
	return 1;
}

int cast(object me, object target)
{
	string skill,str;     
	object *enemy, weapon;
	int sc,i,lvl=750,damage;

	if( !valid_cast(me) )
        	return 0;
        enemy = me->query_enemy();
        if( !enemy || sizeof(enemy)<1 )
		return notify_fail(name()+"必须在战斗中使用。\n");         	
        
	message_vision(msg[0]+"\n", me);
	me->set_temp("wdd_shuyi",time());
	me->add("mana", -300);
	me->receive_damage("sen",100,me);

	for(i=0;i<sizeof(enemy);i++)
	{
		if( !objectp(target = enemy[i])
		 || !target->is_character() 
        	 || !me->is_killing(target->query("id"))
        	 || target==me || !living(target) )
			continue;
		sc = COMBAT_D->attack_percent(me,target,TYPE_CAST);	
        	if( sc<1 )
                {
                	message_vision(CYN"$n"CYN"大袖一抖，挥开这片红雾，却发现\n"NOR, me, target);
                	EMOTE_D->do_emote(target, "hoho",geteuid(me),CYN,0,0,0);
                	message_combatd(RED"\n$n"RED"抖身形闪开这片红雾，喝道：大胆鼠辈，竟敢使用鼠疫行凶，看我今日如何降你。\n"NOR, me, target);
                	target->kill_ob(me);
                	continue;
                }
        	else    
        	{
                	message_vision( msg[1]+"\n", me, target );
                	if( !target->query_condition("shuyi") )
                		target->apply_condition("shuyi",15);
			if( target && me->is_fighting(target) )
        		{       
        			if( !objectp(weapon=me->query_temp("weapon")) )
                			str = msg[4];
                		else if( weapon->query("skill_type")=="blade" )
                			str = msg[5];
                		else if( weapon->query("skill_type")=="sword" )
                			str = msg[3];
				else	continue;
				damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,str,0,0,0,0,"both");
				if( damage<1 )
					message_combatd("结果$n奋力一闪，躲开了这一招攻击。\n",me,target);
			}
		}
	}							
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：鼠疫成灾
        法术所属：妖法
        法术效果：使区域内与自身生死格斗的对象身中鼠疫15秒
                  并追加攻击
                  身中鼠疫下，会造成自身技能有效等级下降,并busy 1-2 秒
        	  冷却时间5-8秒
        	  对火云洞弟子无效
        法术条件：
                  无底洞弟子
        	  人物等级40级
                  精神200点，消耗100点
                  法力800点，消耗300点
                  妖法600级
                  阴风爪600级
                  七修剑600级
                  枯骨刀600级
                  
STR;
        me->start_more(str);
        return 1;
}