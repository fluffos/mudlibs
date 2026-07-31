// six-fingers.c 六脉神剑
// by Lonely

#include <ansi.h>
inherit SKILL;

string main_skill() { return "yinyang-shiertian"; }

string *action_msg = ({
        "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”有如石破天惊、风雨大至之势，分指$n膻中和$l",
        "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
        "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，无形剑气直指$n的$l",
        "$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内力鼓荡而出，如排山倒海般向$n涌去",
        "$N左手小指一伸，一条气流从少泽穴中激射而出，“少泽剑”出手入风，指向$n的$l",
        "$N右手反指，小指伸出，真气自少冲穴激荡而出，“少冲剑”横生奇变，从$n意想不到的方向刺向$n的$l",
});

mapping sub_skills = ([ 
        "shaoshang-sword"  : 120,
        "shangyang-sword"  : 120,
        "zhongchong-sword" : 120,
        "guanchong-sword"  : 120,
        "shaoze-sword"     : 120,
        "shaochong-sword"  : 120,
]); 

int get_ready(object me) 
{ 
        return 1; 
} 

int get_finish(object me) 
{ 
        if (me->query("int") < 32 || me->query_int() < 44) 
        { 
                tell_object(me, "你演练完毕，只感六种剑法毫无牵连，看来依你的悟性，无"
                                "法将其合一。\n");
                return 0; 
        } 

        if (me->query("con") < 26 || me->query_con() < 39) 
        { 
                tell_object(me, "你演练完毕，只觉全身真气乱窜，眼冒金星，两耳轰鸣，好"
                                "不容易才控制下来。\n");
                return 0; 
        } 

        if (me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳不调，难以演练六脉神剑。\n");

        if (me->query_skill("literate", 1) < 200)
        {
                tell_object(me, "你觉得六脉神剑极其深奥，看来多研究一下学问可能更有帮"
                                "助。\n");
                return 0;
        }

        if (me->query_skill("lamaism", 1) < 200)
        {
                tell_object(me, "你演练完毕，发现如果通晓密宗心法应该更有帮助。\n");
                return 0;
        }

        if (me->query_skill("buddhism", 1) < 200)
        {
                tell_object(me, "你演练完毕，发现如果通晓禅宗心法应该更有帮助。\n");
                return 0;
        }
        
        if ((int)me->query_skill("force") < 300) 
        { 
                tell_object(me, "你演练完毕，几乎虚脱，自己的内功水平看来还有待提高。\n"); 
                return 0; 
        } 

        if ((int)me->query("max_neili") < 5000) 
        { 
                tell_object(me, "你演练完毕，丹田提不起半点力来，看来应该继续锻炼内力。\n"); 
                return 0; 
        } 

        if ((int)me->query_skill("martial-cognize", 1) < 100)
        {
                tell_object(me, "你演练完毕，发现如果武学修养更上一层因该更有所帮助。\n");
                return 0;           
        }
        
        if (random(10) < 5) 
        { 
                tell_object(me, "你对六脉神剑的奥妙颇有领悟，或许再演练一次就能够融会贯通。\n"); 
                return 0; 
        } 

        tell_object(me, HIY "一阵凡尘往事涌上心头，你几欲放声长叹。眼前不断闪现出六脉"
                            "剑法，\n霎那间，你终于通晓六脉神剑。\n" NOR);
                            
        return 1; 
} 

mapping query_sub_skills() 
{ 
        return sub_skills; 
} 

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练六脉神剑必须空手。\n");

        if (me->query("int") < 32)
                return notify_fail("你研究了半天，只感六种剑法毫无牵连，无法再作研究。\n");

        if (me->query("con") < 26)
                return notify_fail("你研究了一会儿，只觉得眼前金星乱冒，太阳穴突突的跳。\n");
                
        if (me->query_skill("literate", 1) < 200)
                return notify_fail("你觉得六脉神剑极其深奥，不是你这种学问水平所能研究的。\n");

        if (me->query_skill("lamaism", 1) < 200)
                return notify_fail("你发现这里面有很多奥妙都和密宗心法有关，难以理解。\n");

        if (me->query_skill("buddhism", 1) < 200)
                return notify_fail("你发现这里面有很多奥妙都和禅宗心法有关，难以理解。\n");
                            
        if ((int)me->query("max_neili") < 5000)
                return notify_fail("你的内力太弱，无法学六脉神剑。\n");

        if ((int)me->query_skill("finger", 1) < 200)
                return notify_fail("你的基本指法火候不够。\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("liumai-shenjian", 1) + 10)
                return notify_fail("你的现在必须先提高你基本内功的水平。\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("liumai-shenjian", 1) + 10)
                return notify_fail("你的现在必须先提高你基本指法的水平。\n");
                
        return 1;
}

int practice_skill(object me)
{
        object* ob, obj;
        int i,skill,damage;

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
                
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练六脉神剑。\n");
                
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("这种武功当得行侠义事。\n");
                
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        
        if (damage_bonus < 50) return 0;

        if (random(damage_bonus/2) > victim->query_str())
        {
                result =  ([ "damage" : damage_bonus ]);
                result += ([ "msg" : HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR]);
                return result;
        }
}

string perform_action_file(string action) 
{ 
        return __DIR__"six-finger/" + action; 
} 

void skill_improved(object me) 
{ 
        int i; 
        string *sub_skillnames; 

        sub_skillnames = keys(sub_skills); 
        for (i = 0; i < sizeof(sub_skillnames); i++) 
                me->delete_skill(sub_skillnames); 
} 

int double_attack()
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        int level;
        level   = (int) me->query_skill("six-finger", 1);
        
        if (random(me->query_skill("six-finger",1)) > 120 &&
                me->query("neili") > 100)
        {
                me->add("neili", -100);
                return ([
                        "action": HIC "$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，连绵"
                                      "无尽。\n剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但觉"
                                      "全身几处刺痛，\n几股鲜血从身上标出。忍痛抬头一看，一柱剑气迎面又到" NOR,
                        "damage": 180,
                        "dodge" : 100,
                        "parry" : 100,
                        "attack": 220,
                        "force" : 400,
                        "damage_type": "刺伤",
                ]);
        }
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 150 + random(50),
                "force" : 320 + random(50),
                "attack": 90 + random(10),
                "dodge" : 90 + random(10),
                "parry" : 90 + random(10),
                "damage_type" : "刺伤",
        ]);
}

string query_parry_msg(object victim_weapon)
{
        switch (random(4))
        {
        case 0:
                return "$n随意挥洒，道道剑气纵横交错，宛若天网，$N唯有望洋兴叹，徒呼奈何。\n";
        case 1:
                return "$n不闪不避，一招中冲剑直袭$N的胸前大穴，迫得$N只有回身自救。\n";
        case 2:
                return "$n六剑连出，剑气回荡，直割得$N眉毛削落，脸面生通，再也不能前进半分！\n";
        default:
                return "$n一声长笑，无形剑气四处散开，将$N层层裹住，惟有勉强支撑。才约略摆脱了$n的反击。\n";
        }
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp, level;

        if ((level = (int)me->query_skill("six-finger", 1)) < 100 ||
            ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("six-finger", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

     
                result += (["msg" : HIC "$n" HIC "危急之时，心中一乱，随手一指，一道剑气凌锐的直奔$N而去。\n"
                                    HIC "$n" HIC "见这招来势凶狠，不得不收招自守，纵身避开。\n" NOR]);

                return result;
        } 
}

/*
int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("six-finger", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

*/
int difficult_level() 
{
        return 500; 
}
