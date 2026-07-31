
// fang.c 

inherit NPC;

void create()
{
	set_name("方人智", ({ "fang renzhi", "fang", "renzhi" }));
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「青城派」年轻一代弟子，以智计为师尊喜爱。\n");

	set("combat_exp", 50000);
	set("shen_type", -1);

	set_skill("sword", 50);
	set_skill("pixie-jian", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	create_family("青城派", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
