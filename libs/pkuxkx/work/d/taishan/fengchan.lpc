// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "封禅台");
	set("long", @LONG
如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，
比武夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上
摆放着汉白玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，
上书：替天行道 四个大字。 盟主左右各侍立着两位白衣武士，两
边都放着一长排虎皮交椅，时常有武林前辈高手前来参见盟主。
LONG
	);

	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));

	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));

        set("no_clean_up", 1);
	set("outdoors", "taishan");

	setup();
}

void init()
{
	add_action("do_fengshan","fengshan");
}

int do_fengshan()
{
	object partner,me=this_player();
	if (me->query_temp("songtasks/libu2/task")!=4&&!me->query_temp("songtasks/libu2/fengchan_partner"))
	{
		return 0;
	}
	if (me->query_temp("songtasks/libu2/4/finish"))
	{
		return notify_fail("封禅任务已经结束了。\n");
	}
	if (me->query_temp("songtasks_libu2_fengchan"))
	{
		partner=me->query_temp("songtasks_libu2_fengchan");
	}
	else
	{
		partner=me->query_temp("songtasks/libu2/fengchan_partner");
	}
	if (!partner||!userp(partner))
	{
		return notify_fail("封禅任务已经失败。\n");
	}
	if (!present(partner,this_object()))
	{
		return notify_fail("你的搭档此刻不在这里，要等他到了，才能开始封禅。\n");
	}
	message_vision("$N和$n开启了封禅泰山的仪式。\n",me,partner);
	message_vision("$N开始宣扬大宋诸帝王的文治武功。\n",me);
	message_vision("$N轻诵祝词，使人刻上泰山的石壁。\n",partner);
	message_vision("$N和$n进行完所有流程，封禅泰山结束。\n",me,partner);
	me->set_temp("songtasks/libu2/4/finish",1);
	partner->set_temp("songtasks/libu2/4/finish",1);
	me->delete_temp("songtasks_libu2_fengchan");
	partner->delete_temp("songtasks_libu2_fengchan");
	tell_object(me,"封禅泰山完成，你可以回礼部复命了。\n");
	tell_object(partner,"封禅泰山完成，你可以回礼部复命了。\n");
	return 1;
}