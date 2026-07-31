#include <ansi.h>
inherit NPC;

int do_copy(object me);
//int do_back(object me);

void create()
{
      string weapon;
        set_name("护镖镖师", ({ "biaoshi"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "镖局的镖师。\n");
        set("combat_exp", 1080000 + random(4000000)); 
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(180));
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);
        set_skill("zixia-shengong",100);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
        }) );
 
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
//        map_skill("blade","fanliangyi-dao");
        set("max_qi", 1600); 
        set("eff_jingli", 1600); 
        set("neili", 5000); 
        set("max_neili", 5000);
        set("jiali", 30);
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void die()
{
int i,pot,exp;
	object killer;
	exp= random(10)+8;
	pot= exp/5;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战修为\n"
		+chinese_number(pot)+"点潜能\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
	::die();

return ;
}
int checking(object ob, object me)
{
        if(!me || !present(me, environment())) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
//	if() do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}

int do_copy(object me)
{
        int i;
        object ob;
        ob = this_object();

      if(!me->query_temp("xx_rob")){
                call_out("checking", 5, ob);
//      	   do_back(me);
      	   return 0;
      	   }
        message_vision(HIR"突然从车队后窜出一个$N，二话不说就扑向了$n！\n"NOR, ob, me);
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
        me->add_temp("biaoshi", 1);
        
        ob->kill_ob(me);
	 me->kill_ob(ob);
        checking(ob, me);    
        call_out("leave", 350,  ob);  
        return 1;
}


void init()
{
        remove_call_out("leave");
        call_out("leave",500);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
