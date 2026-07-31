// NPC jiuyi.c

#include <ansi.h>

inherit NPC;

mixed ask_fofa();

void create()
{
	set_name(HIW"静"NOR, ({ "jing"}));
	set("long","她是静，传授佛法知识。\n");
	set("title", HIC"大道归一"NOR);
	set("gender", "女性");
	set("nickname", HIR "万法唯一" NOR);
	set("age", 25);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("max_qi", 99999999);
 	set("qi", 99999999);
	set("jing", 99999999);
	set("max_jing", 99999999);
	set("neili",99999999);
	set("max_neili", 99999999);
	set("jiali", 5000);
	
	set_skill("strike", 1000);
	set_skill("rulai-shenzhang", 1000);

	map_skill("strike", "rulai-shenzhang");

	prepare_skill("strike", "rulai-shenzhang");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "strike.wofo" :),
	}));

	set_temp("apply/attack", 1000);
	set_temp("apply/defense", 1000);
	set_temp("apply/damage", 1000);
	set_temp("apply/unarmed_damage", 1000);
	set_temp("apply/armor", 20000);


	set("combat_exp", 1600000);
	set("score", 1500);
	
	set("inquiry", (["佛法": (:ask_fofa:)]));
	
	setup();
}

mixed ask_fofa()
{
	object ob;
	object me;
	
	me = this_player();
	if (me->query_temp("last_ask/jing") + 10 > time())
		return HIR"你品，你细细的品，这是一个悟的过程~~~~~~~"NOR;

	message_vision("$N看看$n，道："HIW"“好吧，我就与你谈谈我在佛法方面的体会，你可要好好听着。”\n"NOR,
		       this_object(), me);
	
	tell_object(me, HIG "你听的心中豁然开朗，通晓了不少关于佛法的奥妙。"NOR"\n"+
	HIC"你对梵文，禅宗心法，密宗心法，道家心法的认识增加了！\n"NOR);
	me->set_temp("last_ask/jing", time());
	me->improve_skill("sanscrit", 10);
	me->improve_skill("buddhism",10);
	me->improve_skill("lamaism",10);
	me->improve_skill("taoism",10);
	return 1;
}

int accept_fight()
{
	command("say 打打杀杀成何体统。");
	return notify_fail("你还是算了吧！\n");
}

int accept_hit()
{
	command("say 打打杀杀成何体统。");
	return notify_fail("你还是算了吧！\n");
}

int accept_kill()
{
	command("say 呀！你想干什么？");
	return 1;
}

void unconcious()
{
	die();
}

void die()
{
	command("chat 本尊走了，愚蠢的人类。");
	message_vision("$N化作清风飘散。\n", this_object());
	this_object()->set("qi",99999999);
	this_object()->set("jing",99999999);
}


