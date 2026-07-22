int questions(object me)
{
	string answer;
	if (me->query_temp("jyquest")!=4){
		command("?");
		return 1;
	}
	if (me->query_temp("jiuyin/question")>9) {
		command("admire");
		command("say 原来我们是同道中人啊。");
		command("xixi");
//需要 4 题就能过关，不过如果到 10 题以上，就给一点 karma bonus
//		me->add_temp("apply/karma",5);
		return 1; 
	}
	command("hehe");
	command("say 注意听好了！");
	message_vision(HIR"用 answer 来回答，回答请使用拼音输入，不要用汉字。\n"NOR,me);
	switch (random(30)) {
		case 0:
			command("say 我全真教的内功心法是什么？");
			answer = "xiantian-gong";
			break;
		case 1:
			command("say 黄老邪的那厉害指法是什么？");
			answer = "tanzhi-shentong";
			break;
		case 2:
			command("say 段家有门以指为剑的剑法，叫什么名字？");
			answer = "liumai-shenjian";
			break;
		case 3:
			command("say 铁掌帮的著名轻功是？");
			answer = "shuishangpiao";
			break;
		case 4:
			command("say 神龙洪老头的暗器是叫做什么？");
			answer = "hansha-sheying";
			break;
		case 5:
			command("say 老毒物的奇怪内功是什么？");
			answer = "hamagong";
			break;
		case 6:
			command("say 老叫化和郭兄弟都会的掌法是什么？");
			answer = "xianglong-zhang";
			break;
		case 7:
			command("say 少林和尚们的内功是什么？");
			answer = "yijin-jing";
			break;
		case 8:
			command("say 峨嵋的剑法是什么？");
			answer = "huifeng-jian";
			break;
		case 9:
			command("say 武当张老头创出的软绵绵拳法叫什么名字？");
			answer = "taiji-quan";
			break;
		case 10:
			command("say 明教张无忌那小子的内功是什么？");
			answer = "jiuyang-shengong";
			break;
		case 11:
			command("say 星宿派恶名昭彰的功夫是什么？");
			answer = "huagong-dafa";
			break;
		case 12:
			command("say 慕容家的家传特殊招架技能是？");
			answer = "douzhuan-xingyi";
			break;
		case 13:
			command("say 明教前教主阳顶天练什么功夫练到走火而死的？");
			answer = "qiankun-danuoyi";
			break;
		case 14:
			command("say 黄老邪的箫乐是由他的内功而来。这个内功的名字是？");
			answer = "bihai-chaosheng";
			break;
		case 15:
			command("say 金蛇郎君夏雪宜的剑法叫什么名称？");
			answer = "jinshe-jianfa";
			break;
		case 16:
			command("say 有种剑法，练了使人绝子绝孙。这个剑法的名字是什么？");
			answer = "pixie-jian";
			break;
		case 17:
			command("say 华山气宗的镇山之宝是什么？");
			answer = "zixia-gong";
			break;
		case 18:
			command("say 我老顽童的自创拳招是什么啊？");
			answer = "kongming-quan";
			break;
		case 19:
			command("say 华山剑宗的高级剑法是？");
			answer = "dugu-jiujian";
			break;
		case 20:
			command("say 古墓派的内功心法是什么？");
			answer = "yunu-xinjing";
			break;
		case 21:
			command("say 我求杨过这小子教我的掌法叫做什么名称？");
			answer = "anran-zhang";
			break;
		case 22:
			command("say 一灯大师的拿手绝学是什么？");
			answer = "yiyang-zhi";
			break;
		case 23:
			command("say 老叫化教黄蓉那小丫头的是什么拳法？");
			answer = "xiaoyaoyou";
			break;
		case 24:
			command("say 古墓一派的特殊拳法，叫什么名称？");
			answer = "mainu-quan";
			break;
		case 25:
			command("say 黄老邪除了教杨过弹指神通，还教了什么武功？");
			answer = "yuxiao-jian";
			break;
		case 26:
			command("say 瑛姑的高明身法是什么？");
			answer = "niqiugong";
			break;
		case 27:
			command("say 黄蓉的家传手法叫什么名字？");
			answer = "lanhua-shou";
			break;
		case 28:
			command("say 桃花的狂风绝技要以什么和旋风扫叶腿配合施展？");
			answer = "luoying-zhang";
			break;
		case 29:
			command("say 峨嵋的灭绝师太曾经以那种功夫将张无忌打的倒地不起？");
			answer = "jieshou-jiushi";
			break;
	}
	this_object()->set("answer",answer);
	return 1;
}

int do_answer(string arg)
{
	object me = this_player();
	if (me->query_temp("jyquest")!=4)
		return notify_fail("什么？\n");
	if (!arg)
		return notify_fail("你要回答什么？\n");
	if (arg != this_object()->query("answer")) {
		command("say 错！");
		command("papaya " + me->query("id")); 
	}
	else {
		command("say 不错不错，有点头脑嘛。");
		command("praise " + me->query("id"));
		command("say 再来一题吧。");
//		if (me->query_temp("jiuyin/question")>4)
//			me->add_temp("apply/karma",1);
		me->add_temp("jiuyin/question",1); 
	}
	call_out("questions", 1, me);
	return 1;
}
