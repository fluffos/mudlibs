// dizi6.c 吴坎 管理物品
// Modify By River@SJ
// Modified by snowman@SJ 22/11/2000
// 减少flood

#include <ansi.h>
inherit NPC;
int give_tools();
int give_gaotou();
void create()
{
	set_name("吴坎",({ "wu kan", "wu","kan" }) );
	set("title","襄阳武馆六弟子");
	set("gender", "男性" );
	set("age", 25);
	set("long"," 他是万震山的六弟子，精明强干，武馆的物品都是由他保管。\n");
	set("combat_exp", 4000);
	set("attitude", "friendly");

	set_skill("force", 40);
	set_skill("strike", 40);
	set_skill("sword", 40);

	set("inquiry", ([
		"工具" : (: give_tools :),
		"镐头" : (: give_gaotou :),
		"归还" : "把装备上的工具卸下直接给我就行了",
	]) );
	setup();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

int give_tools()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();
	if(ob->query_temp("mark/工具")){
		command("say 你已经领了工具了，还没还呢，怎么又来领了？");
		return 1;
	}
	if(ob->query_temp("mark/还了")){
		command("say 你还没覆命领新活吧，跑来要什么工具。");
		return 1;
	}
	if(!ob->query_temp("job_name")){
		command("say 你没跟大师兄领活吧，跑来要什么工具。");
		return 1;
	}
	switch( ob->query_temp("job_name") ){
		case "锄草":	tools = new(__DIR__"obj/chutou"); break;
		case "灌溉菜地":tools = new(__DIR__"obj/piao"); break;
		case "锯木头":	tools = new(__DIR__"obj/juzi"); break;
		case "劈柴":	tools = new(__DIR__"obj/chaidao"); break;
		case "挑水":	tools = new(__DIR__"obj/shuitong"); break;
		case "打扫马房":tools = new(__DIR__"obj/saozhou"); break;
		default:  return notify_fail(CYN+me->name()+"说道：「你跟大师兄领的什么活？我这里没这种工具。」"NOR"\n");
	}
	tools->set_temp("mark/name", ob->query("id"));
	tools->move(ob);
	ob->set_temp("tools_name", tools->query("name"));
	tell_object(ob, CYN+me->name()+"说道：「既然你已经领了活，我就给你这把工具，小心保管，别弄丢了。」"NOR"\n");
	message_vision("$N交给$n一"+tools->query("unit") + tools->query("name")+"。\n", me, ob);
	ob->set_temp("mark/工具",1);
	return 1;
}
int give_gaotou()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();
	if(present("gao tou",ob))
		return notify_fail("你已经有了啊。");
	tools = new(__DIR__"obj/chutou");
	tools->set("no_drop",1);
	tools->set("no_get",1);
	tools->set("no_give",1);
	tools->set_name("镐头", ({ "gao tou", "tou", "staff" }));
	tools->move(ob);
	tell_object(ob, CYN+me->name()+"说道：「我就给你这把工具，小心保管，别弄丢了。」"NOR"\n");
	message_vision("$N交给$n一"+tools->query("unit") + tools->query("name")+"。\n", me, ob);
	return 1;
}

int accept_object(object me, object obj)
{
       	object ob;
       	me = this_object();
       	ob = this_player();
       	if(!ob->query_temp("mark/工具")){
           	command("shake");
           	tell_object(ob, CYN+me->name()+"说道：「我没有发给你过东西，你是不是还错了？」"NOR"\n");
           	return 0;
       	}
       	if(!(ob->query_temp("mark/完了"))){
           	tell_object(ob, CYN+me->name()+"说道：「你还没完成工作，怎么就回来还工具了，偷懒吗？」"NOR"\n");
           	return 0;
       	}
       	if( obj->query_temp("mark/name") != ob->query("id")){
           	command("? "+ob->query("id") );
           	tell_object(ob, CYN+me->name()+"说道：「我给你的好象不是这样东西吧？」"NOR"\n");
           	return 0;
       	}
       	if((obj->query("id")!= "ju zi")
        &&(obj->query("id")!="chu tou")
        &&(obj->query("id")!="piao")
        &&(obj->query("id")!="sao zhou")
        &&(obj->query("id") != "shui tong")
        &&(obj->query("id") != "chai dao")){
           	tell_object(ob, CYN+me->name()+"说道：「你还错东西了吧，我从没有发过这样工具。」"NOR"\n");
           	return 0;
       	}
       	else {
           	command("nod");
           	tell_object(ob, CYN+me->name()+"说道：「加油，加油，下次再好好干啊！」"NOR"\n");
           	ob->set_temp("mark/还了",1);
           	call_out("destroying", 1, me, obj);
           	return 1;
       }
}

void destroying(object me, object obj)
{
       destruct(obj);
       return;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query_temp("mark/完了")){
		command("smile "+ob->query("id"));
		tell_object(ob, CYN+this_object()->name()+"说道：「工作做完了，可以还工具 "HIY + ob->query_temp("tools_name")+CYN" 给我了！」"NOR"\n");
		return;
	}
	if( ob->query_temp("mark/工具")) return 0;
	if( ob->query_temp("job_name")){
		command("bow "+ob->query("id"));
		tell_object(ob, CYN+this_object()->name()+"说道：「这位"+RANK_D->query_respect(ob)+ "，到我这领工具吧。」"NOR"\n");
	}
}
