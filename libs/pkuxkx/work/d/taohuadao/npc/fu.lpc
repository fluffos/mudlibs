// fu.c 郭芙
#include <ansi.h>
inherit NPC;
string ask_dan();
void create()
{
set_name("郭芙",({"guo fu","fu"}));
// 	set("nickname",RED"小东邪"NOR);
	set("long","她就是北侠郭靖的小女儿，是黄蓉的掌上明珠."
"她看起来十多岁，生得沉鱼落雁，闭月羞花。\n");
	set("str",27);
	set("con",30);
	set("int",30);
	set("dex",29);
	set("gender","女性");
	set("shen_type",1);
	set("attitute","frieldly");
	set("age",16);
	set("max_qi",2500);
	set("qi",2500);
	set("max_neili",1500);
	set("neili",1500);
	set("max_jing",1000);
	set("jing",1000);
	set("jiali",100);
	set("combat_exp",500000);
	set("score",200000);
	set_skill("force",120);
	set_skill("bihai-shengong",120);
	set_skill("dodge",120);
	set_skill("luoying-shenfa",120);
	set_skill("parry",120);
	set_skill("sword",120);
	set_skill("yuxiao-jian",120);
	set_skill("hand",120);
	set_skill("fuxue-shou",120);
	set_skill("finger",120);
	set_skill("tanzhi-shengong",120);
	set_skill("literate",200);
	map_skill("force","bihai-shengong");
	map_skill("dodge","luoying-shenfa");
	map_skill("parry","yuxiao-jian");
	map_skill("sword","yuxiao-jian");
	map_skill("hand","fuxue-shou");
	map_skill("finger","tanzhi-shengong");
	prepare_skill("finger","tanzhi-shengong");

	set("book_court",1);

	set("inquiry",([
	"无常丹" : (: ask_dan :),
	"杨过" : "你是说大哥哥吗。我也很久没有看见他了。",
	]));
	setup();
	carry_object(__DIR__"obj/lanchoushan")->wear();
}
string ask_dan()
{
	mapping fam;
	object ob;
	if(!(fam=this_player()->query("family")) || fam["family_name"]!= "桃花岛")
	return RANK_D->query_respect(this_player()) + 
	"你非桃花岛的人，从何提起此事。";
	if(query("book_court")<1)
	return("你来晚了，我现在没有无常丹。\n");
	add("book_court",-1);
	ob=new(__DIR__"obj/wuchang-dan");
	ob->move(this_player());
	return "好吧，这个无常丹你就拿去吧。"; 
}
