/**
 * @brief 召唤物品到使用者身上
 * @param me 召唤者对象，必须是有效且拥有足够内力的对象。
 * @param item 要召唤的物品对象，必须是不在召唤者身上的有效物品。
 * @return 1 召唤成功，物品已移动到召唤者身上并可能装备。
 * @details 该函数实现了召唤术，消耗500点内力将物品从远处召唤到召唤者手中。
 *          如果物品已经在召唤者身上，或者召唤者内力不足，则召唤失败。
 *          召唤过程会产生不同的视觉效果，根据物品所在的位置和随机类型显示不同的场景。
 *          成功召唤后，物品会自动装备到召唤者身上（如果是装备类物品）。
 */
int receive_summon(object me, object item)
{
	object env;
	object temp;
	int type;

	if ((env = environment(item)) && env == me)
	{
		tell_object(me, item->name() + "不就在你身上"
			    "嘛？你召唤个什么劲？\n");
		return 1;
	}

	if (me->query("neili") < 500)
	{
		tell_object(me, "你试图呼唤" + item->name() +
			    "，可是难以进入境界，看来是内力不济。\n");
		return 0;
	}
	me->add("neili", -500);

	message_vision(HIW "$N" HIW "突然大喝一声，伸出右手凌空"
		       "一抓，忽然乌云密布，雷声隐隐。"NOR"\n", me);

	if (env == environment(me))
	{
		message_vision(HIW "只见地上的" + item->name() +
			       HIW "应声而起，飞跃至$N" HIW
			       "的掌中！"NOR"\n", me);
	} else
	{
		type = random(3);
		if (env)
		{
			if (env->is_character() && environment(env))
					env = environment(env);

			switch (type)
			{
			case 0:
				message("vision", HIW "天空中传来隐隐的雷声"
					"，忽然电闪雷鸣，" + item->name() +
					HIW "腾空而起，"
					"消失不见！"NOR"\n", env);
				break;
			case 1:
				message("vision", HIC "一道神光从天而降"
					"，罩定了" + item->name() + HIC "，只见" +
					item->name() + HIC "化作长虹破空而"
					"走。"NOR"\n", env);
				break;
			default:
				message("vision", HIY "忽然间麝香遍地，氤氲弥漫，" +
					item->name() + HIY "叮呤呤的抖动数下，化作一"
					"道金光转瞬不见！"NOR"\n", env);
				break;
			}

			if (interactive(env = environment(item)))
			{
				tell_object(env, HIM + item->name() +
						 HIM "忽然离你而去了！"NOR"\n");
			}
		}

		switch (type)
		{
		case 0:
			message_vision(HIW "一声" HIR "霹雳" HIW "，"
				       "闪电划破长空，" + item->name() + HIW
				       "从天而降，飞入$N" HIW "的手中！"NOR"\n", me);
			break;
		case 1:
			message_vision(HIW "一道" HIY "长虹" HIW "扫过"
				       "天空，只见" + item->name() + HIW
					"落入了$N" HIW "的掌中！"NOR"\n", me);
			break;
		default:
			message_vision(HIW "只见" + item->name() + HIW "呤呤作响，大"
				       "放异彩，挟云带雾，突现在$N"
				       HIW "的掌中！"NOR"\n", me);
			break;
		}
	}

	// 取消no_get属性
	item->delete_temp("stab_by");
	item->delete("no_get");

	item->move(me, 1);
	if (environment(item) != me)
		return 1;

	if (item->query("armor_type"))
	{
		// is armor
		temp = me->query_temp("armor/" + item->query("armor_type"));
		if (temp) temp->unequip();
		WEAR_CMD->do_wear(me, item);
	} else
	if (item->query("skill_type"))
	{
		if (temp = me->query_temp("weapon"))
			temp->unequip();
		if (temp = me->query_temp("secondary_weapon"))
			temp->unequip();
		WIELD_CMD->do_wield(me, item);
	}

	return 1;
}


/**
 * @brief 隐藏指定物品
 * @param me 执行隐藏动作的对象，必须是物品的所有者
 * @param item 要被隐藏的物品对象
 * @return int 成功隐藏返回1，失败返回0
 * @details 该函数允许物品所有者消耗精力值来使物品完全消失。物品必须是调用者所有，且调用者需要有足够的精力值。
 */
int hide_anywhere(object me, object item)
{
	if (item->item_owner() != me->query("id"))
		return 0;

	if (me->query("jingli") < 100)
	{
		tell_object(me, "你试图令" + item->name() +
			    "遁去，可是精力不济，难以发挥它的能力。\n");
		return 0;
	}
	me->add("jingli", -100);

	message_vision(HIM "$N" HIM "轻轻一旋" + item->name() +
		       HIM "，已然了无踪迹。\n", me);
	destruct(item);
	return 1;
}

// 追寻物品
int receive_miss(object me, object item)
{
	object env;

	env = environment(item);

	if (me->is_busy())
	{
		write("你正忙，等有空了再说。\n");
		return 0;
	}

	if (me->is_fighting())
	{
		write("等你打完了架再说吧！\n");
		return 0;
	}

	if (env == environment(me))
	{
		write("你瞪着" + item->name() + "，看啥？\n");
		return 0;
	}

	if (env == me)
	{
		write("你摸着" + item->name() + "，发了半天的呆。\n");
		return 0;
	}

	if (! objectp(env) || userp(env) || environment(env))
	{
		write("你试图感应" + item->name() + "，但是感觉非常的渺茫。\n");
		return 0;
	}

	if (! wizardp(me) && ! env->query("outdoors"))
	{
		write("冥冥中你感应到" + item->name() + "，但是似乎难以到达那里。\n");
		return 0;
	}

	message("vision", me->name() + "在凝神思索，不知道要做些什么。\n",
		environment(me), ({ me }));
	if (me->query("jingli") < 400)
	{
		write("你觉得" + item->name() + "的感觉相当"
		      "飘忽，看来精力不济，难以感应。\n");
		return 0;
	}

	// 消耗精力
	me->add("jingli", -300 - random(100));
	message_vision(HIM "$N" HIM "口中念念有词，转瞬天际一道长虹划"
		       "过，$N" HIM "驾彩虹而走。"NOR"\n", me);
	tell_object(me, "你追寻" + item->name() + "而去。\n");
	me->move(environment(item));
	message("vision", HIM "一道彩虹划过天际，" + me->name() +
		HIM "飘然落下，有若神仙。"NOR"\n", environment(me), ({ me }));
	tell_object(me, HIM "你追寻到了" + item->name() +
		    HIM "，落下遁光。"NOR"\n");
	return 1;
}

// 插在地上
int do_stab(object me, object item)
{
	if (! item->is_weapon() && item->query("armor_type") != "hands")
		return notify_fail(item->name() + "也能插在地上？\n");

	if (! environment(me)->query("outdoors") &&
	    ! wizardp(me))
		return notify_fail("在这里乱弄什么！\n");

	if (! item->is_stay_in_room())
		return notify_fail("这" + item->name() + "就别放在这儿了。\n");

	item->set("no_get", bind((: call_other, __FILE__, "do_get_item", item :), item));
	item->set_temp("stab_by", me->query("id"));

	message_vision("$N随手将" + item->name() + "往地上一插，发出“嚓愣”一声响。\n", me);
	item->move(environment(me));
	return 1;
}


/**
 * @brief 处理玩家获取特殊插入物品的逻辑
 * @param object item 玩家试图获取的物品对象
 * @return mixed 如果玩家无权获取则返回提示字符串，成功获取返回0，无玩家对象返回1
 * @details 该函数用于控制只有特定玩家才能拔起的物品，比如插入地面的武器或固定在某处的宝物。
 *         物品可能被临时标记为"stab_by"表示谁插入了它，或者有固定的所有者"item_owner"。
 *         只有插入者或所有者才能成功获取该物品，其他玩家尝试时会获得物品无法撼动的反馈。
 *         成功获取后，物品会清除"stab_by"临时标记和"no_get"限制，使其变为普通可拾取状态。
 */
mixed do_get_item(object item)
{
	object me;

	if (! objectp(me = this_player()))
		return 1;

	if (me->query("id") != item->query_temp("stab_by") &&
	    me->query("id") != item->item_owner())
		return "你试图将" + item->name() + "拔起，却发现它仿佛是生长在这里一般，无法撼动。\n";

	message_vision("$N轻轻一拔" + item->name() + "，只听“咔”的一声响。\n", me);
	item->delete_temp("stab_by");
	item->delete("no_get");
	return 0;
}