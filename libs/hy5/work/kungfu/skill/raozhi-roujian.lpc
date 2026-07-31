// raozhi-roujian.c 武当绕指柔剑
#include <ansi.h>
inherit SKILL;
string *taijin = ({"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N使出一招「天外流星」，手中$w如一条银蛇般刺向$n的$l",
        "force"  : 120,
        "dodge"  : 20,
        "parry"  : 114,
        "damage" : 25,
        "lvl"    : 0,
        "damage_type": "刺伤"
]),
([      "action" : "$N一式「落花满天」，手中$w化做满天剑影直刺向$n的$l",
        "force"  : 120,
        "dodge"  : 20,
        "parry"  : 115,
        "damage" : 20,
        "lvl"    : 10,
        "damage_type": "刺伤"
]),
([      "action" : "$N使出一招「窗含柔月」，手中$w挥舞，舞出数个剑花圈向$n的$l",
        "force"  : 140,
        "dodge"  : 15,
        "parry"  : 116,
        "damage" : 25,
        "lvl"    : 20,
        "damage_type": "刺伤"
]),
([      "action" : "$N轻轻一跃，一招「乘风归去」，却在转身之际对准$n$l斜斜挥出一剑",
        "force"  : 150,
        "dodge"  : 15,
        "parry"  : 118,
        "damage" : 35,
        "lvl"    : 30,
        "damage_type": "刺伤"
]),
([      "action" : "$N神态悠闲，手中$w凭空一指，一招「白云千载」轻妙地划向$n的$l",
        "force"  : 130,
        "dodge"  : 25,
        "parry"  : 121,
        "damage" : 25,
        "lvl"    : 40,
        "damage_type": "刺伤"
]),
([      "action" : "$N使出一招「星河影动」，剑光闪烁不定，若有若无地刺向$n$l",
        "force"  : 120,
        "dodge"  : 25,
        "parry"  : 212,
        "damage" : 25,
        "lvl"    : 50,
        "damage_type": "刺伤"
]),
([      "action" : "$N手中$w向外一分，一招「柳暗花明」反手对准$n$l一剑刺去",
        "force"  : 110,
        "dodge"  : 15,
        "parry"  : 135,
        "damage" : 38,
        "lvl"    : 60,
        "damage_type": "刺伤"
]),
([      "action" : "$N身形转个不停，突然一招「一点灵犀」使出，手中$w划出一道银弧，径刺$n$l",
        "force"  : 150,
        "dodge"  : 35,
        "parry" :  145,
        "damage" : 43,
        "lvl"    : 70,
        "damage_type": "刺伤"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("你的内功火候太浅。\n");
         if ((int)me->query_skill("taiji-shengong", 1) < 100)
                return notify_fail("你的本门内功火候太浅。\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("你的武当绵掌火候太浅。\n");


        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("raozhi-roujian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的绕指柔剑。\n");

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 90 ) return 0;

        if( random(4)==0 ) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus ) / 2 );
                return HIR "$n突然觉的伤口一凉，鲜血喷出！\n";
        }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
msg = HIG"$N 如抱太极，一股雄浑无比的力道组成了一个旋涡来！\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"的内力 被太极神功借力打力 反击在自己身上 ！\n"NOR;
//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}       
}
string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("raozhi-roujian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
         if ((int)me->query_skill("taiji-shengong", 1) < 100)
                return notify_fail("你的本门内功火候太浅。\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("你的武当绵掌火候太浅。\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够练绕指柔剑。\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够练绕指柔剑。\n");

        me->receive_damage("qi", 35);
        me->add("neili", -30);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"raozhi-roujian/" + action;
}
