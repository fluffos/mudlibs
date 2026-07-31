// yunv-xinfa 玉女心法
// by Lonely

#include <ansi.h>
#include <combat.h>

inherit FORCE;

int valid_force(string force) { return 1; }       
int query_neili_improve(object me)  
{
        int lvl; 
        lvl = (int)me->query_skill("yunv-xinfa", 1); 
        return lvl * lvl * 20 * 15 / 100 / 200; 
}

int valid_enable(string usage) { return usage == "force"; }

void skill_improved(object me){}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("yunv-xinfa", 1);

        if ( me->query("gender") == "无性" && lvl > 49 )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的玉女心经。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("玉女心经讲究阴阳调合，有违佛家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ( lvl > 10 && (int)me->query("shen") < lvl * 100 )
                return notify_fail("你的侠义正气太低了。\n");
        /*
        if (me->query_skill("yunu-xinfa", 60) < 101 && me->query_skill("yunu-xinfa", 1) > 1
        &&  me->query("request/yunu") < (int)me->query_skill("yunu-xinfa", 1)/20)
                return notify_fail("你体内阳退真气渐弱，难以继续提高。\n");

        if (me->query_skill("yunu-xinfa", 1) < 120 && me->query_skill("yunu-xinfa", 1) > 60
        &&  me->query("request/yunu") < (int)me->query_skill("yunu-xinfa", 1)/10)
                return notify_fail("你体内阳退真气渐弱，难以继续提高。\n");

        if (me->query_skill("yunu-xinfa", 1) > 120
        &&  me->query("request/yunu") < me->query_skill("yunu-xinfa", 1)/5)
                return notify_fail("你体内阳退真气渐弱，难以继续提高。\n");
        */

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("玉女心经，只能用学(learn)或者两人合修来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"yunv-xinfa/" + func;
}

mapping curing_msg(object me)
{
        return ([
                "apply_short"   : "坐在一旁垂帘入定，姿态悠雅，神态清冷。",
                "start_self"    : "轻轻的吸一口气，闭上眼睛，运起玉女心经，内息在脉络中开始运转。\n",
                "start_other"   : "神态突然开始变的清冷无比，可是姿势又变的悠雅异常。\n",
                "finish_self"   : "慢慢收气，归入丹田，睁开眼睛，轻轻的吐了一口气。\n",
                "finish_other"  : "睁开眼睛，轻轻的吐出了一口气，神态恢复自然。\n",
                "unfinish_self" : "渐感真气不纯，后劲不继，内息一转，迅速收气，停止了内息的运转。\n",
                "unfinish_other": me->query("eff_qi") < me->query("max_qi")*3/4 ?
                                  "猛地里"+ me->name() +"口一张，喷出几口鲜血。\n" :
                                  "猛地里"+ me->name() +"口一张，吐出口紫黑瘀血。\n",
        ]);
}

                

/*
mixed do_damage(object me, object victim, int damage, int damage_bonus)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");
        int ap, dp;
        string result;

        if ( (int)victim->query_skill("yunu-jing", 1) < 80 ) return damage;

        dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
        if (objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" ) {
                if ( victim->query_skill_mapped("parry") != "yunu-jian" )
                        return damage;
                dp /= 3;
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/2;
        } else if (!objectp(weapon2) && ( victim->query_skill_mapped("parry") == "tianluo-diwang" || victim->query_skill_mapped("parry") == "yunu-jian" ) ) {
                if ( victim->query_skill_prepared("strike") != "tianluo-diwang" )
                        return damage;
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        } else
                return damage;

        ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);
        if (objectp(weapon1))
                ap += COMBAT_D->skill_power(me, weapon1->query("skill_type"), SKILL_USAGE_ATTACK);
        else 
                ap *= 2;

        ap /= 100;
        dp /= 100;

        if(me->query_temp("shentong")) {
                        result = "$n见$N招数凌厉，也不惧怕，旋即以玉女心经上的武功一一破解！\n";
                        damage_bonus = 0;
                                me->start_busy(1+random(1));
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
        
        }
        
        if ( random(ap+dp+dp) > ap ) {
                if (objectp(weapon2) && objectp(weapon1) && (string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") {
                        result = "那知$n所使玉女剑法正是全真剑法的对头，剑尖一颤，陡地弯过，反而先行刺中$N一剑！\n";
                                me->start_busy(1+random(1));
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                } else if (objectp(weapon2) && objectp(weapon1) && (string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("sword") == "duanyun-bian"){
                        result = "那知$n对断云鞭法早已精研透彻，剑尖回转，$N未能伤敌，先中一剑！\n";
                                me->start_busy(1+random(1));
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                }  else if (!objectp(weapon2) && !objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ||((string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") 
||((string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("whip") == "duanyun-bian") ) ){

                        result = "不料$n忽然一掌按出，无影无踪，手掌竟绕过$N手臂，按到了$N胸口，正是玉女心经上制全真武功的绝招！\n";
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);

                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";


                }
                damage_bonus = -5000; // just a number negative enough
                return ([ "result" : result, "damage" : damage_bonus ]);
        } else if( random(ap+dp+dp+dp) > ap ) {
                if (objectp(weapon2)&& objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ||((string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") 
||((string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("whip") == "duanyun-bian") ) ) {
                        result = "$n剑走轻灵，破开了这一招全真武功。\n";
                        damage_bonus = 0;
                } else if (!objectp(weapon2)&& !objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ) ) {
                        result = "但是$n对全真派拳掌招招精熟，随手化解，将$N的内劲全数卸在一旁。\n";
                        damage_bonus = -5000; 
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        } else 
                return damage;

}
*/
