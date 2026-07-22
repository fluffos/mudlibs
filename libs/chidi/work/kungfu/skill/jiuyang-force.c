// jiuyang-force.c
inherit FORCE;
#include <ansi.h>    
mapping *action = ({
        ([      "action":
"$N使出一招「三重天地混元」，左手聚出一团混元真气击向$n的$l",
               "force" : 300,
          "dodge" : -5,
           "parry" : 20,
           "skill_name" : "三重天地混元",
          "damage": 30,
           "lvl" : 0,
                 "damage_type" : "瘀伤",
        ]),
        ([      "action":
"$N使出一招「五重天地混元」，右手聚出一团混元真气击向$n的$l",
                "force":                500,
                "dodge" : -10,
                 "skill_name" : "五重天地混元",
                "damage": 50,
                 "lvl" : 50,
                 "parry" : 40,        
                              "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「七重天地混元」，双手由掌变拳，聚出一团混元真气击向$n的$l",
                "force":                700,
                "dodge" : -20,
                  "parry" : 60,
                "skill_name" : "七重天地混元",
                "damage": 80,
                "lvl" : 100,
                "damage_type":  "瘀伤"
        ]),
([      "action":
"$N使出一招「九重天地混元」，双手缓缓向前，涌出全身混元真气汇成一团浓浓的白雾击向
$n的$l",
                "force":    1000,
                "dodge" : -30,
                 "parry" : 100,
                "skill_name" : "九重天地混元",
                "damage": 120,
                "lvl" : 140,
                "damage_type":  "瘀伤"
        ]),      ([      "action":
YEL"$N使出一招「风雷震九州」，全身腾空而起，化作一团混元真气击向$n的$l"NOR,
                "force":                2000,
                "dodge" : -50,
                 "parry" : 160,
                "skill_name" : "风雷震九州",
                "damage": 240,
                "lvl" : 180,
                "damage_type":  "瘀伤"
        ]),
});
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
        level   = (int) me->query_skill("jiuyang-force",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
              if( (random(2*(me->query_skill("jiuyang-force"))) > (damage_bonus + foo))&&(me->query("max_neili")>2000)&&(me->query_skill("jiuyang-force")>120) )
                 {                        
                        force = me->query_skill("force");
                        victim->receive_wound("qi", (damage_bonus + foo));
                        victim->receive_wound("jing", random(force/2));
                        victim->set("neili", 0);
                        return
HIR"$N的九阳真气摧毁了$n的真元！！！！\n"NOR;
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
      return usage=="unarmed" ||
        usage=="parry"||
        usage=="force";
}

int valid_learn(object me,mapping fam)
{
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
                return notify_fail("你不是明教弟子又怎么能学更高深的九阳真气呢?\n");
        if ((int)me->query("max_neili") < 1500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query("combat_exp") < 1000000)
                return notify_fail("你的能力还没达到学更高深的九阳真气的地步。 \n");
        if ( me->query("gender") == "无性" && (int)me->query_skill("jiuyang-force", 1) > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳真气。\n");
//      if ((string)me->query("gender") == "女性" )
//              return notify_fail("你一个女人如何能学习九阳神功？\n" );
        if ( me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("shenyuan-gong",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("zixia-shengong",1) 
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("wuji-shengong",1)
        || me->query_skill("guiyuan-dafa",1)
        || me->query_skill("xiantian-wuji",1)
        || me->query_skill("yunu-xinjing",1)
//      || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("xixing-dafa",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("tiangang-zhengqi",1))
                return notify_fail("你不先散了别派内功，怎能学九阳真气？！\n");
                
        return 1;
}

int practice_skill(object me)
{
   return notify_fail("九阳真气只能用学的，或是从运用(exert)中增加熟练度。\n\n");
}

int effective_level() { return 21; }
string *absorb_msg = ({
       GRN "$n身体虚转，双手微划，无坚不摧的九阳真气澎湃而出。\n",
       GRN"$n施展出九阳真气，浑身肌肤坚如寒铁。\n",
       GRN "$n身型微展，九阳真气充斥了丈许空间。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
string *unarmed_parry_msg = ({
        GRN"$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        GRN"$n长袖一甩，一股大力将$N送出丈外。\n",
        GRN"$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",
});
string *parry_msg = ({
        GRN"$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        GRN"$n长袖一甩，一股大力将$N送出丈外。\n",
        GRN"$n施展出「九阳无我」，轻描淡写的化解了$N的攻势。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string exert_function_file(string func)
{
       return __DIR__"jiuyang-force/" + func;
}
string perform_action_file(string action)
{
    return __DIR__"jiuyang-force/" + action;
}

int bounce_ratio()
{
        return 40;
}

int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -500;
}
int black_white_ness()
{
        return 200;
}

