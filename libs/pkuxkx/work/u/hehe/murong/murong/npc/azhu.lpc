//azhu.c
//by hehe
//2003.3.13

#include <ansi.h>

string ask_mg();
string ask_ml();
string ask_hm();

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("阿朱", ({ "a zhu", "azhu", "zhu" }));
	set("long",
	"她是慕容复的贴身丫鬟\n"
    "她看起来十多岁，容貌秀丽，别有一番可人之处。\n");
    set("gender", "女性");
    set("age", 20);      
	set("title",RED"姑苏慕容" + HIB"侍女"NOR);
	set("str", 25);
    set("int", 26);
    set("con", 26);
    set("dex", 26);
    set("combat_exp", 13000);
    set("shen_type", 1);
    set("attitude", "peaceful");
	set("max_qi",1000);
    set("max_jing",1000);
    set("neili",1000);
    set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

    set_skill("cuff", 70);
	set_skill("finger", 70);
	set_skill("sword", 70);
	set_skill("blade", 70);
	set_skill("parry",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	
	set_skill("canhe-zhi",70);
	set_skill("murong-daofa",70);
	set_skill("murong-jianfa",70);
	set_skill("yanling-shenfa",70);
    set_skill("shenyuan-gong",70);

	map_skill("finger","canhe-zhi");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    setup();

	create_family("姑苏慕容" , 4, "弟子");
	set("mg_count",1);
	set("ml_count",1);
	set("hm_count",1);
    
    carry_object(__DIR__"obj/shoe")->wear();
    carry_object(__DIR__"obj/cloth1")->wear();
    set("inquiry", ([
		"玫瑰花露" : (:ask_mg:),
		"茉莉花露" : (:ask_ml:),
		"寒梅花露" : (:ask_hm:),
        "name" : "我是慕容公子的贴身丫鬟，叫做阿朱，好久没有见到慕容公子了。\n",
        "here" : "这里是听香水榭，是慕容老爷为了照顾我给我安排的住处。\n",
        "曼佗罗山庄" : "曼佗罗山庄的王姑母这一阵子不让外人去她的山庄，连我们都不敢。\n",
        "慕容复" : "慕容复是我们燕子坞的主人，以以彼之道，还施彼身而天下闻名。\n",
		"花露" : "你想清楚要什么花露，再来找我吧!\n"
	]));           
}

string ask_mg()
{
	mapping fam; 
	object ob;
	if (!(fam = this_player()->query("family") ) || (fam["family_name"]!="姑苏慕容"))
	return RANK_D->query_respect(this_player()) +
	"你非本派弟子，也来偷窥我的宝物，简直是笑话！";
	if (query("mg_count") < 1)
	return "现在我这没有玫瑰花露。";
	add("mg_count",-1);
	ob = new(__DIR__"obj/meigui");
	ob->move(this_player());
	return "我这滴玫瑰花露你就拿去吧。";
}
string ask_ml()
{
	mapping fam; 
        object ob;
	if (!(fam = this_player()->query("family") ) || (fam["family_name"]!="姑苏慕容"))
	return RANK_D->query_respect(this_player()) +
	"你非本派弟子，也来偷窥我的宝物，简直是笑话！";
	if (query("mg_count") < 1)
	return "现在我这没有茉莉花露。";
	add("mg_count",-1);
	ob = new(__DIR__"obj/moli");
	ob->move(this_player());
	return "我这滴茉莉花露你就拿去吧。";
}
string ask_hm()
{
	mapping fam; 
        object ob;
	if (!(fam = this_player()->query("family") ) || (fam["family_name"]!="姑苏慕容"))
	return RANK_D->query_respect(this_player()) +
	"你非本派弟子，也来偷窥我的宝物，简直是笑话！";
	if (query("mg_count") < 1)
	return "现在我这没有寒梅花露。";
	add("mg_count",-1);
	ob = new(__DIR__"obj/hanmei");
	ob->move(this_player());
	return "我这滴寒梅花露你就拿去吧。";
}