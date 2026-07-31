
inherit NPC;

void create()
{
   set_name("江淮军",({ "bing" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是合肥的江淮军，经常四处巡逻。\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set("per", 22);
//   set("guard","hefei");
	set("combat_exp", 310000);
	set("shen_type", 1);

    set("max_neili",3500);
    set("neili",3500);
    set("qi",3500);
    set("eff_qi",3500);
    set("max_qi",3500);

    set("jing",3500);
    set("eff_jing",3500);
    set("max_jing",3500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 200);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object("/d/city/npc/obj/gangdao")->wield();
  
}

void init()
{
	object *ob,here,me;int i;
	me=this_object();
	here=environment(me);
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{
	
     if(ob[i]->query("killer")==me->query("guard"))
		call_out("kill_killer",1,ob[i],me);
	 else if((int)ob[i]->query("beipan",1)>=3)
		call_out("kill_pantu",1,ob[i],me);
	}
	return;
}

void kill_pantu(object ob,object ob2)
{
	if(!ob||!ob2) {remove_call_out("kill_pantu");return;}
	message_vision("$N朝$n冷笑道:象你这种多个势力的叛徒，休想逃走!\n",ob2,ob);
    ob2->kill_ob(ob);
	remove_call_out("kill_pantu");
	return;
}
void kill_killer(object ob,object ob2)
{
	if(!ob||!ob2) {remove_call_out("kill_killer");return;}
	ob2->kill_ob(ob);
	remove_call_out("kill_killer");return;
}