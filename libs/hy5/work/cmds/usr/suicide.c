// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("你上一个动作还没完成。\n");

	//if( !arg || arg != "-f") {
	//	write("请用 suicide -f 确定自杀。\n");
	//	return 1;
	//}

	if( arg!="-n" && arg!="-f" ) 
		return notify_fail("自杀有两种，您是要永远死掉(suicide -f)还是重新投胎(suicide -n)？\n");

	write(
		"江湖虽然险恶，生活毕竟美好，请不要轻言自杀。\n"
		"选择自杀意味着这个人物的资料就永远删除了，请务必考虑清楚，\n"
		"确定的话请输入您的密码：");
	  if(arg=="-f" )  input_to("check_password", 1, me, 1);
		if(arg=="-n" )  input_to("check_password", 1, me, 0);
	return 1;
}

void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}

	if (!forever) {
		tell_object( me,
			HIR "\n\n你的门派信息 经验和潜能清零。\n\n\n" NOR);
        me->set("combat_exp",0);
        me->set("potential",me->query("learned_points"));
        me->delete("family");
        me->delete("class");
        me->delete("quest");
        me->delete("quest_count");
        me->set("title", "普通百姓");
        me->set("class","0");
        me->delete("party");
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n你决定要自杀了，你有三十秒可以用来告别。\n\n\n" NOR);
		me->set_temp("suicide_countdown", 30);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :),
			(: call_other, this_object(), "halt_suicide" :) );
	}
}

int slow_suicide(object me)
{
	object link_ob;
	int stage;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);

	if( stage > 1 ) {
		if( stage%5 == 0 )
			tell_object(me, HIR "你还有 " + stage + " 秒的时间可以后悔,用"HIG"halt"HIR"可以终止自杀。\n" NOR);
		return 1;
	}

   if (userp(me) && !query_heart_beat(me))
        return 0;
   if( me->query("hunmi",1))
        return 0;
   if( me->query("disable_inputs",1))
        return 0;

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__);
	rm( me->query_save_file() + __SAVE_EXTENSION__ );

rm("/p/residence/banding/"+me->query("id"));
rm("/p/residence/weapon/"+me->query("id")+"_w1.c");
rm("/p/residence/weapon/"+me->query("id")+"_w2.c");
rm("/p/residence/weapon/"+me->query("id")+"_w3.c");
rm("/p/residence/weapon/"+me->query("id")+"_w4.c");
rm("/p/residence/weapon/"+me->query("id")+"_w5.c");
rm("/p/residence/weapon/"+me->query("id")+"_a1.c");
rm("/p/residence/weapon/"+me->query("id")+"_a2.c");
rm("/p/residence/weapon/"+me->query("id")+"_a3.c");
rm("/p/residence/weapon/"+me->query("id")+"_a4.c");
rm("/p/residence/weapon/"+me->query("id")+"_a5.c");
rm("/p/residence/weapon/"+me->query("id")+"_a6.c");
rm("/p/residence/weapon/"+me->query("id")+"_a7.c");
rm("/p/residence/weapon/"+me->query("id")+"_a8.c");
rm("/p/residence/weapon/"+me->query("id")+"_a9.c");
rm("/p/residence/weapon/"+me->query("id")+"_a10.c");


		write("好吧，永别了:)。\n");
	tell_room(environment(me), me->name() +
		"自杀了，以后你再也看不到这个人了。\n", ({me}));
	destruct(me);
	return 0;
}

int halt_suicide(object me)
{
	tell_object(me, "你放弃了自杀的念头。\n");
	CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + "决定继续勇敢地活下去。");
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀.
自杀分两种:
 
suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份.
 
请慎重选择 :)
 
HELP
);
        return 1;
}
