#include <ansi.h>
inherit NPC;

int do_copy(object me);
int do_back(object me);

void create()
{
	string weapon;
        set_name("护镖镖师", ({ "hubiao biaoshi", "biaoshi"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 25);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "镖局的镖师。\n");
        set("combat_exp", 80000 + random(40000)); 
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
        map_skill("blade", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");         
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/blade";
        setup();
        carry_object(weapon)->wield();
        carry_object(ARMOR_D("junfu"))->wear();
}

int do_back(object me)
{                       
  	tell_room(environment(me), me->query("name")+"跳出战圈，转身几个起落就不见了。\n", ({me}));	
  	destruct(me); 
  	return 1;
}
void unconcious()
{            
      	do_back(this_object());       
}

void die(){ do_back(this_object()); }

int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}

int do_copy(object me)
{
        int i;
        object ob = this_object();

	if(!me->query_temp("xx_rob")){
      	   	do_back(me);
      	   	return 0;
      	}

	i = me->query("max_pot") - 100;
	i = i - random(15);

	message_vision(HIR"突然从商队后窜出一个$N，二话不说就扑向了$n！\n"NOR, ob, me);
	me->add_temp("xx2/biaoshi", 1);

	ob->set("combat_exp", me->query("combat_exp")/10*9);
	ob->set_skill("force", i);
	ob->set_skill("sword", i);
	ob->set_skill("blade", i);
	ob->set_skill("dodge", i);
	ob->set_skill("parry", i);
	ob->set_skill("qingmang-jian", i);       
	ob->set_skill("taizu-quan", i); 
	ob->set("max_qi", 1000+me->query("max_qi")/2); 
	ob->set("eff_jingli", 1000+me->query("eff_jingli")/2); 
	ob->set("max_neili", 1000+me->query("max_neili")/2); 
	ob->set("jiali", me->query("jiali")+20);
	ob->reincarnate(); 
	ob->set("target", me);
	ob->kill_ob(me);
	checking(ob, me);    
	call_out("do_back", 350,  ob);  
        
	return 1;
}

void kill_ob(object ob)
{
	object me = this_object();

	if(!objectp(me->query("target"))
	 || (me->query("target") != ob)){
		me->remove_enemy(ob);
		ob->remove_killer(me);
		return;
	}
	::kill_ob(ob);
}

void fight_ob(object ob)
{
	if ( ob != query("target"))
		ob->remove_killer(this_object());
	else
		::fight_ob(ob);
}
