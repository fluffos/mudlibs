//abi.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_sword();

void create()
{
	set_name("阿碧", ({ "a bi", "abi", "bi" }));
	set("long",
	"她是慕容复的贴身丫鬟\n"
    "她看起来十多岁，容貌秀丽，别有一番可人之处。\n");
	set("gender", "女性");
	set("age", 20);      
	set("title",RED"姑苏慕容"NOR + HIB"侍女"NOR);
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

	create_family("姑苏慕容" , 4, "弟子");
    setup();

    carry_object(__DIR__"obj/shoe")->wear();
    carry_object(__DIR__"obj/skirt")->wear();
    set("inquiry", ([
		"name" : "我是慕容公子的贴身丫鬟，叫做阿碧，好久没有见到慕容公子了。\n",
        "here" : "这里是琴韵小筑，是慕容老爷为了照顾我给我安排的住处。\n",
        "曼佗罗山庄" : "曼佗罗山庄的王姑母这一阵子不让外人去她的山庄，连我们都不敢。\n",
        "慕容复" : "慕容复是燕子坞的主人，你找我们家公子什么事?\n",
		"听香剑" : (: ask_sword :),
	]));           
}
int ask_sword()
{
	object me,ob;
	me = this_player();

	if(me->query("family/family_name")!="姑苏慕容")
	{
		command("say 你不是我们姑苏慕容的弟子，也想要剑，也不害臊！\n");
		return 1;
	}
	if(me->query("str")<20)
	{
		command("say 阁下的臂力太低，这把剑不太适合你用吧!\n");
		return 1;
	}
	if(me->query("combat_exp")<2000000)
	{
		command("say 阁下江湖阅历还是太浅，再去多历练一下再来吧！\n");
		return 1;
	}
	command("say 好吧，这把“听香剑”就交给你保存吧！\n");
	ob = new("/d/murong/obj/ting-jian");
	ob->move(me);
	return 1;
}
