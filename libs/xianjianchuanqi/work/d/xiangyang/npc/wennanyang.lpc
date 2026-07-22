// /d/city/npc/wennanyang

inherit NPC;
 
void create()
{
	set_name("温南扬", ({ "wen nanyang", "wen" }));
	set("long", 
       "一个二十来岁的青年，身材匀称。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "friendly");
	set("shen", -2000);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 700);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 200000);
	 

    set_skill("force", 70);
    set_skill("yijin-jing", 70);
    set_skill("dodge", 70);

    set_skill("shaolin-shenfa", 70);
    set_skill("cuff", 70);
    set_skill("wenjia-daofa", 70);
    set_skill("parry", 70);
    set_skill("blade", 70);
    set_skill("wenjia-quan", 70);
    set_skill("literate", 70);

	map_skill("force", "yijin-jing");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-quan");
  	map_skill("blade", "wenjia-daofa");
       prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	 
     
}