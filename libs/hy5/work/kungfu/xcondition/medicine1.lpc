// medicine.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "你吃的金丹，药性过了！\n");
		return 0;
	}
	me->apply_condition("medicine1", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "medicine";
}
