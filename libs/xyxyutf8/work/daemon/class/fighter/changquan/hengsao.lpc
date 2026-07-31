#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string *a1 = ({
        "虚步亮掌","并步对拳",
});
string *a2 = ({
        "弓步冲拳","弹腿冲拳","马步冲拳","弓步冲拳","弹腿冲拳","虚步栽拳",
        "歇步抡砸拳","马步冲拳","弓步下冲拳","换跳步弓步冲拳","虚步挑拳",
        "歇步下冲拳","仆步抡劈拳","提膝劈掌弓步冲拳",
});
string *a3 = ({
        "弓步击掌","马步架掌","提膝穿掌","仆步穿掌","虚步挑掌",
        "马步击掌","叉步双摆掌","弓步击掌","仆步亮掌","弓步劈掌",
        "提膝挑掌",
});
string *a4 = ({
        "弓步顶肘","转身左拍脚","右拍脚","腾空飞脚",
        "转身踢腿马步盘肘","叉步亮掌侧踹腿",
});

int perform(object me, object target)
{
	int damage;
	string msg,*limbs,limb,succ_msg;

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("changquan",1)<200 )
        	return notify_fail("你的长拳修炼还不够。\n");
	if( me->query("force")<800 )
        	return notify_fail("你的内力不够了。\n");               
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
        	return notify_fail("你要对谁使用『横扫千军』？\n");
	
	damage = me->query_skill("unarmed")/15+me->is_knowing("jjf_hengsao")*5;
	me->add("force",-200);
	msg = YEL"$N"YEL"使出一式「"NOR HIY+a1[random(sizeof(a1))]+NOR YEL"」，上步往前，几乎与$n"YEL"贴面而站！$n"YEL"尚未有任何反应，$N"YEL"顺势一招「"NOR HIY+a2[random(sizeof(a2))]+NOR YEL"」，直捣$n"YEL"$l！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
	
	if( me->query("force")<200 )
	{
		me->start_busy(1);
		message_combatd("$N内力不继，停住了攻击。\n",me);
		return 1;
	}
	
	me->add("force",-200);	
	msg = YEL"$N"YEL"撤拳变掌，更步上前，一招「"HIY+a3[random(sizeof(a3))]+NOR YEL"」径直拍向$n"YEL"$l！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
	
	if( me->query("force")<200 )
	{
		me->start_busy(2);
		message_combatd("$N内力不继，停住了攻击。\n",me);
		return 1;
	}

	me->add("force",-200);	
	msg = YEL"$N"YEL"不待招式用老，收掌变招，一招「"HIY+a4[random(sizeof(a4))]+NOR YEL"」猛击$n"YEL"的$l！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
	me->start_busy(3);
	return 1;
}               
        
int help(object me)
{
string str;     
if( !me )      return 0;
str = @LONG
        外功名称：横扫千军
        外功所属：长拳
        外功效果：连续对敌进行带固定伤害的物理攻击
        	  每一击消耗200点内力，最高三击
        	  每一击增加施展后自身busy 1 秒
        外功条件：
                  人物等级20级
                  内力800点
                  长拳200级
LONG;
me->start_more(str);
return 1;
}  
