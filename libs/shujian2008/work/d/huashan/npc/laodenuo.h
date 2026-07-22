// include for lao denuo

string ask_me()
{
        object me, ob, book;

        ob = this_object();
        me = this_player();

        if((random(10) < 6) || me->is_fighting() )
                return "对不起，这件事我不清楚，你还是问我师傅去吧！\n";

	if (me->query_temp("hs/askzixia",1)){
		message("vision", YEL "看来这件事你都知道了？臭贼，去死吧！\n"
			"劳德诺使开长剑，招数精奇，狠辣无比，一改整日笑咪咪的模样。\n" NOR, me, ob);
		ob->set_temp("apply/attack",  50);
		ob->set_temp("apply/defense", 50);
		ob->set_temp("apply/damage",  50);
		ob->set("wmmpy", 80);
		me->delete_temp("hs/askzixia");
		book = unew(__DIR__"obj/zixia");
		if( clonep(book) ){
			book->move(ob);
		}
		ob->kill_ob(me);
		me->fight(ob);
		return "我带艺投师，忍辱负重，你竟敢打我的主意，去死吧！\n";
	}
	return "我师父说秘籍被令狐冲那小子偷走了！\n";
}

string ask_px()
{
	if (random(10) < 8)
                return "辟邪剑法？据说很厉害，不过我没见过！\n";
	return "这件事我不清楚，你还是问我师傅去吧！\n";
}

string ask_zuo()
{
	object me = this_player();

	if (random(10) < 5)
                return "他就是五岳剑派的盟主。\n";
	if (me->query("family/family_name")=="嵩山派"){
		command("whisper "+me->query("id")+" 师傅他老人家最近可好？替我问候他老人家！");
		return "五岳盟主的门下弟子都很出色！\n";
	}
	return "师傅有次说漏了嘴，他说我华山派的大敌就是这个人！\n";
}
