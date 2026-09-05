// 狂风快剑 by Zine new huashan气宗不许用
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    int bt, lh, level, buff, pflv;
    object weapon = me->query_temp("weapon");
    mapping attack_val = ([
                          "base" : ([ "weapon" : "sword", ]), //基本功夫类型
                          "skill" : ([ "weapon" : "kuangfeng-kuaijian", ]), //高级技能名称
                           ]);

    if (!me->query("huashan_newskills/jianzong") ||
         me->query("family/family_name")!="华山派") 
		{	
			if (!me->query("safari_skill/hs_jq"))

		        return notify_fail("这是华山剑宗的秘传绝学，你无法在实战中运用「狂风连环剑」。\n");
		}

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「狂风连环剑」只能对战斗中的对手使用。\n");

    if (!objectp(weapon) || weapon->query("skill_type") != "sword")
        return notify_fail("你手中无剑怎能使用「狂风连环剑」？！\n");

    if ( (int)me->query_skill("huashan-neigong", 1) < 300 )
        return notify_fail("你的华山派内功火候未到，无法施展「狂风连环剑」！\n");

    if ( me->query_skill("sword", 1) < 300 || 
         (level=me->query_skill("kuangfeng-kuaijian", 1)) < 300 )
        return notify_fail("你剑法未到炉火纯青之境，还不会使用「狂风连环剑」！\n");

    if ( me->query("neili") <= 2000 || 
         me->query("max_neili") <= 6000 )
        return notify_fail("你的内力不足无法使用「狂风连环剑」！\n");

    if (time() - me->query_temp("hs/kf_start") < 5)
        return notify_fail("你刚刚使用过「狂风连环剑」。\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;

    me->set_temp("hs/kf_start", time());
    me->add("neili", -500);
    message_vision(CYN"\n\n$N" + CYN + "仰天一声清啸，斜行而前，长剑横削直击，迅捷无比，未到五六招，\n"+
                   "剑势中已发出隐隐风声。$N"+CYN"出剑越来越快，风声也是渐响。$n"+CYN"便\n"+
                   "似是百丈洪涛中的一叶小舟，狂风怒号，骇浪如山，一个又一个的滔天白\n"+
                   "浪向小舟扑去。\n"NOR, me, target);
    lh=level/100;
    bt = me->query("betrayer");
    if ( lh>7 ) lh=7;
    if ( !bt )
    {
      if ( target->is_busy() || ( pflv>=2 && ( target->query_temp("no_exert") || target->query_temp("no_perform")) ) )
        lh+=5;
      else if ( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 9, me, target) )
        lh+=2;
	if ( !me->query("huashan_newskills/jianzong"))
		{
			lh -= 2;
		}
	if (( !me->query("betrayer") )&&( !me->query("chushi/done") ))
		{
		if (me->query("safari_skill/hs_jq"))
			{
			lh += 1;
			}
		}   
	}
    
    for (int i = 0; i < lh; i++)
    { 
      buff = level / 5 + random(level / 5);
	  if (pflv>=2 && me->query("huashan_newskills/jianzong"))
		  buff += buff/10 + random(buff/10);
      me->add_temp("apply/attack", buff*2);
      me->add_temp("apply/damage", buff);
      me->set_temp("attack_val", attack_val);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
      me->add_temp("apply/attack", -buff*2);
      me->add_temp("apply/damage", -buff);
    }
    
    me->add_busy(2);
    return 1;
}