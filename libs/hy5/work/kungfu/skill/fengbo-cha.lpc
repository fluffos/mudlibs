//风波十二叉 fengbo-cha.c

/*
风波十二叉    dodge  0    parry  -5    damage  25
因其有特别之处，建议各项暂设为中等。
*/

//pickle, not changed yet, please try to be compatible. 

// 昔人已乘黄鹤去，此地空余黄鹤楼
// 黄鹤一去不复返，白云千载空悠悠
// 晴川沥沥汉阳树，芳草凄凄鹦鹉洲
// 日暮乡关何处去，烟波江上使人愁

// 江上往来人，但爱鲈鱼美
// 君看一叶舟，出没风波里

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N一招 龙震四野",
        "$N双手一震，发出一招 苍龙出海",
        "$N一提气，使出一招 龙腾四海",
        "$N一声龙吟长啸，使出 龙跃九洲",
        "$N使出 双龙戏珠",
        "$N趁$n防御之际，一招 金龙吐火",
});

string* skill_tail =({
        "，手中$w夹带着尖锐的响声，劈头盖脸地就向$n刺了过去。",
        "，对$n劈头盖脸的刺了过去。",
        "，手中$w斜斜地刺向$n的$l。",
        "，手中$w一阵横扫，直逼$n。",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，$n顿时手忙脚乱！",
});

mapping *action = ({
        ([      "name":                 "「昔人已乘黄鹤去」",
                "action":
"$N似乎在寻找些什么，手中$w在身前试探了数叉。\n"
"叉尖所指之处，正是$n的$l，原来是"BLINK+HIY"「昔人已乘黄鹤去」"NOR,
                "dodge":                10,
		"parry":		10,
                "damage":               345,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n挥动$W，在身前画了个半圆，正好挡开$N的攻势。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「此地空余黄鹤楼」",
                "action":
"$N身形不动，手中$w用一招"BLINK+HIR"「此地空余黄鹤楼」"NOR"，\n"
"拍向$n的$l。这招似乎颇为窒滞生硬，但毫不拖泥带水，攻势甚是凌厉",
                "dodge":                10,
		"parry":		10,
                "damage":               445,
                "damage_type":  	"瘀伤",
		"parry_msg":
"$n丝毫不为所动，轻描淡写地挥叉一刺，逼得$N回手自防。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「黄鹤一去不复返」",
                "action":
"$N接连几个起落，作势欲走，$n忙疾追不迭。正在这时，\n"
"$N于空中突然回身，一式"BLINK+HIC"「黄鹤一去不复返」"NOR"直指$n的$l",
                "dodge":                10,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"刺伤",
		"parry_msg":
"$n一抖手中$W，在$N兵器上一按，借势纵开数丈。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「白云千载空悠悠」",
                "action":
"$N一声清啸，但见漫天叉影，化作朵朵白云，扰得$n眼花缭乱\n"
"这招"BLINK+HIW"「白云千载空悠悠」"NOR"颇为传神，果然有一番前不见古人，后不见来者的气概",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"瘀伤",
		"parry_msg":
"$n将$W舞得风雨不透，$N无奈之下只好换招。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「晴川沥沥汉阳树」",
                "action":
"$N手中$w一颤，用一招"BLINK+HIM"「晴川沥沥汉阳树」"NOR"，迅捷无比地在$n上下左右各刺一叉",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"刺伤",
		"parry_msg":
"$n以手中$W画了个圆弧，将周身破绽都封死了。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「芳草凄凄鹦鹉洲」",
                "action":
"$N施出一招"BLINK+HIG"「芳草凄凄鹦鹉洲」"NOR"，只见$w若有若无地一探，\n"
"看去势似乎刺向$n左侧数寸处，但不知怎的，转瞬间叉尖已到了$l",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n怯生生地举叉一挡，似乎力不从心。但等到二人兵刃相交时，\n"
"$n$W上忽然发出一股韧力，将$N挡了开去。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「日暮乡关何处去」",
                "action":
"$N朗笑一声，手中$w泛出重重暗影，好似一阵阵浓雾，推向$n。\n"
"$n看不透这招"BLINK+HIB"「日暮乡关何处去」"NOR"的来路，实在不知如何招架",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"刺伤",
		"parry_msg":
"$n不避不让，挺$W在身前空处连次数叉。这招看来平平无奇，却于平淡中将$N的攻势封死了。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「烟波江上使人愁」",
                "action":
"$n刚喘得一喘，却见$N身形一闪，已经踪影全无。$n还未来得及转身，\n"
"$N的$w已到背后了。这招"BLINK+YEL"「烟波江上使人愁」"NOR"果然轻快无比，令人防不胜防",
                "dodge":                30,
		"parry":		30,
                "damage":               445,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n眼见$N攻势凌厉，忙用一招「烟波江上使人愁」，连转数圈，将$N的力拨在一边。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「江上往来人」",
                "action":
"$N怒叱一声，手中$w齐快无比地在$n身前来来回回连划七划。\n"
"这招"BLINK+WHT"「江上往来人」"NOR"变幻无方，$n实在不知哪招是虚，哪招是实",
                "dodge":                35,
		"parry":		35,
                "damage":               450,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n连挥手中$W，只听叮叮当当一阵密响，终于将$N挡了回去。\n",
		"parry_power":		15,
        ]),
        ([      "name":                 "「但爱鲈鱼美」",
                "action":
"$N手中$w缓缓画了个圆圈，用一招"BLINK+CYN"「但爱鲈鱼美」"NOR"慢慢向$n的$l套去",
                "dodge":                35,
		"parry":		35,
                "damage":               455,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n似乎胸有成竹，挺叉连划数个圆圈。$N看不透$n的守势，果然不敢贸然进攻。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「君看一叶舟」",
                "action":
"$N身形一旋，冲天而起。手中$w借着下冲之势，一招"BLINK+MAG"「君看一叶舟」"NOR"直插$n的$l",
                "dodge":                10,
		"parry":		30,
                "damage":               455,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n看准来势，以$W向$N的兵刃猛点。只听「当」的一声巨响，果然将$N的兵刃荡了开去。\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "「出没风波里」",
                "action":
"$N突然脸上青气一显，叉上嗡嗡之声大做，正当$n惊诧时，\n"
"$N狂风骤雨般连攻五叉。这招"BLINK+GRN"「出没风波里」"NOR"是整套叉法的精髓，\n"
"施将出来，不但变幻莫测，且声势惊人，$n顿时不知所措",
                "dodge":                35,
		"parry":		35,
                "damage":               460,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n不顾自身，手中$W连连刺向$N。这围魏救赵之记果然奏效，将$N逼了回去。\n",
		"parry_power":		15,
        ]),
});


int valid_learn(object me)
{
        object ob;


 if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才能学。\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("你的缚龙斩鲛刀为不够，无法修炼。\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("你的碧波神剑修为不够，无法修炼。\n");


        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("你必须先找一跟棍子来才能学叉法。\n");
        return 1;
}

int practice_skill(object me)
{
  if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("你的内力或气不够。\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才能学。\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("你的缚龙斩鲛刀为不够，无法修炼。\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("你的碧波神剑修为不够，无法修炼。\n");
		
   me->receive_damage("qi", 32);
   me->add("neili", -16);

   return 1;
}

int valid_enable(string usage)
{
        return usage=="club"||usage=="parry";
}


string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}
string perform_action_file(string action)
{
	return __DIR__"fengbo-cha/" + action;
}


mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("fengbo-cha",1);
         lvl = (int)me->query_skill("fengbo-cha", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("club",1);
        level2= (int) me->query_skill("jinghai-force",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("fengbo-cha",1))+50;
if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "jinghai-force")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("fengbo-cha",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}


}