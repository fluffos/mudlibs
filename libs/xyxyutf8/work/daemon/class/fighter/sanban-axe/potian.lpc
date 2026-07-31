#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,p,i;
	string msg,succ_msg,*skills;

	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("force")<800)
        	return notify_fail("你的内力不足！\n");
	if( me->query("kee")<500 )
        	return notify_fail("你的气血不足，没法子施用外功！\n");
        skills = ({
        	"axe","sanban-axe","dodge","parry","force","lengquan-force",
        	"yanxing-steps",
        });
        for(i=0;i<sizeof(skills);i++)
        	if((int)me->query_skill(skills[i], 1) <400)
        		return notify_fail("你的"+to_chinese(skills[i])+"级别还不够！\n");
	if( me->query_skill_mapped("axe")!= "sanban-axe" )
		return notify_fail("你好似不会三板斧？\n");
	if( me->query_skill_mapped("force")!= "lengquan-force" )
		return notify_fail("你需要冷泉神功的支持。\n");
	if( me->query_skill_mapped("dodge")!= "yanxing-steps" )
		return notify_fail("你需要雁行步法的支持。\n");
	if( me->query("family/family_name")!="将军府" )
        	return notify_fail("你不能使用这项技能！\n"); 
	weapon=me->query_temp("weapon");
	if( !weapon
	 || ( weapon->query("skill_type")!="axe"
	   && weapon->query("use_apply_skill")!="axe" ) )		
        	return notify_fail("你的斧子呢？\n");
        	
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
        	return notify_fail("你要对谁施展这一招"+HIM"「破天」"+NOR"？\n");

	me->add("force", -500);
	me->receive_damage("kee", 200,me);
	damage = target->query_maxkee()/10+1+me->is_knowing("jjf_potian")*10;
	
	msg = HIC"$N"HIC"猛吐一口鲜血在$w"HIC"上，顿时斧上一道古朴图腾一闪，一道炫目的光华闪起，$N"HIC"连人带斧压向$n"HIC"，寒光一闪，$w"HIC"从下而上反撩$n"HIC"$l！\n"NOR;
	succ_msg = HIR"$n"HIR"被$w"HIR"撩了个正着，整个人似掉线的风筝般，身不由己的腾空而起，带着一路的鲜血！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,damage);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(HIY"$n"HIY"腰马合一，沉身挡住了这一斧。\n"NOR,me,target);
		me->start_busy(4);
		return 1;
	}
	if( me->query_skill("sanban-axe",1)>=500
	 && me->query("force")>200 )
	{
		me->add("force",-200);
		message_combatd(HIY"\n$N"HIY"纵身而起，高举手中"+weapon->name()+HIY"狠狠砸向$n"HIY"！\n"HIR"$n"HIR"身在半空，避无可避，顿时「轰」地一声巨响，$n"HIR"被砸得血肉模糊，落在地面，砸出一个巨大的深坑！\n"NOR,me,target);
		p = target->query_maxkee()/10+1;
		if( p<damage )
			p = damage;
		if( COMBAT_D->query_message_type(me,target)==2 )
			message_vision("结果造成"HIR+p+NOR"点气血损失。\n",me);
		target->receive_wound("kee",p,me,TYPE_PERFORM);		  
		COMBAT_D->report_status(target,1);
	}
	me->start_busy(2);
	return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：破天斩
        外功所属：宣花三斧
        外功效果：悬空技，固定伤害为对方最大气血的十分之一，并可通过领悟提高
        	  被击中后，当技能等级达500级，给予对方必中的一击，损伤对方气血，内力增加消耗200点
        	  否则则自身busy 4 秒
        	  使用后自身busy 2 秒
        	  可越阶使用
        外功条件：
                  将军府弟子
                  人物等级15级 
                  内力800点，消耗500点
                  气血500点，消耗200点
                  拆招卸力400级 
                  基本斧法400级 
                  宣花三斧400级并激发
                  基本内功400级 
                  冷泉神功400级并激发
                  基本轻功400级 
                  雁行步法400级并激发
                  
LONG;
me->start_more(str);
return 1;
}

