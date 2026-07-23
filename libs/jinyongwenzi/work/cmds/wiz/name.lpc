// name.c
// last modify by Look@SJ

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	int cost = 2000000;
        string tmp;
        object ob = me;

        if( !arg )
                return notify_fail("你要给谁取什么名字？\n");

        if (sscanf(arg, "%s %s", tmp, arg) == 2)
                ob = present(tmp, environment(me));
        if (!ob) return notify_fail("这里没有这个人。\n");

        if (wiz_level(me) < wiz_level(ob))
                return notify_fail("你不能帮巫师等级比你高的巫师改名。\n");

	if (arg != "名字待定" && ob->query("name") != "名字待定") {
		if (ob->query("balance") < 2000000 && ! wizardp(ob))
			return notify_fail("这个人没有足够的存款用于改名。\n");
	} else cost = 0;

        if( strlen(arg) > 8 )
                return notify_fail("这个名字太长了，想一个短一点的、响亮一点的。\n");

        message_vision(HIY "$N将"+ob->name(1)+"的名字改为" + arg + "。\n" NOR, me);
        ob->set("name", arg);
        if( !wizardp(ob)) ob->add("balance", -cost);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: name [玩家] 名字
 
修改玩家或自己的名字。将从银行存款中扣除200 gold。

HELP );
        return 1;
}
