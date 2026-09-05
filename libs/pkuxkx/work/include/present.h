// 用于对 EFUN present() 的扩展补充
// lordstar 20180510

object present_npc(string arg, object env)
{
	object *allob;
	if (!arg || !objectp(env))
		return 0;
	allob = all_inventory(env);
	for (int i=0; i<sizeof(allob); i++)
	{
		if (allob[i]->query("id") == arg && !userp(allob[i]))
			return allob[i];
	}
	return 0;
}

object present_att(string arg, object env, string att, mixed value)
{
	object *allob;
	if (!arg || !objectp(env))
		return 0;
	if (!att)
		return present(arg, env);
	allob = all_inventory(env);
	for (int i=0; i<sizeof(allob); i++)
	{
		if (allob[i]->query("id") == arg && allob[i]->query(att) == value)
			return allob[i];
	}
	return 0;
}

object present_npc_att(string arg, object env, string att, mixed value)
{
	object *allob;
	if (!arg || !objectp(env))
		return 0;
	if (!att)
		return present(arg, env);
	allob = all_inventory(env);
	for (int i=0; i<sizeof(allob); i++)
	{
		if (allob[i]->query("id") == arg 
			&& !userp(allob[i])
			&& allob[i]->query(att) == value)
			return allob[i];
	}
	return 0;
}

