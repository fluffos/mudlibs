// gengxin.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	object ob,env,gem;
	if (arg=="-h")
	return help(me);
	if (!identification(me,"太常寺卿")&&me->query("id")!="zine")
	return deny(me);
	env=environment(me);
	if (base_name(env)!="/d/yingtianfu/neicheng/taimiao")
	{
		tell_object(me,"只有在太庙才需要更替新的贡品。\n");
		return 1;
	}
	if (me->query("mud_age")-me->query("ming/taichang_gem")<3600*12)
	{
		tell_object(me,"暂时太庙的贡品还很新，不需要换新的贡品。\n");
		return 1;
	}
	me->set("ming/taichang_gem",me->query("mud_age"));
	gem=new("/obj/gem/gem");
	gem->move(me);
	message_vision("$N给太庙换上新的贡品和装饰，将一颗旧的$n收入囊中。\n",me,gem);
	return 1;
}
int help(object me)
{
    write("
指令格式 : ming gengxin
太常寺卿可在太庙更换新的贡品，获得旧的。
"    );
    return 1;
}
