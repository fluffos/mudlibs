// expell.c
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	int i;
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("你要提升谁的身份？\n");
	if( !ob->is_character() )
		return notify_fail("你逐不动他。\n");
	if( !userp(ob) )
		return notify_fail("你只能提升玩家所扮演的人物权力。\n");
	if((int)me->query("guild/tisheng")>=2)
		return notify_fail("你帮里的长老已经够了。\n");
if((int)ob->query("guild/generation")==2)
		return notify_fail("" + ob->name() + "已经是你帮里的长老了。\n");
	if( (int)me->query("guild/generation")<2
	&&	(string)me->query("guild/name")==(string)ob->query("guild/name") ) {
		message_vision("\n$N对着$n说道：从今天起，你就是我"
			+ me->query("guild/name") + "的长老了，好好干！\n\n",
			me, ob);
		tell_object(ob, "\n" + me->name() + "将你的权限提升为长老。\n\n");
	} else
		return notify_fail("这个人不是你的小弟。\n");
	ob->set("guild/generation",2);
	me->add("guild/tisheng",1);
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : fengren <某人>
 
这个指令可以让你提升手下的身份
 
HELP
	);
	return 1;
}
