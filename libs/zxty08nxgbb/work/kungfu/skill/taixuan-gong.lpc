// taixuan-gong.c 侠客岛太玄功
// Jay 4/5/96
// modified by Venus Oct.1997
inherit FORCE;

string *dodge_msg = ({
   HIG "$n左手拍出，劲风到处，把$N震到一边。\n",NOR
   HIG "$n使出一招「佛空」，如轻鸿般飘去，瞬间又闪至$N面前 \n",NOR    
   HIG "$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",NOR
   HIG "$n使出一招「誓言空」，双足一点，跃至数丈之外 \n",NOR
   HIG "$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",NOR
   HIG "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",NOR
   HIG "$n使出一招「心空」，身体向侧后飘去 \n", NOR
});

mapping *action = ({
([  "action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
    "force" : 200,
    "dodge" : 20,
    "damage_type":  "瘀伤"
]),
([  "action":"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去",    
    "force" : 220,
    "dodge" : 20,
    "damage_type":  "瘀伤"
]),
([  "action":"$N大喝一声，张口一股内气向$n脸上喷去",
    "force" : 400,
    "dodge" : 30,
    "damage_type":  "瘀伤"
]),
([  "action":"$N猱身而上，双掌猛地拍向$n",
    "force" : 225,
    "dodge" : 30,
    "damage_type":  "瘀伤"
]),
([  "action":"$N身体微侧，突然飞起一脚，踢向$n下三路。脚到中途，猛地一抬，踢向$n面门",
    "force" : 230,
    "dodge" : 40,
    "damage_type":  "瘀伤"
]),
([  "action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
    "force" : 230,
    "dodge" : 40,
    "damage_type":  "瘀伤"
]),
(["action" : "$N一招"HIW" 大关门式 "NOR"，右手斜斜的劈向$n的$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "大关门式",
        "damage_type" : "瘀伤"
]),
(["action" : "$N双掌轻飘飘地拍向$n，突然反手上勾。一招"HIW" 乳燕抬腮 "NOR"击向$n的$l",
        "force" : 350,
        "dodge" : 10,
         "skill_name" : "乳燕抬腮",
        "damage_type" : "瘀伤"
]),
(["action" : "$N半跪半蹲一招"RED" 白猿献果 "NOR"，双掌幻化一片掌影，将$n笼罩于内。",
        "force" : 400,
        "dodge" : 30,
        "skill_name" : "白猿献果",
        "damage_type" : "瘀伤"
]),

(["action" : "$N一招"RED" 虎门手 "NOR"，双手纷飞，手作虎式，双手反扣$n全身各处大穴",
        "force" : 450,
        "dodge" : 25,
         "skill_name" : "虎门手",
    "damage_type" : "瘀伤"
]),
(["action" : "$N一招"HIY" 揩磨尘垢 "NOR"，中宫直进，只见一片掌影攻向$n",
        "force" : 500,
        "dodge" : 20,
        "skill_name" : "揩磨尘垢",
        "damage_type" : "瘀伤"
]),

(["action" : "$N双掌平挥，一招"HIY" 无欠无馀 "NOR"击向$n,令$n无处可躲.",
        "force" : 550,
        "dodge" : 25,
         "skill_name" : "无欠无馀",
            "damage_type" : "瘀伤"
]),
(["action" : "$N纵起丈余，头下脚上，一招"HIR" 红霞贯日 "NOR"击向$n",
        "force" : 600,
        "dodge" : 30,
         "skill_name" : "红霞贯日",
        "damage_type" : "瘀伤"
]),

(["action" : "$N左掌虚晃，右掌一记"HIM" 紫电穿云 "NOR"击向$n的左颊，招未使老在途中陡变掌缘却劈向$n的右颈。",
        "force" : 650,
        "dodge" : 30,
         "skill_name" : "紫电穿云",
           "damage_type" : "瘀伤"
])

});

int valid_enable(string usage)
{
       return usage == "dodge" || usage == "parry" || usage == "unarmed" || usage == "force";
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
     level   = (int) me->query_skill("taixuan-gong", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                         a_action = action[NewRandom(i, 20, level/2)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level*4;
    a_action["attack"]  = level/3;
    a_action["damage"] = level*4;
    return a_action;

}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 105 ) return 0;
         if (me->query_skill("taixuan-gong",1)>100)
        if( random(me->query("neili")) > random(victim->query("neili"))) {
               victim->receive_wound("qi", (damage_bonus - 100)*2 , me);
                return HIW "太玄功潜藏的威力发挥了出来，$n 感到心头一甜，吐出一口"HIR"鲜血"HIW"！\n" NOR;
        }
}

string query_dodge_msg(string limb)
{ 
      return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
 if (random(this_player()->query("kar")) > 19 && this_player()->query("kar") > 23)
        return 1;
    return notify_fail("你对着石壁冥思苦想了一会，满目的蝌蚪文看得你眼花缭乱。\n");
}
string exert_function_file(string func)
{
    return __DIR__"taixuan-gong/" + func;
}


