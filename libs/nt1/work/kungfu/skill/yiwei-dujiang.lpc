// yiwei-dujiang.c 一苇渡江
// by Lonely

#include <ansi.h>

inherit SKILL; 

string *dodge_msg = ({
        "只见$n一招[似来还往],双脚一前一后,似进又腿,在$N一愣间躲过了攻击。\n",
        "但是$n使出[蜻蜓点水],脚尖站地,身形东倒西歪间,破天冲起。\n",
        "$n一招[立地飞升],身随意转,刹那间在原地转了七八十圈,突然往地上一坐,原是转晕了,却使$N落了空。\n",
        "可是$n一个[白驹过隙],身形微侧,提气直纵,躲过$N攻击。\n",
        "却见$n使出[浮光掠影],在原地留下一个幻象,真身躲到了一边。\n",
        "$n身形一顿,[鹞子穿云],身形平平掠出,在空中留下一道优美弧形。\n",
        "$n一招「青云直上」，身形化做一道清烟，以匪夷所思的速度避开了$N这一招。\n",
}); 

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me)
{ 
        if ((int)me->query("dex") < 25 || (int)me->query("int") < 25) 
               return notify_fail("就你这身法还练一苇渡江功？小心弄折了腿。\n"); 
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me)
{
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力太低了，不能练一苇渡江功。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太差了，不能练一苇渡江功。\n");
                
        me->add("neili", -30);
        me->receive_damage("qi", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yiwei-dujiang/" + action;
}

int query_effect_dodge(object victim, object me)
{
        int lvl;

        lvl = me->query_skill("yiwei-dujiang", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 100;
        if (lvl < 280) return 150;
        if (lvl < 350) return 200;
        return 250;
}

int difficult_level()
{
        return 300;
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{
        mixed result; 
        int ap, dp, mp; 

        if ((int)me->query_skill("yiwei-dujiang", 1) < 100 || 
            ! living(me)) 
                return; 

        mp = ob->query_skill("martial-cognize", 1); 
        ap = ob->query_skill("force") + mp; 
        dp = me->query_skill("dodge", 1) / 2 + 
             me->query_skill("yiwei-dujiang", 1); 

        if (ap / 2 + random(ap) < dp) 
        {
                result = ([ "damage": -damage ]); 
                switch (random(3)) 
                {
                case 0:
                        result += (["msg" : HIY "$n" HIY "一招「蜻蜓点水」，脚尖往地一点，身体冲天而起，" 
                                            "顿时,$N一招失手！\n" NOR]); 
                        break; 
                case 1:
                        result += (["msg" : HIY "$n" HIY "一个「白驹过隙」，身行一侧，提气一纵，"                                            
                                            "$N猛然一招过去，已经收不住去势！\n" NOR]); 
                        if (! ob->is_busy())
                                ob->start_busy(random(2)); 
                        break; 
                default: 
                        result += (["msg" : HIY "$n" HIY "使出「鹞子穿林」，向一旁平平掠出，" 
                                            "一个转身折身而下。\n" NOR]); 
                        break; 
                }
                return result; 
        } else 
        if (mp >= 100) 
        {
                switch (random(3)) 
                {
                case 0: 
                        result = HIY "$n" HIY "一招「蜻蜓点水」，脚尖往地一点，身体冲天而起," 
                                 "可是$N" HIY "早以洞察$n的企图。抢占了先机。\n" NOR;  
                        break; 
                case 1: 
                        result = HIY "$n" HIY "一个「白驹过隙」，身行一侧，提气一纵，" 
                                 "$N拧身而上，全力攻击$n！\n" NOR;  
                        break; 
                default: 
                        result = HIY "$n" HIY "使出「鹞子穿林」，向一旁平平掠出，"                                 
                                 "$N冷笑几声，身行一拔往高处掠去，凌空搏击$n！\n" NOR;  
                        break; 
                }
                COMBAT_D->set_bhinfo(result); 
        }
}


