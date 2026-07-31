// rank.c

#include <ansi.h>

inherit F_CLEAN_UP;

private int   do_normal(object me, string arg);
private int   do_rank(object me, object ob, string arg);
private mixed check_rank(string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string who;
	string rank;

	if (! arg)
	{
		rank = RANK_D->query_rank(me);
		write("你现在的江湖头衔：" + rank + "\n");
		return 1;
	}

	if (! SECURITY_D->valid_grant(me, "(arch)"))
		return do_normal(me, arg);

	if (sscanf(arg, "%s %s", who, arg) != 2)
		return notify_fail("请参见 help rank 获得该命令的使用方法。\n");

	if (who == "me")
		ob = me;
	else
		ob = find_player(who);

	if (! objectp(ob))
		return notify_fail("没有这个玩家。\n");

	return do_rank(me, ob, arg);
}

// 普通玩家使用 rank 命令
private int do_normal(object me, string arg)
{
	if (! wiz_level(me) &&
	    time() - me->query_temp("last/set_rank") > 3600)
	{
		if (! me->query_temp("pending/set_rank"))
		{
			write("你需要缴纳一万两黄金的手续费，如果你确定，请再输入一次这个命令。\n");
			me->set_temp("pending/set_rank", 1);
			return 1;
		}

		if (me->query("balance") < 100000000)
			return notify_fail("你钱庄的存款不够。\n");

		me->add("balance", -100000000);
		write("在你退出游戏之前，你有六十分钟的时间可以自由设定你的头衔。\n");
		me->set_temp("last/set_rank", time());
	}

	return do_rank(me, me, arg);
}

int do_rank(object me, object ob, string arg)
{
	if (! stringp(arg = check_rank(arg)))
		return 0;

	ob->set("rank_info/rank", arg);
	write("你设定好了" + (me == ob ? "自己" : ob->name(1)) + "的头衔。\n");
	return 1;
}

private mixed check_rank(string arg)
{
	int len;
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	if ((len = strlen(filter_color(arg))) > 8)
		return notify_fail("你的头衔不能超过四个汉字。\n");

	while (len++ < 8)
	{
		arg += " ";
		if (len++ < 8)
			arg = " " + arg;
	}
	if (strlen(arg) > 100)
		return notify_fail("这个外号太长了，为了节约资源，请你重新设定。\n");

	return arg + NOR + HIY;
}

int help(object me)
{
	write(@HELP
如果你是没有经过授权的玩家：
指令格式 : rank [<头衔>]

这可以让你自行设定称号，修改称号所需要的手续费一万
两黄金自动从你的钱庄账号上扣除，在你未退出游戏的六
十分钟以内再次修改不需要缴纳任何手续费用。

请注意：设定的称号不要违反游戏规则，否则你可能遭受
到严厉的处罚。故意将头衔设置为系统保留的巫师头衔或
相近字眼的头衔将被视作散布让玩家混淆的信息，除取消
头衔外将会按照规则处罚。

如果你是具有使用该命令权限的玩家或巫师：
指令格式 : rank <玩家> <头衔>
 
这个指令可以让你为某人取一个响亮的头衔，但是只有巫
师才可以使用，你如果希望在外号中使用 ANSI 的控制字
元改变颜色，可以用以下的控制字串：

$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - 红色		$HIR$ - 亮红色
$GRN$ - 绿色		$HIG$ - 亮绿色
$YEL$ - 土黄色		$HIY$ - 黄色
$BLU$ - 深蓝色		$HIB$ - 蓝色
$MAG$ - 浅紫色		$HIM$ - 粉红色
$CYN$ - 蓝绿色		$HIC$ - 天青色
$WHT$ - 浅灰色		$HIW$ - 白色
 
其中系统自动会在字串尾端加一个 $NOR$。
HELP );
	return 1;
}
