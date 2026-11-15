
/**
 * @brief 触摸物品并可能触发特殊效果
 * @param me 执行触摸动作的玩家对象
 * @param item 被触摸的物品对象
 * @return 成功执行返回1，失败返回0
 * @details 该函数用于玩家触摸自己的物品，消耗精力并可能获得内力恢复。有极小概率会触发全场状态恢复效果。
 */
mixed do_touch(object me, object item)
{
	string msg;
	object ob;
	object *obs;
	mapping my;

	if (me->query("id") != item->item_owner())
	{
		message_vision("$N摸了一下" + item->name() + "，结果手被划破了，痛得大叫一声。\n", me);
		me->receive_damage("qi", 50 + random(50));
		return 1;
	}

	if (me->query("jingli") < 100)
	{
		me->set("jingli", 0);
		return notify_fail("你抱着" + item->name() + "摸了半天，口中念念有词。\n");
	}

	me->add("jingli", -80 - random(20));
	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "轻轻一弹$n"
		      HIM "，长吟道：“别来无恙乎？”"NOR"\n";
		break;
	case 1:
		msg = HIM "$N" HIM "轻轻抚过$n"
		      HIM "，感慨良深，作古风一首，$n"
		      HIM "铃铃作响，似以和之。"NOR"\n";
		break;
	default:
		msg = HIM "$N" HIM "抓着$n"
		      HIM "，沉思良久。"NOR"\n";
		break;
	}

	switch (random(3))
	{
	case 0:
		msg += HIM "$n" HIM "忽然闪过一道光华，飞跃而"
		       "起，散作千百流离。"NOR"\n";
		break;
	case 1:
		msg += HIM "$n" HIM "发出一声龙吟，悠悠不绝，"
		       "直沁入到你的心肺中去。"NOR"\n";
		break;
	default:
		msg += HIM "霎时$n" HIM "光芒四射，逼得你无法"
		       "目视，千奇百色，变幻无方。"NOR"\n";
		break;
	}

	msg = replace_string(msg, "$n", item->name());
	message_vision(msg, me);

	if (random(1000) == 1)
	{
		obs = filter_array(all_inventory(environment(me)), (: userp :));
		foreach (ob in obs)
		{
			my = ob->query_entire_dbase();
			my["jing"]   = my["eff_jing"] = my["max_jing"];
			my["qi"]     = my["eff_qi"]   = my["max_qi"];
			my["neili"]  = my["max_neili"];
			my["jingli"] = my["max_jingli"];
			ob->set_temp("nopoison", 1);
		}
		message("vision", HIY "你觉得浑身如同笼罩在阳光一般，暖洋洋的，说不出的舒服。"NOR"\n", obs);
	} else
	if (me->query("neili") < me->query("max_neili"))
	{
		me->set("neili", me->query("max_neili"));
		tell_object(me, HIY "你觉得一股热气从丹田冉冉升起。"NOR"\n");
	}
	return 1;
}


// 10级兵器攻击对手
mixed weapon10lv_hit_ob(object me, object victim, object weapon, int damage_bonus)
{
	mapping magic;
	int jingjia;
	int power, resistance;
	int damage;
	string msg;

	// 计算魔法效果
	magic = weapon->query("magic");
	power = magic["power"];
	damage = 0;
	resistance = 0;
	jingjia = me->query("jiajing");
	switch (magic["type"])
	{
	case "lighting":
		// 闪电攻击
		resistance = victim->query_temp("apply/resistance/lighting");
		damage = (power + jingjia) * 100 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);
		switch (random(3))
		{
		case 0:
			msg = HIY + weapon->name() + HIY "迸发出几道明亮的闪光，兹兹作响，让$n"HIY"不由为之酥麻。"NOR"\n";
			break;
		case 1:
			msg = HIY"一道电光闪过，" + weapon->name() + HIY"变得耀眼夺目，令$n"HIY"无法正视，心神俱废。"NOR"\n";
			break;
		default:
			msg = HIY"天际隐隐响起几声闷雷，紧接着一道霹雳直下，" + weapon->name() + HIY"忽明忽暗，五彩缤纷，震得$n"HIY"酸软无力。"NOR"\n";
			break;
		}
		break;

	case "cold":
		// 冷冻攻击
		resistance = victim->query_temp("apply/resistance/cold");
		damage = (power + jingjia) * 100 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);
		switch (random(3))
		{
		case 0:
			msg = HIB + weapon->name() + HIB "闪过一道冷涩的蓝光，让$n" HIB "不寒而栗。"NOR"\n";
			break;
		case 1:
			msg = HIB "忽然间" + weapon->name() + HIB"变得透体通蓝，一道道冰冷的寒光迸发出来，$n" HIB "浑身只是一冷。"NOR"\n";
			break;
		default:
			msg = HIB "一道光圈由" + weapon->name() + HIB "射出，森然盘旋在$n" HIB "四周，悄然无息。"NOR"\n";
			break;
		}
		break;

	case "fire":
		// 火焰攻击
		resistance = victim->query_temp("apply/resistance/fire");
		damage = (power + jingjia) * 100 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);
		switch (random(3))
		{
		case 0:
			msg = HIR + weapon->name() + HIR "蓦的腾起一串火焰，将$n" HIR "接连逼退了数步，惨叫连连。"NOR"\n";
			break;
		case 1:
			msg = HIR "一道火光从" + weapon->name() + HIR "上迸出，迅捷无伦的击中$n" HIR "，令人避无可避！"NOR"\n";
			break;
		default:
			msg = HIR "一串串火焰从" + weapon->name() + HIR "上飞溅射出，四下散开，接连击中$n" HIR "！"NOR"\n";
			break;
		}
		break;

	case "magic":
		// 魔法攻击
		resistance = victim->query_temp("apply/resistance/magic");
		damage = (power + jingjia) * 100 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);
		switch (random(3))
		{
		case 0:
			msg = HIM + weapon->name() + HIM "响起一阵奇异的声音，犹如龙吟，令$n" HIM "心神不定，神情恍惚。"NOR"\n";
			break;
		case 1:
			msg = HIM "“啵”的一声，" + weapon->name() + HIM"如击败革，却见$n" HIM "闷哼一声，摇晃不定！"NOR"\n";
			break;
		default:
			msg = HIM + weapon->name() + HIM "上旋出一道道五彩缤纷的光圈，笼罩了$n" HIM "，四下飞舞。"NOR"\n";
			break;
		}
		break;
	case "all":
		switch (random(3))
		{
		case 0:
			msg = HIM "$N" HIM "嘿然冷笑，抖动" + weapon->name() + HIM "，数道光华一起射出，将$n" HIM "困在当中，无法自拔。"NOR"\n";
			break;
		case 1:
			msg = HIC "$N" HIC "手中的" + weapon->name() + HIC "射出各种光芒，眩目夺人，一道道神采映射得天地尽情失色，让$n" 
					HIC "目瞪口呆！"NOR"\n";
			break;
		default:
			msg = HIW "$N" HIW "一声长叹，" + weapon->name() + HIW "轻轻递出，霎时万籁俱静，$n" HIW "只觉得整个人都跌进了地狱中去！"NOR"\n";
			break;
		}

		power = power/4;
		// 闪电攻击
		resistance = victim->query_temp("apply/resistance/lighting");
		damage = (power + jingjia) * 200 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);

		// 冷冻攻击：伤害精++和气+
		resistance = victim->query_temp("apply/resistance/cold");
		damage = (power + jingjia) * 200 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);

		// 火焰攻击：伤害精+和气++
		resistance = victim->query_temp("apply/resistance/fire");
		damage = (power + jingjia) * 200 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);

		// 魔法攻击：吸取气+
		resistance = victim->query_temp("apply/resistance/magic");
		damage = (power + jingjia) * 200 / (100 + resistance);
		ITEM_D->receive_damage(me, victim, "qi", damage);

		if(!random(3))
		{
			msg += HIC "$N" HIC "接着又一声冷笑，人与" + weapon->name() + HIC "合而为一，飞也似的扑向$n" HIC "！"NOR"\n";
			msg += HIR "$n" HIR "大骇之下慌忙后退，却哪里躲避得开？一时不禁破绽迭出，受伤不轻！\n";
			damage = power*3 + random(power);
			ITEM_D->receive_damage(me, victim, "qi", damage);
			ITEM_D->receive_wound(me, victim, "qi", damage);
		}
		break;
	default:
		msg += HIM "出问题了，请通知wiz处理。"NOR"\n";
		break;
	}
	if (random(3)) return msg;
}

// 9级兵器攻击对手
mixed weapon_hit_ob(object me, object victim, object weapon, int damage_bonus)
{
 
 
	int damage;

	if (random(2)) return;

	if (! living(victim)) return;

	// 计算damage：不论是空手武器还是普通兵器，统一计算
	if (weapon->is_weapon())
		damage = me->query_temp("apply/damage");
	else
		damage = me->query_temp("apply/unarmed_damage");

	switch (random(6))
	{
	case 0:
		ITEM_D->receive_wound(me, victim, "jing", damage / 4 + random(damage / 4));
		return HIY "$N" HIY "抖动手中的" + weapon->name() + HIY
		       "，幻化成夜空流星，数道" HIM "紫芒" HIY "破空袭向$n"
		       HIY "，光华夺目，令人目眩！"NOR"\n";
	case 1:
		ITEM_D->receive_wound(me, victim, "qi", damage / 2 + random(damage / 2));
		return HIR "$N" HIR "大喝一声，手中的" + weapon->name() +
		       HIR "遥指$n" HIR "，一道杀气登时将$n" HIR "震退数步。"NOR"\n";

	case 2:
	case 3:
	case 4:
		break;

	default:
		if (me->query_temp("weapon_performing"))
			break;
		me->start_call_out(bind((: call_other, __FILE__, "continue_attack",me, victim, weapon, 2 :), me), 0);//这里的2原来是5 + random(4)，现统一降低为2
	}
}

// 绝招：12连环攻击
void continue_attack(object me, object victim, object weapon, int times)
{
	int i;
	string msg;
	int ap, dp;

	if (! me || ! victim || ! weapon || ! me->is_fighting(victim))
		return;

	if (! living(victim))
		return;

	msg  = HIC "\n$N" HIC "一声冷笑，人与" + weapon->name() +
	       HIC "合而为一，飞也似的扑向$n" HIC "！"NOR"\n";
	ap = me->query_skill("force");
	dp = victim->query_skill("parry");
	if (ap / 2 + random(ap * 2) > dp)
		msg += HIR "$n" HIR "大骇之下慌忙后退，却哪里躲避得开？一时不禁破绽迭出！\n"
		       HIY "$N" HIY "抓住$n" HIY "露出的破绽，急挥手中的" +
		       weapon->name() + HIY "，连续" + chinese_number(times) +
		       "招全部指向$n" HIY "的要害！"NOR"\n";
	else
	{
		msg += HIC "$n" HIC "冥神抵挡，将$N" HIC "这必杀一击的所有变化全然封住！"NOR"\n";
		message_combatd(msg, me, victim);
		return;
	}

	message_combatd(msg, me, victim);

	if (! weapon->is_weapon())
		weapon = 0;

	me->set_temp("weapon_performing", 1);
	i = times;
	while (i--)
	{
		if (! me->is_fighting(victim)) break;
		if (! victim->is_busy() && random(2))
			victim->start_busy(1);
		COMBAT_D->do_attack(me, victim, weapon);
	}
	me->delete_temp("weapon_performing");
}