// 东厂check 

void do_check(object ob, object me)
{
	if(ob->query("class") == "eunuch"
		&& ob->query_condition("bjkiller"))
	{
		message_vision(HIR"$N对$n怒喝道：「身为东厂官员居然知法犯法，念你初犯姑且记你一过，记住，若有再犯军法伺候！！」\n"NOR, me, ob);
		ob->add("dongchang/mistake", 1);
		ob->set("dongchang/salary", ob->query("dongchang/salary") + 7200);
		ob->clear_condition("bjkiller");
		tell_object(ob,"你被扣除了一个月的俸禄。\n你被东厂记过一次。\n");
	}
	
	if(ob->query("class") == "eunuch"
		&& ob->query("dongchang/job_fail") / (ob->query("dongchang/job_bonus") + 1) >= 10 )
	{
		message_vision(HIR"$N对$n怒喝道：「身为东厂官员屡次玩忽职守，念你初犯姑且记你一过，记住，若有再犯军法伺候！！」\n"NOR, me, ob);
		ob->add("dongchang/mistake", 1);
		ob->set("dongchang/salary", ob->query("dongchang/salary") + 7200);
		ob->add("dongchang/job_bonus", 1);
		tell_object(ob,"你被扣除了一个月的俸禄。\n你被东厂记过一次。\n");
	}
	if(ob->query("class") == "eunuch" && ob->query("dongchang/mistake") >= 10 )
	{
		message_vision(HIR"$N对$n怒喝道：「身为东厂官员屡次知法犯法，来人啊，给我拉出去斩了！！」\n"NOR, me, ob);
		message_vision(HIR"$N吓得面如土灰，全身不断哆嗦。\n"NOR, ob);
		ob->start_busy(100);
		remove_call_out("responsing");
		call_out("responsing", 3, ob, me);
	}
	
	if(ob->query("class") == "eunuch" && ob->query("shen") > 0 )
		{
			//抓入刑房
		}
}

void responsing(object ob, object me)
{
	if( !ob||ob->is_ghost() ) return;
	message_vision(HIR "兵营内冲进来几个锦衣卫，将$N五花大绑！\n" NOR, ob);
	remove_call_out("beating");
	call_out("beating", 8, ob, me);
	return;
}

void beating(object ob, object me)
{
	if( !ob||ob->is_ghost() ) return;
	message_vision(HIY "\n$N喝道：「将$n押到菜市口斩首示众！！」\n" NOR, me, ob);
	message_vision(HIR "锦衣卫一涌而上，乱棒齐下将$N打得昏了过去......\n" NOR, ob);
	ob->move("/d/beijing/caishikou");
	ob->unconcious();
	remove_call_out("processing");
	call_out("processing", 15, ob, me);
}

void processing(object ob, object me)
{
    if (ob->is_ghost()) return;
    ob->revive();
	write(HIW "\n你恢复了神志，环顾四周，只见数十名刽子手将你团团围起来，\n"
		"一片雪亮的刀光逼得你眼都睁不开。正前方的高台上放着一把\n"
		"铡刀，笼罩着浓烈的肃杀的气氛。\n\n" NOR);
	message_vision(HIR "周围挤满了围观群众，$N心道：「这回真的完了。」\n"
			"旁边的监斩官员扔出一道令牌，.....\n"
			"刽子手大刀一挥..........\n\n" NOR, ob);
	ob->set("dongchang/mistake",0);
	ob->add("dongchang/decapitate", 1);
	ob->start_busy(0);
    ob->receive_damage("qi", 0, me);
	ob->die();
	CHANNEL_D->do_channel(me, "rumor", ob->name()+"在菜市口被斩首示众！");
	return;
}