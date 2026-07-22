inherit NPC;

void create()
{
        set_name("小兵", ({ "bing" }));
        set_level(15);
        set("age", 22);
        set("gender", "男性");
        set("long",
"这些兵士都是秦叔宝，程咬金等从部下中挑出来的精锐。\n");
        set("attitude", "peaceful");

        set("combat_exp", 10000);

        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("blade", 120);
        set_skill("force", 120);

        setup();
        carry_object(0,"armor",random(2))->wear();        
	carry_object(0,"kui",random(2))->wear();        
	carry_object(0,"shoes",random(2))->wear(); 
	carry_object(0,"pifeng",random(2))->wear();        	       
	carry_object(0,"blade",random(2))->wield(); 
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int accept_fight(object me)
{
        command("say 你活得不耐烦了？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

