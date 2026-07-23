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
                "damage":               210,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「清角」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                200,
                "damage":               210,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「正宫」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                200,
                "damage":               210,
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
                "damage":               210,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发"+(order[random(13)])+"「变徵」"NOR"之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               210,
                "damage_type":  "瘀伤"
        ]),
});        


int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }



int valid_learn(object me)
{
        if (me->query_skill("hand", 1) < 100)
                return notify_fail("你的基本手法水平不够，还是先练好再说吧！\n");

        if (me->query_skill("hamagong", 1) < me->query_skill("xiyu-tiezheng", 1))
                return notify_fail("你的蛤蟆功水平有限，无法领会更精妙的西域铁筝音。\n");

        return 1;
}

int practice_skill(object me)
{
        object ob;



        if ((int)me->query("jing") < 80)
                return notify_fail("你的精神不够好，没法练习了。\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("你现在实在是太疲惫了。\n");

        me->receive_damage("jing", 55);
        me->receive_damage("qi", 50);

        return 1;
}

void do_effect(object me)
{
        object *obs;
        int lvl;
        int i;
        int damage;

        lvl = me->query_skill("xiyu-tiezheng", 1) / 2 +
              me->query_skill("xiyu-tiezheng", 1);

        if (environment(me)->query("no_fight")
           || lvl < 150)
                return;

        lvl = lvl / 5 + me->query_skill("force");
        lvl /= 2;

        // special effort
        obs = all_inventory(environment(me));
        for (i = 0; i < sizeof(obs); i++)
        {
                if (! obs[i]->is_character() || obs[i] == me || ! living(obs[i]))
                        continue;

                if (me->query_skill("xiyu-tiezheng") * 2 / 3 <
                    obs[i]->query_skill("xiyu-tiezheng"))
                        continue;

                if (lvl + random(lvl) < obs[i]->query_skill("force"))
                {
                        tell_object(obs[i], HIM "你听了心中不禁微微一动，发现这曲子颇有奥妙之处。\n" NOR);
                        continue;
                }

                damage = me->query("max_neili") - obs[i]->query("max_neili");
                if (damage < 500)
                {
                        tell_object(obs[i], HIB "你忽然觉得一阵难受，连忙运了一口气，才清醒过来。\n" NOR);
                        continue;
                }

                damage /= 10;
                //me->want_kill(obs[i]);
                //me->fight_ob(obs[i]);
                //obs[i]->kill_ob(me);
                //obs[i]->receive_damage("jing", damage, me);
                //obs[i]->receive_wound("jing", damage / 3, me);
                tell_object(obs[i], HIB "你听了这阵鬼哭狼嚎的声音，不由得心浮气躁……\n" NOR);
        }
}

string perform_action_file(string action)
{
        return __DIR__"xiyu-tiezheng/" + action; 
}


mapping query_action(object me, object weapon)
{
	int i, level;
if (( (int)me->query_skill("hand", 1) >= 120 ) 
        &&	( (int)me->query_skill("xiyu-tiezheng", 1) >= 120 )
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
        level = (int) me->query_skill("xiyu-tiezhang",1);
        level2= (int) me->query_skill("xiyu-tiezhang",1);

if (random(7)==0 && level>=200 && me->query_skill_mapped("force") == "hamagong")
{

        if (!victim->is_busy())
        victim->start_busy(2);
        //me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("xiyu-tiezhang", 1) / 3 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("xiyu-tiezhang", 1) / 5 + damage_bonus / 5);
                return HIY "只听一阵鬼哭狼嚎的弦音从$N" BLU "处传来，$n" HIY "『" + name + "』"
                       NOR + BLU "顿时受震，两耳轰鸣，全身真气乱窜不止！\n" NOR;
}

}