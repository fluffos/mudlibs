inherit NPC;
#include <ansi.h>

void create()
{
	set_name("冯锡范", ({ "feng xifan", "feng" }) );
	set("nickname", HIR"一剑无血"NOR);
	set("gender", "男性");
	set("age", 45);
	set("long",
		 "冯锡范是延平王府卫队长，武夷派第一高手，一张白湛湛的面皮。\n"
		 "台湾战败后归降朝廷，被封为一等忠臣伯。");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 6400);
	set("max_neili", 6400);
	set("jiali", 30);
	set("max_qi",12000);
	set("max_jing",11200);

	set("shen_type", -1);
	set("combat_exp", 5000000);

	set_skill("hand", 180);
	set_skill("sword", 160);
	set_skill("cuff", 180);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("literate", 100);
	set_skill("liancheng-jian", 380);
	set_skill("changquan", 370);


	map_skill("sword", "liancheng-jian");
	map_skill("parry", "liancheng-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	create_family("武夷派", 3, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

