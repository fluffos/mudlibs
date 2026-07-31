#include <ansi.h>
inherit NPC;
#include "tree.h"

int is_no_look() { return 1; }

mapping actions = ([
        "$N枝干上泛起一层青光，开始反震$n的砍伐。"                              : 8 ,
        "$N枝干一阵抖动，一股暗劲悄悄的流向$n的双手。"                          : 6 ,
        "$N枝干上泛起一层青光，一股暗劲悄悄的流向$n的双手。"                    : 5 ,
        "$N枝干一阵抖动，开始反震$n的砍伐。"                                    : 5 ,                        
        "$N枝叶一阵抖动，居然好似有生命一般，暗含五行相克之效，反震$n的双手。"  : 6 , 
        "$N枝叶一阵抖动，居然好似有生命一般，一股暗劲悄悄的流向$n的双手。"      : 8 ,
]);             

void create()
{
set_name("桂树",({"gui shu","tree"}));  
set("gender","男性" );
set("age", 10000+random(10000));
set("limbs",({
        "枝叶","枝干","树干","树枝",
}));    

setup();
set_temp("apply_kee",1000);
set_temp("apply_max_kee",1000);
set_temp("apply/damage",120);
}

string long()
{
return "一棵高耸挺拔入云的桂树(tree)，周身上下流连着一股仙家之气。\n这便是月宫奇树月桂，相传吴刚被罚伐(fa)之，斧出而无痕，万年不倒。";
}       

void do_cancel(object who)
{
delete_temp("is_attacking");    
if ( who==this_object() )
        {
        die();
        return;
        }
else    {
        who->delete_temp("apply/short");
        if ( who->query_temp("apply/old_name") )
                who->set_temp("apply/short",who->query_temp("apply/old_name"));
        who->delete_temp("apply/old_name"); 
        if ( !who->query_temp("be_faint_by_tree") )
                {    
                message_vision("\n$n枝干上一阵婆娑，$N只觉手中一麻，大板斧脱手而出。不由一口真气逆转而上，一口鲜血破口！\n\n"NOR,who,this_object());
                who->set_temp("be_faint_by_tree",1);
                who->unconcious();
                }
        }
}                               

varargs int do_attacks(object me,object target,string result)
{
mapping my, your,act;
object weapon;
int damage;

my = me->query_entire_temp_dbase();
your = target->query_entire_temp_dbase();

if ( me==this_object() )
        weapon = target->query_temp("weapon");
else    weapon = me->query_temp("weapon");
if ( !weapon )
        return 0;
if ( !query_temp("is_attacking") )
        return 0;
                
// (1) Find out what action the offenser will take.
if ( me==this_object() )
        act = actions;
else    act = weapon->query_act();
if ( !act || !mapp(act) )
        return 0;
        
result = keys(act)[random(sizeof(keys(act)))];
damage = act[result];
damage+= random(my["apply/damage"]);
// (2) Prepare AP, DP for checking if hit.
if ( random(2)==1 ) 
        {
        if ( damage>0 ) 
                {
                your["apply_kee"]-= damage;
                if ( me==this_object() )
                        result+= "结果$n给震的两眼发花！\n";
                else    result+= "结果砍了个正着！\n";
                result+= damage_msg(target);
                }
        else    result = "结果没有什么反应。。。\n";
        }                                               
else    {
        result+= "结果没有什么反应。。。\n";
        message_vision(result,me,target);
        result = "";
        do_attacks(target,me);
        }
message_vision(result,me,target);
if ( my["apply_kee"]<=1 )
        {
        if ( environment(me)==environment(target) )
                me->set_temp("last_damage_from",target);
        do_cancel(me);
        }
if ( your["apply_kee"]<=1 )
        {
        if ( environment(me)==environment(target) )
                target->set_temp("last_damage_from",me);
        do_cancel(target);
        }
return 1;
}
                
void fights(object me, object victim)
{
if ( !me || !victim || !living(me) || !living(victim) 
  || environment(me)!=environment(victim) ) 
        return;
if ( me->query_temp("netdead") )  
        return;
if ( !me->visible(victim) )
        return;
if ( !query_temp("is_attacking") )
        return;
if ( victim->is_busy() 
  || victim->query_temp("no_move")
  || !living(victim) ) 
        do_attacks(me, victim);
else if ( random(5)==0 ) 
        {
        if ( me==this_object() )        
                message_vision(CYN"\n$N"CYN"仔细观察着$n"CYN"，寻找合适的下手处。\n"NOR,victim,me);
        else    message_vision(CYN"\n$N"CYN"仔细观察着$n"CYN"，寻找合适的下手处。\n"NOR,me,victim);  
        }
else    do_attacks(victim,me);
remove_call_out("fights");
call_out("fights",1+random(3),me,victim);
}

void fight_ob(object who)
{
if ( !who )  return;
remove_all_killer();
all_inventory(environment())->remove_killer(this_object());
if ( !query_temp("is_attacking") )
        return;
fights(this_object(),who);
}

void kill_ob(object who)
{
fight_ob(who);
return;
}

void walk3(object me,object wu)
{
if ( !me )
        return;
if ( !wu || !living(wu) || !present(me,environment(wu)) )
        {
        tell_object(me,"没有吴刚的带路，你只得望着昆仑林立的山脉长叹。\n");
        return;
        }
if ( environment(wu)->query("short")!="碎石路" )
        {
        wu->command("?");
        wu->command("say 真是对不起，时日已久，我一时间想不起了。。。。\n");
        return;
        }       
message_vision("$n伸手在山壁之上细细摸索了一下，忽地“喀喇”一声，山壁之上现出一个洞穴！\n",me,wu);
message_vision("$n连忙对$N说道：赶快进入，通过这个洞穴，后面就是昆仑深山了！\n",me,wu);
message_vision("$n说道：自作孽不可活，我还是回去砍我桂树去。。。。\n",me,wu);
message_vision("说罢，$n将$N往山洞内一推，急急忙忙的离开了。\n",me,wu);
me->move("/quest/blood/moon/start",1);
message_vision("\n\n洞内一阵狂风吹过，$N身不由己，眼前一花，已到了一个新的境地。\n\n",me);
destruct(wu);
}                               

void walk2(object me,object wu)
{
if ( !me )
        return;
if ( !wu || !living(wu) || !present(me,environment(wu)) )
        {
        tell_object(me,"没有吴刚的带路，你只得望着昆仑林立的山脉长叹。\n");
        return;
        }
wu->command("go west");
remove_call_out("walk3");
call_out("walk3",1+random(3),me,wu);
}                               

void job_walk(object me,object wu)
{
if ( !me )
        return;
if ( !wu || !living(wu) || !present(me,environment(wu)) )
        {
        tell_object(me,"没有吴刚的带路，你只得望着昆仑林立的山脉长叹。\n");
        return;
        }
wu->command("go west");
remove_call_out("walk2");
call_out("walk2",1+random(3),me,wu);
}                               

void die()
{
object xi,wu,me = query_temp("last_damage_from");
delete_temp("is_attacking");
set_temp("apply_kee",1000);
set_temp("apply_max_kee",1000);
if ( me && living(me) && present(me,environment()) )
        {
        message_vision("\n\n“轰隆”一声，挺立月宫万年之久的月桂树终于轰然倒地！\n\n",this_object());
        wu = present("wu gang",environment());
        if ( wu && living(wu) )
                {
                wu->command("thank");
                if ( time()<me->query("新任务/血池/吴刚伐桂")+18000 || wizardp(me) )
                        {
                    xi = find_object(__DIR__"xiwangmu");
                        if ( !xi )
                               xi = load_object(__DIR__"xiwangmu");
                        if ( xi && living(xi) )
                                {
                                CHANNEL_D->do_channel(wu,"chat",HIC+me->name(1)+NOR+HIC"助我砍倒桂树，真是莫大的功德。。。。\n"NOR); 
                                if ( environment(xi) )
                                        message("vision",xi->name(1)+"喃喃自语：真是气煞老身，既然有人擅自管我月宫之事！\n",environment(xi),xi);
                                CHANNEL_D->do_channel(xi,"chat",HIC"罪臣吴刚，当初弑炎帝之孙，今又勾结外人逃避刑罚，罪加一等！\n"NOR);
                                message_vision(HIG"\n半空中洒下几滴甘露，"+name()+"顿时又生机勃勃。。。。\n\n"NOR,me);
                                wu->command("sigh2");
                                wu->command("say 当初一时意气，落得今日下场。\n");
                                wu->command("say 时也命也，今得"+me->name(1)+"鼎力相助，无以为报，当初修道偶窥捷径于昆仑后山，\n"+RANK_D->query_respect(me)+"，请随我来。\n");
                                me->command("follow "+wu->query("id"));
                                me->start_busy(1);
                                wu->start_busy(1);
                                remove_call_out("job_walk");
                                call_out("job_walk",2,me,wu);                           
                                me->set("新任务/血池/吴刚伐桂",time());
                                }
                        }
                else    {
                        message_vision(HIG"\n半空中洒下几滴甘露，"+name()+"顿时又生机勃勃。。。。\n\n"NOR,me);
                        wu->command("die");
                        wu->command("sigh2");
                        }
                }
        }
message_vision("一阵大风刮过，挺立月宫万年之久的月桂树依然矗立不倒！\n",this_object());
}

void init()
{
add_action("do_fa","fa");
add_action("do_fa","kan");
add_action("do_fa","crash");
add_action("do_kill","kill");
add_action("do_cast","cast");
add_action("do_kill","fight");
add_action("do_cast","exert");
add_action("do_cast","ji");
}

int do_cast(string arg)
{
string id;
object me = this_player();
if ( arg && sscanf(arg,"%s on %s",arg,id) )
        {
        if ( id(id) )
                {
                write("看清楚一点，那并不是活物。\n");
                return 1;
                }
        }       
return 0;
}
int do_kill(string arg)
{
if ( arg && id(arg) )
        {
        write("看清楚一点，那并不是活物。\n");
        return 1;
        }
return 0;
}


int do_fa(string arg)
{
object wu,weapon,me=this_player();
weapon = me->query_temp("weapon");
if ( !weapon || base_name(weapon)!="/d/moon/obj/bigaxe" )
        {
        wu = present("wu gang",environment());
        if ( !wu )
                {
                write("月宫圣地岂能容你撒野？\n");
                return 1;
                }
        wu->command("say 大胆"+RANK_D->query_rude(me)+"，休得在广寒宫前撒野！");
        wu->kill_ob(me);
        return 1;
        }               
if ( !arg || !id(arg) || !wizardp(me) || me->query_temp("吴刚伐桂/xiwangmu") )
        return 0;
message_vision("$N举起"+weapon->name()+"开始砍树！\n",me);
this_object()->set_temp("is_attacking",1);
if ( me->query_temp("apply/short") )
        me->set_temp("apply/old_name",me->query_temp("apply/short"));
me->set_temp("apply_kee",me->query("kee"));
me->set_temp("apply_max_kee",me->query("max_kee"));
me->delete_temp("be_faint_by_tree");
this_object()->kill_ob(me);
return 1;
}

string short()
{
if ( query_temp("is_attacking") )
        return ::short()+HIR" <被伐中> "NOR;
else    return ::short();
}


varargs int receive_damage(string type, int damage, object who)
{
return 0;
}

varargs int receive_wound(string type, int damage, object who)
{
return 0;
}               
