// quit.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "离线指令");
	set("id", "quit");
	set("channel_id", "离线精灵");
}

int main(object me, string arg)
{
	int i;
	object *inv, link_ob, ob;
string name;
	if( LOGIN_D->get_madlock()) 
		return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");
//	if( me->is_busy()) return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);
        if( !me->query_temp("netdead") && !interactive(me)) 
           return notify_fail("这个指令只能由系统执行。\n");
	if( interactive(me) && query_idle( me ) < 120 )
           return notify_fail("这个指令只能由系统执行。\n");
	
	if( me->over_encumbranced() )
		return notify_fail("身上带的东西太多了，离不开游戏了。\n");
if (present("xin",me))
{
                   me->apply_condition("menpai_busy",8);
                   me->apply_condition("hxsd_busy",8);
}

	if( !wizardp(me) && userp(me)) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() && me )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();

  	if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		if( environment(me)->query("valid_startroom") )
		{
			me->set("startroom", base_name(environment(me)));
			write("当你下次连线进来时，会从这里开始。\n");
		}

		destruct(link_ob);
	}

	write("欢迎下次再来！\n");

//        if ( wiz_level( me->query("id") ) < 2 ){
//             message("channel:chat",HIW"【江湖通告】："
//             +me->query("name")+"("+me->query("id")+")暂时离开了江湖！\n"NOR,users());
//             }

//        message("system", me->name() + "离开游戏。\n", environment(me), me);
        
//	i=me->query("combat_exp")-me->query_temp("temp_exp");
//	if (i < 0 ) i=0;
/*
if (me->query("combat_exp") - me->query_temp("temp_exp") > 100)
{
	if (!wizardp(me)
	&& (i = (me->query("combat_exp") - me->query_temp("temp_exp")) * 60
		/ (me->query("mud_age") - me->query_temp("mud_age"))) > 100)
		log_file("static/EXP",
			sprintf("%s 上次经验：%d，本次经验：%d，平均：%d/min\n",
				geteuid(me), me->query_temp("temp_exp"),
				me->query("combat_exp"), i));
}
	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")离开游戏了。本次连线经验增长"+i+"。\n");
*/
//	CHANNEL_D->do_channel(this_object(), "sys",
//		me->name() + "(" + me->query("id") + ")离开游戏了。共清除 " + reclaim_objects() + " 个变数。\n");
	
//if (present("xin",me))
//me->apply_condition("menpai_busy",6);
	me->save();

//************* Puff added these for update topten ***********
        if( userp(me) )

//************* End of Puff added ******************
if (me->query("combat_exp") <30
&& strlen(me->query("id"))==8 && !me->query("zhuanshen"))
{
name=me->query("id");
	rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
}
	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit | exit

当你(你)想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
