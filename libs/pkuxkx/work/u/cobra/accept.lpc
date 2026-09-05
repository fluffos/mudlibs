// recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, oldob;
	int i;

	if( !arg ) 
		return notify_fail("你要收谁为徒？\n");
	if( !(ob = present(arg, environment(me)))||!ob->is_character() )
		return notify_fail("你要收谁为徒？\n");
	if( (object)ob->query_temp("pending/baishi",1)!=me)
		return notify_fail("对方并没有要拜你为师的意思啊？\n");
	if( ob==me )
		return notify_fail("收自己为弟子？好主意....不过没有用。\n");
	if( ob->is_apprentice_of(me) ) {
		message_vision("$N拍拍$n的头，说道：「好徒儿！」\n", me, ob);
		return 1;
	}
	if( !me->query("自创门派",1) )
		return notify_fail("你尚未开宗立派就想收徒吗？\n");
	if( (object)ob->query_temp("pending/baishi") == me )
	{
		if( !living(ob) )
		{
			message_vision("$N决定收$n为弟子。\n不过看样子$n显然没有办法行拜师之礼。\n",me, ob);
			return 1;
		}
		ob->set("自创门派/门派名称",me->query("自创门派/门派名称",1));
		ob->set("自创门派/gen",me->query("自创门派/gen",1)+1);
		ob->set("自创门派/master_name",me->query("name",1));
		ob->set("自创门派/master_id",me->query("id",1));
		ob->delete_temp("pending/apprentice");
		write("恭喜你新收了一名弟子！\n");
		tell_object( ob, sprintf("恭喜您成为%s的第%s代弟子。\n", me->query("自创门派/门派名称",1),
			chinese_number(ob->query("自创门派/gen",1)) ));
		return 1;
	}
	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : accept <对象>
 
这个指令能让你收某人为弟子, 如果对方也答应要拜你为师的话.
 
See Also:	baishi
HELP
        );
	return 1;
}

