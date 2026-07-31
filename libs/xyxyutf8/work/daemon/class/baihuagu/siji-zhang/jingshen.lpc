// Jingshen.c 惊神一击
// Cracked by 凌惊雪 5-8-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;     
	mapping jingshen= ([
        	"force": 250,
        	"dodge" : -10,
        	"parry" : -5,
        	"weapon": "十指",
       		"damage_type" : "刺伤",
       		"action" :  HIY"$N左手手指三连环，右手手指两相交，指掌相叠，化为无数缕金光射向$n$l"NOR,
	]);
	object weapon=me->query_temp("weapon");
	
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="百花谷")
        	return notify_fail("「惊神一击」只有百花谷弟子才可以用！\n"); 
	if( time()-(int)me->query_temp("bhg_jingshen")<4 )
        	return notify_fail("你现在状态不好，无法发出惊神一击。\n");      
	if( me->query_skill("brightjade-force",1)<60)
        	return notify_fail("你的明玉神功太差，无法发出惊神一击。\n");
	if( me->query_skill("siji-zhang",1)<60
	 || (string)me->query_skill_mapped("unarmed")!="siji-zhang" )
        	return notify_fail("你的百花四季掌太差，无法发出惊神一击。\n");
	if( me->query("force")<300)
        	return notify_fail("你内力不继，难以发出惊神一击。\n");
        	
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
        	return notify_fail("你们没有在打架！\n");

	damage = me->query_skill("unarmed")/5;
	message_vision(HIW"$N"HIW"突然清啸一声，身形微展，飘开三丈！\n"NOR,me,target);     
	me->add("force", -50);
	me->set_temp("bhg_jingshen",time());	
	me->set("actions",jingshen);
	me->set_temp("pfm_color",HIM);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,damage);
	me->set_temp("pfm_color",0);
	me->reset_action();
	return 1;
}

int help(object me)
{
string str;     
if(  !me )      return 0;
str = @LONG
        外功名称：惊神一击
        外功所属：百花四季掌
        外功效果：运用掌力对敌人进行猛烈一击
                  使用完冷却 4 秒
        外功条件：
        	  百花谷弟子
        	  人物等级5级	
                  百花四季掌60级并激发
                  明玉神功60级
                  内力300点,消耗100点
LONG;
me->start_more(str);
return 1;
}       
