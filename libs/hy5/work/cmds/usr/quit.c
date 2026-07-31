// quit.c

#include <ansi.h>
#include <command.h>

inherit F_DBASE;

void do_quit(object, object);

void create() 
{
	seteuid(getuid());
	set("channel_id", "离线指令");
}

int main(object me, string arg)
{
	object link_ob,ob;
	int flag = 0,i;
	object *inv;

	if (me->query_temp("quit"))
		return notify_fail("正在退出过程中，请稍候。\n");
if (present("xin",me))
{
                   me->apply_condition("menpai_busy",8);
                   me->apply_condition("hxsd_busy",8);
}
	link_ob = me->query_temp("link_ob");

		inv = all_inventory(me);
if (inv)
{
		for(i=0; i<sizeof(inv); i++)
			if( userp(inv[i]) )
                        return notify_fail("你身上正背着玩家呢，先把他放下吧！\n");
}
//				DROP_CMD->do_drop(me, inv[i]);

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
	}

	if( LOGIN_D->get_madlock()) 
		return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");
	if( me->is_busy()) return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("身上带的东西太多了，离不开游戏了。\n");

	if (interactive(me) && query_idle(me) < 10) {
		if( me->is_busy()) return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
		if( me->is_fighting()) return notify_fail("你现在正在战斗，不能退出游戏！\n");
	} else flag = 1;

if (!objectp(ob = me->query_temp("guard_ob"))) {
destruct(ob);
	}

if (objectp(ob = me->query_temp("guard_ob"))) {
destruct(ob);
	}


//	if (!environment(me)->query("no_save") && !me->is_ghost()) me->set("startroom", base_name(environment(me)));
//if (present("xin",me))
//me->apply_condition("menpai_busy",6);
	me->set_temp("quit", 1);
//        me->set_temp("no_kill", 1);
        me->set_temp("disable_inputs",1);
	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short() + HIR " 准备离开游戏了。");
//	if (!flag && !wizardp(me) && !environment(me)->query("valid_startroom")) {
	if (!flag && !wizardp(me)) {
		write("正在退出游戏 ,档案保存中......\n");
		call_out("do_quit", 8, me, link_ob);

	} else do_quit(me, link_ob);

	return 1;
}

void do_quit(object me, object link_ob)
{
	int i;
	object *inv;

	if (!me) return;
	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}
	write("欢迎下次再来！\n");
	message("system", me->name() + "离开游戏。\n", environment(me), me);
//	i=me->query("combat_exp")-me->query_temp("temp_exp");
//	if (i < 0 ) i=0;
if (me->query("combat_exp",1)>= 1000000 && me->query_temp("temp_exp") &&  me->query_temp("mud_age"))
{
if (me->query("combat_exp") - me->query_temp("temp_exp") > 100 && 
me->query("mud_age") - me->query_temp("mud_age") > 100
)
{
	if (!wizardp(me)
	&& (i = (me->query("combat_exp") - me->query_temp("temp_exp")) * 60
		/ (me->query("mud_age") - me->query_temp("mud_age"))) > 100)
if (i > 300)
		log_file("static/EXP",
			sprintf("%s 上次经验：%d，本次经验：%d，平均：%d/min\n",
				geteuid(me), me->query_temp("temp_exp"),
				me->query("combat_exp"), i));
}
}
	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short(1) + HIR " 离开游戏了。");

	if (link_ob) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	if (me->query("mud_age") == me->query_temp("mud_age"))
		me->add("mud_age", 1);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")离开游戏了。本次连线经验增长"+i+"。\n");

	me->set_temp("quit", 0);
//        me->set_temp("no_kill", 0);
        me->set_temp("disable_inputs",0);
	me->save();
	destruct(me);
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
