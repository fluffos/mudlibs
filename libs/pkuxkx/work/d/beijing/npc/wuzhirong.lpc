inherit NPC;
string ask_leadership();
void create()
{
 	set_name("吴之荣", ({ "wu zhirong", "wu" ,"zhirong"}) );
 	set("gender", "男性" );
 	set("age", 40);
 	set("int", 28);
 	set("long",
 		"他原是归安县的知县，因贪赃枉法，百姓恨之切齿，终被告发革职。\n"
                +"他长得尖嘴猴腮，一看就知不是好人 。\n");
 	set("attitude", "peaceful");
 	set("shen_type", -1);
    	set("book_count", 1);
        set("str", 10);
 	set("int", 25);
 	set("con", 25);
 	set("dex", 25);
 	set("max_qi", 100);
 	set("max_jing", 100);
 	set("neili", 100);
 	set("max_neili", 100);
 	set("combat_exp", 5000);
 	set("score", 5000);
         set_skill("literate", 100);
    	set("inquiry", ([
//	"为官之道" : "我对可没有什么研究。",
	"兵法战策" : "我对行军打仗可没有什么研究。",
    	]));
 	setup();
 	carry_object("/clone/misc/cloth")->wear();
 	carry_object(__DIR__"obj/goldleaf");
}
/* string ask_leadership()
{
        object ob;
        if (this_player()->query("class") != "officer")
                return RANK_D->query_respect(this_player()) + 
                "与朝廷素无来往，不知此话从何谈起？";
        if (this_player()->query("pin") > 5)
                return "你官阶尚低，以后再来问我吧。";
        if (query("book_count") < 1)
                return "为官之道最重要的是皮厚心黑，不过「厚黑学」已经被人拿走了。";
        add("book_count", -1);
        ob = new(__DIR__"obj/book_houhei");
        ob->move(this_player());
        return "为官之道最重要的是皮厚心黑，这本「厚黑学」就送给大人吧。";
}
*/