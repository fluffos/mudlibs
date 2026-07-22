inherit NPC;

void create()
{
        set_name("东方小二姐", ({ "dongfang sister", "dongfang", "sister"}) );
        set("gender", "女性");
        set_level(10);
        set("age", 16);
	set("per", 30);
        set("long", "东方小二姐是馆主的远房侄女，来傲来见见世面。\n");
	set_skill("sword", 100);
	set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("unarmed",80);
	set_skill("force", 60);
	set("chat_chance",5);
	set("chat_msg", ({
		"小二姐说道：我好喜欢花呦！\n",
		"小二姐说道：外面的花儿好香呦！\n",
	}) );
        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/pink_cloth")->wear();
	carry_object("/d/obj/cloth/bullboots")->wear();
}

int accept_object(object who,object ob)
{
        object m;
        if( ob->query("id")=="flower" && !ob->is_character() ) 
        {
                say("小二姐笑道：多谢"  + RANK_D->query_respect(who) + "，我真的好喜欢呦！\n");
                m = carry_object("/d/obj/book/forcebook");
                if( m )
                {
			command("whisper " + who->query("id") + " 我这里有舅公的一本书，你拿去看吧！\n");
        		m->move(who);
        	}	
		return 1;
        }
        return 0;
}