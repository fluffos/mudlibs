// /kungfu/skill/xiangfu-lun.c
// xiangfu-lun.c 降伏轮
// dubei
// snowman(98,12,22)
// iceland(99.8.3)
#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N一招「大赞叹光明势」，右手立掌护胸，左手单臂抡起$w，当胸砍向$n的$l",
	"skill_name" : "大赞叹光明势",
	"force" : 170,
	"dodge" : 5,
	"parry" : 5,
	"lvl" : 0,
	"damage" : 70,
	"damage_type" : "割伤",
]),
([	"action" : "$N将手中$w抛上半空，跃起一掌砸在$w上，这招「大皈依光明势」有如流星坠地，直轰$n",
	"skill_name" : "大皈依光明势",
	"force" : 210,
	"dodge" : 10,
	"parry" : -10,
	"lvl" : 20,
	"damage" : 90,
	"damage_type" : "瘀伤",
]),
([	"action" : "凭空闪出一道雪白的光幕，光电闪烁中$w挟「大功德光明势」的无上劲力，从$N手中飞出砍向$n的$l",
	"skill_name" : "大功德光明势",
	"force" : 200,
	"dodge" : 5,
	"parry" : 10,
	"lvl" : 40,
	"damage" : 120,
	"damage_type" : "割伤",
]),
([	"action" : "$N双眼磕闭，全身衣物却在内劲鼓荡下涨如气球，那$w在这「大常乐光明势」的推动下，向$n缓缓压去",
	"skill_name" : "大常乐光明势",
	"force" : 220,
	"dodge" : -5,
	"parry" : 15,
	"lvl" : 60,
	"damage" : 65,
	"damage_type" : "内伤",
]),
([	"action" : "$N双手越转越急，光幕俨如一轮明月，将$n笼罩，这「大吉祥光明势」的劲力带着$w以排山倒海之势飞旋而出",
	"skill_name" : "大吉祥光明势",
	"force" : 240,
	"dodge" : -10,
	"parry" : -5,
	"lvl" : 80,
	"damage" : 80,
	"damage_type" : "砸伤",
]),
([	"action" : "$N口中高唱「降魔咒」，一招「大三昧光明势」挥出，$w幻化的漫天的轮影犹如行云流水般涌向$n",
	"skill_name" : "大三昧光明势",
	"force" : 260,
	"dodge" : 10,
	"parry" : -15,
	"lvl" : 100,
	"damage" : 100,
	"damage_type" : "瘀伤",
]),
([	"action" : "$N面现瑞气，以无上降魔大法催动「大般若光明势」，$w舞出的光云慢慢逼近$n。",
	"skill_name" : "大般若光明势",
	"force" : 280,
	"dodge" : -10,
	"parry" : 10,
	"lvl" : 120,
	"damage" : 120,
	"damage_type" : "瘀伤",
]),
([	"action" : "$N提一口真气，手中$w上下翻飞，轮番砸出，这「大智慧光明势」让$n眼前轮影乱舞，应接不暇。",
	"skill_name" : "大智慧光明势",
	"force" : 300,
	"dodge" : -20,
	"parry" : 10,
	"lvl" : 140,
	"damage" : 140,
	"damage_type" : "砸伤",
]),
([	"action" : "$N面带微笑，眼露慈光，全身所散发出的「大慈悲光明势」气劲宛如惊涛骇浪，$w一波接一波地涌向$n",
	"skill_name" : "大慈悲光明势",
	"force" : 320,
	"dodge" : 15,
	"parry" : 10,
	"lvl" : 160,
	"damage" : 160,
	"damage_type" : "瘀伤",
]),
([	"action" : "$N双手高举$w，大喝一声使出「大圆满光明势」自上而下斩向$n，其快绝无比，气势汹涌，已达圆满之境",
	"skill_name" : "大圆满光明势",
	"force" : 350,
	"dodge" : 20,
	"parry" : -15,
	"lvl" : 180,
	"damage" : 200,
	"damage_type" : "刺伤",
]),
});

string *parry_msg = ({
MAG"$n不躲不避，手中法轮摆开，在$N跟前形成了一道光幕，$N此招根本无法递出。\n"NOR,
MAG"却见$n踏前一步，手中法轮翻飞，力道威猛，$N见势心怯，闪身而退。\n"NOR,
MAG"$n轮法突变，法轮带着风声飞舞出去，后发先至，在$N还没攻出时就破了$N的招数。\n"NOR,
MAG"但见$n力贯双臂，举法轮硬架，乒的一声震开了来势汹汹的$N。\n"NOR,
MAG"$n看准来势，法轮摆个天地势，将$N进路封死，$N这招只发得一半就攻不进去了。\n"NOR,
MAG"$N一招运足，才发现$n手中法轮指向自己的$l，正是此招的空门，连忙收招闪避。\n"NOR,
});

string  *msg = ({
CYN"$w"CYN"已彷佛幻化成了千百条般挥舞不息，漫天的轮影形成了一个多角形的图案，每一轮的攻出都是如此凌厉而猛辣"NOR,
HIY"空中那几只法轮对击，声若龙吟，悠悠不绝，就在$n一呆之际，法轮飞砸了出去！"NOR,
YEL"呜呜声响中，法轮旋转飞舞着撞向$n，在$p便要挡隔时，却绕过他飞到了身後"NOR,
YEL"$w"YEL"法轮连续掷出，连续飞回，绕著$n兜个圈子，忽高忽低，或正或斜，所发声音也是有轻有响，旁观众人均给扰得眼花撩乱，心神不定"NOR,
YEL"一声「小心了！」，蓦然间法轮合体归一，并排向$n撞去，势若狂牛冲阵，威不可挡"NOR,
HIC"蓦而$n身前五丈方圆内起了一阵回旋的风暴，光华灿然中，法轮飞舞而出，几似龙降九天"NOR,
HIG"这些$w"HIG"好似彼比连接在一起的巨龙，在$n身前盘旋纵横，鳞甲闪烁，好像宇宙之间，已全被这所遮掩无馀"NOR,
MAG"只见$w"MAG"呜呜响声不绝，绕著$n上下翻飞，掀的阵阵狂风有如刀割，似要把$n从中劈开"NOR,
YEL"突然狂风大作，激荡中那$w"YEL"相碰相撞，数轮归一，合并了向$n砸去"NOR,
HIM"法轮再次合围，紫电精芒围著$n的四周旋舞闪射，千百轮影幻映出一幅美丽而眩目的图案，这图案美极了，似是一片多角形的紫色雪晶体"NOR,
YEL"法轮在$n身前环饶，猛地向$p迎头击下，接着又飞来一轮，一抄一送，呜呜声响，兜向$n$l"NOR,
YEL"呼呼飞啸声中，那几只法轮或直飞、或斜飞、或回旋、或下坠、或上升，霎时间$n的全部退路已被封死"NOR,
BLU"猛地里$w"BLU"向$n$l飞砸下，在$p沉肩卸避之时，法轮又突然上飞击出，砸向$p的$l"NOR,
YEL"那法轮飞旋砸到，$n却并不回头，听风辨器，一一挡开，但法轮便如长上了眼睛一般，竟然又旋飞到了$n$l"NOR,
HIY"随着森森慑人的厉吼，$w"HIY"蓦而急颤晃动，轮身嗡嗡震响，在不及眨眼的瞬息间，耀目的电光金蛇四射迸闪，飞掠周遭，迅捷无匹的击$n"NOR,
});
int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

void skill_improved(object me)
{
	int skill = me->query_skill("xiangfu-lun", 1);
	if(skill >= 200 && !me->query("ryl_add")){
		me->set("ryl_add", 1);   
		tell_object(me, HIW"\n忽然，你感道内息越转越快，瞬时功力已经上升到了一个新的境界！\n你的精力增加了！\n你的内力增加了！\n"NOR);
		me->add("max_jingli", skill/2+random(skill));
		me->add("max_neili",skill/2+random(skill));
	}
	if(skill > 300 && random(4) == 1)
	{
		me->set_skill("xiangfu-lun", skill-1);
	}
}
int valid_learn(object me)
{
        if((int)me->query_str() <35)
		return notify_fail("你的臂力不够学降伏轮。\n");
	if((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力不够。\n");
	if((int)me->query_skill("longxiang-boruo", 1) <= 200)
		return notify_fail("需要有第二层以上龙象般若功火候,才能学降伏轮。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int) me->query_skill("xiangfu-lun",1);
	
	if( !userp(me) && me->query("env/invisibility")
	&& me->query("master_user/user") ){
		return ([
			"action": msg[random(sizeof(msg))],
			"damage":(random(4)+1)*60,
			"damage_type":random(2)?"砸伤":"瘀伤",
			"dodge": 5,
			"force":250+random(250)
		]);
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed query_parry_msg(object weapon, object me, int attack_type)
{
	if (objectp(weapon) && objectp(me)
	&& (string)weapon->query("skill_type") == "hammer"
	&& me->query_skill_mapped("hammer") == "xiangfu-lun"
	&& me->query_skill_mapped("parry") == "xiangfu-lun")
		return parry_msg[random(sizeof(parry_msg))];
	return "结果被堪堪架开。\n";
return "结果被架开！！！！！！！！！！！！\n";

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	    || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的气不够，无法练习降伏轮。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的现在的内力不足，无法继续练降伏轮。\n");
	me->add("qi", -45);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiangfu-lun/" + action;
}

void after_hit(object me, object victim, string attack_skill, int damage)
{
	object wp1, target, *eny; 
	string msg;
	int i, pflv;

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "大轮寺") 
		pflv=0;

	wp1 = me->query_temp("weapon");
	eny=me->query_enemy();
	eny-=({victim});
	if (pflv>=5) i=3;
	else if (pflv==4) i=2;
	else i=1;
	while (i>0 && sizeof(eny)>0 )
	{
		target = eny[random(sizeof(eny))];
		if (F_KUNGFU->hit_rate( me->query_str()+15, target->query_dex(), 9, me, target) )
		{
			msg=HIG"$N"HIG"挥舞" +wp1->name()+ HIG "顺势向$n" HIG "砸了过来，砰的一声砸了个正着。\n"NOR;
			message_vision(msg, me, target);
			F_KUNGFU->hit_wound("qi", damage*4/5, damage/5, me, target);
			COMBAT_D->report_status(target);
			damage = damage * (70+random(20)) / 100;
		}
		else
		{
			message_vision(HIY"$N"HIY"挥舞" +wp1->name()+ HIG "顺势向$n" HIY "砸了过来，但一下挥了个空。\n"NOR, me, target);
			break;
		}
		eny -= ({ target });
		i--;
	}
}

void after_victim_parry(object me, object victim, string attack_skill)
{
	object wp1, wp2; 
	int pflv, dmg, duo = 0;
	string msg;

	if( !objectp(wp2= victim->query_temp("weapon")) )
	{
		if( !objectp(wp2= victim->query_temp("secondary_weapon")) )
			return;
	}
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "大轮寺") 
		pflv=0;
	
	if (pflv>=5 && F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 12, me, victim) )
	{
		if ((wp2->query("id") == "xuantie sword" || wp2->query("never_broken"))
			&& !wp2->query("owner")) //玄铁剑居然没有特殊标记，只好用ID，囧
		{
			msg = HIY+"$N"+HIY"力贯双臂，势挟风雷，砸在$n"+HIY"的"+wp2->name()+HIY"上，噗的一声，响声又沉又闷，便如木棍击打败革！\n"NOR;
			message_vision(msg, me, victim);
		} else {
			msg = HIM+"$N"+HIM"力贯双臂，势挟风雷，砸在$n"+HIM"的"+wp2->name()+HIM"上，发出一声巨响！\n"NOR;
			dmg = me->query_str() / 2;
			wp2->add("rigidity", -dmg);
			if (wp2->query("rigidity") < 1)
			{
				msg += HIR "只听见「啪」地一声，"+ wp2->name() + HIR + "登时断为两截，$n也被这一击震得倒退三步，呕出一口鲜血！\n" NOR;
				message_vision(msg, me, victim);
				dmg = me->query_skill("longxiang-boruo", 1) + me->query_skill("xiangfu-lun",1);
				dmg *= 2;
				dmg = dmg*4/5 + random(dmg/5);
				F_KUNGFU->hit_wound("qi", dmg, dmg/3, me, victim);
				COMBAT_D->report_status(victim);
				return;
			}
			message_vision(msg, me, victim);
		}
	}
		
	if( !me->query("env/锁")
	|| me->query_skill("xiangfu-lun", 1) < 150 
	|| !me->query("jiali")
	|| me->query("neili") < 1000 
	|| me->query_skill_mapped("parry") != "xiangfu-lun" )
		return;

	wp1 = me->query_temp("weapon");

	if( random(10) >= 6 
	&& F_KUNGFU->hit_rate( me->query("combat_exp"), victim->query("combat_exp"), 12, me, victim) ){
		message_vision(HIW"$N"HIW"手臂暴长，施展「锁」字诀，"+wp1->name()+HIW"探出，嚓的一声锁住了$n"+wp2->name()+HIW"。\n"NOR, me,victim);
		if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 18, me, victim) ){           
			me->add("neili", -150);
			message_vision(HIG+"$N"+HIG"运劲回拉，$n"+HIG"臂骨喀的一声，险些就被拉断，剧痛之下手一松，"+wp2->name()+HIG"被夺了过去！\n"NOR, me, victim);
			wp2->unequip();
			wp2->move(me);
			duo = 1;
		}

		else if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 12, me, victim) ){           
			me->add("neili", -50);
			message_vision(HIG+"$N"+HIG"运劲回拉，$n"+HIG"被带得踉跄几步，但觉虎口剧痛，"+wp2->name()+HIG"脱手飞出！\n"NOR, me, victim);
			wp2->unequip();
			wp2->move(environment(victim));
			duo = 1;
		}

		else if( me->query_temp("shield") ){           
			me->add("neili", -50);
			message_vision(HIY"$n"+HIY"借势前冲，"+wp2->name()+HIY"直刺过去，但被$N"+HIY"护体真气荡得滑了开去。\n"NOR, me, victim);
		}

		else message_vision(HIY"$n"+HIY"借势前冲，"+wp2->name()+HIY"直刺$N"+HIY"，$N"+HIY"变招奇快，"+wp1->name()+HIY"一抖松脱，纵身退了开去。\n"NOR, me, victim);
        
        if(duo == 1 && wp2->query("gem_ob_autoloaded") == 1)
        {
            message_vision(wp2->name()+"片片寸断，散落一地,$N不禁叹息不已。\n",victim);
            wp2->unequip();
            destruct(wp2);
        }
	}
}


int help(object me)
//added by iszt@pkuxkx, 2006-11-28
{
	write(HIW"\n降伏轮\n\n"NOR);
	write(@HELP
	可激发为锤法和招架。
	达到200级时可增加100～300点最大内力和最大精力。
	要求：  后天膂力35；
		最大内力2000；
		龙象般若功160级；
	练习：  耗气45；
		耗内力25；
	「锁」字诀：
	设置 set 锁 1 后满足要求随机自动出招，效果为夺来或打掉对方兵器。
	要求：  降伏轮150级；
		加力不为0；
		内力1000；
		激发降伏轮为招架。
HELP
	);
	return 1;
}
