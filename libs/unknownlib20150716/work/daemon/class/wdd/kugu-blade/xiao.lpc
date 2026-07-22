//「刀剑啸」
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
      	int enhance,damage;
      	string msg,str; 

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="陷空山无底洞")
                return notify_fail("「刀剑啸」只有无底洞门人才可以用！\n");	
	if( time()-(int)me->query_temp("wdd_xiao") < 5 )
		return notify_fail("绝招用多就不灵了！\n");      
	if(me->query_skill("huntian-qigong",1)<200)
		return notify_fail("你的内功太差，还不会以剑法御刀。\n");
      	if(me->query_skill("kugu-blade",1)<200) 
		return notify_fail("你还是先把精力集中在枯骨刀法上吧。\n");
	if(me->query_skill("qixiu-jian",1)<100) 
		return notify_fail("你的七修剑太差，强运神功不是笑死人了。\n");
	if(me->query_skill_mapped("force")!="huntian-qigong")
        	return notify_fail("「刀剑啸」必须配合混天气功才能使用。\n");
	if(me->query_skill_mapped("sword")!="qixiu-jian")
		return notify_fail("「刀剑啸」必须配合七修剑才能发挥威力。\n");
	if(me->query("force")<600)
        	return notify_fail("你内力不继，难以出招。\n");
      	weapon = me->query_temp("weapon");
        if( !weapon 
	 || (weapon->query("skill_type")!="blade"
	  && weapon->query("use_apply_skill")!="blade") )	
		return notify_fail("你手里头木有刀。\n");
      	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要攻击谁？\n");
    	message_vision(HIB"$N"HIB"默运混天气功，突然间使出七修剑法，手中"+weapon->name()+HIB"带着慑人的啸声直取$n"HIB"！\n"NOR,me,target);
	me->add("force", -150);
	me->set_temp("wdd_xiao",time());
	
	weapon = me->query_temp("weapon");
	weapon->set("use_apply_skill","sword");
	me->reset_action();
	me->set_temp("pfm_color",HIB);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,50);
	if(me->query_skill("yinfeng-zhua",1)>200)
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,80);
	me->set_temp("pfm_color",0);
	weapon->delete("use_apply_skill");	
	me->reset_action();
	
	message_vision(YEL"\n$N"YEL"倒转混天气功，手中"+weapon->name()+YEL"去剑还刀，化作漫天哭嚎一声，压向$n"YEL"！\n"NOR,me,target);
	me->set_temp("pfm_color",YEL);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,100);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,120);
	me->set_temp("pfm_color",0);
	
	if(me->query_skill("yinfeng-zhua",1)<200)
		return 1;
	////出掌
	message_vision(HIM"\n$N"HIM"不等招式用老，诡异一笑，立刻收刀出爪，一股阴风直扑$n"HIM"！\n"NOR,me,target);
	weapon = me->query_temp("weapon");
	weapon->set("use_apply_skill","unarmed");
	me->reset_action();
	me->set_temp("pfm_color",HIM);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,150);
	me->set_temp("pfm_color",0);
	weapon->delete("use_apply_skill");	
	me->reset_action();
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
              外功名称：刀剑啸
              外功所属：枯骨刀法 
              外功效果：以七修剑、枯骨刀分别攻击对方，带固定伤害
                        阴风爪等级足够后将以阴风爪追加一击
			冷却时间 5 秒
              外功条件：
			无底洞弟子
			人物等级 20 级
			混天气功200级并激发
			枯骨刀200级并激发
			七修剑100级并激发
			内力600点，消耗150点 
LONG;
me->start_more(str);
return 1;
}
