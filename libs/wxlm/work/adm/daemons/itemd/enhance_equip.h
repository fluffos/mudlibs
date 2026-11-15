
/**
 * @brief 在物品上镶嵌宝石，赋予物品魔力
 * @param me 执行镶嵌操作的角色对象
 * @param item 需要镶嵌宝石的物品对象
 * @param tessera 用于镶嵌的宝石对象
 * @return 成功返回1，失败返回0并通知失败原因
 * @details 该函数会检查角色状态、物品属性、宝石属性以及角色技能和资源，
 *          根据宝石的魔力强度确定镶嵌后的等级，并扣除相应金钱。
 *          镶嵌成功后，物品将获得魔力属性，宝石数量减少，角色进入忙碌状态。
 *          根据镶嵌结果，系统会发布相应的消息。
 */
int do_enchase(object me, object item, object tessera)
{
	int lvl,pw;

	if (me->is_busy())
		return notify_fail("你现在正忙。\n");

	if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");

	if (item->query("magic/power") > 0)
		return notify_fail("现在" + item->name() + "的威力已经得到了充分的发挥了。\n");

	if (! item->query("magic/imbue_ok"))
		return notify_fail("现在" + item->name() + "的潜力还没有充分的激发，未到镶嵌的时候。\n");

	if (! tessera->query("can_be_enchased"))
		return notify_fail(tessera->name() + "好象没法用来镶嵌吧。\n");

	if (! mapp(tessera->query("magic")))
		return notify_fail(tessera->name() + "不能发挥魔力，没有必要镶嵌在" + item->name() + "上面。\n");

	if (me->query_skill("certosina", 1) < (30+item->level_now()*30))
		return notify_fail("你觉得你的镶嵌技艺还不够娴熟，不敢贸然动手。\n");

	if (me->query("max_jingli", 1) < 5000)
		return notify_fail("你的精力太低了，不足以驾驭上帝之眼，无法镶嵌。\n");

	pw = tessera->query("magic/power");
	if(pw==30)
	{
		lvl = 1 + rand2(30,3);
	}
	else if(pw==60)
	{
		if(item->level_now()<3)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
		lvl = 31 + rand2(30,3);
	}
	else if(pw==100)
	{
		lvl = 61 + rand2(40,3);
		if(item->level_now()<5)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
	}
	else if(pw==150)
	{
		if(item->level_now()<7)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
		lvl = 101 + rand2(50,3);
	}
	else if(pw==200)
	{
		if(item->level_now()<9)
			return notify_fail(tessera->name() + "的魔力太强，而" + item->name() + "等级不够，请强化装备或者用低级宝石强化。\n");
		lvl = 151 + rand2(150,3);
	}
	else 
		lvl = 1;

	if (me->query("balance") < tessera->query("magic/power")*10000)
		return notify_fail("你钱庄存款不足，不能进行宝石镶嵌！\n");

	me->add("balance",-tessera->query("magic/power")*10000);
	if (me->query("magic_points")<90000)
		me->set("max_jingli",me->query_jingli_limit());

	message_sort(HIM "“喀啦”一声，$N" HIM "将" + tessera->name() + HIM "镶嵌到了$n" HIM "上面，只见$n" HIM "上隐隐的显过了一道奇异的光芒，随"
		     "即变得平静，说不出的平凡。"NOR"\n", me, item);

	tell_object(me, HIC "你感受" + item->name() + HIC "发生了不可言喻的变化。"NOR"\n");

	item->set("magic/power", lvl);
	item->set("magic/type", tessera->query("magic/type"));
	item->set("magic/tessera", tessera->name());
	item->save();
	tessera->add_amount(-1);

	// 发布消息
	if(lvl>149 && me->query("magic_points")>90000)
		CHANNEL_D->do_channel(this_object(), "rumor","听说神品" + item->name() + HIM + "来到了人间。");
	else if(lvl>99 && me->query("magic_points")>90000)
		CHANNEL_D->do_channel(this_object(), "rumor","听说" + item->name() + HIM + "锋芒乍现，威力大增。");

	me->start_busy(1);
	return 1;
}


/**
 * @brief 强化装备物品
 * @param object me 执行强化的玩家对象
 * @param object item 要强化的装备物品
 * @param object obj 用于强化的材料物品
 * @return int 强化成功返回1，失败返回0
 * @details 该函数允许玩家使用材料强化装备，会记录装备的贡献者信息(最多12人)，
 * 并根据装备类型更新相应的属性值。装备强化有等级上限(最高8级)，
 * 只有装备的拥有者才能进行强化操作。强化成功后会消耗材料并更新装备属性。
 */
int do_enhance(object me, object item, object obj)
{
	int exp;
	mapping o;
	string my_id;

	if (! me || ! obj)
		return 0;

	 if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");

	if(item->level_now()>8)
		return notify_fail("装备强化已达到最高等级，不需要再强化了！\n");
	exp = obj->query("item_exp");

	my_id = me->query("id");
	o = item->query("owner");
	if (! o) o = ([ ]);
	if (! undefinedp(o[my_id]) || sizeof(o) < 12)
		o[my_id] += exp;
	else
	{
		int i;
		int lowest;
		string *ks;

		lowest = 0;
		ks = keys(o);
		for (i = 1; i < sizeof(ks); i++)
			if (o[ks[lowest]] > o[ks[i]])
				lowest = i;
		map_delete(o, ks[lowest]);
		o += ([ my_id : exp ]);
	}
	item->set("owner", o);
	if(item->query("skill_type"))
	{
		item->set("weapon_prop/damage",item->apply_damage());
	}
	else if(item->query("armor_type")=="hands")
	{
		item->set("armor_prop/unarmed_damage",item->apply_damage());
	}
	else if(item->query("armor_type"))
	{
		item->set("armor_prop/armor",item->apply_armor());
	}
	tell_object(me, HIW "一阵微弱的光芒闪过，你觉得" + item->name() + HIW "似乎更具威力了。"NOR"\n");
	obj->add_amount(-1);
	if(obj)
		tell_object(me, HIM+ZJSIZE(20)+ZJURL("cmds:enhance "+file_name(item)+" with "+file_name(obj))"继续强化"NOR"\n");
	return 1;
}