// longzuwushi.c 唐门武士

inherit NPC;

void create()
{
        set_name("龙组武士", ({ "longzu wushi", "wushi" }));
        set("long", 
                "他是唐门精心训练的武士，负责唐门的守护。\n"
                "如果有人擅闯唐门，格杀勿论！\n");
        set("gender", "男性");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);

        set("combat_exp", 70000);
        set("score", 8500);

        set_skill("force", 60);
        set_skill("biyun-xinfa", 60);
        set_skill("dodge", 70);
        set_skill("qiulinshiye", 50);
        set_skill("strike", 60);
        set_skill("biye-wu", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("wuzhan-mei", 40);
        

        map_skill("force", "biyun-xinfa");
        map_skill("dodge", "qiulinshiye");
        map_skill("strike", "biye-wu");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");

        create_family("唐门", 9, "弟子");
        set("class", "tangmen");

        setup();
        carry_object("/d/tangmen/obj/changjian")->wield();
        carry_object("/d/tangmen/obj/suozijia")->wear();
}


void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")

	&& ( (fam = ob->query("family")) && fam["family_name"] != "唐门" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say 我唐门且是外人随便闯入的？！\n");
			command("say 速速离开，否则杀了你！\n");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到唐门来里来捣乱！！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}