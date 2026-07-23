// hanbing-zhenqi.c 寒冰真气

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
       if ((int)me->query_skill("force", 1) < 50)
               return notify_fail("你的基本内功火候还不够。\n");

       return 1;
}

int practice_skill(object me)
{
	return notify_fail("寒冰真气只能靠学(learn)来提高。\n");


}

string exert_function_file(string func)
{
       return __DIR__"hanbing-zhenqi/" + func;
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIW + me->name()+"脸上寒气浮现，隐隐有微光流动。" NOR,
    "start_my_msg" : "你手捏剑诀，将寒冰真气提起在体内慢慢转动。\n",
    "start_other_msg" : me->name()+"摆了个盘膝打坐的姿势，全身笼罩在一片寒气之中。\n",
    "halt_msg" : "$N双眼一睁，极速压下内息站了起来。\n",
    "end_my_msg" : HIW"你将寒冰真气按周天之势搬运了一周，感觉精神充沛多了。\n"NOR,
    "end_other_msg" : HIW"只见"+me->name()+"缓缓睁开双眼站起，浑身散发出一股冰冷的寒气。\n"NOR,
    "heal_msg" : HIW"$N运起寒冰真气，开始缓缓运气疗伤。\n"NOR,
    "heal_finish_msg" : HIY"$N内息一停，却见伤势已经全好了。”\n"NOR,
    "heal_unfinish_msg" : "$N眉头一皱，“哇”地吐出一口瘀血，看来这伤还没有全好。\n",
    "heal_halt_msg" : "$N急急把内息一压，也不顾身上的伤势立即站了起来。\n",
    ]);
}

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int skill, neili, neili1;
        object weapon;
        skill = me->query_skill("hanbing-zhenqi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        if(living(me)  &&
        !objectp(weapon = ob->query_temp("weapon")) &&
        random(skill)+10 > ob->query_skill("parry", 1)/2 && 
        me->query("combat_exp") > ob->query("combat_exp")/2 && 
        ob->query_skill_mapped("force") != "hanbing-zhenqi" &&
        skill > 180 && 
        neili > 500 && 
        living(ob) &&        
        !ob->query("env/invisibility"))
        {
                if(random(ob->query_skill("force")) < me->query_skill("force")/2)
                {
                        msg = HIW"猛然$n大叫一声急忙收手，";         
                        if(neili > neili1*2 )
                        {
                                msg += "全身已经被冷得直打寒战，动弹不得！\n"NOR;
                                if(random(ob->query_skill("force")) < 150)
                                        ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
                                ob->start_busy(1+random(4));
                        }
        
                        else if(neili > neili1 )
                        {
                                msg += "却已是全身蒙上了一层白雾！\n"NOR;
                                ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
                        }
                
                        else if(neili > neili1/3*2 )
                        {
                                msg += "就象碰到了冰块一样！\n"NOR;
                                ob->start_busy(random(2));
                        }
                        else msg += "却见身上已经结上了一层薄霜！\n"NOR;
                        
                        damage = -skill*3;
                        message_vision(msg, me, ob);
                }
                
                else if( random(100) >= 90 && neili > neili1)
                {
                        message_vision(HIW"谁知刚一接触到$P，便有一股极寒之气冲来，慌得$n急忙收劲抽手！\n"NOR, me, ob);
                        damage = -8000;
                }       
                
                else
                {
                        message_vision(HIW"谁知刚一接触便有一股寒气冲来，慌得$n急忙收劲抽手！\n"NOR, me, ob);
                        damage = -skill;
                }
                
                return damage;
       }
}
