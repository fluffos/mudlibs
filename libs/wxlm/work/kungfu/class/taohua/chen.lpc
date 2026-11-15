inherit NPC;

void create()
{
	set_name( "陈玄封" ,({ "chen xuanfeng", "chen" }));
	set("title", "黑风双煞");
	set("nickname", HIY"铜尸"NOR);
	set("gender", "男性");
	set("age", 35);
	set("long",
	    "此人是黄岛主的二弟子，他浓眉大眼，背厚膀宽，躯体甚是壮健，只是\n"
	    "面色微微泛黄。\n");

	set("attitude", "aggressive");
	set("str", 28);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	set("shen_type", -1);

	set("max_qi", 3900);
	set("max_jing",1900);
	set("neili", 4700);
	set("max_neili", 4700);
	set("jiali", 100);

	set("combat_exp", 1600000);

	set_skill("claw", 180);
	set_skill("strike", 180);
	set_skill("force", 160);
	set_skill("parry", 180);
	set_skill("dodge", 150);
	set_skill("cuixin-zhang", 180);
	set_skill("jiuyin-baiguzhao", 180);
	set_skill("luoying-xinfa", 160);
	set_skill("anying-fuxiang", 150);

	map_skill("force", "bibo-shengong");
	map_skill("parry", "luoying-shenjian");
	map_skill("dodge", "anying-fuxiang");
	map_skill("claw", "jiuyin-baiguzhao");
	map_skill("strike", "cuixin-zhang");

	prepare_skill("claw", "jiuyin-baiguzhao");
	prepare_skill("strike", "cuixin-zhang");

	create_family("桃花岛", 2, "被逐弟子");
	set("inquiry", ([
	   "铜尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
	   "东邪":     "那是我师父的绰号。",
	   "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
	   "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
	   "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
	   "洪九指":   "洪九指武功高强，而且教会郭大侠那小儿镇岳锁龙劲，可恨！",
	   "黄帮主":     "她是我师父的独女，最是刁蛮任性。",
	   "梅超封":   "她是我的师妹，也是我的内室。",
	   "陈玄封":   "不就是我么？你是白痴啊？",
	   "黄岛主":   "他是我师父。"]) );
	setup();
	carry_object("/clone/cloth/bupao")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 你少烦我，快滚！");
}

