
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N双手一晃，手中的$w如一条银蛇般飞向$n的$l",
                "dodge":                20,
                	"lvl" : 1,
                "damage":               330,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N右手一抖，$w发出刺耳的破空声直射$n的$l",
                "dodge":                40,
                "damage":               330,
                	"lvl" : 1,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手指微动，$w斜斜的飞向$n的$l",
                "dodge":                40,
                	"damage":               330,
                		"lvl" : 1,
               "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N力发肩肘，右手一甩，手中的$w化作一道弧光射向$n的$l",
                "dodge":                20,
                	"lvl" : 1,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage":               340,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法练飞刀绝技。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练飞刀。\n");

        return 1;
}

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("feidao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if( (int)me->query("jing") < 30
        ||      (int)me->query("neili") < 500 )
                return 
notify_fail("你的内力或气不够，没有办法练习飞刀绝技。\n");
        me->receive_damage("jing", 30);
        me->add("neili", -30);
        //write("你按著所学练了一遍飞刀绝技。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feidao/" + action;
}


 
int effective_level() { return 15;}

int learn_bonus()
{
	return -2220;
}
int practice_bonus()
{
	return -1110;
}
int black_white_ness()
{
	return 15;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        string name, weapon;
        

	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(4)==0 ) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return "只听一声惨嚎，一股鲜血从$n的伤口喷出！\n" ;	
}
}