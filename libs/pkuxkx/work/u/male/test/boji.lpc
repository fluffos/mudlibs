//生死相搏
//made by mudy

inherit NPC;
inherit F_SSERVER;
#include <ansi.h>
#include <command.h>
#define JINGJIZHIWANG "/u/male/test/jingjizhiwang"


void consider();
void create()
{
      set_name("竞技者",({"boji zhe","zhe"}));
        set_weight(60000000);
set("unwield",0);
        set("age", 20+random(40));
    set("chat_chance_combat", 100);
 set("chat_msg_combat", ({
    (: consider() :)
       }) );
        set("attitude", "heroism");
        set("time_fill", 0);
        set("time_perf", 0);
     setup();
}

int do_kill(string arg)
{
object me;
object* inv;
int level;
mapping armor;
object weapon,ar;
mapping hp_status, skill_status, map_status, prepare_status;
string *sname, *mname, *pname;
int i, temp;
object zhe;
zhe=this_object();
me=this_player();
level=me->query_temp("xiangbo_level");
if(arg!="boji zhe"&&arg!="zhe")
{
write (HIY"搏击场地，只能和搏击者以生死相搏！\n");
return 1;
}
if(zhe->is_fighting()) 
{
write (MAG"这里不准帮手！\n"NOR);
return 1;
}
       zhe->set("time_perf", 0);
       zhe->set("time_fill", 0);
if(me->query_condition("jingji"))
{
//write (MAG"你刚竞技过，又来？不好吧？\n"NOR);
zhe->add("time_perf",me->query_condition("jingji")*10);
//return 1;
}
 inv = all_inventory(zhe);
for (i=0;i<sizeof(inv);i++)
{
      weapon = inv[i];
destruct(weapon);
}
zhe->set("begin_time",time());
        if ( mapp(skill_status = zhe->query_skills()) ) {
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        zhe->delete_skill(sname[i]);
                }
        }
        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                for(i=0; i<sizeof(skill_status); i++) {
                        zhe->set_skill(sname[i], skill_status[sname[i]]+random(level-4)*2);
                }
        }


        if ( mapp(map_status = zhe->query_skill_map()) ) {
                mname  = keys(map_status);
                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        zhe->map_skill(mname[i]);
                }
        }
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);
                for(i=0; i<sizeof(map_status); i++) {
                        zhe->map_skill(mname[i], map_status[mname[i]]);
                }
        }


        if ( mapp(prepare_status = zhe->query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        zhe->prepare_skill(pname[i]);
                }
        }
        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                for(i=0; i<sizeof(prepare_status); i++) {
                        zhe->prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

        zhe->reset_action();

    me->set("jiali",0);
me->set("neili",me->query("max_neili"));
        hp_status = me->query_entire_dbase();
                zhe->set("str", hp_status["str"]+random(11)-5);
                zhe->set("int", hp_status["int"]);
                zhe->set("con", hp_status["con"]+random(11)-5);
                zhe->set("con", hp_status["dex"]+random(11)-5);
                zhe->set("max_qi",    hp_status["max_qi"]*12);
                zhe->set("eff_qi",    hp_status["max_qi"]*12);
                zhe->set("qi",        hp_status["max_qi"]*12);
                zhe->set("max_jing",  hp_status["max_jing"]*12);
                zhe->set("eff_jing",  hp_status["max_jing"]*12);
                zhe->set("jing",      hp_status["max_jing"]*12);
                zhe->set("max_neili", hp_status["max_neili"]);
                zhe->set("neili",     hp_status["max_neili"]);
//                zhe->set("jiali",     hp_status["jiali"]);
                zhe->set("jiali",     0);
                zhe->set("combat_exp",hp_status["combat_exp"]/10*(me->query_temp("xiangbo_level")+4));
/*
if(query_temp("weapon"))
{
destruct(zhe->query_temp("weapon"));
zhe->delete_temp("weapon");
}
if(zhe->query_temp("second_weapon"))
{
destruct(zhe->query_temp("secondary_weapon"));
zhe->delete_temp("secondary_weapon");
}
if(armor=zhe->query_temp("armor"))
{
 pname=keys(armor);
 for(i=sizeof(armor)-1;i>=0;i--)
{
   destruct(armor[pname[i]]);
}
zhe->delete_temp("armor");
}
*/
                inv = all_inventory(me);
               for (i=0;i<sizeof(inv);i++)
                   {
                     weapon=new(base_name(inv[i]));
                        weapon->move(zhe);
                 }
if(me->query_temp("weapon"))
{
//  weapon=new(base_name(me->query_temp("weapon")));
if(!objectp(weapon=present(me->query_temp("weapon")->query("id"),zhe))) return 1;
 weapon->set("weapon_prop/damage", weapon->query("weapon_prop/damage")/2+random(level)/2);
weapon->set("owner",query("id"));
 weapon->set("value",0);
 weapon->set("no_get",1);
 weapon->set("no_give",1);
 weapon->set("no_drop",1);
 weapon->set("no_store",1);
//weapon->move(zhe);
weapon->wield();

//command("wield all");
}
else
{
 set("unwield",1);
}

if(me->query_temp("secondary_weapon"))
{
//  weapon=new(base_name(me->query_temp("secondary_weapon")));
if(!objectp(weapon=present(me->query_temp("secondary_weapon")->query("id"),zhe))) return 1;
 weapon->set("weapon_prop/damage", weapon->query("weapon_prop/damage")/2);
weapon->set("owner",query("id"));
 weapon->set("value",0);
 weapon->set("no_get",1);
 weapon->set("no_give",1);
 weapon->set("no_drop",1);
 weapon->set("no_store",1);
//weapon->move(zhe);
weapon->wield();
//command("wield all");
}

if(armor=me->query_temp("armor"))
{
pname=keys(armor);
for(i=0;i<sizeof(armor);i++)
{
//ar=new(base_name(armor[pname[i]]));
if(!objectp(ar=present(armor[pname[i]]->query("id"),zhe))) return 1;
ar->set("value",0);
ar->set("no_get",1);
ar->set("no_drop",1);
ar->set("no_give",1);
ar->set("no_store",1);
ar->set("owner",query("id"));
//ar->move(zhe);
ar->wear();
}

//command("wear all");
me->apply_condition("jingji",6);
}
/*
                inv = all_inventory(me);
               for (i=0;i<sizeof(inv);i++)
                   {
                     weapon=new(base_name(inv[i]));
                        weapon->move(zhe);
                 }
*/
                message( "channel:" + "chat",HIR + "【生死竞技】" + me->query("name") + "在竞技场开始生死竞技！\n"NOR,users());
                zhe->set_temp("apply/damage",  me->query_temp("apply/damage")/3*2);
zhe->kill_ob(me);
me->kill_ob(zhe);
return 1;
}

void init()
{
add_action("do_kill","kill");
add_action("do_change","steal");
add_action("do_change","get");
add_action("do_change","drop");
add_action("do_change","abandon");
add_action("do_change","part_abandon");
add_action("do_perform","perform");
add_action("do_yun","yun");
add_action("do_yun","exert");
add_action("do_change","force");
add_action("do_change","cemote");
add_action("do_fill","fill");
add_action("do_hit","hit");
add_action("do_hit","fight");
add_action("do_hit","hitall");
add_action("do_wield","wield");
add_action("do_wear","wear");
add_action("do_unwield","unwield");
add_action("do_remove","remove");
add_action("do_change","jiali");
add_action("do_change","drop");
add_action("do_change","enable");
add_action("do_change","jifa");
add_action("do_change","bei");
add_action("do_change","wbei");
//add_action("do_change","call");
add_action("do_change","summon");
add_action("do_change","goto");
add_action("do_change","fly");
add_action("do_change","chat");
add_action("do_change","chat*");
add_action("do_change","rumor*");
add_action("do_change","rumor");
add_action("do_change","hslj");
add_action("do_change","sys");
add_action("do_change","drink");
add_action("do_change","eat");
add_action("do_change","full");
add_action("do_change","enforce");
add_action("do_change","fullall");
add_action("do_quit","quit");
add_action("do_change","halt");
return;
}
int do_hit(string arg)
{
   write(HIR"想试试？要试就下kill！没胆量别来！\n"NOR);
  return 1;
}
int do_quit(string arg)
{
object me;
me=this_player();
if(random(10)<7)
{
me->start_busy(1);
return 1;
}
                message( "channel:" + "chat",HIR + "【生死竞技】" + me->query("name") + "灰溜溜地逃离了竞技场！\n"+me->query("name")+"竞技失败！\n"NOR,users());
me->set("neili",0);
return 0;
}
int do_change(string arg)
{
   write(HIR"生死相搏，岂能儿戏？\n"NOR);
  return 1;
}
int unconcious()
{
int qi;
int damage;
object me;
me=this_player();
qi=this_object()->query("qi");
if(qi<10)
{
die();
return 1;
return 1;
}
else
{
damage=qi/10;
if(damage<me->query("max_neili")/10)
    damage=me->query("max_neili")/10;
this_object()->set("qi",qi-damage);
return 1;
}
}
void consider()
{
 object *enemy,target;
 enemy = query_enemy() - ({ 0 });
 target = enemy[random(sizeof(enemy))];
if(target->query("qi")<1) target->die();
}
int do_perform(string arg)
{
string perf,name1,name2;
int damage;
object me;
me=this_player();
if (me->is_busy())
{
write(HIR"你正忙着呢！\n"NOR);
this_object()->add("time_perf",3);
return 1;
}
if(!this_object()->is_fighting()||!this_player()->is_fighting())
{
write(HIR"还没开始打，你做什么？\n"NOR);
return 1;
}
else
{
this_object()->add("time_perf",1);
this_object()->set_temp("last_damage_from",this_player());
//if(random(10)==1)
if(random(this_object()->query("combat_exp")/3)>random(this_player()->query("combat_exp"))&&!this_object()->is_busy())
{
if(random(40)==1)
{
//sscanf(arg,"%s %s %s",perf,name1,name2);
if(sscanf(arg,"%s %s %s",perf,name1,name2)!=3)
if(sscanf(arg,"%s %s",perf,name1)!=2)
if(sscanf(arg,"%s",perf)!=1)
 return 1;
command("perform "+perf+" "+this_player()->query("id"));
//write ("perform "+perf+" "+this_player()->query("id"),this_player());
return 1;
}
message_vision(HIR"竞技者料敌机先看出了$N的企图，反而将$N的攻势反弹回去！\n"NOR,me);
damage=me->query("max_qi")/(2+random(4));
me->add_query("qi",0-damage);
me->start_busy(2+random(4));
return 1;
}
return 0;
}
}
int do_fill()
{
object me;
me=this_player();
if(!me->is_fighting()) return notify_fail("没竞技的人，不能fill\n");
if(me->is_busy()) 
{
write(HIC"你现在正忙着呢！\n"NOR);
return 1;
}
this_object()->add("time_fill",1);
me->set("neili",me->query("max_neili"));
me->start_busy(5);
write(HIR"你调整气息，使内力充盈！\n"NOR);
return 1;
}
int do_yun(string arg)
{
object me;
me=this_player();
if(!this_object()->is_fighting()||!this_player()->is_fighting())
{
write(HIR"还没开始打，你做什么？\n"NOR);
return 1;
}
else
{
if(arg=="recover"&&arg=="regenerate")
return 0;
else
{
this_object()->add("time_perf",1);
return 0;
}
}
}
int do_remove(string arg)
{
start_busy(0);
this_object()->start_busy(0);
command("remove "+arg);
//write("remove "+arg,this_player());
return 0;
}
int do_wear(string arg)
{
start_busy(0);
command("wear "+arg);
//write("wear "+arg,this_player());
return 0;
}
int do_unwield(string arg)
{
start_busy(0);
command("unwield "+arg);
set("unwield",1);
return 0;
}
int do_wield(string arg)
{
start_busy(0);
command("wield "+arg);
return 0;
}
void die()
{
string lines;
 object zhe,me;
int exp,potential,exp1,my_exp,time_limit,dt,e,j,t,level;
int coefficient;
zhe=this_object();
//me=this_player();
//me=offensive_target(zhe);
me=zhe->query_temp("last_damage_from");
if(!me) me=offensive_target(zhe);
/*
coefficient=me->query("max_qi")/1200;
if(coefficient<1) coefficient=1;
exp=(300*coefficient-(time()-zhe->query("begin_time")))*(me->query_temp("xiangbo_level")+3)*(me->query("combat_exp")/6000000.0/coefficient);
*/
my_exp=me->query("combat_exp");
if(my_exp<1000)
{
exp1=my_exp/10+1;
}
else if(my_exp<10000)
exp1=my_exp/90*19-111;
else if(my_exp<100000)
  exp1=my_exp/45+1778;
else if(my_exp<1000000)
  exp1=my_exp/225+3556;
else if(my_exp<10000000)
  exp1=my_exp/1125+7111;
else if(my_exp<100000000)
  exp1=my_exp/5625+14222;
else if(my_exp<1000000000)
  exp1=my_exp/28125+28444;
else
  exp1=my_exp/140625+56889;
time_limit=me->query("max_qi")/4;
dt=time_limit/5;
t=time()-zhe->query("begin_time");
if(t<dt)
e=exp1/2*3-exp1/2/dt*t;
else if(t<dt*3)
e=exp1/6*7-exp1/6/dt*t;
else if(t<dt*5)
e=exp1/3*5-exp1/3/dt*t;
else
e=1;
level=me->query_temp("xiangbo_level");
if(level<9)
j=e/8*(level+1);
else
j=e/2+e/16*level;
exp=j/100*(100-zhe->query("time_fill"));// /100*(100+zhe->query("time_perf")/5);
exp=exp/5*3;
if(zhe->query("time_perf")==0) zhe->set("time_perf",1);
j=(t*10/zhe->query("time_perf")-15)*10;
if(j<-90) j=-90;
if(j>0) j=j/5;
if(j>200) j=200;
exp=exp/100*(100+j);
if(me->query_temp("weapon")||!zhe->query("unwield")) exp=exp/2*3;
if(exp<1) exp=1;
if(exp<me->query_temp("last_exp")/10*9) exp=me->query_temp("last_exp")/10*9;
potential=exp/40;
if (potential<1) potential=1;
message_vision(HIR"$N被奖励了"+chinese_number(exp)+"点经验和"+chinese_number(potential)+"点潜能！\n"+HIY"你的奖励只有出去jifen方才有效!\n"NOR,me);
me->add_temp("xiangbo_level",1);
message( "channel:" + "chat",HIR + "【生死竞技】" + me->query("name") + "在竞技场中第"+chinese_number(me->query_temp("xiangbo_level"))+"场竞技获得成功！\n"HIB
        +me->query("name")+"仅花"HIY+chinese_number(time()-zhe->query("begin_time"))+HIB"秒击败对手！\n"NOR,users());
write(HIR"你看到对手在你面前慢慢的倒下，鲜红的血从他的身体下流出来，你长嘘了一口气。\n\n旁边来了几位大汉一声不吭地将尸体抬走了\n"NOR);
rm(JINGJIZHIWANG);
write_file(JINGJIZHIWANG,sprintf("%s %d",me->query("name"),me->query_temp("xiangbo_level")),0);
me->set_temp("last_exp",exp);
me->add_temp("jingji_exp",exp);
me->add_temp("jingji_potential",potential);
destruct(this_object());
return ;
}
