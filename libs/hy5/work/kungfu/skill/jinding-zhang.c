// jinding-zhang.c 金顶绵掌
// Oct. 9 1997 by That
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "skill_name" : "三阳开泰" ,
        "action" : "$N身形微晃，一招"+(order[random(13)])+"「三阳开泰」"NOR"，掌起风生，$n只觉得一股暖气袭向$l",
        "force" : 100,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "内伤",
        "lvl"   : 0,
]),
([      "skill_name" : "五气呈祥" ,
        "action" : "$N双手变幻，五指轻弹，一招"+(order[random(13)])+"「五气呈祥」"NOR"，力分五路，招罩十方，抓向$n的$l",
        "force" : 120,
        "dodge" : 10,
        "damage" : 200,
        "damage_type" : "内伤",
        "lvl"   : 11,
]),
([      "skill_name" : "罡风推云" ,
        "action" : "$N左手前引，右手倏出，抢在头里，一招"+(order[random(13)])+"「罡风推云」"NOR"，疾抓向$n的$l",
        "force" : 150,
        "dodge" : 15,
        "damage" : 250,
        "damage_type" : "内伤",
        "lvl"   : 22,
]),
([      "skill_name" : "逆流捧沙" ,
        "action" : "$N左手圈转，轻拂$n的左手，反向推出，右手连续磕击，一招"+(order[random(13)])+"「逆流捧沙」"NOR"，猛地击向$n的下巴",
        "force" : 200,
        "dodge" : 25,
        "damage" : 300,
        "damage_type" : "内伤",
        "lvl"   : 33,
]),
([      "skill_name" : "雷洞霹雳" ,
        "action" : "$N舌绽春雷，一声娇喝，在$n一愣间，右手一招"+(order[random(13)])+"「雷洞霹雳」"NOR"，直捣$n的$l",
        "force" : 200,
        "dodge" : 10,
        "damage" : 220,
        "damage_type" : "内伤",
        "lvl"   : 44,
]),
([      "skill_name" : "金顶佛光" ,
        "action" : "$N双手平举握拳，脸露微笑，$n恍惚间看到$N分身为二，便见$N四掌齐出，一招"+(order[random(13)])+"「金顶佛光」"NOR"不知哪两掌是实？掌风已经袭面",
        "force" : 300,
        "dodge" : 15,
        "damage" : 250,
        "damage_type" : "内伤",
        "lvl"   : 55,
]),
([      "skill_name" : "梵心降魔" ,
        "action" : "$N一幅宝像庄严，使出"+(order[random(13)])+"「梵心降魔」"NOR"，掌势如虹，绕着$n漂移不定",
        "force" : 230,
        "parry" : 20,
        "dodge" : 20,
        "damage" : 360,
        "damage_type" : "内伤",
        "lvl"   : 66,
]),
([      "skill_name" : "法尊八荒" ,
        "action" : "$N全场游走，双臂疾舞，化为点点掌影，一招"+(order[random(13)])+"「法尊八荒」"NOR"铺天盖地袭向$n全身各处大穴",
        "force" : 300,
        "parry" : 5,
        "dodge" : 300,
        "damage" : 300,
        "damage_type" : "内伤",
        "lvl"   : 77,
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练金顶绵掌必须空手。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
                return notify_fail("你的临济庄心法火候不够，不能练金顶绵掌。\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("你的内力太弱，无法练金顶绵掌。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i-1]["lvl"])
                return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, jiali,p;
        int level   = (int) me->query_skill("jinding-zhang",1);
  string msg; 
        mapping px_info;
	object victim, ob;

	// lasting effects of piaoxue
        ob = me->select_opponent();
p=level+100;
        if (random(me->query_skill("jinding-zhang",1)) > 200
        && me->query_skill("linji-zhuang",1) > 200 &&
        me->query("neili") > 200 && ob)
{
	me->add("neili", -30);
  msg = HIY "\n$P手掌忽低，便像一尾滑溜无比，迅捷无伦的小鱼一般，拍向$n的胸前。\n";
  msg += "$n自然而然的发出内力和对方拍来的掌力一挡，就在这两股巨大的内劲将触未撞、\n";
  msg += "方遇未接之际，$P的掌力却忽然无影无踪的消失了。\n\n"NOR;
if (random(me->query_skill("jinding-zhang",1)) > ob->query_skill("parry",1)/2)
	    if (ob->query("neili") > p) {
		msg += HIR "\n$n摸不透$P的内力虚实，只好大耗真力，把全身都布满真气。\n"NOR;
		ob->receive_damage("qi", p);
		ob->add("neili", -p);
	    } else {
		msg +=HIR "\n$n一口真气提不上来，被$P掌风扫中，脚下踉跄，差点儿倒下。\n"NOR;
		ob->receive_damage("qi", p);
	    }
else
{
if (random(me->query_skill("jinding-zhang",1)) < ob->query_skill("parry",1)/6)
{
    msg += HIB"$n冷笑道：如今武林之中谁人不知这飘雪穿云掌，也好意思出来现丑？\n";
    msg += HIB"$n脚下不丁不八的站了一个桩，左掌连挥，把$P的劲力尽数卸去．\n";
    msg += HIR"$N大吃一惊，身侧，背心的空门大开，狼狈地招架着．\n" NOR;
    me->start_busy(2);
}
else       msg += HIG"$n将真气聚于胸口，凝神接了$P这一掌，笑道：飘雪穿云掌好大的名头，你使来也不过如此。\n" NOR;
}
  message_vision(msg+"\n", me, ob);

}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if (me->query_skill("jinding-zhang", 1) < 100)
                me->receive_damage("qi", 10);
        else
        me->receive_damage("qi", 20);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/"+ action;
}
int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N 五心向天，运行日月二庄，益气升阳，益阴潜阳，
升降反正，天地二气交泰于身，并配合峨嵋九阳功。灭绝之间顿时大起!！\n"NOR;
msg += "$N神色一变,恢复了些活力！\n",  
           message_vision(msg, me, ob);
           return j;
} 
}