inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("谢璎", ({ "xie ying","girl", "dizi" }));
	set("age", 16);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","雁荡女弟子");
	set("combat_exp", 290000);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 220);
	set_skill("force", 120);
set_skill("thunderwhip",280);
set_skill("cloudstaff",280);
set_skill("deisword",280);
set_skill("shortsong-blade",280);
set_skill("pangu-hammer",280);
        set("shen_type",1);
        set_skill("luoyan-jianfa",280);
set_skill("thunderwhip",380);
set_skill("cloudstaff",380);
set_skill("deisword",380);
set_skill("luohua-jian",380);
set_skill("chuixue-jian",380);
set_skill("three-sword",380);
set_skill("shortsong-blade",380);
set_skill("pangu-hammer",380);
set_skill("ill-quan",280);
        set("shen_type",1);
                set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("combat_exp", 10000000); 
        set_skill("yiqiforce",280);
        map_skill("unarmed","ill-quan");
        map_skill("sword","luohua-jian");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
        
create_family("雁荡派",2,"弟子");
	setup();
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