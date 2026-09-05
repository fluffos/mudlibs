// by Vast@pkuxkx
// all comments added by Vast

//这个函数主要用来形成npc出现的几率问题
//产生Npc的房间需要设定以下几个参数
// 1.时间周期值（用period和delay两个参数来控制）; 2.每次最多出现的npc数量；3.出现概率,; 4.有可能出现的npc

void npc_gen(mapping para, string *npc, object room)
{
	int i, n;
	int period, delay, amount, odds;
	object beast;

	period = para["period"];
	delay = para["delay"];
	amount = para["max_amount"];
	odds = para["odds"];

	n = random(amount);

	room->add("luding_maze/period", -1);

	if(period > 0)
	{
		if(random(100) < odds )
		{
			for(i = 0; i < n + 1; i++)
			{
				beast = new(npc[random(sizeof(npc))]);
				if(objectp(beast))
				beast->move(room);
			}
		}
	}
	else if(period <= delay)
	room->delete("luding_maze");
}