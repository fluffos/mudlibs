//kylin.c 火麒麟
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"火麒麟"NOR,({"fire kylin","kylin"}));
        set("race","野兽");
        set("age",30);
        set("long",HIY"一只浑身燃烧着烈火的麒麟，凶猛无比。\n"NOR);
        set("attitude","hateful");
        set("limbs",({"头","身","脚","尾"}));
        set("dex",80);
        set("max_qi",4000);
        set("max_jing",6000);
        set("max_neili",4000);
       set("max_jingli",5000);
        set("jiali",150);
        set("str",80);
        set("verbs",({"claw","bite"}));
        set("combat_exp",3000000);
        set_skill("parry", 400);
         set_skill("dodge", 400);
        set_skill("force", 400);
        set_skill("unarmed", 400);
        
        set("shen_type",0);
        set("condition", "killer");
        set_temp("apply/attack",200);
        set_temp("apply/defense",150);
        set_temp("apply/armor",200);
        set_temp("apply/damage",200);
        set("shen_type",-1);
set("score",5000);
setup();
}
void init()
{
        object ob;
        ob = this_player();
         if ( userp( ob ) )
               if ( ob->query("race") != "野兽" )
        {
                call_out("do_killing", 5, ob);
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
        ob=new(__DIR__"obj/kylinpi");
        ob->move(environment(this_object()));
        destruct(this_object());
}
