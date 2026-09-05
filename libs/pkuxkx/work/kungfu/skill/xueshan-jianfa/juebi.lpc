// File         : linhai.c
// Created By   : iszt@pkuxkx, 2007-03-22

#include <ansi.h>
#define PFM_NAME HIB"绝壁剑法"NOR
#define Menpai "雪山派"
inherit F_SSERVER;

string perform_name(){ return PFM_NAME; }

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, per, m_int;

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「"+PFM_NAME+"」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xueshan-jianfa", 1) < 120 )
                return notify_fail("你的雪山剑法功力太浅。\n");
        if( (int)me->query_skill("xueshan-jianfa", 1) < 180 )
                return notify_fail("你的雪山剑法功力不够，使不出「"+PFM_NAME+"」。\n");
        if( (int)me->query_skill("sword", 1) < 180 )
                return notify_fail("你的基本剑法还要多加练习才是！\n");
        if( (int)me->query_skill("xueshan-neigong", 1) < 180 )
                return notify_fail("你的雪山内功功力太浅，使不出「"+PFM_NAME+"」。\n");
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为太浅，使不出「"+PFM_NAME+"」。\n");
        if( (int)me->query("neili") < 800 )
                return notify_fail("你的真气不够，使不出「"+PFM_NAME+"」。\n");
    	/*if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
                return notify_fail("你真气运转方式不对，使不出「"+PFM_NAME+"」。\n");*/
        if (!objectp(weapon = me->query_temp("weapon"))
                || weapon->query("skill_type") != "sword")
//                || me->query_skill_mapped("sword") != "xueshan-jianfa")
                return notify_fail("你不装备一把剑，使不出「"+PFM_NAME+"」。\n");
        if(target->is_busy())
                return notify_fail("对方正手忙脚乱，无暇出招，何必使用「"+PFM_NAME+"」！\n");
// 修改：无论中没中招，都增加永久属性？不合理吧！这会导致新手雪山号能随意调戏老鸟号。改为临时属性。by lordstar@2017/10/11
        target->add_temp("lingxiao/juebi_victim", 1);

        msg = HIC"\n$N"HIC"身行突然一纵，居高临下，故作狰狞之态，向$n"HIC"迅速挑出六角雪花之形，其快无比！\n"NOR;
		
		m_int = me->query("int");
        ap = me->query_skill("xueshan-jianfa",1) + m_int*10;
        ap += target->query_temp("lingxiao/juebi_victim") * 100;
		if (m_int > 35)
		{
			ap += m_int*12;
		}
		else
		{
			if (m_int > 30)
			{
				ap += m_int*5;
			}
		}
        dp = target->query_skill("dodge",1) + target->query("dex")*10;
        per = me->query_per();
//C-&per
        if( F_KUNGFU->hit_rate( ap, dp, 9, me, target) && random(per) <= 10)
        {
                F_KUNGFU->hit_busy( "confuse", random(8)+me->query_skill("xueshan-jianfa")/10, target );
         //       me->start_busy(2);
                msg+=HIR"$n"HIR"见$N"HIR"面目扭曲变形，丑陋已极，剑法又是极精，心中恐惧，只顾见招拆招，却踏入了$N"HIR"设计好的圈套！\n"NOR;
                msg+=HIB"$N"HIB"冷笑一声，$n"HIB"才发现自己已经置身于绝壁下，要想伤到$N"HIB"，却比登天还难！\n"NOR;
        }
        else if(ap > dp)
        {
                F_KUNGFU->hit_busy( "confuse", random(4)+me->query_skill("xueshan-jianfa")/20, target );
           //     me->start_busy(2);
                msg+=HIM"$n"HIM"见$N"HIM"虽是面目扭曲变形，却仍俊美非常，剑法又是极精，心中暗赞，只顾见招拆招，却踏入了$N"HIM"设计好的圈套！\n"NOR;
                msg+=HIB"$N"HIB"冷笑一声，$n"HIB"才发现自己已经置身于绝壁下，要想伤到$N"HIB"，却比登天还难！\n"NOR;
        }
        else {
           //     me->start_busy(2);
                if(per > 14)
                {
                        msg += HIY"$n"HIY"见$N"HIY"虽是面目扭曲变形，丑陋已极，却不甚惊恐，知其中必定有诈。\n"HIG"转眼间";
                }
                msg+=HIG"$n"HIG"已明白了$N"HIG"的用意，微微一笑，踏出了圈子，反而令$N"HIG"无所适从！\n"NOR;
        }
		if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
		{
			me->add("neili", -200);
			dp = me->query_skill("xueshan-jianfa",1);
			if (dp < 1001)
			{
				ap = 19 - dp/100;
			}
			else if (dp < 1401)
			{
				ap = 14 - dp/200;
			}
			else if (dp < 2001)
			{
				ap = 7 - (dp-1400)/300;
			}
			else
			{
				ap = 5;
			}
	
			if (random(ap)==0)
			{
				me->start_busy(0);
				me->add("neili", -100);
			}
			else
			{
				me->start_busy(1);
			}
		}
		else
		{
			me->start_busy(2);
		}
        me->add("neili", -200);

        message_vision(msg, me, target);

        return 1;
}

int help(object me)
{
        write(WHT"\n雪山剑法之「"+PFM_NAME+WHT"」："NOR"\n");
        write(@HELP
        雪山派中亦不乏聪明才智之士，在剑法中偶尔发挥一下，便有了这套「绝壁
        剑」。向上跃起刺雪花有时能迷惑一些不甚明智的人，从而为我所用，不得
        反击。后人又加以改进，使见过这招甚至会用的人也会上钩。即使如果被破
        掉，也不会有太大的风险。只是由于此招并非正途，所以要求偏高。

        要求：  内力 600 以上；      
                最大内力 2000 以上；  
                基本轻功等级 180 以上；
                基本剑法等级 140 以上；
                雪山剑法等级 160 以上；
                冰雪心法等级 160 以上；
                且使用雪山剑法。
HELP
        );
        return 1;
}
