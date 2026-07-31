// jiangli.c
// 奖励发现bug的玩家
// idea@yqyl

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{
	string id,reason,present;
	object player,gold;
	int i;
	
	if( !arg || arg=="" || sscanf(arg, "%s for %s", id, reason)!=2)
		return notify_fail("指令格式：jiangli <玩家id> for <简要介绍bug>\n");

	player = find_player(id);
	if (!player) return notify_fail("没有这个人\n");
	if (wizardp(player)) return notify_fail("不能奖励巫师\n");
	i=random(3);
	switch (i)
	{
		case 0:
			player->add("combat_exp", 400);
			present="经验 400";
			break;
		case 1:
			player->add("potential",200);
			present="潜能 200";
			break;
		case 2:
			gold = new("/clone/money/gold");
			gold->set_amount(2);
			gold->move(player);
			present="2 gold";
			break;
	}
	tell_object(player,HBRED""+me->query("name")+"奖励给你"+present+"！\n"NOR);
	write(HBRED"你奖励"+player->query("name")+present+"！\n"NOR);
	
	log_file("jiangli",
		sprintf("%s(%s) 奖励 %s(%s) %s 因为 %s  on %s\n",
		me->name(1),
		geteuid(me),
		player->name(1),
		geteuid(player),
		present,
		reason,
		ctime(time()) ));
		
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : jiangli <玩家id> for <简要介绍bug>

本命令给与发现小bug(程序错误--程序失误,且没造成巨大损失的)
的player以奖励.注意请慎用本命令,如果bug问题不明确,经请示讨
论再决定
例子	jiangli tryid for 发现tree错误
HELP	);
	return 1;
}