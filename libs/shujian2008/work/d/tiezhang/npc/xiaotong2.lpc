
inherit NPC;
#include <ansi.h>
int give_tools();

void create()
{
        set_name("小童", ({"xiao tong", "xiao", "tong", }));
        set("long", "他是一位未通世故的少年，脸上挂着天真的稚笑。\n");
        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 10);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 500);
        set("score", 100);
        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("strike", 10);
        set_skill("parry", 10);

        set("inquiry", ([
		"工具" : (: give_tools :),
	]) );
        setup();
        carry_object(__DIR__"obj/huiyi")->wear();

}

int give_tools()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();
	if( !ob->query_temp("job_name")){
		command("say 你没跟帮主领活吧，跑来要什么工具。\n");
		return 1;
	}
	if(ob->query_temp("mark/工具")){
		say (CYN"小僮说道：你先把工具还了，再领工具吧。\n"NOR);
		return 1;
	}
	if(ob->query_temp("mark/还了")){
		say (CYN"小僮说道：你还没覆命领新活吧，跑来要什么工具。\n"NOR);
		return 1;
	}
	command("say 既然你已经领了活，我就给你这把工具，小心保管，别弄丢了。\n");
	message_vision("$N交给$n一把工具。\n", me, ob);

	if(!(ob->query_temp("job_name")!="挖陷井")){
		tools = new(__DIR__"obj/tiechan");
		tools->move(this_player());
		say(CYN"小僮说道：把陷井挖在广场外的山路上，以防江湖门派和官府对铁掌帮的清剿和寻仇。\n"NOR);
	}
	if(!(ob->query_temp("job_name")!="补寨栏")){
		tools = new(__DIR__"obj/tiechui");
		tools->move(this_player());
		say(CYN"小僮说道：把山门二侧的寨栏修补一下，已经有很长时间没人去修补过寨栏了。\n"NOR);
	}
	if(!(ob->query_temp("job_name")!="伐木")){
		tools = new(__DIR__"obj/tiefu");
		tools->move(this_player());
		say(CYN"小僮说道：在中指锋山上有一片松树林，到那里去伐木吧，不过听说树林里有野兽，要当心啊。\n"NOR);
	}
	ob->set_temp("mark/工具",1);
	return 1;
}

int accept_object(object me, object obj)
{
	object ob;
	me=this_object();
	ob=this_player();
	if( !(ob->query_temp("mark/伐完")
	 ||ob->query_temp("mark/补完")
         ||ob->query_temp("mark/挖完"))){
		command("say 你还没完成工作，怎么就回来还工具了，偷懒吗？\n");
		return 0;
	}
	if( (obj->query("id")!="tie chui")
	 && (obj->query("id")!="tie chan")
	 && (obj->query("id")!="tie fu")){
		command("say 你还错东西了吧，我从没有发过这样工具。\n");
		return 0;
	}
	if( ob->query_temp("job_name")=="山路挖陷井"
	 || ob->query_temp("job_name")=="山门二边寨沟补寨栏"
	 || ob->query_temp("job_name")=="中指锋松树林伐木" ){
		command("shake");
		command("say 我没有发给你过东西，你是不是还错了？\n");
		return 0;
	}
	else {
		command("nod");
		command("say 加油，加油，下次再好好干啊!");
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
