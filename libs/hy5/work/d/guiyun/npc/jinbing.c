// jinbing.c

inherit NPC;

void create()
{
	set_name("大金兵", ({ "jin bing", "bing" }));
	set("gender", "男性");
	set("age", 25);
	set("long", "那些大汉个个虎背熊腰，甚是剽健。\n");
	set("combat_exp", 40000);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("apply/attack",  150);
        set_temp("apply/defense", 150);
	set("shen_type", 1);

 set("max_qi",3300+random(5690));
  set("max_jing",3300+random(5890));
  set("max_sen",3300+random(5890));
  set("max_neili",5000);
  set("max_mana",3300+random(5890));
  set("eff_neili",3300+random(5390));
  set("neili",5000);
        set("str", 35);
        set("per", 25);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.fanzhuan" :),
                (: perform_action, "club.fanzhuan" :),
                (: perform_action, "club.huimaqiang" :),
        }) );


        set_skill("unarmed", 180+random(380));
        set_skill("club", 180+random(380));
        set_skill("parry", 180+random(380));
        set_skill("dodge", 180+random(380));
        set_skill("zhong-qiang", 250+random(180));
        set_skill("taiji-shengong", 230+random(180));
	map_skill("club", "zhong-qiang");
	map_skill("parry", "zhong-qiang");
	map_skill("force", "taiji-shengong");
        set_temp("apply/attack", 60);
        set_temp("apply/defense",60);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 120);

	setup();

	add_money("silver",1);
	carry_object("/clone/weapon/changqiang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}



void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(100) < 1)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if( userp(ob[i]) && ob[i]->query("combat_exp") < 80000) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}