// NPC: /d/huashan/npc/shidaizi.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
	set_name("施戴子", ({ "shi daizi", "shi", "daizi" }));
	set("long",
"施戴子身材高挑，长的普普通通，但双眼炯炯有神，他在\n"
"同门中排行第四，是华山派年轻一代中的好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 20);
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
	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("blade", 100);
	set_skill("strike", 100);
	set_skill("zixia-gong", 100);
	set_skill("huashan-jianfa", 100);
	set_skill("huashan-shenfa", 100);
	set_skill("zhengqi-jue", 100);

	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 14, "弟子");

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}
