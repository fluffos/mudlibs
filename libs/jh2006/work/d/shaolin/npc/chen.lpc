// duan1.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("本尘", ({ "ben chen", "chen", "master" }) );
	set("nickname", "天龙寺老僧");
	set("gender", "男性" );
       	set("class", "bonze");
	set("age", 64);
	set("str", 30);
	set("cor", 27);
	set("cps", 32);
	set("int", 19);
         
	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 70);

	set("rank_info/respect", "高僧");

	set("long", 
	"这是位貌不惊人的，普普通通的老和尚。\n");
	create_family("天龙寺", 13, "弟子");

	set("combat_exp", 1200000);
	set("score", 200000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	(: perform_action, "sword.qian" :)
	}) );

    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("force", 150);
    set_skill("finger", 150);
      set_skill("buddhism", 100);
    set_skill("literate", 100);
    set_skill("duanjia-jianfa",180);
    set_skill("tianlong-shengong", 150);
    set_skill("yiyang-zhi", 150);
    set_skill("lingbo-weibu", 150);

    map_skill("dodge", "lingbo-weibu");
    map_skill("parry", "yiyang-zhi");
    map_skill("finger", "yiyang-zhi");
    map_skill("force", "tianlong-shengong");
    map_skill("sword","duanjia-jianfa");
    prepare_skill("finger","yiyang-zhi");
	set("inquiry", ([
	"name": "贫僧就是本尘",
	]) );

	setup();
	carry_object(__DIR__ "obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
    if(ob->query_int() < 25)
{
   command("say 学一阳指之人必须胆大心细，依我看" + RANK_D->query_respect(ob) + "的资质似乎不宜？");
		return;
	}
     if((int)ob->query_skill("buddhism",1)<100)
       {
         command("say 我段家武功与佛学息息相关，我看"+RANK_D->query_respect(ob)+"的禅宗修为似乎不够？");
          return;
        }
       if((int)ob->query_skill("tianlong-shengong",1)<100)
        {
          command("say 修练一阳指内功最为重要，我看"+RANK_D->query_respect(ob)+"似乎应在天龙神功上多下点功夫。");
          return;
        }
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
