#include <ansi.h>
inherit NPC;
string ask_leadership();
void create()
{
    int i, *speed_cur;

    set_name("丁大全", ({"ding daquan", "ding"}));
    set("title", HIR"大宋"+HIW+"  参知政事"+NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的副相丁大全。\n");
    set("attitude","heroism");
    set("generation",0);
	set("book_count", 1);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    create_family("朝廷", 2, "官员");

	set("inquiry", ([
	"五经" : (: ask_leadership :),
	"兵法战策" : "我对行军打仗可没有什么研究。",
    	]));
    setup();
    carry_object("/d/song/npc/obj/cloth1")->wear();
}

string ask_leadership()
{
	object ob;
	if (this_player()->query("class") != "officer")
	return this_object()->query("name")+"转过身去，忙别的事去了。\n";
	if (this_player()->query("pin") > 5)
	return "你官阶尚低，以后再来问我吧。";
	if (query("book_count") < 1)
	return "「周易」不知什么时候弄丢了。";
	add("book_count", -1);
	ob = new("/d/hangzhou/obj/books/book_leadership_4");

	ob->move(this_player());

	return "五经是做官的基础，这本「周易」你拿回去读读吧。";
}
