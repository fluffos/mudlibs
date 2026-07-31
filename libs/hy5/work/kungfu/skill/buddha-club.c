//南海普陀 释厄棍法 buddha-stick
//by junhyun@sk_sjsh
//2002.5.11

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        HIR"$N口宣佛号，使出一招 我佛慈悲"NOR,
        HIR"$N力由心发，平平一招 金刚伏魔"NOR,
        HIR"$N身形一转，悠然一招 暴风骤雨"NOR,
        HIR"$N不退反近，突然一招 舍身饲虎"NOR,
        HIR"$N以棍做剑，单手一招 回头是岸"NOR,
        HIR"$N脚踩连环，一连数招 慈航普渡"NOR,

});

string* skill_tail =({
        RED"，手中$w破空之声大作，朝着$n砸将下来。"NOR,
        RED"，砸向$n，隐隐约约能听到风雷阵阵。"NOR,
        RED"，越到$n身侧，手中$w如暴雨般点向$n。"NOR,
        RED"，硬生生从$n身侧滑过，手中$w扫向$n的$l。"NOR,
        RED"，棍棍不离$n周身大穴，打得$n手忙脚乱。"NOR,
        RED"，手中$w幻做无数影子，从半空中击向$n。"NOR,
});

mapping *action = ({
        ([      "name":                 "我佛慈悲",
                "action":
"$N口宣佛号，使出一招"+BLINK""+HIY"「我佛慈悲」"NOR+"，手中$w破空之声大作，朝着$n砸将下来",
                "dodge":                45,
     "parry":   10,
                "damage":               365,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "金刚伏魔",
                "action":
"$N力由心发，平平一招"+BLINK""+HIY"「金刚伏魔」"NOR+"，砸向$n，隐隐约约能听到风雷阵阵",

                "dodge":                110,
     "parry":     10,
                "damage":               385,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "暴风骤雨",
                "action":
"$N身形一转，悠然一招"+BLINK""+HIY"「暴风骤雨」"NOR+"，越到$n身侧，手中$w如暴雨般点向$n",
                "dodge":                110,
     "parry":   20,
                "damage":              375,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "舍身饲虎",
                "action":
"$N不退反近，突然一招"+BLINK""+HIW"「舍身饲虎」"NOR+"！硬生生从$n身侧滑过，手中$w扫向$n的$l",
                "dodge":               110,
     "parry":   15,
                "damage":               335,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "回头是岸",
                "action":
"$N以棍做剑，单手一招"+BLINK""+HIB"「回头是岸」"NOR+"，棍棍不离$n周身大穴，打得$n手忙脚乱",
                "dodge":                115,
     "parry":     15,
                "damage":               360,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "慈航普渡",
                "action":
"$N脚踩连环，一连数招"+BLINK""+HIB"「慈航普渡」"NOR+"，手中$w幻做无数影子，从半空中击向$n",
                "dodge":                115,
     "parry":   10,
                "damage":               350,
                "damage_type":  "砸伤"
        ]),   
       ([      "name":                 "大闹阎罗府",
                "action":
"$N身形稍退，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来",
                "dodge":                115,
		"parry":	10,
                "damage":               535,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "谈笑退天兵",
                "action":
"$N仰天长笑，看也不看，一招「谈笑退天兵」，随手一棒向$n当头砸下",
                "dodge":                10,
		"parry":		10,
                "damage":               525,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "勇斗二郎神",
                "action":
"$N一个虎跳，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l",
                "dodge":                110,
		"parry":	20,
                "damage":               535,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "脱困老君炉",
                "action":
"$N一声巨喝，好一个「脱困老君炉」！\n就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l",
                "dodge":               110,
		"parry":	15,
                "damage":               525,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "醉闹蟠桃会",
                "action":
"$N使出「醉闹蟠桃会」，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭",
                "dodge":                115,
		"parry":		5,
                "damage":               530,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "三打白骨精",
                "action":
"$N连翻几个筋斗云，手中$w转得如风车一般，\n一连三棒从半空中击向$n顶门",
                "dodge":                115,
		"parry":	10,
                "damage":               520,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "千钧澄玉宇",
                "action":
"$N手中$w一抖，化为千万道霞光，\n就在$n目眩神摇之时，再一抖，霞光顿收，\n$w已到了$n的$l！这一招有个名堂，叫作「千钧澄玉宇」",
                "dodge":                110,
		"parry":	20,
                "damage":               500,
                "damage_type":  "砸伤"
        ]),
	([	"name":			"乾坤一棒",
		"action":	"$N将手中$w迎风一挥，幻出万千虚影，蓄力劲发，高举过顶，
$w对准$n的脑门就砸了下去。这一下要是打中，恐怕连大罗金仙也难逃一命",
		"parry":	30,
		"dodge":	50,
		"damage":	600,
		"damage_type":  "砸伤"
	]),
});


int valid_learn(object me)
{
        object ob;
     if( (string)me->query_skill_mapped("force")!= "zhanzhuang-gong")
     return notify_fail("释厄棍法必须四平大马站桩功才能练。\n");

if ((int)me->query_skill("zhanzhuang-gong", 1) < 200)
		 return notify_fail("你的站桩功火候不够，无法学波罗蜜手。\n");
	if ((me->query_skill("boluomi-hand", 1) < 200) )
		return notify_fail("你的波罗蜜手火候不够。\n");
	if ((me->query_skill("jingang-strike", 1) < 200) )
		return notify_fail("你的大金刚神掌火候不够。\n");

        if( (int)me->query("max_neili") < 550 )
                return notify_fail("你的内力不够，没有办法练释厄棍法，
多练些内力再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("你必须先找一根棍子才能练棍法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="club"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("buddha-club",1);
         lvl = (int)me->query_skill("buddha-club", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 50
        ||      (int)me->query("neili") < 50 )
                return notify_fail("你的内力或气不够，没有办法练习释厄棍法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
//        write("你默念佛号，练习了一遍释厄棍法。\n");
        return 1;
}


string perform_action_file(string action)
{
	return __DIR__"buddha-club/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("zhanzhuang-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("buddha-club",1))+50;
if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "zhanzhuang-gong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("buddha-club",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}


