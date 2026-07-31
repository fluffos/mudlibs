inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("谢琳", ({ "xie lin","girl", "dizi" }));
	set("age", 16);
	set("gender", "女性");
	set("attitude", "peaceful");
       set("title","雁荡小师妹");
	set("str", 34);
	set("dex", 36);
	set("combat_exp", 10000);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
set_skill("thunderwhip",380);
set_skill("cloudstaff",380);
set_skill("deisword",380);
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
        map_skill("sword","deisword");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
set_skill("luoyan-jianfa",280);
   create_family("雁荡派",3,"弟子");
	set("inquiry", ([
		"花" : "是三师兄送来的,我......",
		"flower" : "是三师兄送来的,我......",
		]) );	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
	carry_object(__DIR__"obj/hongmeigui");
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