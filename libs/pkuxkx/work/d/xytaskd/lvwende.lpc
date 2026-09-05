string ask_for_guojing();
inherit NPC;
void create()  
{	set_name("吕文德", ({ "lv wende","lv","lu" }));
	set("gender", "男性");
	set("age", 44);
	set("str", 15);
	set("dex", 16);
        set("long", "蒙古兵打过来，他已经吓的魂不附体了.\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);

	set("neili", 200); 
	set("max_neili", 200);
	set("jiali", 50);
        
        set("inquiry",([
                "郭靖"  : (: ask_for_guojing :),
        ]));


        set("chat_chance", 10);
        set("chat_msg", ({
       "吕文德问道: 郭大侠啊，我们守不守得住啊？\n",
       "吕文德盘算着：看来，我还是跑了的好！\n"
        }) );
        setup();
	carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/armor/tiejia")->wear();
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

string ask_for_guojing()
{
          return "要是没有他，我现在早走了！";
}



