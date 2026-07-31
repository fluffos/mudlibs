#include <ansi.h>
#include "/cmds/std/valid_kill.h";
inherit ROOM;

mapping kill=([]);
mapping query_kill() {return kill;}

void remove_list(string me, string obj)
{
string *targs;
remove_call_out("remove_list");
if(undefinedp(kill[me])) return;
targs=kill[me];
if(!targs || sizeof(targs)<2) 
        {
        map_delete(kill, me);
        } 
else    {
        targs-=({obj});
        kill[me]=targs;
        }
}

void setup()
{
::setup();
set("alternative_die",1);
}
        
void create()
{
set("short","PK开放地带");
setup();
}       

void init()
{
add_action("do_kill","kill");
}       

int do_kill(string arg)
{
string callname,myid,objid;     
object who,guard_ob,me = this_player();
int just_issued = 0;
if ( !arg )     return 0;
who = present(arg,this_object());
if ( !who || !userp(who) )
        return 0;
if ( !valid_kill(me,who,0) ) 
        return 0;
callname = RANK_D->query_rude(who);
myid = me->query("id");
objid= who->query("id");
if(undefinedp(kill[myid])) 
        {
        just_issued=0;
        kill+=([myid:({objid})]);
        remove_call_out("remove_list");
        call_out("remove_list",1,myid,objid);
        } 
else    {
        string *targs=kill[myid];
        if(targs && member_array(objid,targs)!=-1) 
                just_issued=1;
        else    {
                just_issued=0;
                if (!targs)
                        targs=({objid});
                else    targs+=({objid});
                kill[myid]=targs;
                remove_call_out("remove_list");
                call_out("remove_list",1,myid,objid);
                }
        }
if(just_issued==0) 
        message_vision("\n$N对着$n喝道：「" + callname + "！今日不是你死就是我活！」\n\n", me,who);      
else    {
        write("\n你对着"+who->name()+"喝道：「"+ callname + "！今日不是你死就是我活！」\n\n");
        return 1;
        }
if ( who->query_temp("protected")
  && objectp(guard_ob=present(who->query_temp("protect_ob"), this_object()))
  && guard_ob->query_temp("protect")==who->query("id")
  && guard_ob!=me ) 
        {
        message_vision(HIC"$N对着$n大声说：有我在此，不用担心！\n"NOR,guard_ob,who);
        message_vision(HIC"$N冲上前去挡住了$n的攻击。\n"NOR, guard_ob,me);
        guard_ob->kill_ob(me);
        me->kill_ob(guard_ob);
        }
me->kill_ob(who);       
who->kill_ob(me);
tell_object(who, HIR "如果你要和" + me->name() + "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
return 1;
}

void destruct_npc(object who)
{
if ( who )
        destruct(who);
}                       

void victim_penalty(object victim)
{
int i;
int combat_exp_loss = 8000;
int dx_loss = 50000;
combat_exp_loss = combat_exp_loss/2+random(combat_exp_loss/2);
dx_loss = dx_loss/2+random(dx_loss/2);
victim->clear_condition();
victim->set("bellicosity", 0);
i = victim->query_condition("no_pk_time");
if ( i>240 ) 
        victim->apply_condition("no_pk_time",i-80);
//不加，不能用毫毛恢复  
//victim->set("death/mud_age",victim->query("mud_age"));
victim->set("death/combat_exp_loss",combat_exp_loss);
victim->set("death/dx_loss",dx_loss);
log_file("death",victim->query("id")+" lost "+combat_exp_loss+" exp points and "+ dx_loss+ " dx points.\n");
victim->add("combat_exp", -combat_exp_loss);
victim->add("daoxing", -dx_loss);
victim->delete("vendetta");
if ( victim->query("thief") )
        victim->set("thief",victim->query("thief")/2);
victim->set("death/skill_loss",0);
victim->save();
tell_object(victim,"你损失了"+combat_exp_loss+"点武学以及"+COMBAT_D->chinese_daoxing(dx_loss)+"道行。\n");
}

int victim_lose(object killer,object victim) 
{            
int lose,ap,dp;
if ( !present(killer,environment(victim)) )
        lose = 0;
else    {
        ap = killer->query("daoxing");
        dp = victim->query("daoxing");
        lose = dp-ap;
        if ( lose<0 )
                lose = random(2);
        if ( lose>dp/100 )
                lose = dp/100;
        if ( lose>100000 )
                lose = 100000;
        lose = lose/2+random(lose/2);
        }
return lose;
}                

void alternative_die(object who)
{
int lose,no_pk,gain;    
object target;
string str;
if ( !who )     return; 
target = who->query_temp("last_damage_from");
who->remove_all_killer();
who->remove_all_enemy();
all_inventory()->remove_killer(who);
all_inventory()->remove_enemy(who);
who->powerup();
message_vision("$N「啪」的一声倒在地上，挣扎着抽动了几下就死了。\n",who);
if ( target )   message_vision("$N被$n杀死了！\n",who,target);
if ( !userp(who) )
        {
        who->move("/obj/empty");
        remove_call_out("destruct_npc");
        call_out("destruct_npc",1+random(3),who);
        return;
        }
if ( target && userp(target) && present(target,environment(who)) )
        {       
        no_pk = target->query_condition("no_pk_time");
        target->apply_condition("no_pk_time",240+no_pk);
        lose = victim_lose(target,who);
        gain = lose/10*8;
        if ( gain<0 )   gain=0;
        if ( gain>100000 )  gain = 100000;
        gain = gain/2+random(gain/2)+1;
        who->delete_temp("last_fainted_from");
        if ( lose>100 )
                target->delete("kill/last_killer");
        target->add("kill/pkgain",gain);
        target->add("daoxing",gain);
        who->set("kill/last_killer",target->query("id"));
        who->set("kill/last_lose",gain);
        str = COMBAT_D->chinese_daoxing(gain);
        if ( strlen(str)>1 ) 
                str = "，"+target->name(1)+"得到"+str+"道行！";
        else    str = "！";                
        str = who->name(1)+"被"+target->name(1)+"吃掉了"+str;
        CHANNEL_D->do_channel(this_object(), "rumor",str);
        }
victim_penalty(who);
message_vision("一阵浓雾飘来，将$N的尸身缓缓沉入云层中去！\n\n",who);
who->move("/d/dntg/sky/tianhe",2);
message_vision("\n\n半空中云层一分，$N从空中落将下来！\n\n",who);
if ( random(100)>who->query("kar") ) 
        who->unconcious();
}
