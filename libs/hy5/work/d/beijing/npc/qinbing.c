// qingbing.c

inherit NPC;

void create()
{
	set_name("王府亲兵", ({ "qin bing", "bing" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "一名尽忠职守的亲兵，警惕的注视着过往的人。\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 23);

	set("shen_type", 1);

	set("combat_exp", 810000);
	set("shen_type", 1);

    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("taiji-shengong", 180+random(180));
        set_skill("kuang-blade", 280+random(180));
        map_skill("force", "taiji-shengong");
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );
	set_temp("apply/attack", 160);
	set_temp("apply/defense", 160);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
	carry_object("/d/kunming/npc/obj/gangdao")->wield();
	carry_object("/d/kunming/npc/obj/armor")->wear();
}


void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}