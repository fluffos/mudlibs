// huyizhi.c 胡易之



inherit NPC;

string ask_me();
string ask_book();
string ask_hujia_book();

void create()
{
	set_name("胡易之", ({ "hu yizhi", "hu" }));
	set("gender", "男性");
	set("nickname", HIG "美刀王" NOR);
	set("age", 37);
	set("long", @LONG
这人胡子拉碴，头上裹着一围白巾，脚下踢着一双拖鞋，全然一副
乡农模样。
LONG );
	set("attitude", "peaceful");
	set("str", 36);
	set("int", 28);
	set("con", 31);
	set("dex", 33);
    
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 4200);
	set("max_neili", 4200);
	set("jiali", 100);
	set("combat_exp", 1700000);

	set_skill("force", 180);	    // 基本内功
	set_skill("lengyue-shengong", 180); // 冷月神功
	set_skill("blade", 180);	    // 基本刀法
	set_skill("baisheng-daofa", 180);   // 百胜刀法
	set_skill("dodge", 180);	    // 基本躲闪
	set_skill("taxue-wuhen", 180);      // 踏雪无痕
	set_skill("parry", 180);	    // 基本招架

	map_skill("force", "lengyue-shengong");
	map_skill("blade", "baisheng-daofa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "baisheng-daofa");

	set("inquiry", ([
		"百胜刀法": (: ask_me :),
		"美刀王"  : "美刀王已经死了，还提他做甚？",
		"陈圆圆"  : "唉！我也没能和她说上几句话...",
		"陈园园"  : "唉！我也没能和她说上几句话...",
	]));

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_me()
{
 object  me;

	me = this_player();
	if (me->query("family/family_name") != "关外胡家")
		return "这是在下擅长的本事，你要不要较量较量？\n";

	return "很好... 很好... 既然是胡家弟子，有没有兴趣学学我的百胜刀法？";
}

int recognize_apprentice(object ob, string skill)
{
	if (ob->query("family/family_name") != "关外胡家")
	{
		command("say 想偷学我们胡家绝技？嘿嘿...");
		return -1;
	}

	if (skill != "baisheng-daofa")
	{
		command("say 我只传你百胜刀法，其他还是找你师傅去学吧。");
		return -1;
	}

	if (! ob->query_temp("can_learn/huyizhi/baisheng-daofa"))
	{
		command("say 好！你看清楚了！");
		ob->set_temp("can_learn/huyizhi/baisheng-daofa", 1);
	}

	return 1;
}