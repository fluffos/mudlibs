//npc武功，不开放!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({

	([	"action":		"$N手中的$w迎风一晃，刀锋带出裂锦般的声音，一招"+(order[random(13)])+"「袈裟斩」"NOR"万马奔腾般地砍向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 40,
                "lvl" : 0,
                "skill_name" : "袈裟斩",
    		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w迎风狂舞，一招"+(order[random(13)])+"「逆袈裟」"NOR"象暴风中的滚沙，裹向$n的$l",
                "damage":               220,
		"force":		120,
                "dodge" : 120,
                "lvl" : 10,
                "skill_name" : "逆袈裟",
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w象狂风中的流云，正是"+(order[random(13)])+"「左切上」"NOR"忽聚忽散地砍向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 120,
                "lvl" : 30,
                "skill_name" : "左切上",
                "damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w象狂风中的流云，正是"+(order[random(13)])+"「右切上」"NOR"忽聚忽散地砍向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 130,
                "lvl" : 30,
                "skill_name" : "右切上",
                "damage_type":	"割伤"
	]),

	([	"action":		"$N晃动手中的$w，突然使出了"+(order[random(13)])+"「刺突剑」"NOR"刀光忽隐忽现，象秋风中的落叶，一刀连一刀地散向$n的$l",
		"force":		200,
                "damage":               200,
                "dodge" : 130,
                "lvl" : 80,
                "skill_name" : "刺突剑",
                "damage_type":	"割伤"
	]),
	([	"action":		"$N聚起全身的功力，"+(order[random(13)])+"「逆风」"NOR"手中的$w象刺骨寒风般割向$n",
		"force":		240,
		"damage":		240,
                "dodge" : 40,
                "lvl" : 100,
                "skill_name" : "逆风",
                "damage_type":	"割伤"
	]),
       ([  "action" : "$N纵身跃起手中$w轻挥，一式"+(order[random(13)])+"「居合拔斩」"NOR"斩向$n后颈",
               "damage" : 250,
               "dodge"  : 140,
               "force"  : 250,
               "lvl"   : 110,
               "skill_name" : "居合拔斩",
               "damage_type" : "割伤"
        ]),
       ([  "action" : "$N高高跃起，手中$w连话三个弧形，使出"+(order[random(13)])+"「翔尾闪」"NOR"向$n的右臂齐肩斩落",
           "damage" : 280,
           "dodge" : 140,
           "force" : 280,
           "lvl"   : 120,
           "skill_name" : "翔尾闪",
           "damage_type" : "割伤"
       ]),
       ([  "action" : "$N轻吁一声，使出"+(order[random(13)])+"「真直斩」"NOR"，刷刷刷刷四刀，向$n胸，腹，腰，肩四处连刺",
           "damage" : 300,
           "dodge" : 145,
           "force" : 205,
           "lvl"   : 140,
           "skill_name" : "真直斩",
           "damage_type" : "割伤"
       ]),
       ([  "action" : "$N仰天一声清啸，一招"+(order[random(13)])+"「踏入垂直斩」"NOR"，斜行向前，$w横削直击，迅捷无比，击向$n的$l",
           "damage" : 350,
           "dodge" : 145,
           "force" : 205,
           "lvl"   : 160,
           "skill_name" : "踏入垂直斩",
           "damage_type" : "割伤"
       ]),
([      "action":"$N施展出了"+(order[random(13)])+"「疾空杀」"NOR"绕着$n飞旋，$w带着狂野刀风，凌历无比地劈出六刀",
        "force" : 220,
        "dodge" : 130,
	"damage": 400,
        "lvl" : 200,
        "skill_name" : "疾空杀",
        "damage_type":  "割伤"
]),
([      "action":"$N一着"+(order[random(13)])+"「左滑回转斩」"NOR"，突然抢进$n近侧，迅猛地驱刀连斩，攻式顿然合成一个圆圈",
        "force" : 230,
        "dodge" : 130,
        "damage": 420,
        "lvl" : 225,
        "skill_name" : "左滑回转斩",
        "damage_type":  "割伤"
]),
([      "action":"$N大喝一声，手中$w大开大阖，连连挥刀使出"+(order[random(13)])+"「右滑回转斩」"NOR"，斩向$n的$l",
        "force" : 230,
        "dodge" : 130,
        "damage": 420,
        "lvl" : 230,
        "skill_name" : "右滑回转斩",
        "damage_type":  "割伤"
]),
([      "action":"$N运刀如风，连续用出了"+(order[random(13)])+"「疾空杀」"NOR"，"+(order[random(13)])+"「虚空杀」"NOR"，"+(order[random(13)])+"「百鬼杀」"NOR"，刀势霸道之极，向着$n周身各处猛砍猛劈",
        "force" : 500,
        "dodge" : 150,
        "damage": 600,
        "lvl" : 10,
        "skill_name" : "三绝斩",
        "damage_type":  "割伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("你的内力不够，没有办法练日本古剑法。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 200)
   return notify_fail("你的杀意心法火候不够。\n");

 if ((int)me->query_skill("huoxinliu-jianfa", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("你的神谷活心流火候不够，无法学。\n");

 if ((int)me->query_skill("feitian-yujianliu", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("你的飞天御剑流火候不够，无法学。\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("你的五行遁火候不够，无法学。\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("日本古剑法必须配合杀意心法才能练。\n");

    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("你的杀意心法火候不够。\n");

 if ((int)me->query_skill("huoxinliu-jianfa", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("你的神谷活心流火候不够，无法学。\n");

 if ((int)me->query_skill("feitian-yujianliu", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("你的飞天御剑流火候不够，无法学。\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("你的五行遁火候不够，无法学。\n");

        if( (int)me->query("qi") < 100
        ||      (int)me->query("neili") < 100 )
                return notify_fail("你的内力或气不够，没有办法练习日本古剑法。\n");
        me->receive_damage("qi", 80);
        me->add("neili", -80);
        //write("你按著所学练了一遍日本古剑法。\n");
        return 1;
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
        object target;

        level   = (int) me->query_skill("shiren-jianfa",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

    if (!userp(me) || (int)me->query_skill("shayi-xinfa", 1) > 10)
{
	if( random(8)==1 && random(level) > 260)
	{
		return ([
		"action": HIR"「 瞬天杀! 」"+HIM"$N使出超神速的缩地加天剑拔刀术，在$n未感痛楚前想置其死地!"NOR,
		"force" : 850+random(200),
		"dodge" : 250,
		"damage": 850+random(200),
	        "skill_name" : "瞬天杀!",
		"damage_type" : "刺伤" ]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIR"「火产灵神!」"+HIY"$N把整把无限刃由刀身至刀尖燃烧,能力发挥至极限,完全焚毁对手!!"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "火产灵",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIB"「红莲腕!」"+HIY"$N在抓住对手时,用炎灵引爆手套内藏的火药"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "红莲腕",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

         if( random(8)==1 && random(level) > 150)
	{
		return ([

		"action" : HIM"「秘剑.炎灵!」"+HIY"$N以无限刃点火,向对手同时发出斩击和火烧！ "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "土龙闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
 
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIG"「影子着鬼附身!」"+HIY"$N将心之一方作用于自己,使自己相信本身天下无敌,引发所有潜能,发挥最强威力。 "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "影子着鬼附身",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIC"「背车刀!」"+HIY"$N将右手的刀于背后交给左手,利用假动作，在预料不到的地方出刀 。 "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "背车刀",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"「二阶堂平法!」"+HIY"$N由[一,八,十]这三字组成[平]字将剑气射出,麻痹心肺$n,并让$n无法动弹。 "NOR,
		"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "二阶堂平法",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIC"「回天剑舞六连!」"+HIW"$N反握小太刀,运用流水招式刺出,左右再变两招,瞬间出六招。 "NOR,
		"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "回天剑舞六连",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIG"「阴阳双飞!」"+HIW"$N双刀纵横十字 两把小太刀十字交叉做剪刀架势的攻击$n 。"NOR,
		"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "阴阳双飞!",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
}
  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}




string perform_action_file(string action)
{
        return __DIR__"shiren-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("blade",1);
        level2= (int) me->query_skill("shiren-jianfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(level2)/2+1));
	return RED"只见$n$l上鲜血狂奔，已被"+weapon->name()+HIR"斩出的无形气劲切了开来!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("shiren-jianfa", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
    if ((int)me->query_skill("shayi-xinfa", 1) < 10 && userp(me)) return 1;


        if (  random(level) > 150
         && me->query_skill_mapped("parry") =="shiren-jianfa"
         && weapon
         && weapon->query("skill_type") == "blade"
         && me->query_skill("blade") > 150
         && random(3)==0
           ){
         msg = HIG"$N面对$n的攻势。身形一闪，突出狠招!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「 瞬天杀! 」。$N使出超神速的缩地加天剑拔刀术，在$n未感痛楚前想置其死地!!。\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 80000)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}
else
{
ob->add("qi",-7000);
ob->add("qi",-7000);
}

msg += damage_msg(damage, "瘀伤");
            }
else  if (random(3)==1 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「火产灵神!」。$N把整把无限刃由刀身至刀尖燃烧,能力发挥至极限,完全焚毁$n!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 80000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/15);
msg += damage_msg(damage, "瘀伤");
}
else
{
ob->add("qi",-6000);
ob->add("qi",-6000);
msg += damage_msg(damage, "瘀伤");
}
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「回天剑舞六连!」。$N反握小太刀,运用流水招式刺出,左右再变两招,瞬间出六招!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 80000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
msg += damage_msg(damage, "瘀伤");
}
else
{
ob->add("qi",-5500);
ob->add("qi",-5500);
msg += damage_msg(damage, "瘀伤");
}
            }
else
           msg = HIG"$n认得这招历害,逃了开来，还好无事!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
