// apprentice.c

#include <ansi.h>

inherit	F_CLEAN_UP;

int main(object	me, string arg)
{
	object ob, old_app;
	mapping family;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( !arg )
		return notify_fail("指令格式：apprentice | bai [cancel]|<对象>\n");

	if( arg=="cancel" ) {
		old_app	= me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("你现在并没有拜任何人为师的意思。\n");
		write("你改变主意不想拜" + old_app->name() + "为师了。\n");
		tell_object(old_app, me->name()	+ "改变主意不想拜你为师了。\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}

	if( !(ob = present(arg,	environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想拜谁为师？\n");

	if( ob == me )
		return notify_fail("拜自己为师？好主意....不过没有用。\n");

	if( userp(ob) )
		return notify_fail("你不能拜玩家为师。\n");

	if( !living(ob)	)
		return notify_fail("你必须先把"	+ ob->name() + "弄醒。\n");

	if( me->is_apprentice_of(ob) ) {
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);
		return 1;
	}

	if( !mapp( ob->query("family") ) )
		return notify_fail(ob->name() +	"既不属於任何门派，也没有开山立派，不能拜师。\n");

// 加上如果是开除后的判断
	if( me->query("expell")){
	    if(	me->query("expell/family_name")	!= ob->query("family/family_name"))
		return notify_fail("你是被"+me->query("expell/family_name")+"开除的弟子，"+ob->name()+"不会收你为徒。\n");
	}

	if ( ob->query("family/family_name") ==	me->query("family/family_name")
	&& ob->query("family/generation") >= me->query("family/generation")
	&& !me->query_temp("tls_chujia"))
		return notify_fail("你已有明师，我"+ob->name()+"可不敢再收你了。\n");

	// If the target is willing to recruit us already, we do it.

	if( (object)ob->query_temp("pending/recruit") == me ){
		if( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) {
			message_vision(
				"$N决定背叛师门，改投入$n门下！！\n\n"
				"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",
				me, ob);
			me->delete("class");
			me->add("betrayer", 1);
		} else
			message_vision(
				"$N决定拜$n为师。\n\n"
				"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",
				me, ob);
		me->delete("expell");
		ob->recruit_apprentice(me);
		ob->delete_temp("pending/recruit");
		tell_object(ob,	"恭喜你新收了一名弟子！\n");
		family = me->query("family");
		write(sprintf("恭喜您成为%s的第%s代弟子。\n",
			me->query("family/family_name"),
		chinese_number(	me->query("family/generation"))));
		return 1;
	} else {
		old_app	= me->query_temp("pending/apprentice");
		if( ob==old_app	)
			return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
		else if( objectp(old_app) ) {
			write("你改变主意不想拜" + old_app->name() + "为师了。\n");
			tell_object(old_app, me->name()	+ "改变主意不想拜你为师了。\n");
		}

		message_vision("$N想要拜$n为师。\n", me, ob);
		if (me->query("combat_exp") > 10000 && mapp(me->query("family")) && !ob->query("apprentice")
			&& me->query("family/family_name") != ob->query("family/family_name")) {
			message_vision(CYN "$N说道：" +	RANK_D->query_respect(me) +
				"是" + me->query("family/family_name") +
				"高手，" + ob->query("family/family_name") +
				"可不敢收留。\n" NOR, ob);
			return 1;
		}
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) )	{
			tell_object(ob,	YEL "如果你愿意收" + me->name()	+ "为弟子，用 recruit 指令。\n"	NOR);
		} else
			ob->attempt_apprentice(me);
		return 1;
	}
}

int help(object	me)
{
	write(@HELP
指令格式 : apprentice|bai [cancel]|<对象>

这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。

如果对你的师父使用这个指令，会变成向师父请安。

请参考相关指令 expell、recruit
HELP
	);
	return 1;
}
