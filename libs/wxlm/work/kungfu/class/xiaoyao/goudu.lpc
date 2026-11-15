// goudu.c
// shilling 97.2

inherit NPC;
inherit F_GUARDER;



string ask_me();

void create()
{
	set_name("苟读", ({ "gou du", "gou" }));
	set("long", 
		"他看上去也是几十岁的人了，却是纯然一个书呆子的模样。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);

	set("inquiry", ([
		"论语":(:ask_me:),
	]) );

	set("max_qi", 1800);
	set("max_jing", 1800);
       set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 30);
	set("combat_exp", 150000);

	set_skill("blade",80);
	set_skill("ruyi-dao",80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("hand", 80);
	set_skill("parry", 80);
	set_skill("feiyan-zoubi", 80);
	set_skill("xiaoyao-xinfa",80);
	set_skill("zhemei-shou", 80);
	set_skill("literate", 150);

	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("force", "xiaoyao-xinfa");
	map_skill("blade", "ruyi-dao");

	prepare_skill("hand", "zhemei-shou");

	set("coagents", ({
	       ([ "startroom" : "/d/xiaoyao/shishi",
		  "id"	: "xiaoyao zi" ]),
	}));

	set("book_count", 1);

	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","书呆子");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();

}

string ask_me()
{
	object me, ob, book;

	ob = this_player(); 

	me = this_object();

	if (ob->query("family/master_id") == "xiaoyao zi" && !ob->query_temp("xiaoyao_lunyu"))
	{
		call_other("/clone/book/lbook4", "???");
		book = find_object("/clone/book/lbook4");
		if (! objectp(book) || environment(book))
			return "你来晚了，那本《论语》我已经赠送给别入了。";

		command("say 师叔想要《论语》，拿去就是。");
		message_vision(HIY "$N" HIY "从怀里掏出一本旧书，交了给$n" HIY "。"NOR"\n",
			       me, ob);
		book->move(ob, 1);
                ob->set_temp("xiaoyao_lunyu",1);
		return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
	}

	if (query("book_count") < 1)
		return "我现在手头没有什么书了。";

	add("book_count", -1);
	command("say 哈哈，《论语》就没有了，这里有我派高手从少林盗来的书。");
	command("say 既然你那么好学，我就把它送给你吧。\n");
	message_vision(HIY "$N" HIY "翻箱倒柜找了半天，找出一本旧书，交了给$n" HIY "。"NOR"\n",
		       me, ob);
	if (random(2) == 1)
		book = new("/clone/book/strike_book");
	else
		book = new("/clone/book/book-paper");
	book->move(ob, 1);
        ob->set_temp("xiaoyao_lunyu",1);
	return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
}

void reset()
{
	set("book_count", 1);
}
