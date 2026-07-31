#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
int damage,ap,dp,v,k,i,j,num;     
string msg,*limbs,limb;
object sweapon,weapon=me->query_temp("weapon");
return notify_fail("\n");
if ( !target ) 
        target = offensive_target(me);
if ( !target 
  || !target->is_character()
  || target->is_corpse()
  || target==me 
  || !me->is_fighting(target) )
        return notify_fail("你要攻击谁？\n");
if ( !weapon->query("apply/verbs") )
        return notify_fail("你必须将箭作为你的主手武器。\n");
sweapon = me->query_temp("secondary_weapon");
if ( !sweapon || sweapon->query("apply/skill_type")!="archery"
  || sweapon->query("apply/verbs") )
        return notify_fail("你没弓怎么射箭？\n");

if ( me->query_skill("lengquan-force",1)<60 )
        return notify_fail("你的冷泉神功火候太差。\n");
if ( me->query_skill("archery",1)<60 ) 
        return notify_fail("你的基本弓箭火候太差。\n");
if ( me->query_skill("yanxing-steps",1)<60 ) 
        return notify_fail("你的雁行步法火候太差。\n"); 
if ( me->query("max_force")<900 )
        return notify_fail("你内力修为不够。\n");
if ( me->query("force")<500 )
        return notify_fail("你内力不够了。\n");
if ( time()<me->query_temp("jjf_archery")+5 )
        return notify_fail("你刚刚射过箭，暂时无法续力。\n");

v = me->query_skill("archery");
if ( me->query("family/jjf_type") )
        v*= 2;
v = v/2+random(v/2);
num = weapon->query_amount();
if ( v>num )
        v = num;
limbs = target->query("limbs"); 
message_vision(HIR"\n交战片刻，$N"HIR"忽然撤招跃出圈外，弯弓搭箭，将"+sweapon->name()+HIR"拉了个满月，“嘣”的一声，
"+chinese_number(v)+"支"+weapon->name()+HIR""+(v>20?"漫天飞花般":"风驰电掣般")+"射向天空，朝着$n"HIR"落将下来！\n"NOR,me,target);
me->set_temp("jjf_archery",time());
me->add("force",-300);
damage = 0;
j=0;
while(v>0)
        {
        reset_eval_cost(); 
        j++;
        if ( j>5 )
                break;
        k = v/2+random(v/2);
        if ( k<1 )  k = 1;
        if ( k>v )  k = v;
        v-= k;  
        if ( !me || !target || !me->is_fighting(target) 
          || !weapon || !sweapon )
                continue;
        msg = NOR YEL"\n半空中落下"+chinese_number(k)+"支"+weapon->name()+NOR YEL"，朝着$n"YEL"$l1、$l2,$l3等要害射去！\n"NOR;
        ap = COMBAT_D->skill_power(me,"archery",SKILL_USAGE_ATTACK); 
        dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE); 
        if ( COMBAT_D->wuxing_restrain(me,target)==1 ) 
                dp-= random(dp/3);       
        if ( COMBAT_D->wuxing_restrain(me,target)==-1 ) 
                dp+= random(dp/3);       
        if ( random(ap+dp)>dp )
                {
                msg+= YEL"$n"YEL"闪避不了，$l2、$l1、$l3等处给射了个正着！\n"NOR;
                damage = weapon->query("weapon_prop/damage");
                if ( me->query("family/jjf_type") )
                        damage*= (k*3);
                else    damage*= (k*2); 
                damage+= random(damage/2);
                damage-= target->query_temp("apply/armor");
                if ( damage<100 )  damage = 100;
                msg+= COMBAT_D->damage_msg(damage,"刺伤");
                }
        else    {
                 damage = 0;
                 msg+= YEL"$n"YEL"瞅准时机，纵身闪过。\n"NOR;
                }
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg,"$l1",limb);
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg,"$l2",limb);
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg,"$l3",limb);
        msg = replace_string(msg,"$l",limb);        
        msg = replace_string(msg,"$w",weapon->name());
        if ( !me->query("env/brief_message") && !target->query("env/brief_message") )
                message_vision(msg,me,target);
        if ( damage>0 )
                {
                target->receive_damage("kee",damage,me,"perform");
                COMBAT_D->report_status(target);
                }
        if ( weapon->query_amount()<k )
                {
                weapon->unequip();
                destruct(weapon);
                me->reset_action();                     
                }
        else    weapon->add_amount(-k);                                
        }       
return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：射日箭
        外功所属：轩 辕 箭
        外功效果：对敌射出带物理伤害的弓箭
                  冷却时间5秒
        外功条件：
                  内力修为9年        
                  内力500点，消耗200点
                  基本弓箭60级
                  雁行步法60级
                  冷泉神功60级
LONG;
me->start_more(str);
return 1;
}


