// by Lonely

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "只见$n施展凌波微步，神光离合，乍阴乍阳，动无常则，进止难期。\n",
        "只见$n施展凌波微步，步法轻盈，仿佛轻云之蔽月，不知怎的就到了数丈之外。\n",
        "$n的身影飘飘兮若流风之回雪，施展的正是凌波微步，$N连$n的衣角都沾不到。\n",
        "但见$n施展凌波微步，左一转，右一斜，就已经绕到了$N的身後。\n",
        "可是$n施展凌波微步，只是轻描淡写地向旁踏出一步，就巧妙地避开了$N的攻势。\n",
        "只见$n身影滴溜溜地一转，体迅飞鸟，飘忽若神，施展的正是凌波微步。\n",
        "$N只觉得眼前一花，头脑发昏，只觉得四面都是$n的身影！\n",
        "$n左脚轻轻地踏出一步，施展凌波微步，若往若返，把$N牵得团团乱转。\n",
});

int valid_enable(string usage) 
{ 
        return usage == "dodge"; 
}

int practice_level(){ return 101; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力修为不够，无法研习高深的步法。\n");
                
        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候不够，无法研习高深的步法。\n");
                
        if (me->query_skill("dodge", 1) <= me->query_skill("lingboweibu", 1))
                return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
                
        if ((int)me->query("dex") < 21 || (string)me->query("family/family_name") != "逍遥派") 
               return notify_fail("就你这身法还练凌波微步？小心弄折了腿。\n"); 
        
        if ((int)me->query("int") < 25) 
               return notify_fail("就你这悟性想学凌波微步？强学是没有用的。\n"); 
               
        return 1;
}

string query_dodge_msg(string limb,object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太差了，不能练凌波微步。\n");
                
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力太低了，不能练凌波微步。\n");
                
        me->add("neili", -30);          
        me->receive_damage("qi", 20);        
        return 1;
}

string perform_action_file(string action)
{
      return __DIR__"lingboweibu/" + action;
}

int query_effect_dodge(object victim, object me)
{
        int lvl;

        lvl = me->query_skill("lingboweibu", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 100;
        if (lvl < 280) return 150;
        if (lvl < 350) return 200;
        return 250;
}

// 研究的难度的设定
int difficult_level()
{
        return 500;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("lingboweibu", 1) < 50 ||
            ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("dodge", 1) * 2 / 3 +
             me->query_skill("lingboweibu", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "施展凌波微步，神光离合，乍阴乍阳，动无常则，"
                                            "进止难期，\n$N" +
                                            HIC "只觉得眼前一花，头脑发昏，只觉得四面都是$n的身影，攻击全不着力。\n" NOR]);
                        break;

                case 1:
                        result += (["msg" : HIC "$n" HIC "施展凌波微步，步法轻盈，仿佛轻云之蔽月"
                                            "不知怎的就到了数丈之外，化解$N" HIC "的攻势。\n" NOR]);
                        break;

                default:
                        if (! ob->is_busy())
                                ob->start_busy(random(3));
                        result += (["msg" : HIC "$n" HIC "左脚轻轻地踏出一步，施展凌波微步"
                                            HIC "，若往若返，把$N"
                                            HIC "牵得团团乱转，甚不舒畅。\n" NOR]);
                        
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(3))
                {
                case 0:
                        result = HIY "$n" HIY "施展凌波微步，神光离合，乍阴乍阳，动无常则，"
                                 "动无常则，\n然而$N" +
                                 HIY "理也不理，随手挥招直入，进袭$n"
                                 HIY "！\n" NOR;
                        break;

                case 1:
                        result = HIY "$n" HIY "施展凌波微步，步法轻盈，仿佛轻云之蔽月，"
                                 "可是$N" HIY "攻势却是变化无方，不遵循常理。\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "左脚轻轻地踏出一步，施展凌波微步，"
                                 HIY "若往若返，可是$N"
                                 HIY "立刻变化节奏，出奇招快速进击$n"
                                 HIY "！\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

void skill_improved(object me)
{
        if (me->query_skill("lingboweibu",1) == 80 && ! me->query("lbwb") 
        &&  me->query_skill("literate", 1) > 80)
        {
                tell_object(me, HIY "$N一步步走下来，只觉的心情舒畅，不知不觉内力有所积累。\n" NOR);
                me->add("max_neili", random(30)+20);
                me->add("lbwb",1);
        }
        if (me->query_skill("lingboweibu", 1) == 120 && me->query("lbwb") == 1 
        &&  me->query_skill("literate", 1) > 100)
        {
                tell_object(me, HIM "$N六十四卦走完，刚好绕了一个大圈，回到原地，精神大振。\n" NOR);
                me->add("max_neili", random(30)+20);
                me->add("lbwb", 1);
        }
        if (me->query_skill("lingboweibu", 1) == 160 && me->query("lbwb") == 2 
        &&  me->query_skill("literate", 1) > 120)
        {
                tell_object(me, CYN "$N越走越快，内息随着步法不住运转，隐隐然自己的内力已经有了提高！\n" NOR);
                me->add("max_neili", random(30)+20);
                me->add("lbwb", 1);
        }
        if (me->query_skill("lingboweibu", 1) == 200 && me->query("lbwb") == 3 
        &&  me->query_skill("literate", 1) > 140)
        {
                message_vision(RED "$N步法娴熟，随意踏出，脚步成圆，只感神清气爽，全身精力弥漫！\n" NOR, me);
                me->add("max_neili", random(30)+20);
                me->add("lbwb", 1);
        }
}

