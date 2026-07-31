// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("全冠清", ({"quan guanqing", "quan", "guanqing"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位沉默寡言却颇有心计的阴毒的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

          set("max_qi", 1000);
          set("max_jing", 1000);
          set("neili", 1400);
          set("max_neili", 1400);
          set("jiali", 70);
	
        set("combat_exp", 400000);
	
          set_skill("force", 102); 
          set_skill("huntian-qigong", 102); 
          set_skill("unarmed", 102); 
          set_skill("dodge", 102); 
          set_skill("xiaoyaoyou", 102); 
          set_skill("parry", 102); 
            set_skill("strike", 102); 
            set_skill("xianglong-zhang", 102); 
          set_skill("staff", 102); 
          set_skill("begging", 100); 
          set_skill("training", 100);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
          map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
        prepare_skill("strike", "xianglong-zhang");
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( ob->query("con") < 20 ) return;
	command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
	command("recruit " + ob->query("id"));
	ob->set("title", "丐帮一袋弟子");
}
//#include "/kungfu/class/gaibang/gaibang.h"
