// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob,oldob;
	
	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if( !arg )
		return notify_fail("你要拜谁为师？\n");
	if( !(ob = present(arg, environment(me)))||!ob->is_character() )
		return notify_fail("你想拜谁为师？\n");
	if( me->query("自创门派/开山祖师",1))
		return notify_fail("你堂堂一派之主，竟然改投他人门下，岂不丢人？\n");
	if( me->query("自创门派",1))
	{
		if(ob->query("自创门派/门派名称",1)==me->query("自创门派/门派名称"))
		{
			if(ob->name()==me->query("自创门派/master_name",1)&&ob->query("id",1)==me->query("自创门派/master_id",1))
				return notify_fail("$N恭恭敬敬的向$n磕了个响头，说：徒儿给师父您老人家请安了！\n");
		}				
		if( me->query("family",1))
			return notify_fail("你既已有门派，便不能再拜玩家为师了。\n");
	}
	if( ob->query("自创门派/开山祖师",1))
	{
		if( userp(ob) && (object)ob->query_temp("pending/accept")!=me )
		{
			message_vision("\n$N对著$n说道：" + RANK_D->query_self(me) 
				+ me->name() + "久仰" + RANK_D->query_respect(ob) + 
				"的大名，如蒙" + RANK_D->query_respect(ob) + "不弃，收我为徒，徒儿定当终生侍奉师父左右。\n", me, ob);
			me->set_temp("pending/baishi", ob);
			tell_object(ob, YEL "如果你愿意收"+me->name()+YEL+"为徒，请你对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 accept 指令。\n" NOR);
			write(YEL "由于对方是由玩家控制的人物，你必须等对方同意才能入门。\n" NOR);	
		}
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : baishi <对象>
这个指令能让你拜自创门派的玩家为师，如果对方也答应要收你为徒的话，
要等到对方用 accept 指令收你为弟子才能正式拜师。
注意如果你已拜了系统门派后，就不能再改投玩家门下。

如果对你的师父使用这个指令，会变成向师父请安。

see also: accept
HELP
		);
	return 1;
}


