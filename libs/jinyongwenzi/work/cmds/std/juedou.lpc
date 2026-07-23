// juedou.c
// by tiantian@sj 2000.7.17

#include <ansi.h>

int main(object me, string arg)
{
	object obj;
	string callname, msg;

	if( !arg )
	 return notify_fail("你想跟谁决斗？\n");

    if(me->query_temp("juedou")) return notify_fail("同时跟两个人决斗？有志气，不过不公平。\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不准决斗。\n");

	if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0 && !obj->query_condition("killer"))
		return notify_fail("武馆内禁止决斗。\n");
		
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if (me->query_temp("combat_yield"))
		return notify_fail("你正打不还手呢，还想和人决斗？\n");
	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("你不能攻击巫师等级比你高的对手。\n");

	if( me->is_killing(obj) || obj->is_killing(me) )
		return notify_fail("对方已经开始动手了，你还需要这么讲面子么？\n");
	if (obj == me) return notify_fail("用 suicide -f 指令会比较快些。\n");

	if (userp(obj) && me->query_condition("killer") > 100)
		return notify_fail("一日不过三，别杀上瘾了。\n");
/*
	if ( userp(me) && userp(obj) && obj->query("age") < 17 )
		return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n");

	if ( userp(me) && userp(obj) && obj->query("combat_exp") < 15000 )
		return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n");
*/
	callname = RANK_D->query_rude(obj);

if( !userp(obj) ) return notify_fail("他能懂你的意思么？你想过瘾，还是找玩家去吧。\n");
    if( obj->query("race")!="人类" )
	return notify_fail("你怎么跟它决斗？用嘴咬么？\n" );
	
    if( obj->query_temp("juedou") && obj->query_temp("juedou")!= me)
	return notify_fail("对方正跟别人决斗呢，你先休息一会吧。\n");

    if( obj->query_temp("juedou") && obj->query_temp("juedou")==me ) {
    message_vision("$N轻蔑地对$n撇了撇嘴：“今天不给你点厉害看看，你也不知道马王爷三只眼。\n", me, obj );
    me->delete_temp("jiudou");
    obj->delete_temp("juedou");
	CHANNEL_D->do_channel(this_object(), "rumor", me->name(1)+"和" 
	    + obj->name(1)+"在"+environment(me)->query("short")
	    + "开始生死决斗。");
    call_out("begin",3+random(5),me,obj);
return 1;
}
    msg = "$N对着$n大吼一声：“" + callname + "，我今天跟你不死不休，来吧，公公平平的打上一架吧。”\n";
    message_vision(msg,me,obj);
    tell_object(obj, me->query("name")+"要跟你生死决斗，如果你接受对方的邀请，请你向对方使用juedou命令。\n");
    me->set_temp("juedou", obj);

    call_out("remove_effect",30,me);

	return 1;
}

void begin( object me, object obj )
{
	string mid, oid;

	if(!me || !obj ) return;
	if( environment(me)!=environment(obj) ) return;
	if( environment(me)->query("no_fight") || me->query_condition("killer") || obj->query_condition("killer") )
		return;
	mid = me->query("id");
	oid = obj->query("id");
	me->delete("last_death_time/"+oid);
	obj->delete("last_death_time/"+mid);
	me->kill_ob(obj);
	obj->kill_ob(me);
	me->delete_temp("kill_other/"+oid);
	obj->delete_temp("kill_other/"+mid);
	me->set_temp("other_kill/"+oid, 1);
	obj->set_temp("other_kill/"+mid, 1);
	me->set_temp("guarding", 1);
	obj->set_temp("guarding", 1);
}

void remove_effect( object me )
{
    if(!me) return;
    if(me->query_temp("juedou")) {
	tell_object(me,HIR"对方拒绝了你的决斗请求。\n"NOR );
	me->delete_temp("juedou");
    }
}

int help(object me)
{
  write(@HELP
指令格式：juedou <人物>

这个指令，用来表明跟对方不死不休的立场，如果对方接受你的
决斗请求，并且在一定的时间内，对你也使用相同
的指令，那么双方将会在一段时间后，开始互相试图杀死
对方。

决斗是双方自愿的方式，对方可以不接受你的决斗请求，而选择其它的
方式了解双方的恩怨。

其他相关指令：kill fight ansuan
 
HELP
    );
    return 1;
}
