// dssh.c zjpfm 断丝锁魂 
// by snowtu 2007
#include <ansi.h>
#include <combat.h> 
inherit SSERVER;

string name(){return NOR"「"HIG"断丝锁魂"NOR"」";}

int perform(object me, object target)
{
	int damage,extra,t,i,ap,dp;
	string msg,*skills,succ_msg;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name")!="盘丝洞" )
        	return notify_fail(name()+"是盘丝洞绝招！\n");
	if( !me->is_fighting(target) )
        	return notify_fail(name()+"只能在战斗中使用！\n");
	if( me->query("force")<800 )
        	return notify_fail("你的内力不够充沛！\n");
	if( me->query_skill_mapped("whip")!="yinsuo-jinling" )
		return notify_fail(name()+"必须配合银索金玲才能使用。\n");              
	skills = ({
	        "force","spells","sword","whip","dodge",
        	"jiuyin-xinjing","pansi-dafa","qingxia-jian","yinsuo-jinling","yueying-wubu",
	});
	for(i=0;i<sizeof(skills);i++)
    	{
    		if( me->query_skill(skills[i],1)<300 )
        		return notify_fail("你的"+to_chinese(skills[i])+"等级不够，不能施展"+name()+"。\n");
	}       
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
        	return notify_fail("你要对谁施展这一招？\n");
        
	if( time()<(target->query_temp("no_perform/start")+target->query_temp("no_perform/time")) ) 
        	return notify_fail("你现在使用这一招是画蛇添足。\n");
        
	t = me->query_skill("qingxia-jian",1);
	t/= 150;
	if( t>30 )  t = 30;

	me->add("force", -300);
	msg = HIG"$N"HIG"忽将双手一展，$w"HIG"迎风展开，光华四射，隐约有无数佛灯梵呗佛珠在上攒动，顿时一阵悦耳的银铃之声随风飘扬开来。\n"NOR;
	succ_msg = HIC"$n"HIC"只觉的心神一震！";
	if( target->query("gender")=="女性" )
    	{
        	if( !target->query("couple/name") )
            		succ_msg+= "想起自己妙龄已过，尚待字闺中，不由暗自神伤。。。\n"NOR;
		else    succ_msg+= "想起"+target->query("couple/name")+HIC"对自己的所为，不禁凄然泪下。。。\n"NOR;
	}
        else    
        {
        	if( !target->query("couple/name") )
            		succ_msg+= "想起自己鬓发逐白，尚孑然一身，不由暗自神伤。。。\n"NOR;
		else    succ_msg+= "想起"+target->query("couple/name")+HIC"对自己的所为，不禁愈加心中苦闷。。。\n"NOR;
	}	
	succ_msg+= HIR"$n"HIR"越想越气，不由内劲混乱，内外的动作变得凝滞笨重。"NOR;
	succ_msg+= HIR"$n"HIR"“哇”的一声，吐出了一口鲜血！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,me->query_skill("sword"));
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		msg = HIW"怎料$n"HIW"熟视无睹，不为此异像所动，$N"HIW"枉作无用之功。\n"NOR;
        	message_combatd(msg,me,target);
		me->start_busy(1);      	
        	return 1;
        }	
        target->set_temp("no_perform",([
                        "start" : time(),
                        "time"  : t,
                        "msg"   : HIR"你内劲为"+me->name()+HIR"所伤，无法施展外功。"NOR,
        ]));
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：断丝锁魂
        外功所属：青霞剑法
        外功效果：攻击对方，并使对方至多30秒内无法使用外功
		  不能对已不能使用外功的对象使用
		  不中则自身busy 1 秒
        外功条件：
                  盘丝洞弟子
        	  人物等级30级
                  内力800点，消耗300点
                  基本内功300级
                  基本法术300级
                  基本剑术300级
                  基本鞭法300级
                  基本轻功300级
                  九阴心经300级
                  盘丝大法300级
                  青霞剑法300级
                  银锁金铃300级
                  月影舞步300级
                  
STR;
        me->start_more(str);
        return 1;
}	