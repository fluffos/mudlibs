//比武场

#include <ansi.h>
#include <room.h>
#include <present.h>

inherit ROOM;

void build_name(int num)
{
	string *shorts = ({ "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸", });
	string short_name;
	short_name = shorts[num-1];
	set("short", HIW + short_name + "字比武场" NOR);
	set("long", "这是一个用于比武较技的环形场地，地面用坚硬的青石铺就，四周围着一丈余高
的石墙，只有一个小铁门用于进出场地。这比武场中的规矩相当残酷，全凭个人武力
生存。一旦进了这比武场，要么战到最后成为最终的胜利者，要么只能被抬下场去。\n");
	set("lvliu_biwuchang", num);
    set("objects", ([
	    __DIR__"npc/caipan" : 1,
        ]));
    set("no_die",1);
	set("no_sleep_room",1);
}

int player_count()
{
	object *allob = all_inventory(this_object());
	int c = 0;
	for (int i=0;i<sizeof(allob);i++)
	{
		if (userp(allob[i])) c++;
	}
	return c;
}

object player_in_use()
{
	object *allob = all_inventory(this_object());
	for (int i=0;i<sizeof(allob);i++)
	{
		if (userp(allob[i])) return allob[i];
	}
	return 0;
}

int in_use()
{
	if (player_count()>0) return 1;
	return 0;
}

void clean_up_this_room()
{
	object *allob;
	allob = all_inventory(this_object());
	for (int i=0;i<sizeof(allob);i++)
	{
		if (!userp(allob[i]) && !allob[i]->query("biwu_caipan")) destruct(allob[i]);
	}
}

void npc_arise(object me)
{
	object npc;
	npc = new(__DIR__"npc/jinwei");
   	npc->do_copy(me);
   	npc->move(this_object());
	message_vision(HIM"小铁门打开了，一位近卫武士走了进来。\n" +
		HIR "战斗开始！近卫武士大喝一声，对着$N发起了攻击！\n"NOR, me);
   	npc->kill_ob(me);
   	me->kill_ob(npc);
}

int do_alert(string arg)
{
	if(this_player()->is_busy()) return 0;
	tell_object(this_player(),"比武场内，一切生死靠自己！若是能叫帮手，你的人还能多过山庄的武士？\n");
	this_player()->add_busy(random(3)+3);
	return 1;
}

void init()
{
	object me=this_player();
    object room, npc;
	room = this_object();

	if ((!userp(me) && !me->query("lvliu_biwuchang_jinwei") && !me->query("biwu_caipan"))
		|| (userp(me) && player_count()>1))
	{
		me->move(__DIR__"biwulouxia");
		return;
	} //无关人等退场

	add_action("do_alert","alert");
	
	if (userp(me))
	{
		if (!me->query_temp("lvliu_biwuchang/count"))
		{
			clean_up_this_room();
		}
		npc = present_npc("jinwei wushi", room);
		if (!objectp(npc))
		{
			remove_call_out("next_turn");
			call_out("next_turn", 2, me, HIY"场边的裁判见$N进入比武场，站起身来向$P解释了一下比武场的规矩。\n"NOR);
		}
		else
		{
			npc->kill_ob(me);
			me->kill_ob(npc);
		}
	}
}

void countdown(object me, int second)
{
	if (!objectp(me) || environment(me) != this_object()) return;
	if (second<=0)
	{
		tell_object(me, HIG"「开始！」\n"NOR);
        if ((int)me->query_temp("pending/exercise") != 0) {
                message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/respirate") != 0) {
                message_vision("$N强行收回精气，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->delete_temp("pending/practice") != 0) {
                message_vision("$N强行收回内力，停了下来。\n", me);
                me->interrupt_me();
        }
		npc_arise(me);
	}
	else 
	{
		tell_object(me, HIG"「"+chinese_number(second)+"！」\n"NOR);
		call_out("countdown", 1, me, second - 1);
	}
}

void next_turn(object me, string msg)
{
	int interval;
	if (stringp(msg))
		message_vision(msg, me);
	interval = me->query("lvliu/biwuchang/set_interval");
	if (interval<2 || interval>10)
		interval = 10;
	tell_object(me, HIC"下一场比武将在"+chinese_number(interval)+"秒钟之后开始，请做好准备。\n" HIG "场边的裁判开始大声倒计时：\n"NOR);
	if (me->is_busy()) me->start_busy(0);
	remove_call_out("countdown");
	call_out("countdown", 1, me, interval);
}

int prevent_die(object me)
{
	int num;
	object npc, tasknpc, room;
	if (!objectp(me) || !userp(me))
		return 0;
	room = this_object();
	tell_room(room, HIY"几个武士把死猪一样的"+me->query("name")+HIY"拖走了。\n"NOR);
	
	npc = present_npc("jinwei wushi", room);
	if (objectp(npc))
		message_vision(HIC"$N哈哈大笑，向四周看台挥舞手臂，欢呼庆贺自己的胜利，然后趾高气昂地离开了。\n"NOR, npc);
	room->clean_up_this_room();
	me->clear_condition();
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", 1);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", 1);
	me->add("lvliu/biwuchang/times",1);
	num = (int)me->query_temp("lvliu_biwuchang/count"); 
	if (num > (int)me->query("lvliu/biwuchang/max_turn"))
	{
		me->set("lvliu/biwuchang/max_turn", num);
		me->set("lvliu/biwuchang/max_turn_time", time());
	}
	me->delete_temp("lvliu_biwuchang");
	me->move(__DIR__"biwuxiuxi");
	message_vision(HIY"\n几个武士抬着死猪一样的$N进了房间，随手往角落里一扔就走了。\n\n"NOR, me);
	tasknpc = find_object(__DIR__"npc/zongguan");
	if (objectp(tasknpc) && num>5)
		CHANNEL_D->do_channel(tasknpc, "chat", ""+me->query("name")+"挑战敝庄比武场，共战胜"+chinese_number(num)+"位对手！");
	if (num>=20)
		me->add("lvliu/credit", num - 15);
	else if (num>=10 && random(2))
		me->add("lvliu/credit", 1 + random(5));
	return 1;
}


