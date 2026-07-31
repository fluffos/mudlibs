// system.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

string fs(int supplied);
string fc(int cost);
void   show_update_info(string arg);

int main(object me, string arg)
{
	string msg;
	mapping cm;

	if (arg && sscanf(arg, "-ui%s", arg))
	{
		show_update_info(arg);
		return 1;
	}

	cm = COMBAT_D->query_entire_dbase();
	msg = "系统现在的配置：\n";
	if (! mapp(cm))
		msg += "不祥。\n\n";
	else
		msg += "PK 人数限制：每天不超过 " HIR +
		       cm["pk_perday"] + NOR " 人，每人不超过 "
		       HIR + cm["pk_perman"] + NOR + " 次。\n\n";

	cm = CPU_D->query_entire_dbase();
	msg += "最近一段时间系统使用CPU的情况统计：\n";
	msg += "系统提供CPU资源的满足度：" + fs(cm["last_0"]["supplied"]) +
	      "  游戏对CPU的占用率：" + fc(cm["last_0"]["cost"]) + "。\n";

	msg += sprintf("前一些时间CPU的满足度和占用率：%s/%s  %s/%s  %s/%s  %s/%s。\n",
		       fs(cm["last_1"]["supplied"]), fc(cm["last_1"]["cost"]),
		       fs(cm["last_2"]["supplied"]), fc(cm["last_2"]["cost"]),
		       fs(cm["last_3"]["supplied"]), fc(cm["last_3"]["cost"]),
		       fs(cm["last_4"]["supplied"]), fc(cm["last_4"]["cost"]));
	write(msg);
	return 1;
}

string fs(int supplied)
{
	if (supplied <= 70)
		return sprintf(RED "%d%%" NOR, supplied);
	else
	if (supplied <= 90)
		return sprintf(HIR "%d%%" NOR, supplied);

	return sprintf(WHT "%d%%" NOR, supplied);
}

string fc(int cost)
{
	if (cost >= 90)
		return sprintf(RED "%d%%" NOR, cost);
	else
	if (cost >= 70)
		return sprintf(HIR "%d%%" NOR, cost);

	return sprintf(WHT "%d%%" NOR, cost);
}

void show_update_info(string arg)
{
	mapping pri;
	string *fnames;
	string fname;
	string msg;
	int    count;

	pri = NEWS_D->query_family_priority();

	if (! mapp(pri))
	{
		write("没有门派的更新优先级信息，请查阅 NEWS_D。\n");
		return;
	}

	sscanf(arg, " %s", arg);
	if (sscanf(arg, "- %s %d", fname, count) == 2 ||
	    sscanf(arg, "-%s %d", fname, count) == 2)
		count = -count;

	if (sscanf(arg, "+ %s %d", fname, count) == 2||
	    sscanf(arg, "+%s %d", fname, count) == 2)
		;

	if (VERSION_D->is_release_server() && count != 0)
	{
		if (! SECURITY_D->valid_grant(this_player(), "(admin)"))
		{
			write("你没有权限调整门派更新的优先级设置。\n");
			return;
		}

		if (undefinedp(pri[fname]))
		{
			write("没有这个门派。\n");
			return;
		}

		pri[fname] += count;
		write("调整了" + FAMILY_D->query_family_name(fname) +
		      "的优先级，变化点数：" WHT + count + NOR "。\n");
		NEWS_D->save();
		return;
	}

	msg = "目前门派的更新优先级：\n";
	fnames = sort_array(keys(pri), (: $(pri)[$2] - $(pri)[$1] :));
	foreach (fname in fnames)
	{
		msg += sprintf("%-8s  %d\n",
			       FAMILY_D->query_family_name(fname),
			       pri[fname]);
	}
	write(msg);
}

int help(object me)
{
	write(@HELP
指令格式 : system [-ui] [+|- <门派> <点数>]
 
这个指令可以显示出目前游戏的通用配置和使用系统资源的状况。使
用 ui 参数可以查阅目前 MUD 设计者对于的门派的更新优先级别。
 
HELP );
	return 1;
}
