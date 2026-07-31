// NPC: /d/huashan/npc/liangfa.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
	set_name("梁发", ({ "liang fa", "liang", "fa" }));
	set("nickname", "闭嘴佛");
	set("long", 
"梁发身材高瘦，长的有点木呐，但人确极精明，他在\n"
"同门中排行第三，是华山派年轻一代中的好手。\n");
	set("gender", "男性");
	set("age", 29);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 23);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_qi", 3000);
	set("max_jing", 1800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("eff_jingli", 1800);

	set("jiali", 50);
	set("combat_exp", 400000);
	set("score", 4000);

	set_skill("force", 80);
	set_skill("zixia-gong", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	set_skill("strike", 80);
	set_skill("hunyuan-zhang", 80);
	set_skill("huashan-jianfa", 80);
	set_skill("poyu-quan", 80);
	set_skill("huashan-shenfa", 80);
	set_skill("zhengqi-jue", 100);

	map_skill("force", "zixia-gong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 14, "弟子");

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}
