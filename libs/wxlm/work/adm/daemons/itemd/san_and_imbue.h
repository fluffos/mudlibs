
int do_san(object me, object item)
{
	string my_id;
	string ss,*sss;
 
	int san;

	if (!item->query("skill_type") && item->query("armor_type") != "hands" && (!item->is_item_make() || !item->query("armor_type")))
		// 武器、拳套或自制防具才能圣化
		return notify_fail("只有武器、拳套和自制防具才能进行圣化。\n");

	if (me->is_busy())
		return notify_fail("你现在正忙。\n");

	 if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");

	// 武器类的圣化
	if (item->query("magic/power") > 0)
		return notify_fail("现在" + item->name() + "的威力已经得到了充分的发挥了。\n");

	if (item->query("magic/imbue_ok"))
		return notify_fail("现在" + item->name() + "的潜力已经充分挖掘了，现在只是需要最后一步融合。\n");

	my_id = me->query("id");

	if (item->query("magic/imbue_name")&&item->query("magic/imbue_ob"))
		return notify_fail("现在" + item->name() + "已经被充分的圣化了，需要浸入"+ item->query("magic/imbue_name")+ "以进一步磨练。\n");

	if (me->query("neili") < me->query("max_neili") * 9 / 10)
		return notify_fail("你现在内力并不充沛，怎敢贸然运用？\n");

	if (me->query("jingli") < me->query("max_jingli") * 9 / 10)
		return notify_fail("你现在精力不济，怎敢贸然运用？\n");

	if (me->query_skill("force") < 100)
		return notify_fail("你的内功根基不够扎实，不能贸然圣化。\n");

	if (me->query("max_neili") < 5000)
		return notify_fail("你尝试运了一下内力，无法顺利运足一个周天，难以施展你的能力。\n");

	if (me->query("max_jingli") < 1000)
		return notify_fail("你试图凝神运用精力，但是感觉尚有欠缺。\n");

	message_sort(HIM "$N" HIM "轻轻抚过$n" HIM "，两指点于其上，同"
		     "时运转丹田内力，经由奇经\n八脉源源由体内流出，注"
		     "入$n" HIM "。\n忽的只见氤氲紫气从$n" HIM
		     "上腾然升起，弥漫在四周。"NOR"\n", me, item);

	if (me->query("max_neili") < me->query_neili_limit() - 200)
	{
		if (random(2) == 1)
		{
			// 内力未满警告
			message_vision(HIR "$N" HIR "脸色忽然变了变。"NOR"\n",me);
			tell_object(me, HIC "你忽然觉得丹田气息有些错乱。"NOR"\n");
		} else
		{
			message_vision(HIR "$N" HIR "忽然闷哼一声，脸上刹时大汗淋漓！"NOR"\n", me);
			tell_object(me, HIC "你感到可能是你的内力尚未锻炼到极至，结果损伤了你的内功根基。"NOR"\n");
			tell_object(me, HIC "你的基本内功下降了。\n");
			me->set_skill("force", me->query_skill("force", 1) - 10 - random(5));
			return 1;
		}
	}

	// 统计IMBUE过的次数，并用来计算本次MAX_NEILI/JINGLI的消耗
	san = item->query("magic/imbue");

	//me->add("max_neili", -(san + 5));
	me->add("neili", -(san * 10 + 100));
	me->add("max_jingli", -(san * 5));
	me->add("jingli", -(san * 5 + 50));
	me->add("magic_points", -(san * 5 + 50));
	me->start_busy(1);

	if (item->item_owner() == my_id)
	{
		tell_object(me, HIW "你凝神片刻，觉得" + item->name() +  HIW "似乎有了灵性，跳跃不休，不禁微微一笑。"NOR"\n");
		message("vision", HIW + me->name() + HIW "忽然微微一笑。\n" HIW, environment(me), ({ me }));

		// 选定一个需要imbue的物品
		sss=keys(imbue_list);
		ss = sss[random(sizeof(sss))];
		item->set("magic/imbue_ob", ss);
		item->set("magic/imbue_name", imbue_list[ss]);
		tell_object(me,"接下来用"+ imbue_list[ss] + "来浸透一下" +item->name() + "吧。\n");
	}
	return 1;
}


/**
 * @brief 对物品进行浸透操作，提升物品的魔法属性
 * @param object me 执行浸透操作的玩家对象
 * @param object item 被浸透的物品对象
 * @return int 操作成功返回1，失败返回notify_fail的结果
 * @details 该函数实现了游戏中的物品浸透系统，玩家可以通过消耗内力和精力来提升物品的魔法属性。
 *          浸透操作需要满足多个条件：玩家不能忙碌、物品必须属于玩家、物品不能已有魔力、
 *          物品必须先经过圣化、玩家必须拥有浸透所需的材料、玩家的内力和精力必须达到一定要求。
 *          浸透成功后，物品的魔法属性会提升，当达到一定条件时，物品会进入可融合状态。
 */
int do_imbue(object me, object item)
{
	object imbue;

	if (me->is_busy())
		return notify_fail("你现在正忙。\n");

	 if(item->item_owner() != me->query("id"))
		  return notify_fail(item->name() + "不需要你来操心吧！\n");

	if (item->query("magic/power") > 0)
		return notify_fail("现在" + item->name() + "的威力已经得到了充分的发挥了。\n");

	if (item->query("magic/imbue_ok"))
		return notify_fail("现在" + item->name() + "的潜力已经充分挖掘了，现在只是需要最后一步融合。\n");

	if (!item->query("magic/imbue_name")||!item->query("magic/imbue_ob"))
		return notify_fail("你必须先对" + item->name() + "进行充分的圣化才行。\n");

	if (!objectp(imbue = present(item->query("magic/imbue_ob"),me)))
		return notify_fail("你身上没有" + item->query("magic/imbue_name") + "，拿什么浸透？\n");
	 
	if (me->query("max_neili") < 5000)
		return notify_fail("你尝试运了一下内力，无法顺利运足一个周天，难以施展你的能力。\n");

	if (me->query("neili") < 4000)
		return notify_fail("你感觉内力还有点欠缺，无法施展你的能力。\n");

	if (me->query("max_jingli") < 1000)
		return notify_fail("你试图凝神运用精力，但是感觉尚有欠缺。\n");
	 
	if (me->query("jingli") < 500)
		return notify_fail("你现在无法集中精力做这件事。\n");

	message_sort(HIM "$N" HIM "深吸一口气，面上笼罩了一层白霜，只手握住$n" +
		     imbue->name() +
		     HIM "，忽然间融化在掌心，晶莹欲透！$N"
		     HIM "随手一挥，将一汪清液洒在$n" HIM
		     "上，登时化做雾气，须臾成五彩，奇光闪烁。"NOR"\n",
		     me, item);
	
	if (me->query("max_neili") < me->query_neili_limit() - 200)
	{
		if (random(2) == 1)
		{
			// 内力未满警告
			message_vision(HIR "$N" HIR "脸色忽然变了变。"NOR"\n",me);
			tell_object(me, HIC "你忽然觉得丹田气息有些错乱。"NOR"\n");
		} else
		{
			message_vision(HIR "$N" HIR "忽然闷哼一声，脸上刹时大汗淋漓！"NOR"\n", me);
			tell_object(me, HIC "你感到可能是你的内力尚未锻炼到极至，结果损伤了你的内功根基。"NOR"\n");
			tell_object(me, HIC "你的基本内功下降了。\n");
			me->set_skill("force", me->query_skill("force", 1) - 10 - random(5));
			if(imbue->query_amount())
				imbue->add_amount(-1);
			else
				destruct(imbue);
			return 1;
		}
	}
	//me->add("max_neili", -100);
	me->set("neili", 0);
	me->add("max_jingli", -100);
	me->add("jingli", -500);

	tell_object(me, "你将" + imbue->name() + "的效力浸入了" + item->name() + "。\n");

	item->delete("magic/do_san");
	item->delete("magic/imbue_ob");
	item->delete("magic/imbue_name");
	if(imbue->query_amount())
		imbue->add_amount(-1);
	else
		destruct(imbue);
	me->start_busy(1);

	item->add("magic/imbue", 1);
	if (random(item->query("magic/imbue")) >= RANDOM_IMBUE_OK || me->query("imbue_will_ok"))
	{
		// 浸透完成
		tell_object(me, HIG "你忽然发现手中的" + item->name() + HIG "有一种跃跃欲试的感觉，似乎期待着什么。"NOR"\n");
		item->set("magic/imbue_ok", 1);
		me->delete("imbue_will_ok");
	}

	return 1;
}
