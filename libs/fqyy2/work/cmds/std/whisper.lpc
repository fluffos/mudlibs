// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob,*newob;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什么？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要对谁耳语？\n");

	if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
	if(ob == me) return notify_fail("告诉自己？\n");
	if (!interactive(ob)) return notify_fail("这个人断线了。\n");
	if (!living(ob)) return notify_fail("这个人现在无法听见你的话。\n");

        if ( ((int)time() - (int)me->query("tell_time")) < 1 )
        return notify_fail("有话好好说哦。\n");

	write( GRN "你在" + ob->name() + "的耳边悄声说道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳边小声地说了些话。\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "在你的耳边悄声说道：" + msg + "\n" NOR);
                     me->set("tell_time", time());
        newob = filter_array(children(USER_OB),(: userp($1) && wizardp($1) :));
if (!wizardp(me) && query_ip_name(ob)!=query_ip_name(me))
{
message("channel:snp", HIB"【窃听】"+me->query("name")+"告诉"+ob->query("name")+"："+msg+"\n"NOR, newob);
}

	return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <讯息>

这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。
TEXT
	);
	return 1;
}
