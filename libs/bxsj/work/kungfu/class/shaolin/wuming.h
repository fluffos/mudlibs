// wuming.h

int ask_fofa()
{
	object me=this_player();

	if(!me->query("guilty")){
		command("buddhi wuming");
		return 1;
	}
	if(me->query_skill("buddhism",1) < 200) {
		command("say 大师佛法修为不足，恐怕我无法点拨于你。");
		return 1;
	}
	if( me->query("family/master_name") != "无名老僧")
		return 0;
	if( me->query("shen") < 0) {
		command("say 你这等奸诈小人，我怎能传你佛法？\n");
		return 1;
	}
	command("buddhi");
	message_vision(HIW"无名老僧端坐念到：即心即佛，即佛即心，心明识佛，识佛明心，离心非佛，离佛非心……\n"NOR, me);
	message_vision("$N沉思良久，若有所捂。\n", me );
	me->add_busy(5);
	me->delete("guilty");
	return 1;
}

int ask_reset_skill()
{
	object me = this_player();

	if ( me->query("family/family_name") != "少林派") return 0;
	if ( me->query("family/master_name") != "无名老僧"){
		command("say 你的功力不够，还是先去修炼一阵吧。");
		return 1;
	}
	if (me->query("passdu") && me->query_skill("riyue-bian", 1) > 200) {
		command("nod");
		command("say 我会派人去跟三长老说明，你今天开始就去心禅堂修习燃木刀法吧。");
		message_vision(HIR"$N因为强行放弃了原本修习的少林神功，体内积存的内力耗损了大半。\n"NOR, me);
		me->delete_skill("riyue-bian");
		me->set("max_neili", me->query("max_neili")/2);
		me->delete("passdu");
		me->set("pass_xin", 1);
		me->set("no_recover", 1);
		return 1;
	}
	if (me->query("pass_xin") && me->query_skill("ranmu-daofa", 1) > 200) {
		command("nod");
		command("say 我会派人去跟心禅堂说明，你今天开始就跟三长老学习日月鞭法吧。");
		me->delete_skill("ranmu-daofa");
		message_vision(HIR"$N因为强行放弃了原本修习的少林神功，体内积存的内力耗损了大半。\n"NOR, me);
		me->set("max_neili", me->query("max_neili")/2);
		me->delete("pass_xin");
		me->set("no_recover", 1);
		me->set("passdu", 1);
		return 1;
	}
	command("buddhi");
	command("say 你原来的武技还未练成熟，怎么就贪心其他武技呢？");
	return 0;
}

string ask_wtc()
{
	int i;
	object me = this_player();

	if ( me->query("family/master_name") != "无名老僧")
		return "你不是我的弟子，还是找其他人去修炼吧。";

	if ( me->query("sl_wtc"))
		return "你不是已经学了少林绝技韦陀杵了么？";

	if ( me->query("max_neili") < 6000){
		i = 6000 - me->query("max_neili");
		return "韦陀杵过于威猛，你的内力还差"+CHINESE_D->chinese_number(i) +"点才能修炼。";
	}
	if ( me->query_skill("buddhism", 1) < 200)
		return "韦陀杵过于威猛，你的佛法修为还不够。";

	if ( !me->query("passdu") && !me->query("pass_xin"))
		return "你没有修练过燃木刀法、日月鞭法等少林兵器武技？？";

	if ( me->query_temp("sangong"))
		return "你想散功的话，我帮你护法，就不需要多问了。";

	if ( me->query("passdu"))
		me->set_temp("sangong", "passdu");

	if ( me->query("pass_xin"))
		me->set_temp("sangong", "pass_xin");

	command("buddhi");
	command("say 如若你想练习少林绝技韦陀杵，必须散去原来修练的武功且内力大损。");
	command("pat "+ me->query("id"));
	return "考虑清楚的话，可以在这里散功(sangong)，老衲帮你护法吧。";
}

string ask_sangong()
{
	object me = this_player();

	if ( me->query_temp("sangong"))
		return "你想散功的话，我帮你护法，就不需要多问了。";

	if ( me->query("family/master_name") != "无名老僧")
		return "你不是我的弟子，何出此问？";

	if ( me->query("sl_wtc"))
		return "你已经学过少林绝技韦陀杵了，再散功有害无益。";

	if ( me->query_skill("buddhism", 1) < 200)
		return "你的佛法修为不够，如何能散功？";

	command("buddhi "+me->query("id"));
	return "散功是学习韦陀杵的唯一途径，你要研究韦陀杵嘛？";
}