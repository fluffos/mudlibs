/**
 * @brief 根据击杀行为给予武器奖励经验值
 * @param me 击杀者对象，通常是玩家对象
 * @param victim 被击杀者对象，可以是玩家或NPC
 * @param item 获得奖励的武器或装备对象
 * @details 该函数根据被击杀者的属性和击杀者的实力差距，给予武器经验值奖励。
 *          只有当被击杀者能说话、击杀者实力足够强、且满足其他条件时才会给予奖励。
 *          武器会根据被击杀者的善恶属性和类型（玩家/NPC）记录不同的战斗数据。
 *          每个武器最多记录12个玩家的经验值，当达到上限时会替换经验值最少的一个。
 */
void killer_reward(object me, object victim, object item)
{
	int exp;
	mapping o;
	string my_id;

	if (! me || ! victim)
		return;

	if (! victim->query("can_speak"))
		return;

	// record for this weapon
	if (victim->is_not_bad())  item->add("combat/WPK_NOTBAD", 1);
	if (victim->is_not_good()) item->add("combat/WPK_NOTGOOD", 1);
	if (victim->is_good())     item->add("combat/WPK_GOOD", 1);
	if (victim->is_bad())      item->add("combat/WPK_BAD", 1);

	if (userp(victim))
		item->add("combat/PKS", 1);
	else
		item->add("combat/MKS", 1);

	exp = (int)victim->query("combat_exp");
	if (exp < 10000 || me->query("combat_exp") < exp * 4 / 5 || exp < item->level_now()*300000 || item->item_owner()!=me->query("id"))
		return;

	if(random(2))
		return;

	exp /= 10000;
	if (exp > 250) exp = 100 + (exp - 250) / 16; 
	else if (exp > 50) exp = 50 + (exp - 50) / 4;
	if (exp>100) exp = 100;
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
}