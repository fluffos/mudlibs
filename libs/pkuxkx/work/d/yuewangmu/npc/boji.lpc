//生死相搏
//made by mudy

inherit NPC;
#include <ansi.h>
#include <command.h>


void create()
{
      set_name("竞技者",({"boji zhe","zhe"}));
        set_weight(60000000);
        set("age", 20+random(40));
        set("attitude", "heroism");
     setup();
}

int do_kill(string arg)
{
object me;
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


    me->set("jiali",0);
me->set("neili",me->query("max_neili"));
        hp_status = me->query_entire_dbase();
                zhe->set("str", hp_status["str"]);
                zhe->set("int", hp_status["int"]);
                zhe->set("con", hp_status["con"]);
                zhe->set("con", hp_status["dex"]);
                zhe->set("max_qi",    hp_status["max_qi"]*10);
                zhe->set("eff_qi",    hp_status["eff_qi"]*10);
                zhe->set("qi",        hp_status["qi"]*10);
                zhe->set("max_jing",  hp_status["max_jing"]*10);
                zhe->set("eff_jing",  hp_status["eff_jing"]*10);
                zhe->set("jing",      hp_status["jing"]*10);
                zhe->set("max_neili", hp_status["max_neili"]);
                zhe->set("neili",     hp_status["neili"]);
//                zhe->set("jiali",     hp_status["jiali"]);
                zhe->set("jiali",     0);
                zhe->set("combat_exp",hp_status["combat_exp"]/10*(me->query_temp("xiangbo_level")+3));
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
if(me->query_temp("weapon"))
{
  weapon=new(base_name(me->query_temp("weapon")));
 weapon->set("weapon_prop/damage", weapon->query("weapon_prop/damage")/2+random(level)/2);
weapon->set("owner",query("id"));
 weapon->set("value",0);
 weapon->set("no_get",1);
 weapon->set("no_give",1);
 weapon->set("no_drop",1);
 weapon->set("no_store",1);
weapon->move(zhe);

command("wield all");
}

if(me->query_temp("secondary_weapon"))
{
  weapon=new(base_name(me->query_temp("secondary_weapon")));
 weapon->set("weapon_prop/damage", weapon->query("weapon_prop/damage")/2);
weapon->set("owner",query("id"));
 weapon->set("value",0);
 weapon->set("no_get",1);
 weapon->set("no_give",1);
 weapon->set("no_drop",1);
 weapon->set("no_store",1);
weapon->move(zhe);
command("wield all");
}

if(armor=me->query_temp("armor"))
{
pname=keys(armor);
for(i=0;i<sizeof(armor);i++)
{
ar=new(base_name(armor[pname[i]]));
ar->set("value",0);
ar->set("no_get",1);
ar->set("no_drop",1);
ar->set("no_give",1);
ar->set("no_store",1);
ar->set("owner",query("id"));
ar->move(zhe);
}

command("wear all");
}
                message( "channel:" + "chat",HIR + "【生死竞技】" + me->query("name") + "在竞技场开始生死竞技！\n"NOR,users());
return 0;
}

void init()
{
add_action("do_kill","kill");
add_action("do_change","steal");
add_action("do_perform","perform");
add_action("do_fill","fill");
add_action("do_hit","hit");
add_action("do_hit","fight");
add_action("do_hit","hitall");
add_action("do_change","wield");
add_action("do_change","wear");
add_action("do_change","unwield");
add_action("do_change","remove");
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
add_action("do_change","rumor");
add_action("do_change","hslj");
add_action("do_change","sys");
add_action("do_change","drink");
add_action("do_change","eat");
add_action("do_change","full");
add_action("do_change","quit");
add_action("do_change","halt");
return;
}
int do_hit(string arg)
{
   write(HIR"想试试？要试就下kill！没胆量别来！\n"NOR);
  return 1;
}
int do_change(string arg)
{
   write(HIR"生死相搏，岂能儿戏？\n"NOR);
  return 1;
}
void unconcious()
{
int qi;
qi=this_object()->query("qi");
if(qi<10)
{
die();
return;
}
else
{
this_object()->set("qi",qi-qi/10);
return;
}
}
int do_perform(string arg)
{
if(!this_object()->is_fighting())
{
write(HIR"还没开始打，你做什么？\n"NOR);
return 1;
}
else
return 0;
}
int do_fill()
{
object me;
me=this_player();
if(me->is_busy()) 
{
write(HIC"你现在正忙着呢！\n"NOR);
return 1;
}
me->set("neili",me->query("max_neili"));
me->start_busy(5);
write(HIR"你调整气息，使内力充盈！\n"NOR);
return 1;
}
void die()
{
 object zhe,me;
int exp,potential;
zhe=this_object();
me=this_player();
exp=(300-(time()-zhe->query("begin_time")))*(me->query_temp("xiangbo_level")+3)*(me->query("combat_exp")/800000.0);
if(me->query_temp("weapon")) exp=exp*2;
if(exp<1) exp=1;
potential=exp/20;
if (potential<1) potential=1;
message_vision(HIR"$N被奖励了"+chinese_number(exp)+"点经验和"+chinese_number(potential)+"点潜能！\n"NOR,me);
me->add_temp("xiangbo_level",1);
message( "channel:" + "chat",HIR + "【生死竞技】" + me->query("name") + "在竞技场中第"+chinese_number(me->query_temp("xiangbo_level"))+"场竞技获得成功！\n"HIB
        +me->query("name")+"仅花"HIY+chinese_number(time()-zhe->query("begin_time"))+HIB"秒击败对手！\n"NOR,users());
write(HIR"你看到对手在你面前慢慢的倒下，鲜红的血从他的身体下流出来，你长嘘了一口气。\n\n旁边来了几位大汉一声不吭地将尸体抬走了\n");
destruct(this_object());
return ;
}
