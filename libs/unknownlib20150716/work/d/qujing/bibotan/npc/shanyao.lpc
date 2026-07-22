inherit NPC;
void create()
{
	int i = 30+random(20);
        set_name("山妖", ({"shan yao", "yao"}));
        set("long", "一个凶神恶煞般的山妖。\n");
        set("age", 30);
        set("attitude", "herosim");
        set("gender", "男性");
	set("class", "yaomo");
	set_level(i);
        set("per", 10);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);

	set("eff_dx", -20000);
        set("nkgain", 200);

        set("force_factor", 20);
        set("mana_factor", 10);
        set_skill("unarmed",i*10);
        set_skill("force",i*10);
        set_skill("spells",i*10);
        set_skill("dodge",i*10);
	set_skill("parry",i*10);
	set_skill("blade",i*10);
	set_skill("wuhu-blade",i*10);
	map_skill("blade", "wuhu-blade");
	map_skill("parry", "wuhu-blade");
        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
	carry_object("/d/obj/weapon/blade/kandao")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 40, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
	
	command("look " + ob->query("id") );
	command("say 又白又胖，刚好让老子下酒！");
	command("chan " + ob->query("id") );
	kill_ob(ob);
	ob->fight_ob(this_object());

	return;
}