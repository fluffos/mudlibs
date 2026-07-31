// huangzhong-gong.c

inherit NPC;

void create()
{
	set_name("黄钟公", ({ "huangzhong gong", "gong" }));
	set("title", "梅庄大庄主");
	set("long",
		"他就是梅庄四位庄主排行第一的黄钟公。\n"
		"身穿一件干干净净的黄色长袍。\n"
		"他已年愈六旬，身材中等，面容和蔼可亲。\n");
	set("gender", "男性");
	set("age", 62);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 1000000);

	set_skill("force", 200);
	set_skill("wuzheng-xinfa", 200);
	set_skill("dodge", 150);
	set_skill("piaoyibu", 150);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("wuyun-jianfa", 180);
	set_skill("literate", 150);

	map_skill("force", "wuzheng-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jianfa");
	map_skill("sword", "wuyun-jianfa");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
