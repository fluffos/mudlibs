// tiger.c 老虎
inherit NPC;
void create()
{
set_name("老虎",({"lao hu","tiger","hu"}));
set("race","野兽");
set("age",10);
set("long","一只饥饿的老虎，凶猛无比。\n");
set("attitude","hateful");
set("limbs",({"头","身","脚","尾"}));
set("dex",30);
set("max_qi",1000);
set("str",35);
set("verbs",({"claw","bite"}));
set("combat_exp",50000);
set("shen_type",0);
set("condition", "killer");
set_temp("apply/attack",50);
set_temp("apply/defense",50);
set_temp("apply/armor",50);
set_temp("apply/damage",50);
set("shen_type",-1);
set("score",1000);
setup();
}
void init()
{
object ob;
::init();
if(interactive(ob=this_player())&&(ob->query("race")!="野兽"))
{
if( ob->query("combat_exp") > 5000 )
this_object()->set_leader(ob);
remove_call_out("do_killing");
call_out("do_killing", 4, ob);
 }
}
void do_killing(object ob)
{
if(!ob||environment(ob)!=environment()||environment(ob)->query("no_fight"))

return;
this_object()->kill_ob(ob);

}
void die()
{ 
object ob;
message_vision("$N凄惨地叫了几声，死了。\n",this_object());
ob=new(__DIR__"obj/hupi");
ob->move(environment(this_object()));
destruct(this_object());
}
