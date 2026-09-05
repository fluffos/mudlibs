#include <ansi.h>
#include <room.h>
#include <localtime.h>

#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", HIG"庄门"NOR);
	set("long","顺着青石板大路来到一所大庄院前，庄子周围小河环绕，河边满是
绿柳，在甘凉一带竟能见到这等江南风景，所有人都会为之胸襟一爽。
只见庄门大开，吊桥早已放下，一位穿着男装的小姐站在门口迎接。庄
门正上方高悬匾额，写着四个大字。\n\n"
+HIC"      ◎───────────────────────◎\n"
+"      │                                              │\n"
+"      │                "HIG"绿  柳  山  庄"HIC"                │\n"
+"      │                                              │\n"
+"      ◎───────────────────────◎\n\n"NOR);
	set("outdoors", "lvliu");
	set("exits", ([
		"north" : __DIR__"dating",
	]));
    set("objects", ([
	    __DIR__"npc/zhaomin" : 1,
        ]));
	setup();
}

void init()
{
	int reward;
	string mday;
	object me = this_player();
	mixed* timeinfos=localtime(time());
	mday = "" + timeinfos[LT_YEAR] + sprintf("%02d", timeinfos[LT_MON]) + sprintf("%02d", timeinfos[LT_MDAY]);
	reward = me->query_temp("lvliu/move_exp");
	if (reward > 0 && me->query("lvliu/move/last") != mday )
	{
		me->set("lvliu/move/last", mday);
		me->delete_temp("lvliu/move_exp");
		remove_call_out("give_reward");
		call_out("give_reward",1,me,reward);
	}
}

void give_reward(object me, int reward)
{
	string msg;
	int exp,pot,rep;
	if (!objectp(me) || reward <= 0) return;
	message_vision(HIW"赵敏" HIC "对$N" HIC "微笑拱手道：「尊客远道光降，这厢奉上薄礼，敝庄诸多简慢，尚请恕罪。」\n"NOR, me);
	msg = "你被奖励了：\n";
	exp = REWARD_D->add_exp(me, 2000 + random(2000) + reward * 200);
	msg += "\t"+chinese_number(exp)+"点经验；\n";
	pot = REWARD_D->add_pot(me, 1500 + random(1000) + reward * 100);
	msg += "\t"+chinese_number(pot)+"点潜能；\n";
	rep = REWARD_D->add_rep(me, 1000 + random(500) + reward * 80);
	msg += "\t"+chinese_number(rep)+"点声望。\n\n";
	me->add("lvliu/credit", reward);
	me->add("exp/lvliu_move", exp);
	me->add("lvliu/move/times",1);
	tell_object( me, HIW + msg + NOR);	
}

