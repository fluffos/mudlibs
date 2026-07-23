#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"劳宫穴", "膻中穴", "曲池穴", "关元穴", "曲骨穴", "中极穴", "承浆穴", "天突穴", "百会穴",
"幽门穴", "章门穴", "大横穴", "紫宫穴", "冷渊穴", "天井穴", "极泉穴", "清灵穴", "至阳穴", }); 


string *parry_msg = ({
        "$n左手拇指食指虚捻，右手轻挥，空气中骤生"+(order[random(13)])+"「变商」"NOR"之音，一轮音波将$N迫开。\n",
        "$n两手凌空虚划，冷冽的气劲吹过，忽传"+(order[random(13)])+"「清徵」"NOR"之音，$N不觉有点心神撼动。\n",
        "$n凝神专著，伸手轻抚，如拨琴弦，耳侧传来"+(order[random(13)])+"「正宫」"NOR"之调，$N一时茫然不知所以。\n", 
        });

        
string *unarmed_parry_msg = ({
        "$n左手拇指食指虚捻，右手轻挥，空气中骤生"+(order[random(13)])+"「变商」"NOR"之音，一轮音波将$N迫开。\n",
        "$n两手凌空虚划，冷冽的气劲吹过，忽传"+(order[random(13)])+"「清角」"NOR"之音，$N不觉有点心神撼动。\n",
        "$n凝神专著，伸手轻抚，如拨琴弦，耳侧传来"+(order[random(13)])+"「正宫」"NOR"之调，$N一时茫然不知所以。\n", 
        });

mapping *action = ({
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「变商」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「清角」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「正宫」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),        
        
        ([      "action":               "$N轮指急抚，阵阵疾风如珠玉落盘，激起"+(order[random(13)])+"「变羽」"NOR"之音，袭向$n的$l",
                "dodge":                180,
                "parry":                20,
                "damage":               270,
                "damage_type":          "刺伤",
                "weapon":               "指风",
        ]),
        ([      "action":               "$N信手轻敲，"+(order[random(13)])+"「变角」"NOR"声沉，周围忽起鼓点隆隆，如十面埋伏围向$n",
                "dodge":                140,
                "parry":                90,
                "damage":               220,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左手凝气，右手横拉而过，"+(order[random(13)])+"「清商」"NOR"之调如无边丝雨，漫漫飘向$n的$l",
                "dodge":                120,
                "parry":                120,
                "damage":               290,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N伸掌直拍，疾风忽起，流云四散，在气流波动的"+(order[random(13)])+"「正商」"NOR"之音中，击向$n的$l",
                "dodge":                160,
                "parry":                20,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「变徵」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "瘀伤"
        ]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qidao"; }

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
	int i, level;
if (( (int)me->query_skill("cuff", 1) >= 120 ) 
        &&	( (int)me->query_skill("music", 1) >= 120 )
	&&      ( (int)me->query("neili") >= 500 )
      && random(8)==0 ) {
		return ([
		"action": HIG"$N左手拇指食指虚捻，右手轻挥，空气中骤生"+(order[random(13)])+"「变商」"HIG"之音，一轮音波击向$n。"NOR,
	                "parry":(int)me->query_skill("parry",1)/3,
	       	       "damage":(int)me->query_skill("music",1)*2,
                 "dodge":(int)me->query_skill("dodge")/10+(int)me->query_skill("leg")/15,
		             "force": (int)me->query_skill("music")+(int)me->query_skill("leg"),
		"damage_type": "内伤"
  ]);
	}
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
        //me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("music", 1) / 3 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("music", 1) / 5 + damage_bonus / 5);
                return BLU "只听一阵淳厚的弦音从$N" BLU "处传来，$n" HIY "『" + name + "』"
                       NOR + BLU "顿时受震，两耳轰鸣，全身真气乱窜不止！\n" NOR;
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
                message_vision(HIG"$N心神合一，琴弈相通，弈道的"+(order[random(13)])+"「得算篇」"NOR"历历在目，身形骤然轻巧起来。\n"NOR, me);       
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
    return __DIR__"music/" + action;
}