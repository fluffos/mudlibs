
string *oblist =({
	"/clone/mongolia/bonus/sword",
	"/clone/mongolia/bonus/blade",
	"/clone/mongolia/bonus/staff",
	"/clone/mongolia/bonus/whip",
	"/clone/mongolia/bonus/armor",
        "/clone/mongolia/bonus/boots",
	"/clone/mongolia/bonus/wrists",
	"/clone/mongolia/bonus/necklace.lpc",
	"/clone/mongolia/bonus/kui",
	"/clone/mongolia/bonus/craze-dan",
	"/clone/mongolia/bonus/hold-age",
});
void afterdie_func(object killer)
{
	object money;
	object obj;
	int amount;

	amount = query("level") / 10;
	money = new(SILVER_OB);
	money->set_amount(amount);
	tell_object(killer,sprintf(HIG"恭喜！最后一击获得 %s 两白银！\n"NOR,
		chinese_number(amount)));
	money->move(killer,1);

	if(NATURE_D->is_night() && random(150) < killer->query_kar())
	{
		obj = new(oblist[random(sizeof(oblist))]);
		obj->move(killer,1);
		tell_object(killer,sprintf(HIG"\n只听见“啪嗒”一声，从%s"HIG"身上掉"
		                              "下了一%s%s"HIG"。\n"NOR,
					      name(),obj->query("unit"),
					      obj->name()));
	}
}
