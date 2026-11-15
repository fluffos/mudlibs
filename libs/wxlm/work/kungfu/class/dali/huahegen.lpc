// huahegen.c 华赫艮


inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("华赫艮", ({ "hua hegen", "hua" }));
	set("title",  "大理司徒" );
	set("long", @LONG
他是大理国三大公之一。华司徒本名阿根，出身贫贱，现今在大理国位列三公，未
发迹时，干部的却是盗墓掘坟的勾当，  最擅长的本领是偷盗王公巨贾的坟墓。这
些富贵人物死后，必有珍异宝物殉葬，华阿根从极远处挖掘地道，通入坟墓，然后
盗取宝物。所花的一和虽巨，却由此而从未为人发觉。有一次他掘入一坟，在棺木
中得到了一本殉葬的武功秘诀，依法修习，练成了一身卓绝的外门功夫，便舍弃了
这下贱的营生，辅佐保定帝，累立奇功，终于升到司徒之职。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_qi", 1800);
	set("max_jing", 900);
	set("neili", 2100);
	set("max_neili", 2100);
	set("jiali", 50);
	set("combat_exp", 430000);
	set("score", 10000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("parry", 80);
	set_skill("cuff", 95);
	set_skill("sword", 80);
	set_skill("staff", 80);
	set_skill("shaolin-xinfa", 80);
	set_skill("tiannan-step", 90);
	set_skill("jinyu-quan", 95);
	set_skill("duanjia-sword", 80);
	set_skill("literate", 60);

	map_skill("force", "shaolin-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("大理段家", 0, "武将");
}

