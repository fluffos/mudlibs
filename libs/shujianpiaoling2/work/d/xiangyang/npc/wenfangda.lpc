// /d/city/npc/wenfangda

inherit NPC;
 
void create()
{
	set_name("温方达", ({ "wen fangda", "wen" }));
	set("nickname", "温家五老");
	set("long", 
        "他就是温家五老的老大温方达。\n"
        "一个精瘦的老者，一双眼睛露出狡猾的目光。\n");
	set("gender", "男性");
	set("age", 66);
	set("attitude", "friendly");
	set("shen", -10000);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2000);
	set("max_jing", 1800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	 

    set_skill("force", 150);
    set_skill("yijin-jing", 150);
    set_skill("dodge", 150);

    set_skill("shaolin-shenfa", 150);
    set_skill("cuff", 150);
    set_skill("wenjia-daofa", 160);
    set_skill("parry", 150);
    set_skill("blade", 150);
    set_skill("wenjia-quan", 150);
    set_skill("literate", 110);

	map_skill("force", "yijin-jing");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-daofa");
  	map_skill("blade", "wenjia-daofa");
       prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade1")->wield();  	 
     
}