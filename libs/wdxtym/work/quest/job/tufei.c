#include <ansi.h>
inherit NPC;
void create()
{
      string weapon;
        set_name("土匪", ({ "tufei"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("eff_neili", 8000);
        set("max_neili", 8000);
        set("dex", 23);
        set("long", "山西劫匪。\n");
        set("combat_exp", 1080000 + random(4000000)); 
       
        set("no_quest", 1);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(180));
        
//        set_temp("apply/attack", 20);
//        set_temp("apply/defense",20);
//        set_temp("apply/armor", 20);
//        set_temp("apply/damage", 20);
        set_skill("zixia-shengong",100);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
        }) );
 
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
//        map_skill("blade","fanliangyi-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
}

void checking(object ob)
{
        object me = this_object();
        int i;
//        object ob;
        ob = this_object();
//	mapping hp_status, skill_status, map_status, prepare_status;
//	string *sname, *mname, *pname;
//	int i, temp;

        if( !ob || !present(ob, environment(this_object())) || !present("biao yin", ob) ) {
                if(ob == query_leader() )       set_leader(0);
                return;
        }

        command("say "+ob->name()+"，把镖银留下，放你走路！！\n");
        set_leader(ob);

//        kill_ob(ob);
//        ob->fight_ob(me);
//        command("kill "+ob->query("id") );


        ob->set("str", me->query("str"));
        ob->set("dex", me->query("dex")*2);
        ob->set("per", me->query("per"));
        ob->set("qi", me->query("qi")* 3/4);
        ob->set("eff_qi", me->query("eff_qi")* 3/4);
        ob->set("jing", me->query("jing")* 3/4);
        ob->set("neili", me->query("neili")* 3/4);
        ob->set("max_neili", me->query("max_neili")* 3/4);
        ob->set("eff_jing", me->query("eff_jing")* 3/4);
if (me->query_skill("force",1)>10)
{
        ob->set_skill("kuang-jian",me->query_skill("force",1)/2);
        ob->set_skill("sword",me->query_skill("force",1)/2);
        ob->set_skill("parry",me->query_skill("force",1)/2);        
}
        ob->set("combat_exp",me->query("combat_exp")* 3/4);

        ob->kill_ob(me);
        me->kill_ob(ob);
        ob->set_leader(me);
//        kill_ob(ob);
//        ob->fight_ob(me);

}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB+name()+"急急忙忙地走开了。\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
}
