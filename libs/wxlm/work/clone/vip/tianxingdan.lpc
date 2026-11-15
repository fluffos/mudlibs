//tianxing.c


inherit COMBINED_ITEM;

void do_character(object player, string character);

void create()
{
	set_name(HIR"天性丹" NOR, ({ "tianxing dan"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("base_unit", "颗");
		set("base_unit", "颗");
		set("base_value", 1);
		set("base_weight", 1);
		set("base_value", 1);
		set("channel_id","系统");
		set("no_sell",1);
		set("no_steal",1);
		set("no_shop", 1);
		set("long","一颗红红的丹药，据说"+ZJURL("cmds:fuyong tianxing dan")+ZJSIZE(22)+HIG
				+"服用"NOR"后可改变自己的天性。"ZJBR+HIR"注意：只能使用一次，且不符合天性的技能会被清除，慎用！"NOR"\n");
		set("yuanbao", 1000);
	}
	set("action_list", ([
		"使用" : "fuyong tianxing dan",
	]));
	set_amount(1);
	setup();
	
}

void init()
{
	add_action("do_eat", "fuyong");
}

int do_eat(string arg)
{
	object me = this_player();		
	object ob;		
	string character, id, id2, msg;
	
	if (me->query("fuyongtianxing", 1)) {
		tell_object(me, "你已经使用过一次天性丹了，不可以再使用。\n");
		return 1;
	}
	if (sscanf(arg,"%s %s %s", character, id, id2) != 3)
	{
		msg = ZJOBLONG +HIR"注意：只能使用一次，且不符合天性的技能会被清除，慎用！"NOR+ZJBR+
		      "心狠手辣，宗师技能-九阴神功"ZJBR
			"光明磊落，宗师技能-南海玄功"ZJBR
			"狡黠多变，宗师技能-不败神功"ZJBR
			"阴险奸诈，宗师技能-葵花魔功"ZJBR
			HIY"当前天性："+me->query("character")+ZJBR+NOR+HIG"请选择你想要的天性："NOR"\n";
		
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "光明磊落:fuyong 光明磊落 tianxing dan";
		msg += ZJSEP"狡黠多变:fuyong 狡黠多变 tianxing dan";
		msg += ZJSEP"阴险奸诈:fuyong 阴险奸诈 tianxing dan";
		msg += ZJSEP"心狠手辣:fuyong 心狠手辣 tianxing dan";
		
		write(msg + "\n");
		return 1;
	}
	if (!id(id + " " +id2))
		return 0;	
	
	if( !objectp(ob = present(id + " " +id2, me)) )
		return 0;	
		
	tell_object(me, "你一仰脖，吞下一颗" + name() +"。\n");
	
	do_character(me, character);

	return 1;
}

void do_character(object player, string character)
{
	if (character !="光明磊落" && character !="狡黠多变" && character !="阴险奸诈" && character !="心狠手辣") {
		tell_object(player, "没有这种天性！\n");
		return;
	}

	if(player->query("character") == character)
	{
		tell_object(player,sprintf("你本来就是%s！\n", character));
		return;
	}

	player->set("character", character);
	tell_object(player,"改变天性为："+character+"，成功！\n");
	//检查分配先天后的技能是否符合要求，不符合的删除
	UPDATE_D->check_skill(player);
	player->set("fuyongtianxing", time());
	player->save();
	log_file("/cmds/tianxing", sprintf("%s %s %s\n", player->name()+"("+player->query("id")+")", "天性="+character, CHINESE_D->chinese_date(time(), 2)));
	add_amount(-1);
}
