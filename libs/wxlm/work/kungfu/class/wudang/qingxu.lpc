// guxu.c 清虚

inherit NPC;
//inherit F_MASTER;

string ask_me();

void create()
{
	set_name("清虚道长", ({ "qingxu daozhang", "qingxu" }));
	set("long", 
		"他就是鱼莲舟的弟子清虚道长。\n"
		"他今年二十多岁，主管复真观的杂事。\n"
		"专门在这里看守本派的各种道经");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	
	set("max_qi", 1800);
	set("max_jing", 900);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);

	set("combat_exp", 70000);
	set("score", 8500);

	set_skill("force", 85);
	set_skill("wudang-xinfa", 85);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 80);
	set_skill("strike", 85);
	set_skill("wudang-zhang", 85);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("wudang-jian", 80);
	set_skill("taoism", 50);
  	set_skill("literate", 50);

	map_skill("force", "wudang-xinfa");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");
	map_skill("strike", "wudang-zhang");

	prepare_skill("strike", "wudang-zhang");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set("inquiry", ([
			"道德经" : (: ask_me :),
	]));
				
	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}


string ask_me()
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "武当派")
	{
		return RANK_D->query_respect(this_player()) + 
		       "与本派素无来往，不知此话从何谈起？";
	}

	if (query("book_count") < 1)
		return "你来晚了，本派的道德真经不在此处。";

	add("book_count", -1);
	ob = new("/clone/book/daodejing-ii");
	ob->move(this_player());
	return "好吧，这本「道德经」你拿回去好好钻研。";
}
