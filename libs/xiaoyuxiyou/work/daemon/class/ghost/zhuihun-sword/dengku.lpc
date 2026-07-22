// dengku.c 油尽灯枯
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i,skill,ap,dp,damage,*skills;
	int dayphase = NATURE_D->query_current_day_phase();  
	return notify_fail("暂未开放。\n");		
	if( !target ) target = offensive_target(me);        
	if( !target        
 	 || !target->is_character()        
 	 || target->is_corpse()        
 	 || target==me 
 	 || !me->is_fighting(target) )
		return notify_fail("你要对谁施展『油尽灯枯』？\n");        
	weapon = me->query_temp("weapon");
	skill=(int)me->query_skill("zhuihun-sword",1);
	if( time()-(int)me->query_temp("souldrinker_end") < 6 )                 
        	return notify_fail("『油尽灯枯』耗费体力极大，不能连续使用！\n");        
	if((int)me->query("max_force") < 6000)                
        	return notify_fail("你的内力火候需要6000点！\n");          
	if((int)me->query("force") < 2000 )                  
        	return notify_fail("你体内的内力不足2000点！\n");        
	if((int)me->query("sen") < 800 )                
        	return notify_fail("你的精神不足800点，无力施展『油尽灯枯』！\n");        
skills = ({
        "zhuihun-sword","kusang-bang","hellfire-whip",
});     
for(i=0;i<sizeof(skills);i++)
        {
        if((int)me->query_skill(skills[i],1) < 600)               
                return notify_fail("你的『"+to_chinese(skills[i])+"』等级需要600级！\n");
        }
message_vision(HIB "\n$N"HIB"法袍一舞，剑招急若骤雨，漫天的剑影裹着一道道黑气向$n"HIB"卷了过去！
"HIR"$n"HIR"只觉眼前剑光飞舞，周围鬼影幢幢！似乎已经身陷鲜血淋漓的十八层地狱中一样！
"HIB"$n"HIB"腾挪闪跃，竭力招架，试图冲破眼前的黑雾。\n"NOR, me, target);
me->set_temp("souldrinker_end",time());         //时间间隔
me->add("force", -300);

ap = COMBAT_D->skill_power(me,"sword",SKILL_USAGE_ATTACK);
dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE);
if ( COMBAT_D->wuxing_restrain(me,target)==1 )
        dp-= random(dp/3);      
if ( COMBAT_D->wuxing_restrain(me,target)==-1 )
        dp+= random(dp/3);      

if ( random(ap+dp)>dp )
        {
        damage = (int)me->query_skill("sword");
        damage+= (int)me->query_skill("force");
        damage = damage+random(damage);
        damage-= target->query_temp("apply/armor");
        if ( damage<500 ) damage = 500;
        if ( damage>5000 ) damage = 5000;
        if ( dayphase < 6)                       
                damage += damage/3;
        if ( !me->query("env/brief_message") && !target->query("env/brief_message") ) 
                message_vision(HIB"\n$N"HIB"既占先机，後着绵绵而至，$n"HIB"中了一剑，大骇之下，急向後退。
"HIR"$p"HIR"只觉一缕缕鲜血从伤口溅出，自身的灵魂逐渐飘出体外，身体越来越虚弱。\n"NOR, me,target);
        if ( random(target->query("force"))<500 )
                {    
                target->set_temp("no_exert",([
                        "start" : time(),
                        "time"  : 5,
                        "msg"   : "你的内息已被"+me->name()+"的『油尽灯枯』 打乱，暂时无法使用内功。\n",
                ]));    
                message_vision(HIR"$n觉得自己无法再运起气来了！\n"NOR, me, target);
                }  
        target->receive_wound("kee", damage/3, me,"perform");
        target->receive_damage("kee", damage, me,"perform");
        target->receive_wound("sen", damage/5, me,"perform");
        target->receive_damage("sen", damage/3, me,"perform");
        COMBAT_D->report_status(target,damage/3);
        if ( wizardp(me) && (string)me->query("env/test") )    
                tell_object(me, sprintf(HIW "伤害比:%d \n" NOR, damage));
        }
else    {
        message_vision(HIW"\n可是$n"HIW"早有警觉，兔起鹘落，几下跳出了$P的剑幕。\n"NOR, me,target);
        me->add("force", -200);
        me->receive_damage("sen", 500);
        }
me->start_busy(1 + random(3));
return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
return notify_fail("暂未开放。\n");	
str = @LONG
        外功名称：油尽灯枯
        外功所属：追 魂 剑
        外功效果：将摄气诀加成在武器上，对敌进行攻击
                  对其气血的前后限进行打击，并有可能
                  封住对方的内力 
                  使后自身busy 1-2 秒
                  失败消耗500点精神
        外功条件：
                  烈火鞭600级
                  哭丧棒600级
                  追魂剑600级
                  内力修为60年
                  内力2000点，消耗300-500点
                  气血800点，消耗0－500点
LONG;
me->start_more(str);
return 1;
}

