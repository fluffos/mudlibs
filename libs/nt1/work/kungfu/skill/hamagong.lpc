// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hamagong.c 蛤蟆功

#include <ansi.h>
inherit FORCE;

int valid_force(string force) { return 1; }    

int query_neili_improve(object me) 
{
        int lvl; 
        lvl = (int)me->query_skill("hamagong", 1); 
        return lvl * lvl * 22 * 15 / 100 / 200; 
}
string *action_msg = ({
        "$N劲由心生，蛤蟆功内劲迸发，一股热气从丹田中直冲上来，双腿一弯，口中阁的一声叫喝，手掌便朝$n推出",
        "$N猛喝一声，双掌倏向$n$l推出，掌力疾冲而去，劲力十分猛恶，祗隐听得呼呼风响，声音劲急，非同寻常",
        "$N蹲下身子，“咕”的一声大叫，猛地双掌推出，掌风沉雄凌厉。$n突觉一股排山倒海般的力道撞来，猛迅无伦",
        "$N蹲低身子，发掌向$n击去，左掌右掌，连环邀击，双掌连绵而上，掌法愈厉，乘势不住追击，後著凌厉之极",
        "$N“阁”的一声大叫，发劲急推，双掌一上一下，一放一收，斗然击出，朝著$n排山倒海般劈将过来",
        "$N身子蹲下，双掌平推而出，口中咯咯大叫，身子一幌一幌。这一推劲力极大，\n去势却慢，看来平平无奇，内中却是暗藏极大潜力",
        "$N蹲在地下，咕咕咕的叫了几声，内力崩涌，丹田中一股热气激升而上，身子猛\n跃而起，双掌推出，一股凌厉之极的掌风随之朝$n压到",
});

mapping *reverse_action = ({
        "忽听$N大叫三声，三个筋斗翻将出来，大吼一声，恶狠狠的朝$n扑将上来",
        "但见$N疯势更加厉害，口吐白沫，举头朝$n猛撞",
        "$N蓦地张口，白牙一闪，已向$n$l咬落，又快又准",
        "$N一口唾沫急吐，势挟劲风，竟将痰涎唾沫也当作了攻敌利器",
        "$N忽然张嘴，一口唾沫往$n脸上吐去，发掌击向$n趋避的方位，同时又是一口浓痰吐将过来",
        "此时$N所使的招数更是希奇古怪，诡异绝伦，身子时而倒竖，时而直立，\n忽然一手撑地，身子横挺，一手出掌打向$n$l",
});

int valid_enable(string usage) 
{
        if (usage == "force" || usage == "parry" ) return 1;
        if (usage == "strike") 
        {
                if (this_player()->query_skill("hamagong", 1) < 100) 
                {
                        message_vision("$N蹲下身来，口中咕咕咕的叫了几声，要将蛤蟆功口诀用在拳脚之上，但无论如何使用不上。\n", this_player() );
                        return 0;
                }
                return 1;
        }
        return 0;
}

mapping query_action(object me, object weapon)
{
        string *power_msg = 
        ({
                HIR"$N蹲下身来，运起蛤蟆功，双手平推，吐气扬眉，阁阁阁三声叫喊。这\n三推之力带有风疾雷迅的猛劲，实是非同小可"NOR,
                WHT"$N阁阁两声怒吼，蹲下身来，呼的双掌齐出，掌力未到，掌风已将地下\n尘土激起，一股劲风直扑$n面门，势道雄强无比"NOR,
                HIR"$N脸色阴沉，脸颊上两块肌肉微微牵动，两臂弯曲，阁的一声大叫，双\n手挺出，一股巨力横冲直撞的朝$n推将过来"NOR,
                WHT"$N蹲低身子，口中咕咕咕的叫了三声，双手推出，以蛤蟆功向$n猛攻。\n$n身周在$P掌力笼罩之下，只激得灰泥弥漫，尘土飞扬"NOR,
        });
        string *reverse_msg = 
        ({
                HIM"但见$N招术奇特，怪异无伦，忽尔伸手在自己脸上猛抓一把，忽尔反足\n在自己臀上狠踢一脚，每一掌打将出来，中途方向必变，实不知打将何处"NOR,
                HIM"$N忽然反手拍拍拍连打自己三个耳光，大喊一声，双手据地，爬向$n，\n忽地翻身一滚，骤然间飞身跃起，双足向$n连环猛踢"NOR,
                HIM"突然之间，$N俯身疾攻，上盘全然不守，出招怪异无比，将蛤蟆功逆转\n运用，上者下之，左者右之，招数难以捉摸"NOR,
                HIM"$N全身经脉忽顺忽逆，手上招数虽然走了错道，但是错有错着，出手怪\n诞，竟教$n差愕难解"NOR,
        });


        if (me->query_skill_mapped("force") == "hamagong") 
        {
                if (! me->query_temp("reverse") && me->query_temp("powerup") 
                &&  random(me->query_skill("force")) > 250 && me->query("neili") > 1000 
                &&  me->query("jiali") > 100)
                        return ([
                                "action": power_msg[random(sizeof(power_msg))],
                                "dodge" : 100,
                                "parry" : 100,
                                "force" : 550,
                                "attack": 180,
                                "damage_type": random(2)?"内伤":"瘀伤"
                        ]);
                else 
                if (me->query_temp("reverse") && random(me->query_skill("force")) > 400  
                &&  random(me->query_skill("strike")) > 300 && me->query("neili") > 1000)
                        return ([
                                "action": reverse_msg[random(sizeof(reverse_msg))],
                                "dodge" : 120,
                                "parry" : 120,
                                "force" : 600,
                                "attack": 200,
                                "damage_type": "瘀伤",
                        ]);
        }
        if (me->query_temp("reverse"))
                return ([ 
                        "action" : reverse_action[random(sizeof(reverse_action))],
                        "attack" : 90 + random(10),
                        "dodge"  : 90 + random(10),
                        "parry"  : 90 + random(10),
                        "force"  : 460 + random(40),
                        "damage_type": random(2)?"内伤":"瘀伤",
                ]);
        return ([
                "action" : action_msg[random(sizeof(action_msg))],
                "attack" : 80 + random(10),
                "dodge"  : 80 + random(10),
                "parry"  : 80 + random(10),
                "force"  : 460 + random(40),
                "damage_type": random(2)?"内伤":"瘀伤",
        ]);

}


int valid_learn(object me)
{
        mapping skl; 
        string *sname;
        int v, k=0;
        
        int i = (int)me->query_skill("hamagong", 1);


        if ( me->query("class")=="bonze" )
        {
                if (me->query("gender")=="女性")
                        return notify_fail("小尼姑练蛤蟆功，不怕别人叫你秃头蛤蟆吗？\n");
                        
                if (me->query("gender")=="男性")
                        return notify_fail("大师傅练蛤蟆功，不怕别人叫你秃头蛤蟆吗？\n");
        }

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        if (me->query("family/master_id") != "ouyang feng"
        &&  me->query_skill("hamagong", 1) > 99)
                 return notify_fail("蛤蟆功需高人指点才能继续提高。\n");
                 
        if (me->query_temp("weapon"))
                 return notify_fail("蛤蟆从不手持兵刃，所以练蛤蟆功也必须空手。\n");
                 
        if ((int)me->query("qi") < 90)
                return notify_fail("你的体力不够练蛤蟆功。\n");
                
        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不够练蛤蟆功。\n");
        
        me->add("neili", -80);
        me->receive_damage("qi", 80);
 
        return 1;
}
        
string perform_action_file(string action)
{
        return __DIR__"hamagong/perform/" + action;
}

string exert_function_file(string func)
{
        return __DIR__"hamagong/exert/" + func;
}

int difficult_level() 
{
        return 500;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        mixed result;

        lvl = me->query_skill("hamagong", 1);

        if (damage_bonus < 100
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "hamagong"
           || me->query_skill_mapped("strike") != "hamagong"
           || me->query_skill_prepared("strike") != "hamagong")
                return 0;

        if (damage_bonus / 2 > victim->query_con())
        {
                me->add("neili", -50);
                result = ([ "damage" : (damage_bonus - 80) / 2 ]);
                result += ([ "msg" : HIR "忽见$N" HIR "口中咕咕咕的叫了三声，真气汹涌而出"
                                     "，$n" HIR "只感喉咙一甜，喷出一口鲜血！！\n" 
                                     NOR ]);
                return result;
        }
}

mapping exercise_msg(object me)
{
        return ([
                "status_msg" : "半蹲在地上，身冒白气",
                "heal_msg" :  "$N全身放松，半蹲在地上开始运功疗伤。。\n",
                "heal_finish_msg" : "“哇！”的大叫一声，全身的白气渐渐消散。\n",
                "heal_unfinish_msg" : "“哇！”的大叫一声，站了起来，但脸色苍白，看来还有伤在身。\n",
                "heal_halt_msg" : "身冒白气，“哇！”的大叫一声，站起身来。\n",
        ]);
}

