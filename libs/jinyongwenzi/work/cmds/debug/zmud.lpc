// zmud.c  ;放在/cmds下以便可以使用force_me函数
// By Jpei

#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit FINGER;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

void create()
{
	seteuid(getuid());

	set("long",@LONG
这是一个叫做ZMUD的程式。

键入<help zmud>以获得更多的资讯。
LONG
);

	set("unit","个");
	set("no_get", 1);
	set("no_drop", 1);

	set("material", "program");
	set("armor_prop/armor", 100);
	set_weight(1);
	setup();
}

void init()
{
	object me = this_player();

	seteuid(geteuid());
	if (!wizardp(me)) return;
	if (me && present(this_object(), me))
		set_name (me->name(1) + "的ZMUD程式", ({ "zmud program" }));
	else
		set_name ("ZMUD程式", ({ "zmud program" }));

	if (me && present(this_object(), me)) {
		add_action("help", "help");
		add_action("do_loop", ({"loop", "#"}));
		add_action("do_run", ({"run", "~"}));
	}
}

int help(string str)
{

	if (str != "zmud" && str != "zmud program") return 0;

	write(@Help

	你可以使用以下的几个命令:

	loop或# <次数n> <命令>		<重复做命令n次>
	run或~ <由;隔开的命令组合>	<一次执行由;隔开的多条命令>

Help
);
	return 1;
}

int query_autoload()
{
	if (wizardp(this_player())) return 1;
	else return 0;
}

int do_loop(string arg)
{
	int count, i;
        object me = this_player();
        string cmd;

	if (!geteuid()) seteuid(getuid());
        if (!arg || arg == "") return notify_fail ("[ZMUD]: 你想做什么呀？\n");
        if (sscanf(arg,"%d %s", count, cmd) != 2)
		return notify_fail ("loop或# <count> <cmd>\n");
	for (i = 0; i < count; i++)
		if (objectp(me)) me->force_me(cmd);
	return 1;
}

int do_run(string arg)
{
	int i;
        object me = this_player();
        string *cmds;

	if (!geteuid()) seteuid(getuid());
        if (!arg || arg == "") return notify_fail ("[ZMUD]: 你想做什么呀？\n");
	cmds = explode(arg, ";") - ({ "" });
	for (i = 0; i < sizeof(cmds); i++)
		if (objectp(me)) me->force_me(cmds[i]);
	return 1;
}

