// duanyun-fu.c 断云斧
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N蓦地腾空跃起，双手紧握$w，对准$n的头顶，自上而下地砍了下去，
只在半空中留下一团巨大的黑影",
    "damage": 500,
    "force": 300,
    "dodge" : 50,
    "damage_type" : "砍伤",
    "lvl" : 0,
    "skill_name" : "开天辟地"
]),
([  "action" : "$N突然发一声喊，冲前两步，手中$w由下而上反撩$n下三路，$n见到
一道淡黄色的气影逼向自己，情知不妙，急忙招架",
    "damage": 525,
    "force": 300,
    "dodge" : 45,
    "damage_type" : "割伤",
    "lvl" : 10,
    "skill_name" : "气冲霄汉"
]),
([  "action" : "$N忽然虎吼一声，闪身斜向左前方冲出一步，身体微晃，手中$w在空
中划出一道淡影，急速横扫$n的右肩，气势迫人",
    "damage": 550,
    "force": 300,
    "dodge" : 40,
    "damage_type" : "砍伤",
    "lvl" : 20,
    "skill_name" : "横扫千军"
]),
([  "action" : "$N突然抽身向右滚倒，随即跳起，就在跳起的一瞬间，已单臂握着$w
砸向$n的左肋，出手既快且狠",
    "damage": 590,
    "force": 300,
    "dodge" : 35,
    "damage_type" : "砸伤",
    "lvl" : 30,
    "skill_name" : "以退为进"
]),
([  "action" : "$N双手横举$w，平扫$n前胸，招式未使老就已打住猝然变招，斧尖直
撞$n的小腹，",
    "damage": 530,
    "force": 300,    
    "dodge" : 40,
    "damage_type" : "内伤",
    "lvl" : 42,
    "skill_name" : "金斧撞钟"
]),
([  "action" : "$N不急不缓地转身微蹲，$n见$N露出破绽，急忙抢攻，却突然发现$N
的身体已转过来，手中$w正迅猛地扫向自己的下盘",
    "damage": 680,
    "force": 500,
    "dodge" : 130,
    "parry" : 54,
    "damage_type" : "割伤",
    "lvl" : 55,
    "skill_name" : "回风转云"
]),
([  "action" : "$N身形微动，就在同一时间自上中下左右砍出五斧，$n见五把$w从不
同的方位砍向自己，一时间竟不知该如何招架",
    "damage": 580,
    "dodge" : 125,
    "force": 500,
    "parry" : 66,
    "damage_type" : "砍伤",
    "lvl" : 68,
    "skill_name" : "五斧夺命"
]),
([  "action" : "$N前脚猛地往地上一顿，大地也微微一震，接着举起斧头在头顶急转
数圈，$w就隐含风云之声平直而沉稳地袭向$n，$n无论向何处闪躲，
总看见斧尖离自己不到一尺，不由大惊失色",
    "damage": 680,
    "force": 500,
    "parry" : 155,
    "dodge" : 65,
    "damage_type" : "砍伤",
    "lvl" : 80,
    "skill_name" : "一斧断云"
])
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("你的内功心法火候不够，无法学断云斧。\n");
    if ((int)me->query("max_neili") < 150)
   return notify_fail("你的内力太弱，无法练断云斧。\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("你的铁雪锤法太低了。\n");
    return 1;
}

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
    level = (int)me->query_skill("duanyun-fu", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
   return notify_fail("你使用的武器不对。\n");    if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 50)
    return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练断云斧。\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("你的铁雪锤法太低了。\n");


    me->receive_damage("qi", 25);
return 1;
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N深吸一口气，身体如一片落叶随风飘舞,$n头一昏，不知所措!\n"NOR;

victim->start_busy(3);

                return msg;
}
        weapon = me->query_temp("weapon");

level2= (int) me->query_skill("duanyun-fu",1);             
if (weapon)
{

        if (random(5)==1 && me->query_skill("duanyun-fu",1)>100
        && (string)weapon->query("skill_type") == "axe"
        && me->query_skill_mapped("force") == "guiyuan-tunafa")
        {
        if (!victim->is_busy())
        victim->start_busy(3);
        return HIR"$N狂舞大斧,$n无法近身，也无法进攻!!\n"NOR;
        }
        if( damage_bonus > 30 && random(level2)>60
        && (string)weapon->query("skill_type") == "axe"
        && random(2)==0
        && me->query_skill_mapped("force") == "guiyuan-tunafa") {
        victim->receive_wound("qi", (random(damage_bonus)+150));
        return HIB"$n被斧砍中$l要害，血贱了一地!!\n"NOR;
        }
}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("duanyun-fu", 1);
level2 = me->query_skill("duanyun-fu", 1);
if (weapon)
{
        if (  level2 > 100
        && random(5)==1
        && (string)weapon->query("skill_type") == "axe"){
 
            msg = HIC"$n出招时，$N狂舞大斧，$n无法近身，也无法进攻!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }

}
}








string perform_action_file(string action)
{
    return __DIR__"duanyun-fu/" + action;
}

