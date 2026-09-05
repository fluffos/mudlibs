// guo.c 郭靖
#include <ansi.h>
inherit NPC;
int ask_zhou();
int ask_jing();
void create()
{
	set_name("郭靖",({"guo jing","guo"}));
	set("nickname",RED"北侠"NOR);
	set("long","他就是人见人敬的北侠郭靖."
"他看起来三十多岁.\n");
	set("str",30);
	set("con",28);
	set("int",20);
	set("dex",29);
	set("gender","男性");
	set("shen_type",1);
	set("attitute","frieldly");
	set("age",37);
	set("max_qi",4000);
	set("qi",4000);
	set("max_neili",2500);
	set("neili",2500);
	set("max_jing",2000);
	set("jing",2000);
	set("jiali",150);
	set("combat_exp",2000000);
	set("score",500000);
	set_skill("force",200);
	set_skill("quanzhen-xinfa",200);
	set_skill("dodge",200);
	set_skill("panyun-gong",200);
	set_skill("parry",200);
	set_skill("sword",200);
	set_skill("quanzhen-jian",200);
	set_skill("strike",200);
	set_skill("xianglong-zhang",200);
	set_skill("cuff",200);
	set_skill("kongming-quan",200);
	set_skill("literate",150);
	map_skill("force","quanzhen-xinfa");
	map_skill("dodge","panyun-gong");
	map_skill("parry","quanzhen-jian");
	map_skill("sword","quanzhen-jian");
	map_skill("strike","xianglong-zhang");
	map_skill("cuff","kongming-quan");
	prepare_skill("strike","xianglong-zhang");
	set("inquiry",([
	"九阴真经" : (: ask_jing :),
	"周伯通" : (: ask_zhou :),
	]));

setup();
carry_object("d/city/obj/cloth")->wear();
}
int ask_zhou()
{
	mapping fam;
	object ob;
	ob=this_player();
	if((int)ob->query_temp("marks/周1")&&(int)ob->query_temp("marks/经"))
	{
	say("周大哥在山脚下的那个山洞里。\n");
	ob->set_temp("marks/周",1);
	ob->set_temp("marks/枝",0);
	ob->set_temp("marks/坑",0);
	return 1;
	}
	else
	{
	say("你怎么会知道周大哥在这里呢？\n");
	return 0;
	}
}

int ask_jing()
{
	mapping fam;
	object ob=this_player();
	if(!(fam=this_player()->query("family")) || fam["family_name"]!="桃花岛")
	{
	say("你怎么会知道真经的事呢？\n");
	return 0;
	}
	else
	{
	say("九阴真经，周大哥那好象有一本吧。\n");
	ob->set_temp("marks/经",1);
	return 1;
	}
}

