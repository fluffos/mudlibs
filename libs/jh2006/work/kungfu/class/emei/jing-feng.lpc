// /kungfu/class/emei/jing-feng.c
// Make by jackie 98.2

inherit NPC;
string ask_sword();
string ask_sword1();
string ask_drug();
string ask_yaodai(); 
void create()
{
	set_name("静风师太", ({
		"jingfeng shitai",
		"jingfeng",
		"shitai",
	}));
	set("long",
		"她是在华藏庵修行的师太，平时在储物间发放峨嵋派的练功武器及药品。\n"
	);


	set("gender", "女性");
	set("attitude", "friendly");
         set("unique", 1);
	set("class", "bonze");

	set("age", 45);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 35);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 550000);
	set("score", 100);

	set_skill("dacheng-fofa", 120);
	set_skill("linji-zhuang", 120);
	set_skill("huifeng-jian", 120);
	set_skill("sword", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("force", 120);
	set_skill("anying-fuxiang", 120);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
       	set("inquiry", 
                ([
			"长剑" : (: ask_sword :),
                        "皮腰带" : (: ask_yaodai :),
                        "软剑" : (: ask_sword1 :),
                        "天香断续膏" : (: ask_drug :)
]));
       	set("drug_count", 5);
       	set("sword_count",5);
        set("sword1_count" ,4);
	set("yaodai_count", 4);
	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}

string ask_sword()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (  present("changjian", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有长剑了嘛，怎么又来要了？ 真是贪得无餍！";

	if (query("sword_count") < 1) return "对不起，长剑已经被别人要光了。";

	ob = new("/d/emei/obj/changjian");
	ob->move(this_player());

	add("sword_count", -1);

	message_vision("$N得到一柄长剑。\n",this_player());
	return "拿去吧。不过要记住，武器只可防身练武，不可凭此杀害生灵。";

}

string ask_sword1()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (  present("ruan jian", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有软剑了嘛，怎么又来要了？ 真是贪得无餍！";

	if (query("sword1_count") < 1) return "对不起，软剑已经被别人要光了。";

	ob = new("/d/emei/obj/ruanjian");
	ob->move(this_player());

	add("sword1_count", -1);

	message_vision("$N得到一柄软剑。\n",this_player());
	return "拿去吧。不过要记住，武器只可防身练武，不可凭此杀害生灵。";

}

string ask_drug()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

    if (present("tianxiang duanxugao", this_player()))
        return RANK_D->query_respect(this_player()) + 
        "不是身上有吗？";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("tianxiang duanxugao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("drug_count") < 1) return "对不起，天香断续膏已经发完了";

	ob = new("/d/emei/obj/duanxu-gao");
	ob->move(this_player());

	add("drug_count", -1);

	message_vision("$N获得一包天香断续膏。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}

string ask_yaodai()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (  present("yao dai", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有皮腰带了嘛，怎么又来要了？ 真是贪得无餍！";

	if (query("yaodai_count") < 1) return "对不起，皮腰带已经被别人要光了。";

	ob = new("/d/emei/obj/yaodai");
	ob->move(this_player());

	add("yaodai_count", -1);

	message_vision("$N得到一个皮腰带。\n",this_player());
	return "拿去吧。不过要记住，防具只可防身练武，不可凭此妨害他人。";
}
