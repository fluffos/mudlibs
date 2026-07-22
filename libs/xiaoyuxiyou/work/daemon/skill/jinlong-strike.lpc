// Jinlong-strike.c 金龙血影击
// Cracked by 凌惊雪 4-17-2003

#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":               
HIY"$N 使出金龙血影击的［"BLU"金龙魅影"HIY"］，骤然间，一片金光，一道血影，左右直扑$n！"NOR,
                "dodge":                -30,
                "parry":                -30,
                "force":                200,
                "damage_type":  "瘀伤",
                "weapon":               "双爪",
        ]),
        ([      "action":               
HIY"$N 使出金龙血影击的［"BLU"金龙漩尘"HIY"］，身上的劲气激扬，覆盖了$n的视线，$N的一双“血影爪”，
已戳向$n。"NOR,
                "dodge":                -30,
                "parry":                -20,
                "force":                190,
                "damage_type":  "瘀伤",
                "weapon":               "双爪",
        ]),
        ([      "action":               
HIY"$N 马上知道$n变招，立时移开双手，却见［"BLU"龙影漫天"HIY"］，向$n扑去！"NOR,
                "dodge":                -30,
                "parry":                -30,
                "force":                180,
                "damage_type":  "瘀伤",
                "weapon":               "左爪",
        ]),
        ([      "action":               
HIY"$N 左右开弓，使出金龙血影击的［"BLU"金龙影随"HIY"］，迅如鬼魅，十指如戟，左右疾刺$n！"NOR,
                "dodge":                -30,
                "parry":                -20,
                "force":                220,
                "damage_type":  "瘀伤",
                "weapon":               "双掌",
        ]),
        ([      "action":               
HIY"$N左手挥起，掌心朝天，掌中带红，直奔$n"HIY",一招［"HIR"金龙血影击"HIY"］使了出来! "NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                250,
                "damage_type":  "瘀伤",
                "weapon":               "双掌",
        ]),
});
int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("jinlong_per");
        if( !me->query_temp("jinlong_per") ) {
        return action[random(4)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 100 
        ||    (int)me->query("force") < 100  )
                return
        notify_fail("你的体力不够练这门功夫，还是先休息休息吧。\n");
//        if (me->query("mark/jinlong")!="jinlongji")
//                return notify_fail("你怎么练好象都没有任何长进？\n"); 
        if( (int)me->query_skill("jinlong-strike",1) < 20 )
                return notify_fail("你对金龙血影击的领悟还不够，没有办法自行练习。\n");
        me->receive_damage("kee", 30);
        me->add("force", -30);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("suburb") + "/jinlong-strike/" + func;
}


