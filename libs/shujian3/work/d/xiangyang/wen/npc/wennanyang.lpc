// /d/city/npc/wennanyang

inherit NPC;
 
void create()
{
	set_name("温南扬", ({ "wen nanyang", "wen", "nanyang" }));
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
	
	set("max_qi", 1000);
	set("eff_jingli", 800);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 200000);
	 

	set_skill("force", 110);
	set_skill("yijin-jing", 110);
	set_skill("dodge", 110);

	set_skill("shaolin-shenfa", 110);
	set_skill("cuff", 110);
	set_skill("wenjia-daofa", 110);
	set_skill("parry", 110);
	set_skill("blade", 110);
	set_skill("wenjia-quan", 110);
	set_skill("literate", 110);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "wenjia-quan");
	map_skill("parry", "wenjia-quan");
	map_skill("blade", "wenjia-daofa");
	prepare_skill("cuff", "wenjia-quan");

	setup(); 
	carry_object(ARMOR_D("cloth"))->wear();
}
