// powerup.c 玉女心法加力


inherit F_CLEAN_UP;

string *pictures=({
  HIY"少思、"YEL"少念、"HIC"少欲、"HIR"少事、"HIB"少语、"MAG"少笑"HIW,
  YEL"少愁、"CYN"少乐、"HIG"少喜、"HIR"少怒、"HIY"少好、"RED"少恶"HIW,
  HIC"多思"HIG"则"HIW"神怠，"HIB"多念"MAG"则"HIY"精散"HIW,
  HIR"多欲"YEL"则"BLU"智损，"MAG"多事"RED"则"HIG"形疲"HIW,
  HIB"多语"CYN"则"RED"气促，"HIR"多笑"HIC"则"BLU"肝伤"HIW,
  MAG"多愁"YEL"则"HIR"心慑，"RED"多乐"BLU"则"HIY"意溢"HIW,
  HIW"多喜"HIG"则"HIY"忘错"MAG"昏乱，"HIC"多怒"HIR"则"HIB"百脉"HIG"不定"HIW,
  HIG"多好"RED"则"BLU"专迷"HIG"不治，"HIW"多恶"HIB"则"MAG"焦煎"CYN"无宁"HIW
});

void remove_effect(object me, int amount);

string query_name() { return "玉女"ZJBR"心经"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
        string picture;

	if (target != me)
		return notify_fail("你只能提升自己的战斗力。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	if ((int)me->query_skill("yunv-xinjing",1) < 120)
		return notify_fail("你的玉女心经还不够精熟。\n");

	skill = me->query_skill("force");

        picture = pictures[random(sizeof(pictures))];
        message_vision(HIY"$N屏气凝神，口中默念"HIW"「"+picture+"」"HIY"的玉女心经正反要诀。"NOR"\n", me);

//	message_combatd(HIC "$N" HIC "脸色微微一沉，双掌向外一分，姿势曼"
//			"妙，如一朵" HIW "白玉兰花" HIC "盛开在初冬的寒风中！"NOR"\n", me);

	me->add_temp("apply/attack", skill / 4);
	me->add_temp("apply/dodge", skill / 4);
	me->add_temp("apply/defense", skill / 4);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill / 4 :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/dodge", -amount);
		me->add_temp("apply/defense", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的玉女心经运行完毕，将内力收回丹田。\n");
	}
}
