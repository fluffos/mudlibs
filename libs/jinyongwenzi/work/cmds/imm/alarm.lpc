// alarm.c creat by Look@SJ 19990909
// Modified by bbb 19991214
// Modified by snowman 14/12/1999
// Modified by Looklove 2000/8/25

#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 )
		return help(me);
	if( strlen(msg) > 40 ) return notify_fail("没必要搞这么长吧？\n");
	obj = find_player(target);
	if (!obj) return notify_fail("你要警告谁啊？好象没("+target+")这个人啊。\n");
	message("wizard", getuid(this_player(1))+"发布警告\n", users());
	if (obj->query("id") == "yuj")
		message("system", HIR "【警告】" + me->name(1) + "("+ me->query("id")
		+ ")「胡乱警告巫师」的行为造成了不良影响，如果再犯，将被请到桃花源作客。\n" NOR,users());
	else
		message("system", HIR "【警告】" + obj->name(1) + "("+ obj->query("id")
		+ ")「"+msg+"」的行为造成了不良影响，如果再犯，将被请到桃花源作客。\n" NOR,users());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：alarm <某人> <讯息>
你可以用这个指令警告一些违反游戏规则的玩家。
HELP
	);
	return 1;
}
