// NPC: /d/meizhuang/npc/dingjian.c
// By Jpei

inherit NPC;

int do_flatter(string arg);

void create()
{
	set_name("丁坚", ({ "ding jian", "ding" }));
	set("nickname", "家人");

	set("gender", "男性");
	set("age", 48);
	set("long", "他目光炯炯，步履稳重，显是武功不低。\n");
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_temp("apply/damage", 40);

	set("combat_exp", 1400000);
	set("attitude", "peaceful");

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	string where;
	object inv, me = this_player();

	set("nickname", "家人");
	::init();
	where = base_name(environment(this_object()));
	if (where == "/d/meizhuang/entrance")
	        add_action("do_flatter", "pai");
	else if (where == "/d/meizhuang/hall") {
		if (me->query_temp("plummanor/flag") == 3 && me->query_temp("plummanor/ding_friend") >= 18) {
			me->set_temp("plummanor/flag", 4);
			if (objectp(inv = present("wuse lingqi", me))) destruct(inv);
			message_vision("丁坚对$N道：“请先用茶，待在下拿这面令旗去禀告敝上，见与不见，却是难言。”\n", me);
			call_out("destruct_me", 1);
		}
	}
	else if (where == "/d/meizhuang/hall") {
		set("nickname", "一字电剑");
	}
}

void destruct_me()
{
	destruct(this_object());
}

int do_flatter(string arg)
{
	object npc = this_object();
	object me = this_player();

	if (base_name(environment(npc)) != "/d/meizhuang/hall") return 0;
	if (!arg) return notify_fail("你要拍谁的马屁？\n");
	if (arg == "four-friends") {
		if (me->query_temp("plummanor/flag") != 2) {
			message_vision("$N一脸谄媚地对着两位家人说道：“江南四友，德配天地，威震寰宇，古今无比！”\n", me);
			message_vision("两位家人鄙夷地看着$N，似乎一辈子都没见过这么厚颜无耻的人。\n", me);
			me->add_temp("plummanor/ding_friend", -15);
			me->add_temp("plummanor/shi_friend", -15);
			return 1;
		}
		me->add_temp("plummanor/friends_flatter", 1);
		if (me->query_temp("plummanor/friends_flatter") > 2) {
			me->add_temp("plummanor/friends_flatter", -1);
			write("你还拍江南四友，自己不觉得肉麻吗？\n");
			return 1;
		}
		if (me->query_temp("plummanor/friends_flatter") == 1) {
			write("你对着两位家人说道：“江南四位前辈是何等样人，自然不会将在下看在眼里的。”\n");
			tell_room(environment(npc), me->name() + "对着两位家人说了些称颂江南四友的话。\n", ({me}));
			message_vision("两位家人听$N话中将江南四友的身份抬得甚高，脸色便和缓了许多。\n", me);
			me->add_temp("plummanor/ding_friend", 5);
			me->add_temp("plummanor/shi_friend", 5);
			call_out("decrease_friend", 1, me);
			return 1;
		}
		else if (!me->query_temp("plummanor/ding_flatter") || !me->query_temp("plummanor/shi_flatter")) {
			message_vision("$N一脸谄媚地对着两位家人说道：“江南四友，德配天地，威震寰宇，古今无比！”\n", me);
			message_vision("两位家人鄙夷地看着$N，似乎一辈子都没见过这么厚颜无耻的人。\n", me);
			me->add_temp("plummanor/ding_friend", -15);
			me->add_temp("plummanor/shi_friend", -15);
			call_out("decrease_friend", 1, me);
			return 1;
		}
		else {
			write("你对着两位家人说道：“在下这次来江南，心想江南四友虽未必瞧得起在下，但如能见到“一字电剑”和“五路神”二位，便算不虚此行。”\n");
			tell_room(environment(npc), me->name() + "对着两位家人说了些抬高江南四友又顺便称颂两人的话。\n", ({me}));
			message_vision("丁施二人听$N既捧江南四友，又大大的捧了自己二人，甚为高兴。\n", me);
			me->add_temp("plummanor/ding_friend", 12);
			me->add_temp("plummanor/shi_friend", 12);
			call_out("decrease_friend", 1, me);
			return 1;
		}
	}
	if (id(arg)) {
		if (me->query_temp("plummanor/flag") != 2) {
			message_vision("$N指着$n道：“壮士的相貌岂仅俊美而已，简直是风流潇洒，前无古人，后无来者。潘安退避三舍，宋玉甘拜下风。”\n", me, npc);
			message_vision("$N鄙夷地看着$n，似乎一辈子都没见过这么厚颜无耻的人。\n", npc, me);
			me->add_temp("plummanor/ding_friend", -12);
			return 1;
		}
		if (me->query_temp("plummanor/ding_flatter")) {
			write("你还拍丁坚呀，自己不觉得肉麻吗？\n");
			return 1;
		}
		me->set_temp("plummanor/ding_flatter", 1);
		write("你对着丁坚说道：“想当年丁兄在祁连山单掌劈四霸，一剑伏双雄，何等威风！”\n");
		tell_room(environment(npc), me->name() + "对着丁坚说了些称颂的话。\n", ({me}));
		message_vision("$N微微一笑，对$n道：“小事一件，何足挂齿？阁下见闻倒广博得很。”\n", npc, me);
		me->add_temp("plummanor/ding_friend", 10);
		call_out("decrease_friend", 1, me);
		return 1;
	}
	return 0;
}

void decrease_friend(object me)
{
	if (base_name(environment(this_object())) != "/d/meizhuang/entrance") return;
	if (objectp(me)) {
		me->add_temp("plummanor/ding_friend", -1);
		call_out("decrease_friend", 1, me);
	}
}

void fight_ob(object ob)
{
	return;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("丁坚漠然道：“这种江湖仇杀已经与我无关了。”\n", ob);
}

int accept_fight(object ob)
{
	message_vision("丁坚摇首道：“我退隐梅庄，不再和人动手了。”\n", ob);
	return 0;
}

void unconcious()
{
	say("丁坚喝道：“住手！我已经不再和人动手了！”\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

