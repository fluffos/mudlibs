// taixuan-gong.c 侠客岛太玄功
// Jay 4/5/96
// modified by Venus Oct.1997
//2000/6/10日 由lywin调整攻击力！加入自动pfm

#include <ansi.h>
//inherit FORCE;
inherit SKILL;

string *dodge_msg = ({
    "$n左手拍出，劲风到处，把$N震到一边。\n",
    "$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
    "$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
    "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});
mapping *actionw = ({
([      "action" : "$N攻势如虹，气势非凡，$w忽隐忽现，捉摸不定向$n慢慢攻去",
        "force" : 510,
        "attack": 180,
        "dodge" : 85,
        "parry" : 175,
        "damage": 325,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w龙吟不定，犹如长江滚滚而来，将$n笼罩",
        "force" : 510,
        "attack": 108,
        "dodge" : 72,
        "parry" : 115,
        "damage": 310,
        "damage_type": "刺伤"
]),
([      "action":"$N卷起手中的$w，宛如翻江倒海直射向$n而去",
        "force" : 532,
        "attack": 125,
        "dodge" : 60,
        "parry" : 102,
        "damage": 365,
        "damage_type": "刺伤"
]),
([      "action":"$N手中$w幻出一个个光环，顿时将$n团团包围",
        "force" : 565,
        "attack": 110,
        "dodge" : 75,
        "parry" : 105,
        "damage": 390,
        "damage_type": "内伤"
]),
([      "action":"$N飞身而起，手中$w犹如神龙般地卷向$n",
        "force" : 550,
        "attack": 108,
        "dodge" : 70,
        "parry" : 120,
        "damage": 420,
        "damage_type": "刺伤"
]),
});

mapping *action = ({
([      "action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
        "force" : 540,
        "attack": 50,
        "dodge" : 50,
        "parry" : 120,
        "damage": 355,
        "damage_type":  "瘀伤"
]),
([      "action":"$N右手伸出，霎时一股气流激射而出袭向$n",    
        "force" : 560,
        "attack": 60,
        "dodge" : 60,
        "parry" : 90,
        "damage": 330,
        "damage_type":  "瘀伤"
]),
([      "action":"$N大喝一声，左掌一抖，顿时一股气流向$n脸上涌去",
        "force" : 570,
        "attack": 75,
        "dodge" : 75,
        "parry" : 135,
        "damage": 360,
        "damage_type":  "瘀伤"
]),
([      "action":"$N猱身而上，全身真气暴发，双掌猛地拍向$n",
        "force" : 580,
        "attack": 80,
        "dodge" : 80,
        "parry" : 75,
        "damage": 395,
        "damage_type":  "瘀伤"
]),
([      "action":"$N身法陡快，忽左忽又，突然间$N双掌连连拍出，数股太玄内劲已射向$n",
        "force" : 580,
        "attack": 95,
        "dodge" : 90,
        "parry" : 125,
        "damage": 360,
        "damage_type":  "瘀伤"
]),
([      "action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
        "force" : 580,
        "attack": 100,
        "dodge" : 100,
        "parry" : 145,
        "damage": 580,
        "damage_type":  "瘀伤"
]),
});

int valid_enable(string usage)
{
      return usage == "unarmed" || usage == "hand" || usage == "dodge" ||usage == "parry" || usage == "force";
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("taixuan-gong",1)) > 300 && me->query("neili") > 100)
	{
		me->add("neili", -50);
		return ([
	"action": HIR "$N的心中突然一片茫然，只觉得经脉中象有无数的蝌蚪在串来串去，难过非常，
当下不及多想，顺着蝌蚪的走向一阵拳打脚踢！四周顿时劲风乱飑，好不热闹！"NOR,
	"damage": 1000,
	"dodge" : 100,
	"force" : 500,
	"damage_type": "瘀伤"]);
	}
	return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return notify_fail("太玄神功无法通过练习来成长。\n");
}

int valid_learn(object me)
{
	if (
	me->query_skill("bahuang-gong",1)
|| me->query_skill("xuantian-wuji",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("taiji-shengong",1)||
me->query_skill("guiyuan-tunafa",1)||
me->query_skill("kongdong-xinfa",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("baiyun-xinfa",1)||
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("bluesea-force",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("你不先散了别派内功，怎能学？！\n");
		
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");

        if (me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳不调，难以领会高深的太玄功。\n");

        if ((int)me->query("int") < 30)
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if ((int)me->query("dex") < 30)
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");

    if (random(this_player()->query("int",1)) > 23)
        return 1;
    return notify_fail("你苦思良久！竟是一头雾水，毫无所得！。\n");

}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/exert/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"taixuan-gong/perform/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("parry") != "taixuan-gong")
return damage;
        if ((int)me->query_skill("literate", 1)> 5 )	
return damage;

if (me->query("neili") < 500)
return damage;
 if (objectp(weapon = me->query_temp("weapon"))
        )
return damage;

             
  if (random(ap) < dp/2  
  && random(2)==0)
        {

                switch (random(2))
                {
                case 0:
                        result =  HIR "$n" HIR "默念太玄功口诀，太玄内"
                                            "劲齐聚于全身，$N" HIR "只觉这招攻在"
                                            "$n" HIR "身上\n，犹如碰到铜墙铁壁一般，"
                                            "丝毫不起作用。\n"NOR;
                        break;
                case 1:
                        result =  HIR "$N" HIR "一招击中$n" HIR "上身"
                                            "，可却犹如击在铜墙铁壁上一般\n，力道顿时"
                                            "消失得无影无踪。\n" NOR;
                        break;
                default:
                        result =  HIR "但见$n" HIR "一声轻啸，浑若无事"
                                            "的接下了$N" HIR "这一招，\n却没有受到"
                                            "半点伤害。\n" NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (random(3)==0 && !ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi")*2)
me->add("qi",damage/5+200);
if ((int)me->query("eff_qi") < (int)me->query("max_qi")*2)
me->add("eff_qi",damage/5+200);
            damage=100;
            j=100;
            return j;

        }

}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;



if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;
if (me->query_skill_mapped("parry") != "taixuan-gong")
return 0;
        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( (damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 ) || random(3)==0
	) {
	victim->receive_wound("qi", (lvl+80));
return random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，太玄内劲"
                                   "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                   HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                   "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
}
}