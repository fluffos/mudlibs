// 装备修理员
inherit NPC;

void create()
{
	set_name("修理员", ({ "xiu li" }));

	set("gender", "男性");
	set("age", 16);
	set("per", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("str", 25);
	set("title",HIM"修理装备"NOR);
	set("long","我可以为你修理装备，你想修理什么装备呢？\n");
	set("no_kill",1);
	set("inquiry", ([
		"修理装备" : "修理装备指令：xiu<需要修理装备ID>\n",
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_xiu", "xiu");
}

int do_xiu_2(object me,string arg)
{
	object *inv,item;
	int size,i,gold,p=0,add_money,ok=0;

	inv = all_inventory(me);
	size = sizeof(inv);
	for(i=0;i<size;i++)
	{
		if(!inv[i]->query_xy()) continue;
		item = inv[i];
		if(!item->query("max_naijiu"))
		{
			item->set("max_naijiu",20000);
			ok = 1;
		}
		if(item->query("max_naijiu") < 2)
		{
			tell_object(me,sprintf("%s到处都是补丁,已经无法修理了。\n",item->name()));
			continue;
		}
		if(item->query("max_lasting") >= item->query("max_naijiu")) continue;

		gold = me->query("rmb");
		add_money = (item->query("max_naijiu") - item->query("max_lasting"))/5000;
		if(add_money < 1) add_money = 1;
		if(item->query("level") < 50) add_money = 0;
		if(gold < add_money)
		{
			tell_object(me,"抱歉你的人民币不足，无法为你修理。\n");
			return 1;
		}
		me->add("rmb",-add_money);
		if(!ok) item->add("max_naijiu",-(1000+random(500)));
		item->set("max_lasting",item->query("max_naijiu"));
		item->delete("long");
		item->init();
		tell_object(me,sprintf("%s修理完成，请look %s 察看耐久度。\n",item->name(),item->query("id")));
		p++;
	}
	if(p) tell_object(me,sprintf("本次共修理了%d件装备\n",p));
	else tell_object(me,"没有可修理的装备.\n");
	return 1;
}

int do_xiu(string age)
{
	object me,npc,item;
	int gold,add_money,ok=0;
	me = this_player();
	npc = this_object();
	
	if(!age || age == " ")
	{
		tell_object(me,"你想修理什么装备呢？\n");
		return 1;
	}

	if(age = "all") return do_xiu_2(me,age);

	if(!item = present(age,me))
	{
		tell_object(me,"你身上没有这件物品。\n");
		return 1;
	}
	if(!item->query_xy())
	{
		tell_object(me,"这件装备不用修理。\n");
		return 1;
	}
	if(!item->query("max_naijiu"))
	{
		item->set("max_naijiu",20000);
		ok = 1;
	}
	if(item->query("max_naijiu") < 2)
	{
		tell_object(me,"这件装备到处都是补丁,已经无法修理了。\n");
		return 1;
	}
	if(item->query("max_lasting") >= item->query("max_naijiu"))
	{
		tell_object(me,"这件装备毫无瑕疵，无法为你修理。\n");
		return 1;
	}
	gold = me->query("rmb");
	add_money = (item->query("max_lasting") - item->query("max_lasting"))/5000;
	if(add_money < 1) add_money = 1;
	if(item->query("level") < 50) add_money = 0;
	if(gold < add_money)
	{
		tell_object(me,"抱歉你的存款不足1元人民币，无法为你修理。\n");
		return 1;
	}
	me->add("rmb",-add_money);
	if(!ok) item->add("max_naijiu",-(1000+random(500)));
	item->set("max_lasting",item->query("max_naijiu"));
	item->delete("long");
	item->init();
	tell_object(me,"装备修理完成，请look <装备ID> 察看耐久度。\n");
	return 1;
}