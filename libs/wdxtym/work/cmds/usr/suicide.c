// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

private int slow_suicide(object me);
private int halt_suicide(object me);
private void check_password(string passwd, object me, int forever);

int main(object me, string arg)
{
	object *inv;
	int i;
	//if (!wizardp(me))
	//	return notify_fail("修正中，等待开放。\n");
	if (me->is_busy())
		return notify_fail("你上一个动作还没完成。\n");
/*	if( me->query("id")=="z217330")
	{
		return notify_fail("猫是死不了的。\n");
	}*/
	inv = deep_inventory(me);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (! userp(inv[i]) && ! playerp(inv[i])) continue;
		return notify_fail("你身上还有个大活人呢，想不开也别急呀？\n");
	}

	if( me->query("marry"))
	{
		return notify_fail("你还有伴侣在江湖里，怎么舍得删档？\n");
	}

	if( me->query("banghui"))
	{
		return notify_fail("你还有一帮兄弟在江湖里，怎么舍得删档？\n");
	}
	/*if( me->query("p_master"))
	{
		return notify_fail("你还有师傅在江湖里，怎么舍得删档？\n");
	}*/
    if(sizeof(me->query("p_dizi"))>0)
	{
		return notify_fail("你还有弟子在江湖里，怎么舍得删档？\n");
	}

	if( me->query("combat_exp") > 1000000 )
	{
		return notify_fail("提示：你的修为超出100万了，不能再删档了。\n");
	}

	if (! arg)
	{
		write(ZJOBLONG"您选择了直接删档的删档方式，这个人物的资料将被永久删除，且无法恢复，请慎重考虑。"ZJBR"你确定要删档么？\n"
			ZJOBACTS2+ZJMENUF(3,3,8,30)+"确定:suicide -f"ZJSEP"取消:shake\n");
		return 1;
	}
	else if (arg == "-f") 
	{
		check_password("YES",me,1);
	}
	else
		return notify_fail("你要干什么？\n");
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("ad_password");
	if (passwd!="YES")
	{
		write(HIR "你想了想决定先不删档了。"NOR"\n");
		return;
	}

	if (forever)
	{
		tell_object(me, HIR "\n你决定要删档了，如果三十秒钟内不后悔，就真的永别了。"NOR"\n");
		me->set_temp("suicide/time", time());
		me->set_temp("suicide/last", 0);
		me->set_temp("suicide/from", query_ip_number(me));
		me->start_busy(bind((: call_other, __FILE__, "slow_suicide", me :), me),
			       bind((: call_other, __FILE__, "halt_suicide", me :), me));
	}
}

int slow_suicide(object me)
{
	object link_ob;
	int t;

	if (! objectp(me) || previous_object() != me)
		return 0;

	t = time() - me->query_temp("suicide/time");
	if (t < me->query_temp("suicide/last"))
	{
		me->delete_temp("suicide/");
		return 0;
	}

	if (t < 30)
	{
		if (t - me->query_temp("suicide/last") < 5)
			return 1;

		tell_object(me, HIR"你还有" + chinese_number(30 - t) +
			    "秒钟仔细考虑("ZJURL("cmds:halt")+ ZJSIZE(20)+ HIC "停止删档" NOR+HIR")。"NOR"\n");
		me->set_temp("suicide/last", t / 5 * 5);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if (! link_ob || ! interactive(me)) return 0;

	log_file("static/suicide",
		 sprintf("%s %s commits a suicide from %s\n",
			log_time(), log_id(me),
			me->query_temp("suicide/from")));
	//VIP_D->save_vdata(me);
	seteuid(getuid());
	write("\n好吧，永别了:)。\n\n");
	if(me->query("combat_exp") > 0)
	{
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s离开了江湖，我一定会回来的。",me->name()));
	}
	tell_room(environment(me), me->name() +	"在你的面前化作轻烟，渐渐消失了...\n", ({me}));

	UPDATE_D->remove_user(me->query("id"));
	return 0;
}

int halt_suicide(object me)
{
	if (! objectp(me) || previous_object() != me)
		return 0;

	tell_object(me, HIG "你打消了寻死的念头。"NOR"\n");
	me->delete_temp("suicide");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择删档.
删档分两种:
 
suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你
	     输入密码以确认身份.
 
请慎重选择 :)
 
HELP );
	return 1;
}
