// /d/city/npc/wenfangwu

inherit NPC;
 
void create()
{
	set_name("温方悟", ({ "wen fangwu", "wen", "fangwu" }));
	set("title", "温家五老");
	set("long", 
        "他就是温家五老的最小的温方悟。\n"
        "一个貌不其扬的老者，脸上的皱纹显然比实际年龄要大。\n");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "friendly");
	set("shen", -9000);
	set("str", 30);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2000);
	set("max_jing", 1800);
	set("eff_jingli", 1800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 800000);
	 
	set_skill("force", 140);
	set_skill("yijin-jing", 140);
	set_skill("dodge", 150);

	set_skill("shaolin-shenfa", 140);
	set_skill("cuff", 140);
	set_skill("wenjia-daofa", 130);
	set_skill("parry", 140);
	set_skill("blade", 140);
	set_skill("wenjia-quan", 150);
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
