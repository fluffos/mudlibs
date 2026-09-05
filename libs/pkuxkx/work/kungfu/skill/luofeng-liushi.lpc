// 落风六式    luofeng-liushi.c

inherit SKILL;

mapping *action = ({
        ([     
                "action":               
"只见$n身随意转，一招「浮云无定」，倏地往一旁挪开了三尺，避过了$N这一招。\n",

                "dodge"  : 10,
        ]),
        ([      "action":
"$n使出一招「轻舟泛月」，向一旁飘然纵出，轻轻着地。\n",

                "dodge"  :30,
        ]),
        ([      
                "action":               
"$n身形微晃，一招「落日浮云」，有惊无险地避开了$N这一招。\n",

                "dodge"  : 50,
        ]),
        ([    
                "action":               
"$n漫不经心的向左一个「日落沙明」，刚好避过$N的凌厉攻势。\n",

                "dodge"  : 80,
        ]),
        ([      
                "action":               
"$n身形向后一纵，使出一招「落叶秋风」，避过了$N的攻击。\n",

                "dodge"  : 120,
        ]),
        ([      
                "action":               
"可是$n使一招「风飘落日」，身子轻轻飘了开去。\n",

                "dodge"  : 150,
        ]),
});

mapping query_action(object me)
{
        int zhaoshu, level;
        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("luofeng-liushi",1);
        if (level < 150 )
                zhaoshu--;
        if (level < 100 )
                zhaoshu--;
        if (level < 50 )
                zhaoshu--;
        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge";
}
int valid_learn(object me)
{
        return 1;
}
string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练习『落风六式』。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
 {     
 	return __DIR__"luofeng-liushi/" + action;
 }