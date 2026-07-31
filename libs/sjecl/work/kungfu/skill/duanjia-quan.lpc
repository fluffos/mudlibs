// duanjia-quan.c 段家拳法
// update by cool@SJ,990605

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「釜底抽薪」，左手一探，右手从左手拳底穿出，便向$n击去",
          "skill_name" : "釜底抽薪",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N长笑声中一式「大鹏展翅」，右手硬生生的缩回，左手对着$n$l横击而至",
          "skill_name" : "大鹏展翅",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「连绵不绝」左拳推出，右拳疾跟而至，左拳一缩回，又加在右拳的推力之上",
         "skill_name" : "连绵不绝",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N侧身让开，一式「左右逢源」，右手自上而下斜掠，擦的一声，击向$n腰间",
          "skill_name" : "左右逢源",
        "damage_type" : "瘀伤"
]), 
([      "action" : "$N一个箭步，一式「逆水行舟」，便向$n扑了过来，右手重重一拳，打向$n的$l",
          "skill_name" : "逆水行舟",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练段家拳法必须空手。\n");
          if ((int)me->query_skill("qiantian-yiyang", 1) < 20)
                return notify_fail("你的乾天一阳功火候不够，无法学练段家拳法。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练段家拳法。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                   return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level,a;
        level   = (int) me->query_skill("duanjia-quan",1);
        if (level>100) a=100;
		      else a=level;
     if (( (int)me->query_skill("cuff") >= 120 ) 
      && ( (int)me->query("neili") >= 500 )
      && (me->query_skill_prepared("cuff") == "duanjia-quan")
      && random(10)>7 ) {
                return ([
                "action": "$N左拳一晃，随即右拳击出，紧跟着双拳交错，上下前后连续击出三十六道劲风，眼花缭乱之极．",
                "parry":(int)me->query_skill("parry")/8,
                "dodge":(int)me->query_skill("dodge")/6,
                "force":level*2,
                "damage_type": "内伤"
  ]);
        }
        for(i = sizeof(action); i > 0; i--) {
        return ([
                "action":action[NewRandom(i, 20, level/5)]["action"],
                "damage_type": action[NewRandom(i, 20, level/5)]["damage_type"],
                "dodge": random(20)-random(20),
                "force": 100+a+random(170),
                "parry": 10+random(20),
                "skill_name" : action[NewRandom(i, 20, level/5)]["skill_name"],
                ]);
       }
}
int practice_skill(object me)
{
        int lvl = me->query_skill("duanjia-quan", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练段家拳法。\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

