// feitian-yujianliu // feitian-yujianliu 飞天御剑流
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({

	([	"action":		"$N手中的$w迎风一晃，刀锋带出裂锦般的声音，一招"+(order[random(13)])+"「袈裟斩」"NOR"万马奔腾般地砍向$n的$l",
		"force":		100,
                "damage":               100,
                "dodge" : 10,
                "lvl" : 0,
                "skill_name" : "袈裟斩",
    		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w迎风狂舞，一招"+(order[random(13)])+"「逆袈裟」"NOR"象暴风中的滚沙，裹向$n的$l",
                "damage":               120,
		"force":		120,
                "dodge" : 20,
                "lvl" : 10,
                "skill_name" : "逆袈裟",
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w象狂风中的流云，正是"+(order[random(13)])+"「左切上」"NOR"忽聚忽散地砍向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 20,
                "lvl" : 30,
                "skill_name" : "左切上",
                "damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w象狂风中的流云，正是"+(order[random(13)])+"「右切上」"NOR"忽聚忽散地砍向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 30,
                "lvl" : 30,
                "skill_name" : "右切上",
                "damage_type":	"割伤"
	]),

	([	"action":		"$N晃动手中的$w，突然使出了"+(order[random(13)])+"「刺突剑」"NOR"刀光忽隐忽现，象秋风中的落叶，一刀连一刀地散向$n的$l",
		"force":		200,
                "damage":               200,
                "dodge" : 30,
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
               "dodge"  : 40,
               "force"  : 250,
               "lvl"   : 110,
               "skill_name" : "居合拔斩",
               "damage_type" : "割伤"
        ]),
       ([  "action" : "$N高高跃起，手中$w连话三个弧形，使出"+(order[random(13)])+"「翔尾闪」"NOR"向$n的右臂齐肩斩落",
           "damage" : 280,
           "dodge" : 40,
           "force" : 280,
           "lvl"   : 120,
           "skill_name" : "翔尾闪",
           "damage_type" : "割伤"
       ]),
       ([  "action" : "$N轻吁一声，使出"+(order[random(13)])+"「真直斩」"NOR"，刷刷刷刷四刀，向$n胸，腹，腰，肩四处连刺",
           "damage" : 300,
           "dodge" : 45,
           "force" : 205,
           "lvl"   : 140,
           "skill_name" : "真直斩",
           "damage_type" : "割伤"
       ]),
       ([  "action" : "$N仰天一声清啸，一招"+(order[random(13)])+"「踏入垂直斩」"NOR"，斜行向前，$w横削直击，迅捷无比，击向$n的$l",
           "damage" : 350,
           "dodge" : 45,
           "force" : 205,
           "lvl"   : 160,
           "skill_name" : "踏入垂直斩",
           "damage_type" : "割伤"
       ]),
([      "action":"$N施展出了"+(order[random(13)])+"「疾空杀」"NOR"绕着$n飞旋，$w带着狂野刀风，凌历无比地劈出六刀",
        "force" : 220,
        "dodge" : 30,
	"damage": 400,
        "lvl" : 200,
        "skill_name" : "疾空杀",
        "damage_type":  "割伤"
]),
([      "action":"$N一着"+(order[random(13)])+"「左滑回转斩」"NOR"，突然抢进$n近侧，迅猛地驱刀连斩，攻式顿然合成一个圆圈",
        "force" : 230,
        "dodge" : 30,
        "damage": 420,
        "lvl" : 225,
        "skill_name" : "左滑回转斩",
        "damage_type":  "割伤"
]),
([      "action":"$N大喝一声，手中$w大开大阖，连连挥刀使出"+(order[random(13)])+"「右滑回转斩」"NOR"，斩向$n的$l",
        "force" : 230,
        "dodge" : 30,
        "damage": 420,
        "lvl" : 230,
        "skill_name" : "右滑回转斩",
        "damage_type":  "割伤"
]),
([      "action":"$N运刀如风，连续用出了"+(order[random(13)])+"「疾空杀」"NOR"，"+(order[random(13)])+"「虚空杀」"NOR"，"+(order[random(13)])+"「百鬼杀」"NOR"，刀势霸道之极，向着$n周身各处猛砍猛劈",
        "force" : 500,
        "dodge" : 50,
        "damage": 600,
        "lvl" : 10,
        "skill_name" : "三绝斩",
        "damage_type":  "割伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练飞天御剑流。\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("你的杀意心法火候不够。\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("飞天御剑流必须配合杀意心法才能练。\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("你必须先找一把刀才能练飞天御剑流。\n");

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

        level   = (int) me->query_skill("feitian-yujianliu",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(8)==1 && random(level) > 260)
	{
		return ([
		"action": HIR"「 龙翔闪! 」"+HIM"$N一手按刀身,由下而上直抽，奇快无比，无与伦比，出刀还刀，只一瞬间之事"NOR,
		"force" : 550+random(200),
		"dodge" : 50,
		"damage": 550+random(200),
	        "skill_name" : "龙翔闪",
		"damage_type" : "刺伤" ]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : CYN"「 龙锤闪! 」"+HIY"$N手中$w"+HIY"微微颤动，刀光若有若无，刀法古朴飘逸，兼而有之"NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "龙锤闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIB"「 双龙闪! 」"+HIY"$N的$w"+HIY"弥补拔刀后空隙,刀和刀鞘同时攻向$n的全身。"NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "双龙闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

         if( random(8)==1 && random(level) > 150)
	{
		return ([

		"action" : HIM"「 土龙闪! 」"+HIY"$N的$w"+HIY"向地面猛烈斩击,打碎地面石块,溅向$n的要害！ "NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "土龙闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
 
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIG"「 龙巢闪! 」"+HIY"$N突然高高跃起$w"+HIY"从天而至!! $n被吓的讲不出话来了。 "NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "龙巢闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIC"「 龙卷闪! 」"+HIY"$N利用旋转的离心力，极速的挥动$w"+HIY"无数的劲气向$n卷了过去。 "NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "龙卷闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"「 飞翔龙闪! 」"+HIY"$N突然消失了！随后$w的反光出现在了$n的头上。"+HIY"$N尽然在办空使出了拔刀术。 "NOR,
		"force" : 650,
        	"dodge" : 50,
        	"damage": 650,
        	"skill_name" : "飞翔龙闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIC"「 龙椎闪! 」"+HIW"$N利用脚和腰的弹力飞身跃起,利用日光或者月光掩护向$n大力劈下 。 "NOR,
		"force" : 550,
        	"dodge" : 50,
        	"damage": 550,
        	"skill_name" : "龙椎闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIG"「 飞龙闪! 」"+HIW"$N假装高速拔刀,实则利用腕力推出刀身,使刀高速飞向$n 。 "NOR,
		"force" : 550,
        	"dodge" : 50,
        	"damage": 550,
        	"skill_name" : "飞龙闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("你的杀意心法火候不够。\n");

        if( (int)me->query("qi") < 80
        ||      (int)me->query("neili") < 80 )
                return notify_fail("你的内力或气不够，没有办法练习飞天御剑流。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
        write("你按著所学练了一遍飞天御剑流。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feitian-yujianliu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("shayi-xinfa",1);
        level2= (int) me->query_skill("feitian-yujianliu",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
//if (!level) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"只见$n$l上鲜血狂奔，已被"+weapon->name()+HIR"斩出的无形气劲切了开来!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("feitian-yujianliu", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 200
         && me->query_skill_mapped("blade") =="feitian-yujianliu"
         && me->query_skill_mapped("parry") =="feitian-yujianliu"
         && weapon
         && weapon->query("skill_type") == "blade"
         && me->query_skill("blade") > 300
         && random(me->query_skill("blade",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 900
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIM"$N面对$n的攻势。手上的刀轻轻一移，一道阳光真射在刀背上，$n被这道闪光刺的睁不开眼！。\n"NOR;
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
}
else             msg = HIG"$N面对$n的攻势。手上的刀轻轻一移，一道阳光真射在刀背上，$n双眼一闭,还好无事!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
