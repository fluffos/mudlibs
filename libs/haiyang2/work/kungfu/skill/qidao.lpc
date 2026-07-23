#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"劳宫穴", "膻中穴", "曲池穴", "关元穴", "曲骨穴", "中极穴", "承浆穴", "天突穴", "百会穴",
"幽门穴", "章门穴", "大横穴", "紫宫穴", "冷渊穴", "天井穴", "极泉穴", "清灵穴", "至阳穴", }); 


string *parry_msg = ({
 "$n运起真气，挡住了$N的攻势。\n",
         });

        
string *unarmed_parry_msg = ({
"$n运起真气，挡住了$N的攻势。\n",
        });

mapping *action = ({
       ([      "action":
"$N使出一招"+(order[random(13)])+"「镇神头」"NOR"，左手聚出一团真气，从上而下，击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「大斜」"NOR"，右手聚出一团真气，斜斜击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「双飞燕」"NOR"，双手聚出一团真气，左右同时击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「倒垂莲」"NOR"，全身腾空而起，运起全身的真气击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
       ([      "action":
"$N使出一招"+(order[random(13)])+"「莲花角」"NOR"，左手聚出一团真气，从上而下，击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「重屏图」"NOR"，右手聚出一团真气，斜斜击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「金井栏」"NOR"，双手聚出一团真气，左右同时击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「宽带钩」"NOR"，全身腾空而起，运起全身的真气击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「四劫连环」"NOR"，左手聚出一团真气，从上而下，击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「拆二斜飞」"NOR"，右手聚出一团真气，斜斜击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「滚打包收」"NOR"，双手聚出一团真气，左右同时击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招"+(order[random(13)])+"「朝天拆二」"NOR"，全身腾空而起，运起全身的真气击向$n的$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="music"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("你的内功心法火候不够。\n");
    if ((int)me->query("max_neili") < 250)
   return notify_fail("你的内力太弱。\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("你的玄天无极功的修为不够! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("你的迅雷剑法还不到家！\n");

        if( (int)me->query_skill("chuanyun-tui", 1) < 100 )
                return notify_fail("你的穿云腿还不到家！\n");
                
        if( (int)me->query_skill("kunlun-zhang", 1) < 100 )
                return notify_fail("你的昆仑掌还不到家！\n");

        if( (int)me->query_skill("mantian-huayu", 1) < 100 )
                return notify_fail("你的漫天花雨还不到家！\n");

        if( (int)me->query_skill("zhentian-quan", 1) < 100 )
                return notify_fail("你的震天拳还不到家！\n");

        if( (int)me->query_skill("art", 1) < 100 )
                return notify_fail("你的琴棋书画还不到家！\n");

        if( (int)me->query_skill("taxue-wuhen", 1) < 100 )
                return notify_fail("你的踏雪无痕还不到家！\n");

    return 1;
}

int practice_skill(object me)
{
    object weapon;

     if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 70)
    return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("你的内力不够。\n");

       if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("你的玄天无极功的修为不够! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("你的迅雷剑法还不到家！\n");

        if( (int)me->query_skill("chuanyun-tui", 1) < 100 )
                return notify_fail("你的穿云腿还不到家！\n");
                
        if( (int)me->query_skill("kunlun-zhang", 1) < 100 )
                return notify_fail("你的昆仑掌还不到家！\n");

        if( (int)me->query_skill("mantian-huayu", 1) < 100 )
                return notify_fail("你的漫天花雨还不到家！\n");

        if( (int)me->query_skill("zhentian-quan", 1) < 100 )
                return notify_fail("你的震天拳还不到家！\n");

        if( (int)me->query_skill("art", 1) < 100 )
                return notify_fail("你的琴棋书画还不到家！\n");

        if( (int)me->query_skill("taxue-wuhen", 1) < 100 )
                return notify_fail("你的踏雪无痕还不到家！\n");

    me->receive_damage("qi", 55);
return 1;
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
} 
   
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	        string name;
        name = xue_name[random(sizeof(xue_name))];
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);

if (random(5)==0 && level>=200 && me->query_skill_mapped("force") == "xuantian-wuji")
{

        if (!victim->is_busy())
        victim->start_busy(2);
//        me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("qidao", 1)/3  + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("qidao", 1)/3  + damage_bonus / 5);
        if (random(2)==0)
                        return  WHT"\n$N身侧的玉色光芒忽如蝶翼般片片飞向$n，$n只觉" HIY "『" + name + "』" NOR + WHT "中一阵灼痛。\n"NOR;
                else 
                        return  HIC"\n$N将内力凝为一线，攻入$n"+HIC"的体内。\n"NOR;

}

}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
     int busy_time;
        int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=ob->query("combat_exp");
        
        skill=me->query_skill("music",1);
        

        if (random(6)==0 && me->is_busy()) {
                message_vision(HIG"$N心神合一，琴弈相通，弈道的"+(order[random(13)])+""+(order[random(13)])+"「得算篇」"NOR""NOR"历历在目，身形骤然轻巧起来。\n"NOR, me);       
if (me->query("eff_qi")<= me->query("max_qi") )
{
                me->add("qi",me->query_skill("art",1)+200);
                me->add("eff_qi",me->query_skill("art",1)+200);
}
                me->start_busy(1);
        }
        

}

string perform_action_file(string action)
{
    return __DIR__"qidao/" + action;
}