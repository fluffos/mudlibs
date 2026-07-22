// By River@SJ

inherit NPC;
#include <ansi.h>

void create()
{
	mapping name;
	int i = random(4);
	object ob;

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"] + ({ "robber" }));
	set("gender", (i==0?"女性":"男性"));
	set("age", 20 + random(40));
	set("combat_exp", 500000);
	set("meitude", "peaceful");
	set("str", 20+random(5));
	set("dex", 30);
	set("int", 25+random(5));
	set("con", 30);

	set("no_get", 1);
	set("no_bark", 1);
	set("job_npc", 1);
	set("no_ansuan", 1);
	set("no_quest", 1);

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 3000);
	set("neili", 3000);
	set("eff_jingli", 3000);

	set_skill("huagu-mianzhang", 150);
	set_skill("strike", 150);
	set_skill("xinyuegong", 150);
	set_skill("taiji-shengong", 150);
	set_skill("dodge", 150);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("literate", query("int") * 10);
	map_skill("force", "taiji-shengong");
	map_skill("parry", "xinyuegong");
	map_skill("strike", "huagu-mianzhang");
	prepare_skill("strike", "huagu-mianzhang");

	setup();
	ob = new(ARMOR_D("cloth"));
	ob->set("name", YEL"黄布衣"NOR);
	ob->move(this_object());
	ob->wear();

	if (clonep())
		call_out("dest", 500);
}

void init()
{
	object ob;       

	::init();
	if (interactive(ob = this_player()) && query_temp("target") == getuid(ob)) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object obj, me = this_object();
	
	if (!ob || !present(ob) || query_temp("target") != getuid(ob))
		return;

	if (ob->query_temp("changle/changle_job")) {
		ob->add_busy(1);
		me->set("eff_qi", 10);
		me->set("qi", 10);
		message_vision("\n$N手中紧握一块粗布碎片，怔怔的看着$n，手指胡乱地在空中乱划。\n", me, ob);
		command("say 杀我之人乃……");
		ob->set_temp("changle/meet_die_npc", 1);
		obj = new("/d/changle/obj/buliao");
		obj->set_temp("target", getuid(ob));
		obj->move(me);
		me->die();
	}
}

void dest()
{
	message_vision("$N好象突然想起什么事，急急忙忙的走开了。\n", this_object());
	destruct(this_object());
}
