#include <ansi.h>
inherit NPC;

void create()
{
      string weapon;

        set_name("护镖镖师", ({ "hubiao biaoshi", "biaoshi"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("str", 28);
        set("con", 23);
        set("int", 15);
        set("dex", 26);
        set("long", "镖局的镖师。\n");
        set("combat_exp", 75000 + random(30000)); 
        set("attitude", "friendly");

        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jian", 50); 
        map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");
         
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);

        weapon = random(2)?"/clone/weapon/changjian1":"/clone/weapon/blade";
        setup();
        carry_object(weapon)->wield();
        carry_object(ARMOR_D("junfu"))->wear();
}

void init()
{
        int i, a;
        object ob, me;
        ob = this_object();
        me = this_player();
      if(me->query_temp("xx_rob")){
        a = me->query_temp("j")-1;
        if(a < 2) a=2;
        message_vision(HIR"突然从商队后窜出一个$N，二话不说就扑向了$n！\n"NOR, ob, me);
        me->add_temp("biaoshi", 1);
        ob->set("combat_exp", ob->query("combat_exp")*a);
        ob->set_skill("force", 60+(10*a));
        ob->set_skill("sword", 60+(10*a));
        ob->set_skill("blade", 60+(10*a));
        ob->set_skill("dodge", 90+(10*a));
        ob->set_skill("parry", 90+(10*a));
        ob->set_skill("qingmang-jian", 90+(10*a));       
        ob->set_skill("taizu-quan", 60+(10*a)); 
        if(present("blade", ob)) 
          ob->map_skill("blade", "qingmang-jian");
        ob->set("max_qi", 700+(50*a)); 
        ob->set("eff_jingli", 400+(50*a)); 
        ob->set("neili", 700+(50*a)); 
        ob->set("max_neili", 700+(50*a));
        ob->set("jiali", 30);
        ob->reincarnate(); 
        ob->kill_ob(me);
        call_out("checking", 3, ob);
        }      
        remove_call_out("do_back");
        call_out("do_back", 350,  ob);  
}
int checking(object me)
{
        if (me->is_fighting())
 	{
	call_out("checking", 2, me);
        return 1;
	}
        remove_call_out("do_back");
  	call_out("do_back", 5, me);
	return 1;
}
void do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"转身几个起落就不见了。\n", ({me}));	
  destruct(me); 
  return;
}
void unconcious()
{    
      command("fly");        
      do_back(this_object());       
}
void die(){ do_back(this_object()); }