// lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);
string ask_me();

void create()
{
	set_name("陆高轩", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("title", HIY"神龙教"NOR"军师");
	set("nickname",HIC "神机妙算" NOR);
	set("long", "他天庭饱满,地阔方圆,容貌颇为英俊.\n然而满面愁容,恰似顷刻间便有杀身之祸一般.\n" );
	set("gender", "男性");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
        set("qi",1500);
	set("max_jing",500);
        set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

        set_skill("force", 70);
	set_skill("shenlong-xinfa", 70);
        set_skill("dodge", 70);
	set_skill("yixingbu", 70);
        set_skill("hand", 70);
	set_skill("shenlong-bashi", 70);
        set_skill("parry", 70);
        set_skill("staff", 70);
	set_skill("shedao-qigong", 70);
	set_skill("literate", 70);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
	prepare_skill("hand", "shenlong-bashi");

	create_family("神龙教",2,"弟子");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老!永享仙福!寿与天齐!文武仁圣!\n",
		"秘籍" : (: ask_me :),
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "神龙教" NOR ) {
		command("say 你不是本教教众, 想来找死啊!");
		return;
	}
	if ((int)ob->query_skill("literate",1) < 40 ) {
		command("say 你的学问太低了,还是努努力先提高一下吧!");
		return;
	}
	if ((int)ob->query("shen") > -0  ) {
		command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "神龙教")
		return RANK_D->query_respect(this_player()) + 
		"与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本教的秘籍不在此处。";
	add("book_count", -1);
	if (random(2) == 0) ob = new("/clone/book/shoufa");
	else ob = new("/clone/book/bufa");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到"+ob->query("name")+"啦。\n");
	return "好吧，这本「"+ob->query("name")+"」你拿回去好好钻研。";
}
#include "/kungfu/class/shenlong/shenlong.h"; 
