inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("花无邪", ({ "hua wuxie","girl", "dizi" }));
	set("age", 22);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 34);
	set("per", 26);
       set("title","雁荡三剑");
       set("nickname","慈心剑");
set("combat_exp", 1000000);
	set_skill("literate",150);
	set_skill("unarmed", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("force", 160);
set_skill("yiqiforce",380);
set_skill("luoriquan",380);
set_skill("luoyan-jianfa",280);
set_skill("kuangfeng-blade",380);
set_skill("qinnashou",380);
set_skill("cuff", 120);
set_skill("doomsword",380);
       set_skill("nei-bagua",180);
       set_skill("wai-bagua",180);
       set_skill("bagua-bu",180);

  set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("combat_exp", 10000000); 
        set_skill("taixuan-gong",280);
        map_skill("unarmed","luoriquan");
        map_skill("sword","doomsword");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
        map_skill("dodge","bagua-bu");

create_family("雁荡派",2,"弟子");
    set("chat_chance", 7);
	set("chat_msg", ({
		"各有所痴,哪也叫无可奈何!\n",
		
	}));
	setup();
       add_money("silver",60);
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if( (int)ob->query("PKS") > 10 ) 
        {
                command("hmm");
                command("say 你手上血腥浓重，怎能修身得道？\n");
                return;
        }
        if ( ob->query("gender") == "无性" )
        {
                command("heihei");
                command("say 你是一个阉割之人，怎能修身得道？\n");
                return;
        }

        command("recruit "+ob->query("id") );

}