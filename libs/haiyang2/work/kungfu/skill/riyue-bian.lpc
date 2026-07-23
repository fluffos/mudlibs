// riyue-bian.c 日月鞭法
// modified by Venus Oct.1997

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N手中$w挥出，$w势道奇急，却是绝无劲风，自$n$l横掠而过，相距已不逾半尺",
        "dodge":  5,
        "damage": 260,
        "force" : 160,
        "lvl" : 33,
        "damage_type":  "鞭伤"
]),
([      "action": "$N手腕一抖，$w直昂上来，撞向$n面门，灵动威猛，便如一条张牙舞爪的墨龙相似",
        "dodge": 10,
        "damage":  295,
        "force" : 320,
        "lvl" : 63,
        "damage_type":  "鞭伤"
]),
([      "action": "$N$w抖动，转成两个圆圈，从半空中往$n头顶盖下，不但招数精巧，内劲更是雄厚无比",
        "dodge":  15,
        "damage": 220,
        "force" : 480,
        "lvl" : 93,
        "damage_type":  "鞭伤"
]),
([      "action": "$N手运刚劲，$w上所发内力直如排山倒海一般，向着四面八方逼去，登时迫得$n连连倒退",
        "dodge":  15,
        "damage": 240,
        "force" : 520,
        "lvl" : 124,
        "damage_type":  "内伤",
]),
([      "action": "$N手腕一抖，$w向$n胸口点到，化成一条笔直的兵刃，如长矛，如杆棒，疾刺而至，招数厉害之极",
        "dodge":  15,
        "damage": 260,
        "force" : 400,
        "lvl" : 185,
        "damage_type":  "刺伤",
]),
([      "action": "$N鞭上内劲不绝催动，内功施展到了淋漓尽致，$w呼啸而出，向$n面门点去，鞭身未到，$w上所挟劲风已令$n一阵气窒",
        "dodge":  15,
        "damage": 240,
        "force" : 540,
        "lvl" : 205,
        "damage_type":  "内伤",
]),
([      "action": "$N手中$w滚动飞舞，宛若灵蛇乱颤，鞭影纵横，似真似幻，骤出三招九式，每一式中都隐藏数十招变化，数十下杀手",
        "dodge":  15,
        "damage": 270,
        "force" : 600,
        "lvl" :  205,
        "damage_type":  "鞭伤",
]),
([      "action":      "$N端坐不动，一招"+(order[random(13)])+"「裂石式」"NOR"，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
        "dodge":       10,
        "damage":      200,
        "force" : 300,
        "lvl" :        0,
        "skill_name" : "裂石式",
        "damage_type": "刺伤"
]),
([      "action":      "$N身形一转，一招"+(order[random(13)])+"「断川式」"NOR"，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
        "dodge":       20,
        "damage":      200,
        "force" : 300,
        "lvl" :        60,
        "skill_name" : "断川式",
        "damage_type": "刺伤"
]),
([      "action":      "$N力贯鞭梢，一招"+(order[random(13)])+"「破云式」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "dodge":       40,
        "damage":      300,
        "force" : 300,
        "lvl" :        90,
        "skill_name" : "破云式",
        "damage_type": "刺伤"
]),
([	"action":"$N力贯鞭梢，一招"+(order[random(13)])+"「分海式」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"dodge":       50,
	"damage":      400,
	"force" : 300,
	"lvl" :        100,
	"skill_name" : "分海式",
	"damage_type": "刺伤"
]),
([	"action":"$N力贯鞭梢，一招"+(order[random(13)])+"「裂空式」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"dodge":       60,
	"damage":      500,
	"force" : 300,
	"lvl" :        110,
	"skill_name" : "裂空式",
	"damage_type": "刺伤"
]),
([	"action":"$N力贯鞭梢，一招"+(order[random(13)])+"「佛光普照」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"dodge":       60,
	"damage":      600,
	"force" : 300,
	"lvl" :        120,
	"skill_name":  "佛光普照",
	"damage_type": "刺伤"
]),
([	"action":"$N力贯鞭梢，一招"+(order[random(13)])+"「金刚伏魔」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"dodge":       70,
	"damage":      700,
	"force" : 300,
	"lvl" :        130,
	"skill_name" : "金刚伏魔",
	"damage_type": "刺伤"
]),
([	"action":"$N力贯鞭梢，一招"+(order[random(13)])+"「佛法无边」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"dodge":       100,
	"damage":      800,
	"force" : 300,
	"lvl" :        200,
	"skill_name" : "佛法无边",
	"damage_type": "刺伤"
]),
([     "action": "$N端坐不动，一式"+(order[random(13)])+"「阿那律刺」"NOR"，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤，前缠后绕，其力沾粘不散",
       "dodge": 15,
       "damage": 270,
       "force" : 300,
       "lvl" : 0,
       "skill_name" : "阿那律刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N一式"+(order[random(13)])+"「目捷连刺」"NOR"，将手$w中抖得笔直，“呲呲”声中向$n疾刺而至，所挟劲风已令$n一阵气窒",
       "dodge": 10,
       "damage": 260,
       "force": 200,
       "lvl" : 30,
       "skill_name" : "目捷连刺",
       "damage_type":  "刺伤"
]),
([     "action": "$N内劲到处，将$w抖动转成两个圆圈，一式"+(order[random(13)])+"「舍利佛刺」"NOR"，跃起从半空中往$n$l缠下",
       "dodge":  20,
       "damage": 250,
       "force":  300,
       "lvl" : 60,
       "skill_name" : "舍利佛刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N劲走螺旋，一式"+(order[random(13)])+"「富楼那刺」"NOR"，$w在$n眼前上圈下钩，左旋右转，连变了数种招式，忽然从$n$l处倒卷上来",
       "dodge": 20,
       "damage": 380,
       "force": 200,
       "lvl" : 90,
       "skill_name" : "富楼那刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N一声高喝，吸气催力，一式"+(order[random(13)])+"「迦旋延刺」"NOR"，$w急速转动，鞭影纵横，直中有圆，圆中有直，似真似幻，绞向$n",
       "dodge": 25,
       "damage": 350,
       "force": 300,
       "lvl" : 120,
       "skill_name" : "迦旋延刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N含胸拔背、沉肩坠肘，一式"+(order[random(13)])+"「弘忍能刺」"NOR"，力道灵动威猛，虚实分明，劲力从四面八方向$n挤压出去",
       "dodge": 25,
       "damage": 320,
       "force": 350,
       "lvl" : 150,
       "skill_name" : "弘忍能刺",
       "damage_type":  "拉伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry");
 }

int valid_learn(object me)
{
    object weapon;

    if( (int)me->query("max_neili") < 500 )
       return notify_fail("你的内力不足，没有办法练日月鞭法, 多练些内力再来吧。\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
       return notify_fail("你的混元一气功火候太浅。\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("你的易筋经内功火候太浅。\n");
       if(!me->query("family") || me->query("family/family_name")!="少林派" )
               return notify_fail("你不是少林弟子，如何能用这日月鞭法？\n");

         if((int)me->query_skill("shaolin-shenfa",1) <=120)
      		return notify_fail("你的少林身法火候不足，难以领悟日月鞭法。\n");

         if((int)me->query_skill("yizhi-chan",1) <=120)
      		return notify_fail("你的一指禅不足，难以领悟日月鞭法。\n");

    if ( !objectp(weapon = me->query_temp("weapon"))
    || ( string)weapon->query("skill_type") != "whip" )
       return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
   if(level >= action[i]["lvl"])
      return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i,j, level;
     
        level   = (int) me->query_skill("riyue-bian",1);
        if (random(level) > 270 && me->query("neili") > 800 ){
        me->add("neili", -50);
        return ([
        "action":HIW"$N心神宁定，$w"NOR+HIW"挥动时无声无息，内力返照空明，功力精纯，不露棱角，$n祗觉身周气流略有异状，这一下袭击事先竟无半点朕兆"NOR,
        "force" : 520+(level/5)+random(level/2),
        "dodge" : 0,
        "parry" : 0,
        "damage" : 550+random(level/3),
        "damage_type":"内伤",
        ]);
}
        if (random(me->query_str()) >= 35 && me->query_skill("riyue-bian",1) > 120 &&
             me->query_skill("parry",1) > 120 &&
             me->query("neili") > 1000 && random(me->query("jiali")) >= 20 &&
             me->query("jing")>300) {
                me->add("jing",-8);           
                me->add("neili", -30);
                return ([
                "action": HIR "$N手腕一抖，但见飞舞的$w从天而下和$n缠在一起，一股排山倒海的内劲无声息的向$n胸口撞去！"NOR,
                "force": 600,
                "dodge": 25,
                "damage" : 600,
                "damage_type": "内伤"]);
        }
           if (random(me->query_str()) >= 39 && me->query_skill("riyue-bian",1)> 150 &&
                me->query_skill("parry",1) > 150 && random(me->query("jiali")) >= 20 &&
                me->query("neili") > 1500 &&
                me->query("jing")>500) {
                me->add("jing",-10);            
                me->add("neili", -50);
                return ([
                "action": HIR "$N把手中$w抖动成圈，绕着$n越转越急，越转越快，$p登时身不由主，被套得连转了几身，眼看就要摔倒！"NOR,
                "force": 520,
                "dodge": 35,
                "damage" : 580,
                "damage_type": "摔伤"]);
        }
      
          if (me->query_temp("riyue"))
                {                
                    return ([  
                    "action" : HIR+action[j]["action"]+NOR,
                    "force" : (me->query("gender")=="男性"?action[j]["force"]:action[j]["force"]/2)+me->query_str()*5,
                    "dodge":(me->query("gender")=="男性"?action[j]["dodge"]:action[j]["force"]+10)+random(15),
                    "lvl" : action[j]["lvl"],
                    "weapon" : action[j]["weapon"],
                    "damage_type" : action[j]["damage_type"],
                    ]);
               }        


       level   = (int) me->query_skill("riyue-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
   return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的体力不够练日月鞭法。\n");
    me->receive_damage("qi", 5);
    me->receive_damage("jing", 10);
    return 1;
}


string perform_action_file(string action)
{
       return __DIR__"riyue-bian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"只见$n$l闷哼一声，吐出一口鲜血，已被易筋经的护体真气给击伤!\n"NOR;
}
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("riyue-bian",1)) > 130 ) 
{
	  victim->receive_wound("qi", (damage_bonus-60)/2);
        return HIY "$n被鞭风扫中，一阵巨痛！\n" NOR;
}
}
