// hanxiaoyin.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("韩筱莹", ({ "han xiaoyin", "han" }));
	set("title", "江南七侠");
	set("nickname", HIR"越女剑"NOR);
	set("long", "她大约十八九岁年纪，身形苗条，大眼睛，皮肤如雪，露出一
头乌云般的秀发。正是江南水乡的人物。\n");
	set("gender", "女性");
	set("age", 18);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 6000);

	set_skill("force", 60);
	set_skill("taixuan-gong", 60);
	set_skill("dodge", 60);
	set_skill("lingxu-bu", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("sword", 60);
	set_skill("yunu-sword", 60);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed", "changquan");
	map_skill("sword", "yunu-sword");
	map_skill("parry", "yunu-sword");

	set("inquiry", ([
		"郭大侠" : "靖儿是我们的乖徒儿！\n",
		"江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
		"江南七怪" : "七怪也是你叫的？！\n",
		"丘玄机" : "丘道长豪侠仗义，是条汉子！\n",
		"柯震恶" : "那是我大哥。\n",
		"朱骢"   : "那是我二哥。\n",
		"韩天驹"   : "那是我三哥。\n",
		"南溪仁"   : "那是我四哥。\n",
		"张阿笙"   : "那是我五哥。\n",
		"全金髦"   : "那是我六哥。\n",
		"韩筱莹"   : "就是我了。\n",
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
