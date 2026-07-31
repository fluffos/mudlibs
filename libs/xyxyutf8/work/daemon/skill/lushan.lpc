//【廬山聖龍】lushan-quan.c
// snowtu...20/06/03.
//meipai skill(only shengdoushi related NPCs can use it)

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N纵身跃起",
        "$N似退反进",
        "$$N一旋身",
        "$N忽发龙吟，使出一招",
        "$N一个筋斗翻在半空",
        "$N身形一长",
});

string* skill_tail =({
        "，双掌以排山倒海之势击向$n。",
        "，对准$n一把腰间抓了过去",
        "，双臂如铁铸一般扫向$n",
        "，双臂一阵横扫，直逼$n得连连倒退",
        "，直逼的$n节节后退。",
        "，全身劲气疾卷$n",
});

mapping *action = ({
        ([      "action":
"$N纵身跃起，一招"+HIR"「庐山爆裂拳」"NOR"，双拳化作万重幻影击向$n的$l",
                "dodge":                -40,
                "parry":                -40,
                "force":                180,
                "damage_type":          "瘀伤",
                "weapon" :              "双掌",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
        ([      "action":
"$N似退反进，突然欺身向前，左收右进，一招"+HIW"「庐山龙探睛」"NOR"，对准$n的$l一把刺了过去",
                "dodge":                -60,
                "parry":                -40,
                "force":                250,
                "damage_type":          "插伤",
                "weapon":               "右手食指",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
        ([      "action":
"只见$N一旋身，双拳舞动如风攻向$n。这一招"+HIB"「庐山龙卷风」"NOR"当真是防不胜防",
                "dodge":                -50,
                "parry":                -40,
                "force":                250,
                "damage_type":          "内伤",
                "weapon":               "双拳",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
        ([      "action":
"$N催动小宇宙，一招"+HIY"「庐山逆水流」"NOR"，啸声中和身而上，向$n直撞而来",
                "dodge":                -60,
                "parry":                -40,
                "force":                200,
                "damage_type":          "撞伤",
                "weapon":               "全身",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
            ([  "action":
"只见$N一个筋斗翻在半空，一招"+HIC"「庐山击水流」"NOR"将发未发，但是全身劲气疾卷$n",
                "dodge":                -40,
                "parry":                -20,
                "force":                250,
                "damage_type":          "内伤",
                "weapon":               "劲气",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
            ([  "action":
"$N身形一变，冲到$n面前就是一拳。这招"+HIG"「庐山百啸拳」"NOR"势若奔雷，气势如虹",
                "dodge":                -10,
                "parry":                -50,
                "force":                180,
                "damage_type":          "重伤",
                "weapon":               "拳头",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
});

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry" ;
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_lushan-quan");
if( !me->query_temp("HTH_perform")) {
if(me->query("skill_lushan-quan")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];
}else{ return action[6];}
  return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("star") + "/lushan-quan/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
int i = random((int)me->query_skill("lushan",1)*100);
if( damage_bonus < 100 ) return 0;
if ( !me || !victim || !me->is_fighting(victim) )
        return 0;
if( random(damage_bonus) > victim->query_str()/20) 
        {
        victim->receive_wound("kee", damage_bonus / 2 );
        switch(random(6)) 
                {
                case 0: return HIC"$n浑身一阵爆响,已身中"+chinese_number(i)+"拳！\n"NOR;
                case 1: return HIC"$n被$N强大的小宇宙惊的目瞪口呆！已受了一击!\n"NOR;
                case 2: return HIC"只听见$n的$l「砰」地一声,已中了"+chinese_number(i)+"拳！\n"NOR;
                case 3:
                        {
                        message_vision(HIB"$N大喊一声『庐山升龙霸』一条居龙自九天而起，直飞$n！\n"NOR,me,victim);
                if(random(1)==0)
                                {
                              message_vision(HIB"\n$N被巨龙在空中顶得翻了几十个跟头！\n"NOR,victim);
                       victim->add("eff_kee",-2*victim->query("max_kee")/10);
                        victim->add("eff_sen",-2*victim->query("max_sen")/10);
                                }
                        else
                                message_vision(HIB"\n$N身型急转，不知道绕了多少圈才夺过巨龙的攻击！\n"NOR,victim);
                        }
                break;
                case 4:
                        {
                        message_vision(HIR"$N高喊一声：『庐山亢龙霸』，一条恶龙自溅底而出，尾巴向$n扫去！\n"NOR,me,victim);
                        if(random(1)==0)
                                {
                                message_vision(HIR"\n$N被恶龙的尾巴甩了个正着，$N顿时眼冒金星！\n"NOR,victim);
                       victim->add("eff_kee",-2*victim->query("max_kee")/10);
                victim->add("eff_sen",-2*victim->query("max_sen")/10);
                        }
                        else
                        message_vision(RED"$N用尽全身力气，飞升而气，恶龙的尾巴正从$N的脚底板扫过！\n"NOR,victim);
                        } 
                break;
         case 5:
                       {
                        message_vision(HIW"$N高喊一声：『庐山百龙霸』，无数只巨龙向$n冲过来！\n"NOR,me,victim);
                        if(random(1)==0)
                                {
                                message_vision(HIW"$N如一个球一样，被无数只巨龙在空中戏弄着！\n"NOR,victim);
                        victim->add("eff_kee",-3*victim->query("max_kee")/10);
                        victim->add("eff_sen",-3*victim->query("max_sen")/10);
                                }
                        else
                        message_vision(WHT"$N看准了巨龙之间的空隙，左转右转，才勉强离难！\n"NOR,victim);
                        }
                break;
                }
        }
}

