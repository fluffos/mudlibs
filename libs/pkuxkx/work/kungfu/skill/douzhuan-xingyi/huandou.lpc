#include <ansi.h>
#include <combat.h>
#include <combat/skill.h>       //战斗过程中和技能相关的函数
inherit F_SSERVER;
#define TEMPSKILL "apply_skills"

string *expel_skills = ({ "xuanming-zhangfa", "boxing", "jiuyang-shengong" }); // 某些变态的、不允许复制的技能

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}

void remove_old_copy_skill(object me)
{
	mapping sk = me->query_temp("last_copy_skills");
	string *skn;
	int level;
	if (sizeof(sk)>0)
	{
		skn = keys(sk);
		for (int i=0;i<sizeof(skn);i++)
		{
			level = me->query_temp_skill(skn[i]);
			if (level<=0) continue;
			if (level<=sk[skn[i]])
				me->delete_temp_skill(skn[i]);
			else
				me->set_temp(TEMPSKILL+"/"+skn[i]+"/level", level - sk[skn[i]]);
		}
		me->delete_temp("last_copy_skills");
	}
}

int perform(object me, object target)
{
	int pflv;
	string msg;

	if( !target ) target = offensive_target(me);
	
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「移星换斗」。\n");

	if ( me->query_temp("pfm_huandou_yixing"))
		return notify_fail("你已经在使用「移星换斗」了。\n");

	if (me->query_temp("huandou_yixing_cd") > time())
		return notify_fail("你刚刚使用过「移星换斗」，气息还未平复。\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "姑苏慕容") 
		pflv=0;
	if (pflv>5) pflv=5;
	
	if (pflv<=0 || me->query("family/family_name")!="姑苏慕容") 
		return notify_fail("非姑苏慕容内门弟子无法使用「移星换斗」。\n");
	
	if (pflv<4 || (int)me->query_skill("douzhuan-xingyi", 1) < 1000 )
		return notify_fail("你还没得到「斗转星移」心法的真传，没有学会「移星换斗」。\n");
	
	if( (int)me->query_skill("shenyuan-gong",1) < 800 )
        return notify_fail("你的神元功修为不够，使不出「移星换斗」！\n");
	
    if( (int)me->query("neili") < 1000 )
        return notify_fail("你现在真气不足，不能使用「移星换斗」！\n");
	
    if( (int)me->query("jing") < (int)me->query("max_jing") / 2 )
        return notify_fail("你现在自己都神志不清了，如何收敛心神使用「移星换斗」？\n");
	
	msg = HIW"\n$N" HIW "收敛心神，施展「移星换斗」绝技，身形随着$n" HIW "进退而动，仔细探查对手招式之间的奥秘。\n\n"NOR;
	
	me->set_temp("pfm_huandou_yixing", 1);
	me->set_temp("huandou_yixing_cd", time()+60);
	me->start_busy(1);
	
	remove_old_copy_skill(me);
	
	remove_call_out("get_hdyx");
	call_out("get_hdyx", 3+random(3), me, target, pflv);
	message_vision(msg, me, target);
	return 1;
}

void get_hdyx(object me, object target, int pflv)
{
	string msg, sk;
	mapping sks = ([ ]);
	int level, lmt, dur;
	if (!objectp(me)) return;
	me->delete_temp("pfm_huandou_yixing");
	if (!objectp(target) || !me->is_fighting(target)) 
	{
		tell_object(me, HIY"\n你吐出一口浊气，缓缓收敛了心法。\n\n"NOR);
		return;
	}
	if (userp(target))
	{
		tell_object(me, HIY "\n"+ target->query("name")+ HIY"谨守门户，你试了一会儿无机可乘，只好悻悻然地收敛了心法。\n\n"NOR);
		return;
	}
	if (environment(target) != environment(me))
	{
		tell_object(me, HIY "\n"+ target->query("name")+ HIY"不见了踪影，你只好悻悻然地收敛了心法。\n\n"NOR);
		return;
	}
	msg = "\n";
	sk = target->query_skill_mapped(choose_attack_skill(target, target->query_temp("weapon")));
	if (sk && member_array(sk, expel_skills)== -1)
	{
		level = target->query_skill(sk, 1);
		if (level<200)
		{
			msg += HIY+target->query("name")+HIY"的"+to_chinese(sk)+"使得杂乱无章，没有什么值得借鉴的地方。\n\n"NOR;
		}
		else
		{
			lmt = me->query_skill_limit();
			level = level*9/10 + random(level/5);
			level /= 2;
			sks += ([ sk:level]);
			level += me->query_temp_skill(sk);
			if (level>lmt) level = lmt;
			dur = me->query_skill("douzhuan-xingyi", 1) / 10;
			me->set_temp_skill(sk, level, dur);
			msg += HIW"经过一番试探，你似有所得，暗自点了点头。\n";
			msg += HIC"你从"+target->query("name")+HIC"的攻势中领悟到「"+to_chinese(sk)+"」的奥秘！\n"NOR;
			if (pflv>=5)
			{
				sk = target->query_skill_mapped("force");
				if (sk && member_array(sk, expel_skills)== -1)
				{
					level = target->query_skill(sk, 1);
					if (level > me->query_skill("force", 1)/2)
						level = me->query_skill("force", 1)/2;
					if (level>=200)
					{
						level = 50 + random(50);
						sks += ([sk:level]);
						level += me->query_temp_skill(sk);
						if (level>lmt) level = lmt;
						dur = me->query_skill("douzhuan-xingyi", 1) / 30;
						if (dur>90) dur=90;
						me->set_temp_skill(sk, level, dur);
						msg += HIW"你忽然心念一动，开始留意"+target->query("name")+ HIW"真气运行的细微之处，并有了一些心得。\n" NOR;
						msg += HIC"你领悟到「"+to_chinese(sk)+"」的奥秘！\n"NOR;
					}
				}
			}
			if (sizeof(sks)>0)
				me->set_temp("last_copy_skills", sks);
		}
	}
	else
	{
		if (sk)
			msg += HIY+target->query("name")+ HIY "的功夫看起来十分古怪，你从未见识过。犹豫了片刻之后，你悻悻然收敛了心法。\n\n"NOR;
		else
			msg += HIY"看起来"+target->query("name")+ HIY "这点三脚猫的功夫还不如一个街头无赖，你撇了撇嘴，露出一个鄙视的神情。\n\n"NOR;
	}
	tell_object(me, msg);
}

