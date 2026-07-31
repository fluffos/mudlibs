// ask.c
#include <ansi.h>
inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n疑惑地看着$N，摇了摇头。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic, tmpinq, msg;
	object ob;
	mapping inquiry;
	object env;
	mixed info;

	seteuid(getuid());

	if (! arg)
		return notify_fail("你要问谁什么事？\n");

	if (sscanf(arg, "%s about %s", dest, topic) != 2 &&
	    sscanf(arg, "%s %s", dest, topic) != 2)
		return notify_fail("你要问谁什么事？\n");

	env = environment(me);
	if (info = env->query("no_say"))
	{
		if (stringp(info))
		{
			write(info);
			return 1;
		}

		write("这个地方不能讲话。\n");
		return 1;
	}

	if (! objectp(ob = present(dest, env)))
		return notify_fail("这里没有这个人。\n");

	if (me->ban_say(1) && playerp(ob))
		return 0;

	if (! ob->is_character())
	{
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}

	if (ob == me)
	{
		message_vision("$N自己自言自语。\n", me);
		return 1;
	}

	if (me->query("jing") < 30 && ! playerp(ob))
	{
		write("你现在的精神不太好，没法和别人套瓷。\n");
		return 1;
	}

	if(sscanf(topic,"#%*d-%s",tmpinq)!=2)
		tmpinq = topic;

	if (! ob->query("can_speak"))
	{
		message_vision(CYN "$N" CYN "向$n" CYN 
			       "打听有关『" HIG + tmpinq + NOR CYN "』"
			       "的消息，但是$p显然听不懂人话。"NOR"\n", me, ob);
		return 1;
	}

	if (! INQUIRY_D->parse_inquiry(me, ob, topic))
		message_vision(CYN "$N" CYN "向$n" CYN "打听有关『" HIG +
			       tmpinq + NOR CYN "』的消息。"NOR"\n", me, ob);

	if (! living(ob))
	{
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",	me, ob);
		return 1;
	}

	if (playerp(ob) || ob->is_chatter())
	{
		ob->set_temp("ask_you", me->query("id"));
		return 1;
	}

	me->receive_damage("jing", 10 + random(10));
	if (msg = ob->query("inquiry/" + topic) || msg = ob->accept_ask(me, topic))
	{
		if (stringp(msg))
		{
			tell_object(me,CYN+ob->query("name")+"说道：" + msg + NOR"\n");
			return 1;
		}
	} else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
	write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP );
	return 1;
}

