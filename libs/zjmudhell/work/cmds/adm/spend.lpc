// spend.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string str, str1;
	int amount;
	int yuan;
	int little;
	int rmb;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	if (! arg)
		return notify_fail("你要扣谁的钱？\n");

	if (sscanf(arg, "%s %s", arg, str) != 2)
		return notify_fail("格式：spend <id> <钱数>\n");

	if (sscanf(str, "%d.%s", yuan, str1) != 2)
		return notify_fail("钱数必须包括小数点。\n");

	switch (strlen(str1))
	{
	case 0:
		little = 0;
		break;

	case 1:
		if (str1[0] < '0' || str1[0] > '9')
			return notify_fail("钱数的格式不正确。\n");

		little = (str1[0] - '0') * 10;
		break;

	case 2:
		if (str1[0] < '0' || str1[0] > '9' ||
		    str1[1] < '0' || str1[1] > '9')
			return notify_fail("钱数的格式不正确。\n");

		little = (str1[0] - '0') * 10 + (str1[1] - '0');
		break;

	default:
		return notify_fail("钱数的格式不正确。\n");
	}

	ob = find_player(arg);
	if (! objectp(ob))
		return notify_fail("没有这个玩家。\n");

	amount = yuan * 100 + little;
	if (amount < 0)
		return notify_fail("你要扣除负的钱？\n");

	if (! amount)
		return notify_fail("你扣不扣钱啊？\n");

	if (amount > ob->query("rmb"))
		return notify_fail((string) ob->name(1) + "现在没有这么多钱。\n");

	rmb = ob->add("rmb", -amount);
	str = sprintf("扣除了%s账号上%4d元%d角%d分，余额：%4d元%d角%d分。\n",
		      ob->name(1),
		      yuan, (little / 10), (little % 10),
		      rmb / 100, (rmb % 100) / 10, (rmb % 100));
	write(str);

	log_file("nosave/spend",
		 sprintf("%s %s%s", log_time(time()), me->name(1), str));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : spend <id> <费用>
 
这个指令扣除该玩家身上的现金(人民币)数量。
 
HELP );
	return 1;
}
