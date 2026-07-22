#include <ansi.h>
inherit NPC;

int mu();
string yuzhuo();

void create()
{
	set_name("正宫皇后", ({ "zhenggong huanghou", "zhenggong" ,"huanghou"}));
        set("title", "大理段氏");
	set("gender", "女性");
	set("age", 35);
	set("per", 29);
        set("unique", 1);
	set("count", 1);
	set("combat_exp", 5000);
        set("attitude", "friendly");
        set("rank_info/respect", "娘娘");
	set("long", 
        "她就是大理国的皇后，看上去气度雍容，端正贤慧，一副和蔼可亲的样子。\n");
	set("inquiry", ([
//	"木婉清" : (: mu :), 
//	"玉镯" : (: yuzhuo :),
	]) );
	setup();
	carry_object(__DIR__"obj/fengpao")->wear();
}

void kill_ob(object ob)
{	
        command("say 你不要后悔，皇上一定会为我报仇的！！！");
        ob->set_temp("killqueen",1);
}

int mu()
{
       command("ah");
       command("say 这位" + RANK_D->query_respect(this_player()) + "原来是木姑娘的朋友，失敬，失敬。");
//       this_player()->set_temp("mu",1);
       return 1;
}
	
string yuzhuo()
{
	object ob;
	ob = unew(__DIR__"obj/yuzhuo");
	if (!this_player()->query_temp("mu"))
	   return RANK_D->query_respect(this_player())+"与哀家素味平生，不知此话从何谈起？";
        if(!clonep(ob))
           return "我已把玉镯给了木姑娘了。";
         ob->set_temp("give_player", this_player()->query("id"));
	 ob->move(this_player());         
         this_player()->delete_temp("mu");
           return "请" + RANK_D->query_respect(this_player()) + "把这只玉镯带给木姑娘吧。";
}
