//yudian 2000-11-14
// zouxiao.c  碧箫传情  
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string succ_msg,msg;
        int damage,p;
        object weapon;
        
        if( me->query_level()<30 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("force")!="zhenyuan-force" )
		return notify_fail("只有用镇元神功才能运力吹箫。\n");
        if(me->query_skill("xiaofeng-sword",1)<300 )
		return notify_fail("你的晓风残月剑还得再练练。\n");
        if(me->query("family/family_name") != "五庄观") 
                return notify_fail("[吹箫]是五庄观不传之密！\n");
	if( me->is_knowing("wzg_zouxiao")<1 && userp(me) && !wizardp(me) )
		return notify_fail("你奏箫的功夫还不够，再好好练练吧。\n");
        if((int)me->query("force") < 200 )
                return notify_fail("你的内力还不到火候。\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("你的体力已经不够了！\n");
	if((int)me->query("sen") < 200 )
                return notify_fail("你无法集中精力！\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要对谁奏箫？\n");
        
        msg = HIC"$N"HIC"将$w"HIC"一收，凝气成箫，对着$n"HIC"奏起了一曲，箫声凄凉，似是叹息，又似哭泣，跟着箫声颤抖，发出瑟瑟瑟断续之音，如是一滴滴小雨落上树叶。\n"NOR;
        succ_msg = HIR"$n"HIR"听了箫声，心中莫名其妙的感到一阵酸楚，悲从中来，泪水正涔涔落下。\n"NOR;
        p = me->is_knowing("wzg_zouxiao");
        if( p<2 ) p = 2;
        me->add("force",-150);
        me->receive_damage("kee",100,me);
        me->receive_damage("sen",100,me);
        me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg);
        me->set_temp("pfm_msg",0);
        if( damage<1 )
        	me->start_busy(2);
        else if( target )
        	target->start_busy(p);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：碧箫传情
        外功所属：晓风残月剑
        外功效果：以箫声伤敌精神并使其busy
        	  需领悟，领悟越高，busy时间越长
                  不中则自身busy 2 秒
                  不能对busy中的敌方使用
        外功条件：
        	  五庄观弟子
        	  人物等级30级	
                  内力200点，消耗150点
                  气血200点，消耗100点
                  精神200点，消耗100点
                  晓风残月剑 300 级
                  内功激发镇元神功
                  
STR;
        me->start_more(str);
        return 1;
}