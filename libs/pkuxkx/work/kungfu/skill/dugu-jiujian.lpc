// dugu-jiujian.c 独孤九剑
// 1997-2-14
#include <ansi.h>
#include <combat.h>

inherit SKILL;

string *parry_msg = ({
"$n不闪不避，举剑闪电般使出「叠翠浮青」反削$N的$l，想挡过$N此招",
"却见$n踏前一步，剑式斜指$N的$l，想要使$N闪身而退",
"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」回攻$N",
"$n举剑狂挥，迅速无比地点向$N的$l，却令人看不出其所用是什么招式",
"$n运剑如风，剑光霍霍中反攻$N的$l，尝试逼$N自守，剑招似是「伏魔剑」的「龙吞式」",
"只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地指向$N的$l",
"$n挺剑一招象是「白云出岫」回刺$N的$l，企图将$N的攻势化解",
"$n以攻为守，以进为退，凝神运气向$N猛攻快打地挥出方位大异的泰山「快活三」三剑"
});

string  *msg = ({
"$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思",
"$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑",
"$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法",
"$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好",
"$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测",
"$N突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，$w对着$n一绞，企图突破$n的攻势",
"$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转向，大出$n意料之外",
"$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地缠向$n",
"$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实",
"$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法",
"$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力却是奇大，$n难以看清剑招来势",
"却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」为一剑攻向$n",
"$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，$n不得不守",
"$N神色凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏魔剑」剑意表露无遗",
"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去",
"$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削",
"$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l",
"$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好",
"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山剑势击向$n",
"$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云卷雾涌，旁观者不由得目为之眩",
"只见$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l",
"但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l",
"$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议",
"$n窥准$N一招华山剑法「有凤来仪」的趋势，准备进行反击，却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招",
"$n攻向$N的$l，$N不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周",
"$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n"
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
  int level, damage;
  
  level=me->query_skill("dugu-jiujian", 1);
  damage=level/5+200;
  if ( damage>550 )
    damage=550;
  if (me->query_temp("active_buffer/shenghuo-lingfa.jindou"))
  {
	  damage=damage/3;
  }
  return ([
    "action":msg[random(sizeof(msg))],
    "damage":damage,
    "damage_type":random(2)?"刺伤":"割伤",
    "dodge":100,
    "force":400
  ]);
}

string query_parry_msg(object weapon)
{
        if (!weapon) return 0;
        if (weapon->query("skill_type") == "sword")
                return parry_msg[random(sizeof(parry_msg))] + "。\n";
}


string perform_action_file(string action)
{
        return __DIR__"dugu-jiujian/" + action;
}



int practice_skill(object me)
{
        object weapon;
		string sname1,sname2,sname3;
		sname1=me->query("tqt/old_family1");
		sname2=me->query("tqt/old_family2");
		sname3=me->query("tqt/old_family3");
	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 100)
                 return notify_fail("你的体力不够练独孤九剑。\n");
        if ((int)me->query("jing") < 100)
                 return notify_fail("你目前精神状态并不足以领悟独孤九剑。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够。\n");
        if (me->query("family/family_name") != "华山派" && me->query("chushi/last_family")!="华山派")
		{
			if ((sname1=="华山派")||(sname2=="华山派")||(sname3=="华山派"))
			{
			}
			else
			{
        		return notify_fail("你不是华山派的弟子，不能练独孤九剑！\n");
			}
		}
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 10);
        me->add("neili", -10);
        return 1;
}

int kf_antirate(object me)
{
	if (me->query("safari_skill/9jian")==1)
	return 1+random(2);
	else
	return 0;
}

mapping buffer_applied(object ob)
{
	if (ob->query("safari_skill/9jian")==1 && ob->query_skill_mapped("parry") == "dugu-jiujian")
	{
		ob->set_temp("active_buffer/dugu-jiujian.wujian/name", "无剑胜有剑");                       //buff名称
		ob->set_temp("active_buffer/dugu-jiujian.wujian/effect1", "随机降低对手绝招命中率1-2级");     //效果描述1
	}
    return ([]);
}

mapping buffer_removed(object ob)
{
    ob->delete_temp("active_buffer/dugu-jiujian.wujian");
    return ([]);
}


int after_hit(object me, object ob, string attack_skill)
{
	int exp, pflv, i, c, buff;
	object weapon;
	string* msg =({
		HIR"归妹趋无妄，无妄趋同人，同人趋大有"NOR,
		HIG"甲转丙，丙转庚，庚转癸"NOR,
		HIY"子丑之交，辰己之交，午未之交"NOR,
		HIM"风雷是一变，山泽是一变，水火是一变"NOR,
		HIC"乾坤相激，震兑相激，离巽相激"NOR,
		HIB"三增而成五，五增而成九"NOR,
	});
    mapping attack_val = ([
        "base" : ([ "weapon" : "sword", ]), //基本功夫类型
        "skill" : ([ "weapon" : "dugu-jiujian", ]), //高级技能名称
    ]);
	
	if (!objectp(me) || !objectp(ob) || !ob->is_fighting(me) || me->query_temp("extra_attack")) return 0;

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;
	if (pflv<3 || !me->query("huashan_newskills/jianzong")) return 0;
	
	weapon = me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		weapon = me->query_temp("secondary_weapon"); 
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		return 0;
	
	if (F_KUNGFU->hit_rate( me->query_skill("sword","dugu-jiujian"), ob->query_skill("parry"), 11-pflv, me, ob) ) 
	{
		me->set_temp("extra_attack", 1);
		me->set_temp("apply/invalid_target_special", 1);
		buff = me->query_skill("dugu-jiujian", 1) ;
		me->add_temp("apply/attack", buff);
		me->add_temp("apply/damage", buff/2);
		
		message_vision(HIW"\n$N心中默念要诀「"+msg[random(sizeof(msg))]+HIW"」，一剑连着一剑，一剑快似一剑！\n"
			+HIC"每一剑全是进攻之招，招招攻敌之不得不守，独孤九剑，有进无退！\n"NOR, me, ob);
		c = pflv;
		for (i = 0; i<pflv; i++)
		{
			COMBAT_D->do_attack(me, ob, weapon, TYPE_SPECIAL);
			if (!ob->is_fighting(me))
			{
				c = i+1;
				break;
			}
		}
		if (c>=pflv)
			message_vision(HIW"$N一口气连绵不绝地刺出"+chinese_number(c)+"剑，余势去尽，才向后跃开半步。\n"NOR, me, ob);
		else
			message_vision(HIW"$N才刺出"+chinese_number(c)+"剑，见$n"HIW"败像已露，便向后跃开半步。\n"NOR, me, ob);

		me->add_temp("apply/damage", -buff/2);
		me->add_temp("apply/attack", -buff);
		me->delete_temp("extra_attack");
		me->delete_temp("apply/invalid_target_special");
	}
	return 1;
}

int after_parry(object me, object target, string attack_skill)
{
	object weapon;
	string limb, *limbs;
	int dmg, pflv, rate;
	if (!objectp(me) || !objectp(target)) 
		return 0;
	weapon = me->query_temp("weapon"); 
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		weapon = me->query_temp("secondary_weapon"); 
	if (!weapon || weapon->query("skill_type") != "sword" ) 
		return 0;
	pflv = (int)me->query("purefamily/level");
	if (pflv<4 || me->query("purefamily/family_name") != "华山派") return 0;
	
	rate = 13-pflv;
	if (pflv>=5 && target->query_temp("no_perform")) rate -= 3;
	if (F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), rate, me, target) )
	{
		limbs = target->query("limbs");
		if (sizeof(limbs)<=0) limb = "胸口";
		else limb = limbs[random(sizeof(limbs))];
		dmg = me->query_skill("dugu-jiujian",1);
		dmg += random(dmg/2);
		message_vision(HIC"$N反手一剑指向$n，有如神来之笔，听得噗的一声响，剑尖从$p"HIC+limb+"一穿而过。\n"NOR, me, target);
		F_KUNGFU->hit_wound("qi", dmg, dmg/2, me, target);
		COMBAT_D->report_status(target);
	}
	return 1;
}

