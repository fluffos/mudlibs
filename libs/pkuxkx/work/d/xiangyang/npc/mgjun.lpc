inherit NPC;

void create()
{
        set_name("营门守军", ({ "shou jun","jun" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", 
            "他们个个盔甲鲜明，训练有素。\n");
        set("str", 20);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("blade", 55);    
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 20000);

        set("attitude", "peaceful");
        setup();
        carry_object(__DIR__"obj/junfu")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
}

void init()
{
        object me,ob;
        ::init();
        me=this_object();
        if (this_player()->query_temp("杀")){ 
          command("haha");
          command("kill " + this_player()->query("id"));
        }
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
                command("haha");
                this_player()->set_temp("杀",1);
	}
}





