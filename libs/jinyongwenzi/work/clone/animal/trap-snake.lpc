// trap-snake by Darken@SJ
// Modify by Looklove@SJ

inherit NPC;
#include <ansi.h>
int do_target(string arg);
int do_pickup(string arg);

void create()
{
	set_name(HIG"小青蛇"NOR, ({ "qing she","she" }));
	set("race", "野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set("shen", 1);
	set("attitude", "peaceful");
	set("age", 1+ random(3));
	set("combat_exp", 1);
	set("no_get",1);
	set("max_qi",1);
	set("eff_qi",1);
	set("qi",1);
	set("max_jing",1);
	set("eff_jing",1);
	set("jing",1);
	set("max_jingli",1);
	set("eff_jingli",1);
	set("jingli",1);
	set("neili",1);
	set("jiali", 1);
	set("max_neili",1);
	set_skill("force",1);
	set_skill("dodge",1);
	set_skill("parry",1);
	set_skill("unarmed",1);
	set("chat_chance", 3);
	set("chat_msg", ({
		"小青蛇列成环型阵势，围在你周围。\n",
		"小青蛇爬过来，在你的腿边爬来爬去。\n",
		"小青蛇向着你，慢慢爬了过来。\n",
		}) );
	setup();
}

void init()
{
	object me,snake;

	me = this_player();
	snake = this_object();
	
	if (me->query("id") == query("target")
	 && userp(me)
	 && !environment(me)->query("no_fight")){
		snake->set_leader(me);
		message_vision("小青蛇决定和$N一起行动。\n",me);
		snake->kill_ob(me);
		snake->add_busy(1);
		me->add_busy(1);
	}
	if (present(snake, environment(me)) && query("owner") == me->query("id")) {
		add_action("do_target","target");
		add_action("do_pickup","pickup");
	}
}

int hit_ob(object me, object victim, int damage)
{
	victim->add_condition("snake_poison", 8+random(6));
	return 0;
}

int do_target(string arg)
{
	object me, *ob;
	int i,j,e;
	me=this_player();

	if (!arg || !find_player(arg))
		return notify_fail("你要对付谁？\n");
	if (present(arg))
		return notify_fail("你要对付的人就在旁边，不太好吧？\n");
	if (me->query("combat_exp") >= 5000000)
		return notify_fail("你这样的高手还要用这种下三滥的东西，不怕自贬身份，贻笑江湖吗？\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不适合组蛇阵。\n");

	message_vision(HIG"$N发出一些古怪的声音，对著蛇比手划脚。\n"NOR, me);
	j = me->query("max_pot") / 2 * 3;
	e = me->query("combat_exp") / 5 * 3;
	if (e > 1000000) e = 1000000+random(200000);
	if (j > 200) j = 200 + random(30);
	ob = all_inventory(environment(me));

	for (i=0;i<sizeof(ob);i++) {
		if (ob[i]->id("qing she") && ob[i]->query("owner")==me->query("id")) {
		if (ob[i]->is_fighting())
			return notify_fail("你的蛇正忙着呢，现在没空听你指挥。\n");
		me->add_condition("killer", 15);
		ob[i]->set("target",arg);
		ob[i]->set("combat_exp", e);
		ob[i]->set("max_qi", me->query("max_qi"));
		ob[i]->set("max_jing", me->query("max_jing"));
		ob[i]->set("eff_jingli", me->query("eff_jingli"));
		ob[i]->set("max_neili", me->query("max_neili"));
		ob[i]->set("jiali", me->query("jiali"));
		ob[i]->set("str", me->query("str"));
		ob[i]->set("con", me->query("con"));
		ob[i]->set("dex", me->query("dex"));
		ob[i]->set("int", me->query("int"));
		ob[i]->set_skill("unarmed",j +random(50));
		ob[i]->set_skill("force",j + random(50));
		ob[i]->set_skill("dodge",j + random(50));
		ob[i]->set_skill("parry",j + random(50));
		ob[i]->reincarnate();
		}
	}
	return 1;
}

int do_pickup(string arg)
{
	object me, *ob;
	int i;
	me=this_player();

	if(!arg || arg != "qing she")
		return notify_fail("请用pickup qing she指令拿起小青蛇。\n");

	if(!present(arg,environment(me)))
		return notify_fail("你要捡什么？\n");

	ob = all_inventory(environment(me));
	for (i=0;i<sizeof(ob);i++) {
		if (ob[i]->id("qing she") && ob[i]->query("owner")==me->query("id")) {
		ob[i]->move(me);
	}
	}
	message_vision(HIG"$N发出一些古怪的声音，蛇便乖乖的爬回$N身上。\n"NOR, me);
	return 1;
}

void unconcious()
{
	::die();
}
