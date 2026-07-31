// danqing-sheng.c 

inherit NPC;

void create()
{
	set_name("丹青生", ({ "danqing sheng", "sheng" }));
	set("title", "梅庄四庄主");
	set("long",
		"他就是梅庄四位庄主排行第四的丹青生。\n"
		"身穿一件干干净净的青色长袍。\n"
		"他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 300000);

	set_skill("force", 100);
	set_skill("wuzheng-xinfa", 120);
	set_skill("dodge", 100);
	set_skill("piaoyibu", 110);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("wuyun-jianfa", 100);
	set_skill("literate", 130);

	map_skill("force", "wuzheng-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jianfa");
	map_skill("sword", "wuyun-jianfa");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
