// dagou-bang.c 打狗棒法
// Code By Looklove@SJ 2001/4/1
// Modify By Looklove 2001.4.7
// Modify By Looklove 2001.4.8
// Looklove modified at 2001.5.5
// Looklove modified at 2001.5.15
// Looklove modified at 2001.5.18

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
        "action": "$N一声轻吟，挥起$w，使出一式「打草惊蛇」，猛扫向$n的$l",
        "force": 80,
        "lvl" : 0,
        "skill_name": "打草惊蛇",
        "damage_type": "挫伤"
]),
([
        "action": "$N步伐跳跃，手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
        "force": 100,
        "lvl":10,
        "skill_name": "拨草寻蛇",
        "damage_type": "内伤"
]),
([
        "action": "$N手中$w一圈，使出一招「关门打狗」将$n四面八方围个密不透风",
        "force": 140,
        "lvl" : 20,
        "skill_name": "关门打狗",
        "damage_type": "淤伤"
]),

([
        "action": "$N步踏坤位，施出「拨狗朝天」，反手将$w由下往上向$n撩去",
        "force": 160,
        "lvl" : 30,
        "skill_name": "拨狗朝天",
        "damage_type": "挫伤"
]),
([
        "action": "$N大喝一声「狗急跳墙」！抢上一步，将$w劈头抡向$n的$l",
        "force": 180,
        "lvl" : 50,
        "skill_name": "狗急跳墙",
        "damage_type": "挫伤"
]),
([
        "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
        "force": 200,
        "lvl" : 80,
        "skill_name": "棒打双犬",
        "damage_type": "挫伤"
]),
([
        "action": "$N手腕一翻，一招「恶犬拦路」，将手中$w向$n的去势封了过去",
        "force": 220,
        "lvl" : 100,
        "skill_name": "恶犬拦路",
        "damage_type": "挫伤"
]),
([
        "action": "$N一招「棒打狗头」，只见$w突然飞起，直击$n的顶门",
        "force": 240,
        "lvl" : 120,
        "skill_name": "棒打狗头",
        "damage_type": "挫伤"
]),
([
        "action": "只见$N使出一招「斜打狗背」，侧身拧腰，$w斜劈向$n的$l",
        "force": 260,
        "lvl" : 140,
        "skill_name": "斜打狗背",
        "damage_type": "挫伤"
]),
([
        "action": "$N灵机一动，使出一招「反截狗臀」，反手将$w戳向$n的$l",
        "force": 270,
        "lvl" : 160,
        "skill_name": "反截狗臀",
        "damage_type": "挫伤"
]),
([
        "action": "$N一招「打狗入洞」，将$w舞了个棒花，横扫$n的$l",
        "force": 280,
        "lvl" : 180,
        "skill_name": "打狗入洞",
        "damage_type": "挫伤"
]),
([
        "action": "$N反身错步，手中$w一幌，使一招「压肩狗背」，夹头夹脸打向$n的$l",
        "force": 300,
        "lvl" : 200,
        "skill_name": "压肩狗背",
        "damage_type": "内伤"
]),
});

int valid_enable(string usage) { return (usage == "stick") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((string)me->query("family/master_name")!="洪七公")
                return notify_fail("打狗棒只能从洪七公处学到。\n");

        if ((int)me->query_skill("stick", 1) < 20)
                return notify_fail("你的基本棒法太差, 还领会不了打狗棒法。\n");

        if (me->query("gender") == "无性")
                return notify_fail("你一个不男不女之人如何能学打狗棒？\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, j, level, glvl, d, p;
        string msg;

        d = (int)me->query_dex() * (random(4)+1);
        p = (int)me->query_int() * (random(2)+2);
	level = me->query_skill("dagou-bang", 1);
	weapon = me->query_temp("weapon");

	if (me->query("gender")=="女性") glvl = level/5;
	else glvl = level/6;
	if (glvl > 100) glvl = 100;

        if( me->query_temp("shuangjue/dgb")){
                switch((int)me->query_temp("shuangjue/dgb")){
                        case 2: msg = HIG"$N忽然斜挪一步，眼中灵光一闪，手中$w"HIG"横扫向$n的$l"NOR; break;
                        case 1: msg =  HIW"$N招数突变，忽然跃起，只见$w"HIW"化作一团棒影直向$n的$l打去"NOR;break;
                        default: msg = HIW"$N晃身错步，猛然一声长啸，舞起漫天棒影攻向$n的$l"NOR; break;
                }
                me->add_temp("shuangjue/dgb", -1);
                return ([
                "action": msg,
                "dodge": glvl,
                "parry": p+d,
                "damage": glvl + p/2,
                "force": level+glvl+p,
                "damage_type": "挫伤"
                ]);
        }

        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        break;
                }
        if (level > 400 && userp(me))
                return ([
                        "action" : action[j]["action"],
                        "dodge":(d+p)/2,
                        "parry": glvl/2+(p+d)/2,
                        "damage": glvl/4+(p+d)/2,
                        "force" : action[j]["force"]+glvl/2+p+d,
                        "lvl" : action[j]["lvl"],
                        "damage_type" : action[j]["damage_type"],
                        ]);

        return ([
                "action" : action[j]["action"],
                "dodge":me->query("gender")=="女性"?level/10+d:level/15+d/2,
                "parry": glvl/2+p/2,
                "damage": glvl/4+p/2,
                "force" : action[j]["force"]+glvl/2+p+d,
                "force" : me->query("gender")=="女性"?action[j]["force"]:action[j]["force"]*3/2,
                "lvl" : action[j]["lvl"],
                "damage_type" : action[j]["damage_type"],
        ]);
}

int practice_skill(object me)
{
        object weapon;
        int lvl = me->query_skill("dagou-bang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if (!objectp(weapon = me->query_temp("weapon"))
         ||(string)weapon->query("skill_type") != "stick")
                return notify_fail("你使用的武器不对。\n");

        if( me->query("gender") == "无性")
                return notify_fail("你一个不男不女之人如何能练打狗棒？\n");

        if ((int)me->query("jingli") < 40)
                return notify_fail("你的精力不够练打狗棒法。\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("你的内力不够练打狗棒。\n");

        me->receive_damage("jingli",40);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int b, x, p, level, damage, quest;
	object weapon, tweapon;
	string msg;

	quest = (int)me->query("dgb/wugou");
	b = me->query_skill("bangjue", 1);
	level = me->query_skill("dagou-bang", 1);
	weapon = me->query_temp("weapon");
	tweapon = victim->query_temp("weapon");

	if ((string)me->query_skill_mapped("parry") != "dagou-bang") return 0;
	if (!me->is_fighting(victim) || !weapon || !userp(me)) return 0;
	if ( !living(me) || !living(victim)) return 0;
	if ( damage_bonus < 100 ) return 0;
	if ( damage_bonus > 300 ) damage_bonus = 300;

	if ( random(quest+6) > 6
	 && quest > 0
	 && !me->query_temp("shuangjue")
	 && !me->query_temp("dgb/wugou")
	 && !me->query_temp("dgb/hit2")
	 && !me->query_temp("dgb/wugoua")
	 && (int)me->query("neili") >= 500
	 && random(b+quest*10) >=120 ){
		x = random(1+quest);
		me->set_temp("dgb/wugoua",1);
		if( x > 5 ) x = 5;
		switch(x) {
			case 5: msg = HIR"$N「天下无狗」第五变，披天盖地般打来。只见"+ weapon->name() +HIR"招招不离$n的脑门"NOR; break;
			case 4: msg = HIB"只见慢天棒影一停，$N将「天下无狗」第四变使出，脚在"+ weapon->name() +HIB"一端一踢，"+ weapon->name() +HIB"突然飞向$n的小腹"NOR; break;
			case 3: msg = HIG"$N使出「天下无狗」第三变，将"+ weapon->name() +HIG"抡圆了，突然直捅$n的眼睛"NOR; break;
			case 2: msg = HIW"$N闪身后跳，使出「天下无狗」第二变，手中"+ weapon->name() +HIW"猛扫向$n的脚踝"NOR; break;
                        case 1: msg =  HIC"忽然$N急走数步，回身"+ weapon->name() +HIC"斜劈，使出「天下无狗」第一变，戳向$n的肩头"NOR;break;
                        case 0: msg = HIC"$N棒走偏峰，将"+ weapon->name() +HIC"舞成满天棒影，竟然使的是「天下无狗」"NOR; break;
                        default: msg = HIC"$N棒走偏峰，将"+ weapon->name() +HIC"舞成满天棒影，竟然使的是「天下无狗」"NOR; break;
		}
		damage = damage_bonus/10 + random(damage_bonus)/5*level/20+x*10;
		victim->receive_damage("qi",damage/10+x*50+level/10,me);
		victim->receive_wound("qi", damage/10+x*50+level/5,me);
		p = (int)victim->query("qi")*100/(int)victim->query("max_qi");
		msg += COMBAT_D->damage_msg(damage, "劈伤");
		msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		me->add("neili", -(x*10+40));
		me->delete_temp("dgb/wugoua");
		message_vision(msg, me, victim);
	}
	else
	if (!victim->is_busy()
	 && random(b) >= 100
	 && victim->query("neili")
	 && !me->query_temp("shuangjue")
	 && !me->query_temp("dgb/wugoua")
	 && !me->query_temp("dgb/hit2")
	 && random(level) > 100
	 && random((int)me->query("neili")) > 400
	 && (int)me->query("max_neili") >= 1200
	 && random(20) > 17 ){
		victim->start_busy(1);
		me->set_temp("dgb/hit2",1);
		damage = damage_bonus/10 + random(damage_bonus)/10*level/40;
		if (!random(2)) {
			msg = HIM"紧跟着$N朗声诵道：「狗急跳墙如何打？ 快击狗臀劈狗尾。」，随之向$n下盘接连攻出数招。\n"NOR;
			msg += "$n叫声不好，不及回身招架，向前窜跃趋避，岂知$N的点打连绵不断，$n一个疏神，连连中招!\n";
			victim->receive_damage("qi",damage/6,me);
			victim->recieve_wound("qi",damage/6,me);
			p = (int)victim->query("qi")*100/(int)victim->query("max_qi");
			msg += COMBAT_D->damage_msg(damage, "劈伤");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			message_vision(msg, me, victim);
		}
		else {
			msg = HIG"$N悄声念道：「棒回掠地施妙手 ，横打双犬莫回头。」, 随之棒影横掠而下，$n躲闪不及连中几下。\n"NOR;
			victim->receive_damage("qi",damage/10,me);
			victim->receive_wound("qi", damage/10,me);
                        p = (int)victim->query("qi")*100/(int)victim->query("max_qi");
                        msg += COMBAT_D->damage_msg(damage, "劈伤");
                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			message_vision(msg, me, victim);
                }
		me->add("neili", -100);
		me->delete_temp("dgb/hit2");
	}
	return 1;
}

int ob_hit(object ob, object me, int damage)
{
	object wp,twp;
	string msg;
	int j, p, bj, level;

	wp = me->query_temp("weapon");
	twp = ob->query_temp("weapon");
	level = (int)me->query_skill("dagou-bang",1);
	bj = me->query_skill("bangjue",1);

	if( living(me)
	 && userp(me)
	 && living(ob)
	 && !ob->query("env/invisibility")
	 && wp
	 && (string)me->query_skill_mapped("parry") == "dagou-bang"
	 && (string)wp->query("skill_type") == "stick"
	 && random(level) > 100
	 && random(bj) > 100
	 && (int)me->query("neili") > 500
	 && random(level)+level/2 > (int)ob->query_skill("parry")/2
	 && random(20) > 7) {
		me->add("neili", -50);
		if(twp) {
			msg = HIM"$n"+ twp->name() +HIM"一招甫出，但见$N使个“封”字诀，棒影飘飘，登时将自己\n"NOR;
			msg += HIM"身前数尺之地尽数封住了。$n无奈之下，只有后退一步，静观变化。\n"NOR;
			if(!ob->is_busy()){
				ob->start_busy(2);
				me->add("neili",-70);
			}
			else
				ob->add_busy(1);
			me->add("neili",-40);
			j = -damage;
		}
		else {
			msg = HIM"$n的手指刚要碰到$N手腕，突然只见青影闪动，"NOR;
			msg += HIM""+wp->name() +HIM "一势“封”字诀，来势神妙无方，\n"NOR;
			msg += HIM"手腕已被重重地敲了一下。$n慌忙后退两步，变色斜睨，背上惊出了一阵冷汗。\n"NOR;
			if(!ob->is_busy()){
				ob->start_busy(2);
				me->add("neili",-50);
			}
			else
				ob->add_busy(1);
			ob->receive_damage("qi", damage/5 > 0?damage/5:10, me);
			ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += COMBAT_D->damage_msg(damage, "劈伤");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
			me->add("neili",-100);
			j = damage;
		}
		message_vision(msg, me, ob);
		return j;
	}
}

int help(object me)
{
        write(HIG"\n打狗棒："NOR"\n");
        write(@HELP
        打狗棒共有绊、劈、缠、戳、挑、引、封、转八诀，是闻名天下的
        丐帮镇帮绝技。以轻、灵、奇、巧诸称，舞将起来是四处只见棒影
        不见人影。武学中有言道：“四两拨千斤”，乃打狗棒法的精妙招
        数精髓体现。修习时如不同时学习棒诀，终将无法大成。

HELP
        );
        return 1;
}

