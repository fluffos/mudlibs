// xiao qiushui.c 萧秋水

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
	set_name("萧秋水", ({ "xiao qiushui", "xiao" }));
	set("nickname", HIY "大侠" NOR);
	set("long", 
		"原来他就是与唐方痴心相恋，为了唐方大闹唐门的萧秋水。\n"
		"他在江湖上行侠仗义，侠名远播，人称“大侠”。\n"
		"他大约二十有余，虽然受尽折磨，仍然带着一身傲气。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	
	set("max_qi", 1000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 700000);

	set_skill("force", 200);
	set_skill("biyun-xinfa",200);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 200);
	set_skill("biye-wu", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("wuzhan-mei", 300);
	set_skill("literate", 200);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("parry", "wuzhan-mei");
	map_skill("sword", "wuzhan-mei");
	create_family("唐门", 7, "弟子");
	set("class", "tangmen");
	
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.wumei" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", 
		([
			"唐方" : (: ask_me :)
		]));
	set("yu_count", 1);

	setup();
	carry_object("/d/tangmen/obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 200) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 看在唐方姑娘份上，我收下你了。");
	command("recruit " + ob->query("id"));
}
string ask_me()
{object ob;
 object me;
 me=this_player();
	if (query("yu_count") < 1){return "是唐方叫你来见我的？可惜我的玉佩已经交给别人了。\n";}
	command("touch " + this_player()->query("id"));
	command("say 是唐方叫你来见我的？\n");
	command("sigh" );
	command("say 自从当日大闹唐门之后，我就和唐方生死相隔了。\n");
	ob=new("/d/tangmen/obj/yupei");
        ob->move(this_player());
	message_vision("$N交给$n一块玉佩。\n", me, ob);
	add("yu_count", -1);
	return"你把这块玉佩交给唐方吧。\n";
	

							

}
