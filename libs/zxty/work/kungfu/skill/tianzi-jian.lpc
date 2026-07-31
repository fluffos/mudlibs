
#include <ansi.h> 
inherit SKILL;

mapping *action = ({
([      "action" : "$N指南打北，剑势如虹，$w忽隐忽现，忽左忽右向$n攻去",
        "force" : 510,
        "attack": 180,
        "dodge" : 115,
        "parry" : 125,
        "damage": 325,
        "damage_type": "内伤"
]),
([      "action":"$N手中的$w龙吟不定，犹如长江滚滚而来，将$n笼罩在一片剑影之下",
        "force" : 510,
        "attack": 188,
        "dodge" : 112,
        "parry" : 115,
        "damage": 310,
        "damage_type": "刺伤"
]),
([      "action":"$N面带九仪天尊之相，卷起手中的$w，向$n直刺过去",
        "force" : 532,
        "attack": 225,
        "dodge" : 120,
        "parry" : 102,
        "damage": 365,
        "damage_type": "刺伤"
]),
([      "action":"$N舞动手中$w，幻出的一个个光环化作条条金龙，顿时将$n围得水泄不通",
        "force" : 565,
        "attack": 210,
        "dodge" : 115,
        "parry" : 105,
        "damage": 390,
        "damage_type": "内伤"
]),
([      "action":"$N飞身而起，人剑合一，犹如神龙般向$n直射而去",
        "force" : 550,
        "attack": 248,
        "dodge" : 110,
        "parry" : 120,
        "damage": 420,
        "damage_type": "刺伤"
]),
});


string *usage_skills = ({ "sword", "dodge", "parry" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
       return action[random(sizeof(action))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;
        int cost;  
        object m_weapon;

        if ((int) me->query_skill("tianzi-jian", 1) < 150 ||
            ! (m_weapon = me->query_temp("weapon")) ||
            me->query_skill_mapped("parry") != "tianzi-jian" ||
            ! living(me) || m_weapon->query("skill_type") != "sword")
                return;


        cost = damage / 2;

        if (cost > 100) cost = 100;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force");
        dp = me->query_skill("parry");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIY "$n" HIY "面露九仪天尊之相，镇定自若"
                                            "，$N" HIY "只觉$n浑身毫无破绽可寻，" HIY 
                                            "一时间根本无从攻击。\n"NOR]);
                        break;
                case 1:
                        result += (["msg" : HIY "$N" HIY "一招击中$n" HIY "上身"
                                            "，可却被$n帝王霸气所慑，招式顿显无力。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "但见$n" HIW "动作潇洒致极。"
                                            "随手接下了$N" HIW "这一招，却没有受到"
                                            "半点伤害。\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(3))
                {
                case 0:
                        result = HIY "$n" HIY "面露九仪天尊之相，镇定自若，"
                                 "浑身毫无破绽可寻，但是$N"
                                 HIY "精通易理，将其中虚实辨得清清楚楚。\n" NOR;
                        break;
                case 1:
                        result = HIY "$n" HIY "气沉丹田，帝王霸气尽现$N"
                                 HIY "然而$N也不示弱，真力迸发，招招抢攻。\n" NOR;
                        break;
                case 2:
                        result = HIW "$n" HIW "动作潇洒致极。随手接下了$N"
                                 HIW "这一招，丝毫无损。可是$N"
                                 HIW "招中有招，进攻却是不止。\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("tianzi-jian", 1);


        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300 )         
            return 0;


             if (objectp(weapon) && weapon->query("skill_type") != "sword")                
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "tianzi-jian")
                         return 0;

        if (random(2) == 1)return 0;

        if (damage_bonus / 5 > victim->query_con())
        {
                me->add("neili", -100);
                victim->receive_wound("qi", (damage_bonus - 76) / 2, me);
                victim->add("neili", -((damage_bonus - random(70)) / 2), me);
         
                return random(2) ? HIY "$N" HIY "一剑挥出，竟似招来千万条护架金龙，"
                                   "尽数射入$n" HIY "体内！\n" NOR:
                                   HIM "$N" HIM "突然连出数剑，$n" HIM "只感全身一"
                                   "震，登时被刺出数个伤口！\n" NOR;
        }
}

int practice_skill(object me)
{
      return notify_fail("天子剑法博大精深，无法简单的通过练习进步。\n");
}

int valid_learn(object me)
{
        int level;
        
        if ( ! me->query("special_skill/emperor"))
                return notify_fail("你不是真命天子,无法修习天子剑法。\n");

        if (me->query("gender") != "男性")
                return notify_fail("天子剑法只有男性方可修习。\n");
     
        level = me->query_skill("tianzi-jian", 1);

        if (me->query_skill("sword", 1) < level)
                return notify_fail("你对基本剑法的理解还不够，无法继续领会更"
                                   "高深的天子剑法。\n");

        if (me->query_skill("dodge", 1) < level)
                return notify_fail("你对基本轻功的理解还不够，无法继续领会更"
                                   "高深的天子剑法。\n");

        if (me->query_skill("parry", 1) < level)
                return notify_fail("你对基本招架的理解还不够，无法继续领会更"
                                   "高深的天子剑法。\n");

        return ::valid_learn(me);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
       if ( this_player()->query_skill("tianzi-jian", 1) > 300)
       return 1200;
       else   return 1000;
}

string perform_action_file(string action)
{
        return __DIR__"tianzi-jian/" + action;
}

