// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "传功长老");
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。\n"
		"丐帮武功向来较强，近来梁长老一力整顿，更是蒸蒸日上。\n");

	set("attitude", "peaceful");
        set("beggarlvl",9);
        set("class", "beggar");
//        set("no_get", "1");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 3900);
	set("max_qi", 3900);
	set("jing", 3400);
	set("max_jing", 3400);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 120);
	
	set("combat_exp", 600000);
	
	set_skill("force", 190); 
	set_skill("huntian-qigong", 195); 
	set_skill("unarmed", 185); 
	set_skill("xianglong-zhang", 190); 
	set_skill("dodge", 193); 
	set_skill("xiaoyaoyou", 190); 
	set_skill("parry", 180); 
	set_skill("staff", 180); 
	set_skill("dagou-bang", 180); 
	set_skill("begging", 180); 
	set_skill("checking", 190);
	set_skill("training", 180);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
		set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	create_family("丐帮", 18, "九袋长老");
	setup();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "丐帮")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	message_vision("\n粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
    if (environment(ob)->query("short")=="树洞下"){
	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +
		"从小门里飞了出来。\n", environment(ob), ob);
}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("str") < 25) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
		return;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
