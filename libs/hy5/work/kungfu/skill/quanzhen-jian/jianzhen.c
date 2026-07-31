//jianzhen.c 【七星剑阵】csy 99.05.26

#include <ansi.h>

inherit F_SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int perform(object me, object target)
{
        string msg;
        string npc_dir = "/d/quanzhen/npc/";
        object where;
        int fenshen_time; //this time is the time interval fenshen can be used again. 
        object soldier;
int skill;
mapping ob_fam; 
  

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me
        ||   !me->is_fighting(target))
                return notify_fail("你想请全真弟子对付谁呀？\n");

        if(userp(me) && (string)me->query("family/family_name") != "全真教" )
                return notify_fail("你又不是全真教弟子，全真弟子哪里会帮你？n");

        if(userp(me) && (string)target->query("family/family_name") == "全真教" )
                return notify_fail("同门相斗叫师傅帮忙？\n");

        if(me->query_temp("nojz") )
                return notify_fail("同门相斗叫师傅帮忙？\n");

        if((int)me->query_skill("qixing-array", 1) < 150)
                return notify_fail("你的北斗七星阵修为不深，无法和全真弟子组合剑阵。\n"); 

        if((int)me->query_skill("quanzhen-jian", 1) < 150)
                return notify_fail("你的全真剑法修为不深，不能和全真弟子相配合。\n");        

if (me->query_condition("zdizi_busy"))
return notify_fail("你刚刚召唤过附近的全真门人，暂时没人帮你！\n");
        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不够，没办法和全真弟子相配合。\n"); 
       
        if((int)me->query("jing") < 60 )
                return notify_fail("你现在神智不清，不被人拿已是万幸了！\n");


if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("分身无法再分身！\n");

if (me->query_temp("invoker"))
return notify_fail("分身无法再分身！\n");

if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("超出一次战斗上限。\n");    

if (!environment(me))
return notify_fail("无法使用!\n");    

        me->add("neili", -50);
        me->receive_damage("jing", 10);

        if( random(me->query("max_qi")) < 60 ) 
        {
                write("咦？你受伤太重，呼叫不了救援。\n");
                return 1;
        }

     msg = HIR "\n$N袍袖一展，一道火光冲天而起，只听见$N大喝一声：全真弟子现在何处？\n" NOR +
              HIY "\n只听四周一连串的声音答道：「全真弟子，在此！\n"NOR +
              HIR "\n$N一指$n：此人无恶不作，罪大恶极，请师兄弟门替弟子拿人！\n\n" NOR;      
        message_vision(msg, me, target);
        msg = HIC "$n对着$N高声骂道：好家伙，一拥而上了，我宰了你！\n\n" NOR;     
        message_vision(msg, me, target);

  me->receive_damage("jing", 40);
        skill=(int)me->query_skill("qixing-array",1);
        skill=skill*0.8;
 seteuid(getuid());
        soldier = new("/d/biwu/qz");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
        if (me->query("vendetta/authority")) soldier->set("vendetta/authority",1);
        soldier->add_team_member(me);
        me->add_team_member(soldier);
              soldier->set_name(this_player()->query("name")+"的师兄弟",({"qz dizi"}));
   

        soldier->set_temp("nojz",1);
        soldier->initlvl(skill,18);
soldier->invocation(me);
        me->start_busy(2);

        return 30+random(30);
}

