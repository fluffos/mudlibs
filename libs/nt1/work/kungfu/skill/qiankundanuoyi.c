// qingkundanuoyi.c 乾坤大挪移
// Created by Lonely (06/11/2002)

#include <ansi.h>
#include <combat.h>
inherit SKILL;


int valid_enable(string usage) { return usage=="parry"; }

int valid_learn(object me)
{
   	if ((int)me->query("shen") < 0)
   		return notify_fail("你的邪气太重，无法修炼乾坤大挪移。\n");
   		
   	if (me->query("character") != "光明磊落") 
                return notify_fail("你天性不符，受其拘束，无法修炼乾坤大挪移。\n");

   	if (me->query("gender") == "无性")
   		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之"
			"气，无法领会里面的乾坤阴阳变化之道。\n");

   	return 1;
}

int practice_skill(object me)
{
    	return notify_fail("乾坤大挪移只能学习得来。\n");
}

int parry_action(object me, object target, object target_weapon, 
		 int attack_type, mapping action, string limb)
{
        object weapon, *enemy, vic;
        string msg;
        int pp, ap, i;

        if (me->query_condition("jiujian_qi_damage")) 
                return 0;

        if (! living(me)) return 0;

        if (target_weapon)
        	ap = target->query_skill(target_weapon->query("skill_type"));
        else ap = target->query_skill("force");

        pp = me->query_skill("parry");
        if (random(pp) < ap / 2) return 0;

        msg = "\n" + action["action"] + "\n";
        if (target_weapon)   
        	msg = replace_string(msg, "$w", target_weapon->query("name"));
        	
        msg = replace_string(msg ,"$l", limb);
        enemy = me->query_enemy();
        
        if (! enemy || ! arrayp(enemy) || sizeof(enemy) < 1) 
        	return 0;

	weapon = me->query_temp("weapon");         
        i = sizeof(enemy);
        if (i == 1)       
        {
        	if ((target_weapon && ! weapon) || (! target_weapon && weapon))
		{        	
                	msg += HIW "$n " HIW "神意合一，施展「乾坤大挪移」神技，$N" HIW "的招数尽数落空！\n" NOR;
                	message_combatd(msg, target, me);
                	return 1;
                }
                msg += HIW "$n" HIW "神意合一，施展「乾坤大挪移」神技，将$N" HIW "的招数尽数挪回去！" NOR;
                message_combatd(msg, target, me); 
                COMBAT_D->do_attack1(me, target, weapon, 2, action, limb); 
                return 1;
        }
        else if (i > 2)
        {
        	if (member_array(target, enemy) != -1) 
        		enemy -= ({target});
        	vic = enemy[random(sizeof(enemy))];
                msg += HIW "$n" HIW "神意合一，施展「乾坤大挪移」神技，将$N" HIW "的招数尽数引向" + 
                       vic->query("name") + HIW "！\n" NOR;
                message_combatd(msg, target, me);
                
                if (! vic->is_busy())
                	vic->start_busy(1);
                	
                COMBAT_D->do_attack1(target, vic, target_weapon, 2, action, limb);
                return 1;
        }
}

string perform_action_file(string action) 
{
        return __DIR__"qiankundanuoyi/" + action; 
}

void skill_improved(object me)
{
        int lvl;
        int layer;

        lvl = me->query_skill("qiankundanuoyi", 1);
        layer = lvl / 50;
        if (layer > 7) layer = 7;

        if (! layer)
        {
                tell_object(me, HIM "你潜心修炼乾坤大挪"
                            "移心法，若有所悟。\n" NOR);
        } else
        if ((lvl % 50) == 0)
        {
                tell_object(me, HIM "你修炼成了第" + chinese_number(layer) +
                            "层的乾坤大挪移心法。\n" NOR);
        } else
                tell_object(me, HIM "你对第" + chinese_number(layer) +
                            "层的乾坤大挪移心法又加深了一层了解。\n" NOR);

        if (lvl > me->query_skill("force") * 2 / 3)
        {
                if (lvl < me->query_skill("force") * 2 / 3 + 10)
                {
                        tell_object(me, HIG "你觉得内息一阵紊乱，丹田时冷时"
                                        "热，不由得大吃一惊。\n心想莫非是走"
                                        "火入魔？丹田越来越是寒冷，极为难受"
                                        "。\n" NOR);

                        message("vision", HIG + me->name() + HIG "的脸色忽红"
                                          "忽绿，变得不停，只是浑身颤抖，似"
                                          "乎十分痛苦。\n" NOR,
                                          environment(me), ({ me }));
                        return;
                }

                tell_object(me, HIB "你忽然觉得丹田腾起一阵寒意，霎时间四肢"
                                "百赅一起变得寒冷无比，忍不住大声呻吟。\n" NOR);

                message("vision", HIB + me->name() + HIB "忽然一抖，脸色忽然"
                                  "变得惨白，隐然笼罩了一股绿气，呻吟不止。"
                                  "\n" NOR, environment(me), ({ me }));
        } else

        if (lvl < 350 && (lvl * 20 + 4000) > me->query("max_neili"))
        {
                if ((lvl * 20 + 4000) < me->query("max_neili") + 200)
                {
                        tell_object(me, HIR "你试着运转了一下内息，一时觉得内"
                              "力不济，看来还是不要贸然修炼大挪移神功。\n" NOR);
                        return;
                }

                tell_object(me, HIR "你试着运转了一下内息，忽然觉得一口气"
                      "竟然转不过来，顿时心中绞痛，接连吐了几口鲜血。\n" NOR);
                message("vision", HIR + me->name() + HIR "脸色忽然"
                        "一变，呕出几口鲜血，触目惊心。\n" NOR,
                        environment(me), ({ me }));
        } else
                return;
}
