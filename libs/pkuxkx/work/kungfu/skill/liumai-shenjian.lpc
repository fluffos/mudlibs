// /d/dali/kungfu/liumai-shenjian.c 六脉神剑
//edit by whuan@pkuxkx 2007-8-16
//对筋斗进行一些限制
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N倒退身形，嗤嗤两指，从容不迫地架开来势，大拇指使出"HIR"「少商剑」"NOR"，按向$n的$l，
劲道使得甚巧，初缓后急，剑气如怒潮般汹涌而至，剑路雄劲，石破天惊",

        "force" : 360,
        "dodge" : 50,
        "damage" : 280,
	      "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N食指连动，快速无比，格开对方来势，变招奇速，如毒蛇出洞，疾从袖底穿出，大喝一声，
使出"HIR"「商阳剑」"NOR"，双手幻出无数指影，巧妙灵活，难以琢磨，拂向$n的$l",
        "force" : 400,
        "dodge" : 50,
        "damage" : 300,
        "lvl" : 150,
        "damage_type" : "刺伤"
]),
([      "action" : "两指之间，相距只是电光般一闪，$N一翻掌，身向右移，奋起神威，右手斗然探出，
中指一竖，一招"HIR"「中冲剑」"NOR"，迅疾的向$n的$l划去，大开大合，气势雄伟",
        "force" : 450,
        "dodge" : 50,
        "damage" : 340,
        "lvl" : 300,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长笑一声，右手硬生生缩回，左手横斩而至，俯身斜倚，无名指弹出，一式"HIR"「关冲剑」"NOR"，
拙滞古朴，奇正有别，指尖已对准$n的$l发出了一缕强烈的劲风",
        "force" : 480,
        "dodge" : 50,
        "damage" : 380,
        "lvl" : 450,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双掌自外向里划了一个圈，双掌托在胸前，伸出右小指，一招"HIR"「少冲剑」"NOR"，
缓缓地点向$n的周身大穴，弹指无声，到得近前，劲气弥漫，破空之声甚厉",
        "force" : 500,
        "dodge" : 50,
        "damage" : 420,
        "lvl" : 600,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手臂陡然一提，对$n发起攻击，手掌离$n不到一尺，立即变掌为指，使出"HIR"「少泽剑」"NOR"，
忽来忽去，变化精微，只见一股剑气从左小指激射而出，击向$n的$l",
        "force" : 550,
        "dodge" : 70,
        "damage" : 480,
        "lvl" : 750,
        "damage_type" : "刺伤"
]),
});

mapping *action_sword = ({
([
        "action" : "$N嘴角轻笑，提$w平胸，看准时机一剑刺出，激起呼呼风声，迅猛无比地直插$n$l",
        "damage_type" : "刺伤",
]),
([ 
        "action" : "$N左手捏个剑诀，右腕传动，将六脉神剑化于$w之上，出剑凝重，平平正正地刺向$n",
        "damage_type" : "刺伤",
]),
([ 
        "action" : "只见$N屏息凝神，脚步沉着，剑走刀势，一式横劈，砍向$n$l，招式威猛正大",
        "damage_type" : "割伤",
]),
([
        "action" : "$N脚下步法微变，身随剑走，端凝自重，极飘逸的一剑向$n刺出，轻灵中却也不失王者气象",
        "damage_type" : "刺伤",
]),
([
        "action" : "$N平推一剑，手中的$w看似渐渐沉重，使动时略比先前滞涩，但实是举轻若重，威猛之极",
        "damage_type" : "刺伤",
]),
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry" || usage == "sword"; }

int valid_learn(object me)
{

        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力不够。\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level, damage, force;
        level = (int) me->query_skill("liumai-shenjian", 1);
        damage= (level/150)*30+250+random(50);
        if ( damage> 580 )
        	damage=580;
        force= level/8 + 250 + random(50);
        if ( force>480 )
          force=480;
		if (me->query_temp("active_buffer/shenghuo-lingfa.jindou"))
		{
			force /= 3;
			force *= 2;
			damage >>=2;
			damage *= 3;
		}

        if( objectp(weapon) ) // whuan@pkuxkx 当剑法使用时...
                return ([
                        "action": action_sword[random(sizeof(action_sword))]["action"],
                        "force": force,
                        "damage": damage,
                        "damage_type": "刺伤",
                        "dodge": random(20),
                ]); 
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/2)];
	return 0;
}

int practice_skill(object me)
{
        object weapon;
		int level,level2;
        level = (int) me->query_skill("liumai-shenjian", 1);
		level2 = (int) me->query_skill("yiyang-zhi", 1);
		if (level>level2+10)
			return notify_fail("一阳指是六脉神剑的基础，不打好基础无法提升六脉神剑。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}

string *parry_msg = ({
       "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

