inherit NPC;
#include <localtime.h>

void create()
{
	set_name("妙手神医", ({"shenyi"}));
	set("long", "他好像一脸猥琐的盯着你！");
	set("combat_exp", 10000);
	
	setup();
}

void init()
{
	add_action("do_zhengrong", "zhengrong");
}

int do_zhengrong(string arg)
{
	object who = this_player();
	int last_time, num;
	
	
	last_time = who->query("fuben_moku/last_time");
	if ((localtime(last_time)[LT_MON] == localtime(time())[LT_MON]) && (localtime(last_time)[LT_MDAY] == localtime(time())[LT_MDAY]))
	{
		write(ZJOBLONG + "一天只能整容一次。\n");
		return 0;
	}
	
	if (!arg)
	{
		write(INPUTTXT("一天一次，花费1金，50万以下修为不收费。"ZJBR"你想将容貌修改为多少？(10-30)", "zhengrong $txt#") + "\n");
		return 0;
	}
	
	if (!sscanf(arg, "%d", num) || num < 10 || num > 30)
	{
		write(ZJOBLONG + "请输入一个大于10，小于30的数。\n");
		return 0;
	}
	
	if (!MONEY_D->player_pay(who, 10000) && who->query("combat_exp") > 500000)
		return notify_fail(ZJOBLONG + "你的钱不够。\n");
	
	who->set("per", num);
	write("整容成功，你的容貌修改为" + num + "。\n");
	return 1;
}