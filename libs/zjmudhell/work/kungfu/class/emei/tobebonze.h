string ask_for_join()
{
	object me;

	me = this_player();
	if (me->query("family/family_name") != "峨嵋派")
		return ("你和峨嵋没有渊源，贫尼不敢给你剃度。");

	if ((string)me->query("class") == "bonze")
		return "阿弥陀佛！出家人不打诳语。你已经不是俗家人了。";

	if ((string)me->query("gender") != "女性")
		return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去少林寺受戒。";

	if (me->query("couple/id"))
		return me->name(1) + "你尘缘未了，怎能出家？";

	me->set_temp("pending/join_bonze", 1);
	command ("say 阿弥陀佛！善哉！善哉！施主若真心皈依我"
		 "佛，请跪下(kneel)受戒。");
	return "记住，既然出了家，就一心向佛，不能还俗。";
}

int do_kneel()
{
	object me = this_player();
	string *prename = ({ "灵", "文", "心", "妙"});
	string name, new_name;

	if (! me->query_temp("pending/join_bonze"))
		return notify_fail("你在地上跪了一会儿，没人理你。\n");

	message_vision(
		"$N你双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n看着$N说道：好吧，你就在本庵修行吧。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
		me, this_object());
	name = me->query("purename");
	if (! name) name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..0];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("chat " + name + "削发为尼，在峨嵋山修行，取法名" + new_name + "。");
	command("smile");
	me->set("marks/old_name",name);
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);

	return 1;
}

void init()
{
	add_action("do_kneel", "kneel");
}
