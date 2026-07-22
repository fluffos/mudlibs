// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "山坡");
	set("long", @LONG
只见山坡上一头黄牛昂首吽鸣，所处形势却极怪异。那牛仰天卧在一块岩
石上，四足挣扎，站不起来，那石摇摇欲堕，下面一人摆起了丁字步，双手托
住岩石，只要一松手，势必连牛带石一起跌入下面深谷。那人所站处又是一块
突出的悬岩，无处退让，纵然舍得那牛不要，但那岩石压将下来，不是断手，
也必折足。瞧这情势，必是那牛爬在坡上吃草，失足跌将下来，撞松岩石，那
人便在近处，抢着托石救牛，却将自己陷入这狼狈境地。
LONG
	);
	set("outdoors", "桃源县");

	set("exits", ([
		"westdown" : __DIR__"shanding",
		"east" : __DIR__"shiliang",
	]));

	set("objects", ([
		__DIR__"npc/gengzi" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_tuo", "tuo");
}

int do_tuo(string arg)
{
	object ob, me = this_player();

	if (! arg || arg != "shi")
		return notify_fail("你要托什么？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("yideng/nongfu_pass"))
		return notify_fail("你已经帮农夫托起石块了，还不快离开？\n");

	if ( query("ppl"))
		return notify_fail("已经有人托着了。\n");

	if ( ! ob = present("nong fu", environment(me)))
		return notify_fail("农夫不在，这么大的石块你一个人无法入手。\n");

	if ( me->query("neili") < 2500 )
		return notify_fail("你的内力不够，看来要托起这块石块比较危险。\n");

	message_vision(CYN"\n$N挨到农夫身边，蹲下身去举手托住岩石，道：我托着，你先去将牛牵开！\n\n"NOR, me);
	me->start_busy(100);
	me->add("neili", -2500);
	set("ppl", 1);
	remove_call_out("wait");
	call_out("wait", 2, me, ob);
	return 1;
}

void wait(object me, object ob)
{
	if ( !me ) return;

	if ( !ob ) {
		remove_call_out("finish");
		call_out("finish", 0, me, ob);
		return;
	}

	message_vision(YEL"\n那$n手上斗轻，还不放心$N有偌大力气托得起黄牛与大石，当下先松右手，\n"+
			"侧过身子，左手仍然托在石底。$N脚下踏稳，运起内劲，双臂向上奋力挺举，\n"+
			"大石登时高起尺许，那$n左手也就松了。\n\n"NOR, me, ob);

	remove_call_out("wait2");
	call_out("wait2", 5, me, ob);
}

void wait2(object me, object ob)
{
	if ( !me ) return;

	if ( !ob ) {
		remove_call_out("finish");
		call_out("finish", 0, me, ob);
		return;
	}

	message_vision(YEL"\n$n稍待片刻，见那大石并不压将下来，知道$N尽可支撑得住，这才弯腰从大\n"+
			"石下钻过，跃上山坡，要去牵开黄牛。\n\n"NOR, me, ob);

	remove_call_out("wait3");
	call_out("wait3", 5, me, ob);
}

void wait3(object me, object ob)
{
	if ( !me ) return;

	if ( !ob ) {
		remove_call_out("finish");
		call_out("finish", 0, me, ob);
		return;
	}
	message_vision(YEL"\n$n走过去将牛牵走，从坡上跃下地来，又来至$N的身边。\n\n"NOR, me, ob);

	remove_call_out("finish");
	call_out("finish", 1, me, ob);
}

void finish(object me, object ob)
{
	delete("ppl");

	if ( !me && ! ob) return;

	if ( !ob && me ){
		me->start_busy(-1);
		message_vision("农夫不知去向，$N觉得有点累，就放下了石块。\n"NOR, me);
		return;
	}
	if ( !me && objectp(ob))
		return;

	me->set_temp("yideng/nongfu_pass", 1);
	message_vision(CYN"\n$n双手托住大石，臂上运劲，挺起大石，对$N说道：「多谢相助，你过去吧。」\n"NOR, me, ob);
	me->start_busy(-1);
	return;
}

int valid_leave(object me, string dir)
{
	if ( dir == "east" 
	&& !me->query_temp("yideng/nongfu_pass")) {
		if ( present("nong fu", environment(me)))
			return notify_fail("一位农夫举着大石块，拦住了你的去路。\n");
		else
			return notify_fail("一块大石块拦住了你的去路。\n");
	}
	return ::valid_leave(me, dir);
}
