// zidian-jianfa.c 紫电穿云剑法  by: pipip

inherit SKILL;

mapping *action = ({
([      "action":YEL"$N连续向"WHT"$n"YEL"刺出了几剑，剑剑杂乱，剑剑无章！",
        "force" : 380,
        "damage": 150,
        "lvl" : 60,
        "skill_name" : "起手试招",
        "damage_type":  "刺伤"
]),
([      "action":MAG"$N错步上前，人未到，剑已发，一道剑光混合着紫色电光射向"WHT"$n"MAG"的咽喉！"NOR,
        "force" : 380,
        "damage": 150,
        "lvl" : 60,
        "skill_name" : "快如闪电",
        "damage_type":  "刺伤"
]),
([      "action":RED"$N手中$w一抖，幻出千把，万把$w"RED"，虚虚实实攻向"WHT"$n"RED"全身要害"NOR,
        "force" : 380,
        "damage": 150,
        "lvl" : 60,
        "skill_name" : "千变万化",
        "damage_type":  "瘀伤"
]),
([      "action":HIB"$N平平一剑刺出，不带一丝花巧，可是"WHT"$n"HIB"连变数种身法也没能碰开这一剑。"NOR,
        "force" : 380,
        "damage": 150,
        "lvl" : 60,
        "skill_name" : "一剑西来",
        "damage_type":  "内伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me) { return 1; }
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {                                                victim->receive_wound("qi", (damage_bonus ));
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
                return HIB "只见剑光一闪，一道"BLINK MAG" 紫色剑气 "NOR HIB"已经从$N手中剑器传入了$n的体内！\n" NOR;
        }
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
        level   = (int) me->query_skill("zidian-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("yijing-force", 1) < 60)
                return notify_fail("你的太极神功火候太浅。\n");
        if ((int)me->query("qi") < 500)
                return notify_fail("你的体力不够练紫电穿云剑法。\n");
        me->receive_damage("qi", 150);
        return 1;
}
void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;string skillname;int skill_basic;skillname = me->query_skill_mapped("sword");skill_basic = me->query_skill("sword", 1);skill = me->query_skill(skillname, 1);if( (me->query_("shen")) < -5000000 &&
        me->query_skill("zidian-jianfa") > 500)  {
                me->improve_skill(skillname, skill_basic/5 +1,  1);}
    
    if (!weapon) return;
    skill=me->query_skill("zidian-jianfa", 1);
    if (skill>999){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("、"+enemy[i]->name());
        message_vision(HIG+"$N手中剑器突然射出数道剑芒，形成一片剑幕将"HIR+all_enemy+""HIG"逼进死角！\n\n" NOR,me);
        me->set_temp("zidian-jianfa",1);
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(50*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    me->set_temp("action_msg",""WHT"剑尖回转"NOR"\n");
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"));
                     }
                }else break;
        }
    me->delete_temp("zidian-jianfa");
    }
}
string perform_action_file(string action)
{
        return __DIR__"zidian-jianfa/" + action;
}

