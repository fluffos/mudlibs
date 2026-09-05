//created by hacky
//data: 1997,11.20

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
void heal();

void create()
{
	set_name("尹志平",({"yin zhiping","yin"}));
	set("long",@LONG
他就是王处一的弟子尹志平，也是全真教第三代弟子中的佼佼者。
LONG);
	set("title", HIB"全真派"NOR+GRN"道长"NOR);
	set("gender","男性");
	set("age",40);
	set("attitude","peaceful");
	set("shen_type",-1);
	set("str",26);
	set("int",20);
	set("con",23);
	set("dex",26);

	set("chat_chance_combat",100);
	set("chat_msg_combat",({
		(:exert_function,"powerup" :)
	}));
	set("chat_chance",100);
	set("chat_msg", ({
		(:heal:),
	}));
    
	set("max_qi",1000);
	set("max_jing",800);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",30);
	set("combat_exp",50000);

	set_skill("force",60);
	set_skill("xiantian-gong",40);
	set_skill("dodge",60);
	set_skill("jinyan-gong",40);
	set_skill("sword",60);
	set_skill("quanzhen-jian",40);
	set_skill("daoxue-xinfa",60);
	set_skill("parry",60);
	set_skill("cuff",40);
	set_skill("yangxin-quan",60);

	map_skill("force","xiantian-gong");
	map_skill("dodge","jinyan-gong");
	map_skill("sword","quanzhen-jian");
	map_skill("cuff","yangxin-quan");

	create_family("全真派",3,"弟子");
	set("class","taoist");

	setup();
	carry_object(__DIR__"obj/robe")->wear();
}



void attempt_apprentice(object ob)
{
	if (ob->query("class")=="bonze")
	{
		command("say "+RANK_D->query_respect(ob)+"既然已经加入佛门，为何还要入我道教呢?");
		return;
	}
	if( (string)ob->query("gender")!="男性")
	{
		command("say 我只收男徒。");
		return;
	}
	if (ob->query("class")!="taoist")
	{
		command("say 我派只收道士，"+ RANK_D->query_respect(ob) + "是否愿意入我全真？");
		command("say 如果你决定了。请发誓(swear 忠于全真)");
		ob->set_temp("prepare/taoist",1);
		ob->set_temp("pending/swear",1);
		return;
	}
	if ((int)ob->query("shen") < 0)
	{
		command("say 我全真乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
	ob->set("class", "taoist");
	ob->set("title",HIB "全真派" NOR + YEL"道童" NOR);
//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, HIB "全真派" NOR + YEL"道童" NOR);
}

void init()
{
	object ob;
	mapping fam;

	add_action("do_swear", "swear");
	add_action("do_learn", "learn");

	::init();

	ob = this_player();
	if((int)ob->query("shen")<0&&ob->query("family/master_id")=="yin zhiping")
	{
		command("say 你多次杀人越货，胡作非为，如若知错不改，我全真岂能容你。\n");
		command("expell "+ ob->query("id"));
	}
}

int do_swear(string arg)
{
	if( !this_player()->query_temp("pending/swear") )
		return 0;
	if( !arg ) return notify_fail("你不会发誓？那是与本门无缘了。\n");
	this_player()->set_temp("pending/flatter", 0);
	message_vision("$N举起右手，信誓旦旦：" + arg + "\n", this_player());
	if( strsrch(arg, "忠于全真") >=0 )
	{
		command("smile");
		command("say 也真难为你啦，行啦。");
		command("recruit " + this_player()->query("id"));
        	this_player()->set("class", "taoist");
		this_player()->set("title",HIB "全真派" NOR + YEL +"道童" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  this_player()->set_title(TITLE_RANK, HIB "全真派" NOR + YEL +"道童" NOR);
	}
	else
	{
		command("say 你既然不愿发誓，全真也不强留你。");
	}
	return 1;
}
void heal()
{
	object ob=this_object();

	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 30");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}

int do_learn()
{
	object ob = this_player();
	if((int)ob->query("shen") < 0 && (string)ob->query("family/master_id") == "yin zhiping")
	{
		command("say 你屡次在外杀戮良民，败坏我的名声，我尹志平不会教你这个徒弟。\n");
		return 1;
	}
	return 0;
}